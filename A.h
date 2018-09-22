
#include <iostream>
#include <functional>

#include "B.h"

using namespace std;

class A
{
public:
	A() = default;
	
	// A->B
	void GetValueFromAtoB()
	{
		function<int(int, int)> callback = [&](int a, int b){
					int num = a + b;
					cout << "code defined on from A: " << num << endl;
					return num;
		};
		
		B bb;
		bb.AddCallBack(callback);
		bb.Print();
		
		function<bool()> tClallback = [](){ return true; };
		auto bFunc = bb.ByPassCallback(tClallback);
		bFunc();
		
		function<bool()> ttClallback = [](){ return false; };
		auto fFunc = bb.ByPassCallback(ttClallback);
		fFunc();

	}
	
	//A->B->A
	void GetValueFromAtoBtoA()
	{
		B bb;
		
		function<bool()> tClallback = [](){ return true; };
		auto bFunc = bb.ByPassCallback(tClallback);
		bFunc();
		
		function<bool()> ttClallback = [](){ return false; };
		auto fFunc = bb.ByPassCallback(ttClallback);
		fFunc();
	}
};



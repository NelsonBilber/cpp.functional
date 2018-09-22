
#include <iostream>
#include <functional>

class B
{
public:
	B() = default;
	
	void AddCallBack(std::function<int(int,int)>& Func)
	{
		std::cout << "antes class b" << std::endl;
		std::cout << "Func res = "  << Func(3,5) << std::endl;
		std::cout << "depois class b" << std::endl;
	}
	
	std::function<void()> ByPassCallback(std::function<bool()> Func)
	{
		if(Func())
		{
			return [](){ std::cout << "from B is true " << std::endl; };
		}
		else
		{
			return [](){ std::cout << "from B is false " << std::endl; };
		}
	}
	
	void Print() { std::cout << "class b" << std::endl;	};
};



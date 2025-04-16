#include "_libs.hpp"

class Base
{
public:
	void testFunction()
	{
		cout << "Base class" << endl;
	}
};
class Derived : public Base
{
public:
	void testFunction()
	{
		cout << "Derived class" << endl;
	}
};
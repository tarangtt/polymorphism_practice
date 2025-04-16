//tarang teredesai CPTS 122 LAB13
//polymorphism

#include "_libs.hpp"
#include "Task1.hpp"
#include "Task2.hpp"
#include "Task3.hpp"

int main(void)
{
	Base* ptr = new Base;
	ptr->testFunction(); // prints "Base class"
	delete ptr;
	ptr = new Derived;
	ptr->testFunction(); // prints "Base class" because the base
	class function is not virtual
	delete ptr;
	return 0;
}

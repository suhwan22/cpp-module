#include "Bureaucrat.hpp"

int main()
{
	std::cout << "---------------increase exception case---------------" << std::endl;
	Bureaucrat	jerk("jerk", 10);
	int	i;

	i = 0;
	try
	{
		std::cout << jerk << std::endl;
		for (; i < 10; i++)
		{
			jerk.increaseGrade();
			std::cout << jerk << std::endl;
		}
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n\n---------------decrease exception case---------------" << std::endl;
	Bureaucrat	idiot("idiot", 141);
	i = 0;
	try
	{
		std::cout << idiot << std::endl;
		for (; i < 10; i++)
		{
			idiot.decreaseGrade();
			std::cout << idiot << std::endl;
		}
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\n---------------constructor exception case---------------" << std::endl;
	try
	{
		Bureaucrat	test("test", 0);
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	test2("test2", 170);
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

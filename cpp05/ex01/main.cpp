#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "---------------Form constructor grade exception case---------------" << std::endl;

	try
	{
		Form	testForm1("test1", 0, 0);
		std::cout << testForm1 << std::endl;
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form	testForm2("test2", 151, 151);
		std::cout << testForm2 << std::endl;
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form	testForm3("test3", 50, 20);
		std::cout << testForm3 << std::endl;
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\n---------------sign exception case---------------" << std::endl;
	try
	{
		Bureaucrat	user1("user1", 30);
		Form		form1("form1", 50, 20);
		std::cout << form1 << std::endl;
		user1.signForm(form1);
		std::cout << form1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	user2("user2", 70);
		Form		form2("form2", 50, 20);
		std::cout << form2 << std::endl;
		user2.signForm(form2);
		std::cout << form2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::cout << "---------------ShrubberyCreationForm exception case---------------" << std::endl;

	try
	{
		Bureaucrat	user1("user1", 150);
		ShrubberyCreationForm	form1("home");
		
		user1.signForm(form1);
		user1.executeForm(form1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	user2("user2", 140);
		ShrubberyCreationForm	form2("home");

		user2.signForm(form2);
		user2.executeForm(form2);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	user3("user3", 10);
		ShrubberyCreationForm	form3("home");
		user3.signForm(form3);
		user3.executeForm(form3);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\n---------------RobotomyRequestForm exception case---------------" << std::endl;
	try
	{
		Bureaucrat	user1("user1", 150);
		RobotomyRequestForm	form1("cook");
		
		user1.signForm(form1);
		user1.executeForm(form1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	user2("user2", 70);
		RobotomyRequestForm	form2("cook");

		user2.signForm(form2);
		user2.executeForm(form2);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	user3("user3", 10);
		RobotomyRequestForm	form3("cook");
		user3.signForm(form3);
		user3.executeForm(form3);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\n---------------PresidentialPardonForm exception case---------------" << std::endl;
	try
	{
		Bureaucrat	user1("user1", 150);
		PresidentialPardonForm	form1("criminal");
		
		user1.signForm(form1);
		user1.executeForm(form1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	user2("user2", 20);
		PresidentialPardonForm	form2("criminal");

		user2.signForm(form2);
		user2.executeForm(form2);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	user3("user3", 2);
		PresidentialPardonForm	form3("criminal");
		user3.signForm(form3);
		user3.executeForm(form3);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

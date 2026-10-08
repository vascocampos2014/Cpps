#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	std::cout << "--- test 1: execute unsigned form\n";
	try
	{
		Bureaucrat a("ana", 1);
		PresidentialPardonForm b("Arthur");
		a.executeForm(b);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << "--- test 2: signed but bureaucrat grade too low to execute\n";
	try
	{
		Bureaucrat c("Miguel", 20);
		PresidentialPardonForm d("Ford");
		c.signForm(d);
		c.executeForm(d);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << "--- test 3: grade too low to sign\n";
	try
	{
		Bureaucrat e("Joao", 150);
		ShrubberyCreationForm f("garden");
		e.signForm(f);
		e.executeForm(f);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << "--- test 4: shrubbery success (creates home_shrubbery)\n";
	try
	{
		Bureaucrat g("Rita", 137);
		ShrubberyCreationForm h("home");
		std::cout << h << std::endl;
		g.signForm(h);
		g.executeForm(h);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << "--- test 5: robotomy success, executed 4 times (50%)\n";
	try
	{
		Bureaucrat i("Pedro", 45);
		RobotomyRequestForm j("Bender");
		i.signForm(j);
		for (int k = 0; k < 4; k++)
			i.executeForm(j);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << "--- test 6: presidential pardon success\n";
	try
	{
		Bureaucrat l("Zaphod", 1);
		PresidentialPardonForm m("Arthur Dent");
		l.signForm(m);
		l.executeForm(m);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << "--- test 7: execute through AForm reference\n";
	try
	{
		Bureaucrat n("Boss", 1);
		RobotomyRequestForm o("Marvin");
		AForm& ref = o;
		n.signForm(ref);
		n.executeForm(ref);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
	return 0;
}

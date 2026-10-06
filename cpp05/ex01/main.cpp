#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <climits>

int main()
{
	std::cout << "--- test 1: sucesseful sign form\n";
	try
	{
		Bureaucrat a("ana", 100);
		Form b("Teste", 0, 100, 100);
		a.signForm(b);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << "--- test 2: fail sign form because form low\n";
	try
	{
		Bureaucrat c("Miguel",10);
		Form d("Carta", 0, 9, 5);
		c.signForm(d);
		std::cout << "Sign of form: " << d.getSign() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << "--- test 3: create form with invalid grades\n";
	try
	{
		Form e("Invalida", 0, 0, 50);
		std::cout << e << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
	try
	{
		Form f("Invalida2", 0, 50, 151);
		std::cout << f << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << "--- test 4: sign at exact grade, print form before and after\n";
	try
	{
		Bureaucrat g("Rita", 42);
		Form h("Contrato", 0, 42, 1);
		std::cout << h << std::endl;
		g.signForm(h);
		std::cout << h << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
	return 0;
}

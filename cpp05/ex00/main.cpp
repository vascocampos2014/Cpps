#include "Bureaucrat.hpp"

int main()
{
	std::cout << "--- test 1: create with grade 0\n";
	try
	{
		Bureaucrat a("ana", 0);
		std::cout << "created OK\n";
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}

	std::cout << "--- test 2: create with grade 151\n";
	try
	{
		Bureaucrat t("tiago", 151);
		std::cout << "created OK\n";
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}

	std::cout << "--- test 3: grade 2, increment twice\n";
	try
	{
		Bureaucrat boss("boss", 2);
		boss.incrementGrade();
		std::cout << "first increment OK\n";
		boss.incrementGrade();
		std::cout << "second increment OK\n";
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}

	std::cout << "--- test 4: grade 149, decrement twice\n";
	try
	{
		Bureaucrat intern("intern", 149);
		intern.decrementGrade();
		std::cout << "first decrement OK\n";
		intern.decrementGrade();
		std::cout << "second decrement OK\n";
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
	return 0;
}

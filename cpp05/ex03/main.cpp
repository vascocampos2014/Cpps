#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	Intern someRandomIntern;
	Bureaucrat boss("Boss", 1);
	Bureaucrat low("Joao", 150);

	std::cout << "--- test 1: robotomy request (subject example)\n";
	AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "--- test 2: shrubbery creation (creates home_shrubbery)\n";
	AForm* scf = someRandomIntern.makeForm("shrubbery creation", "home");
	if (scf)
	{
		std::cout << *scf << std::endl;
		boss.signForm(*scf);
		boss.executeForm(*scf);
		delete scf;
	}

	std::cout << "--- test 3: presidential pardon, low grade bureaucrat fails\n";
	AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	if (ppf)
	{
		std::cout << *ppf << std::endl;
		low.signForm(*ppf);
		low.executeForm(*ppf);
		boss.signForm(*ppf);
		boss.executeForm(*ppf);
		delete ppf;
	}

	std::cout << "--- test 4: form name that doesnt exist\n";
	AForm* bad = someRandomIntern.makeForm("coffee making", "kitchen");
	if (!bad)
		std::cout << "makeForm returned NULL" << std::endl;

	std::cout << "--- test 5: wrong case is not accepted\n";
	AForm* bad2 = someRandomIntern.makeForm("Robotomy Request", "Bender");
	if (!bad2)
		std::cout << "makeForm returned NULL" << std::endl;
	return 0;
}

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& copy)
{
	(void)copy;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{

}

AForm* Intern::makeShrubbery(const std::string& target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomy(const std::string& target) const
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePardon(const std::string& target) const
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*makers[3])(const std::string&) const = {
		&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePardon
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << names[i] << std::endl;
			return ((this->*makers[i])(target));
		}
	}
	std::cout << "Intern couldnt create form: \"" << name << "\" doesnt exist" << std::endl;
	return (NULL);
}

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	private:
		AForm* makeShrubbery(const std::string& target) const;
		AForm* makeRobotomy(const std::string& target) const;
		AForm* makePardon(const std::string& target) const;
	public:
		Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm* makeForm(const std::string& name, const std::string& target) const;
};

#endif

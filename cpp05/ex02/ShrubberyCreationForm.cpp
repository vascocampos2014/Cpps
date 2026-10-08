#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 0, 145, 137), _target("test")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 0, 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm(copy), _target(copy._target)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->_target = copy._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::action() const
{
	std::string filename = this->_target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cout << "Could not create file " << filename << std::endl;
		return ;
	}
	file << "       _-_\n"
		 << "    /~~   ~~\\\n"
		 << " /~~         ~~\\\n"
		 << "{               }\n"
		 << " \\  _-     -_  /\n"
		 << "   ~  \\\\ //  ~\n"
		 << "_- -   | | _- _\n"
		 << "  _ -  | |   -_\n"
		 << "      // \\\\\n"
		 << "\n"
		 << "        *\n"
		 << "       /|\\\n"
		 << "      /*|O\\\n"
		 << "     /*/|\\*\\\n"
		 << "    /X/O|*\\X\\\n"
		 << "   /*/X/|\\X\\*\\\n"
		 << "  /O/*/X|*\\O\\X\\\n"
		 << "        |X|\n"
		 << "        |X|\n";
	file.close();
}

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeRequiredSign;
		const int _gradeRequiredExec;
	public:
		Form();
		Form(const std::string name, bool sign, const int signGrade, const int execGrade);
		Form(const Form& copy);
		Form& operator=(const Form& other);
		~Form();

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		void beSigned(const Bureaucrat& bureaucrat);
		std::string getName() const;
		bool getSign() const;
		int getRequiredsign() const;
		int getRequiredExec() const;
};

std::ostream& operator<<(std::ostream& stream, const Form& form);

#endif

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

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
		void signForm(Form& form);
		void incrementGrade();
		void decrementGrade();
		std::string getName() const;
		int getGrade() const;
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& name);

#endif


#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeRequiredSign;
		const int _gradeRequiredExec;
	protected:
		virtual void action() const = 0;
	public:
		AForm();
		AForm(const std::string name, bool sign, const int signGrade, const int execGrade);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		void execute(Bureaucrat const & executor) const;
		void beSigned(const Bureaucrat& bureaucrat);
		std::string getName() const;
		bool getSign() const;
		int getRequiredsign() const;
		int getRequiredExec() const;
};

std::ostream& operator<<(std::ostream& stream, const AForm& AForm);

#endif

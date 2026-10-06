#include "Form.hpp"

Form::Form(): _name("test"), _signed(0), _gradeRequiredSign(75), _gradeRequiredExec(75)
{

}

Form::Form(const std::string name, bool sign, const int signGrade, const int execGrade): _name(name), _signed(sign), _gradeRequiredSign(signGrade), _gradeRequiredExec(execGrade)
{
	if (execGrade > 150 || signGrade > 150)
		throw GradeTooLowException();
	if (execGrade < 1 || signGrade < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& copy): _name(copy._name), _signed(copy._signed), _gradeRequiredSign(copy._gradeRequiredSign), _gradeRequiredExec(copy._gradeRequiredExec)
{

}


Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

Form::~Form()
{
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->getRequiredsign() < bureaucrat.getGrade())
		throw GradeTooLowException();
	else
		this->_signed = 1;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return("Form grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("Form grade too low");
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSign() const
{
	return (this->_signed);
}

int Form::getRequiredsign() const
{
	return (this->_gradeRequiredSign);
}

int Form::getRequiredExec() const
{
	return (this->_gradeRequiredExec);
}

std::ostream& operator<<(std::ostream& stream, const Form& form)
{
	stream << "Form " << form.getName() << ", signed: " << (form.getSign() ? "yes" : "no")
		<< ", grade to sign: " << form.getRequiredsign()
		<< ", grade to execute: " << form.getRequiredExec() << ".";
	return (stream);
}

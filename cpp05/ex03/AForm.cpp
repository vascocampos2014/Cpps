#include "AForm.hpp"

AForm::AForm(): _name("test"), _signed(0), _gradeRequiredSign(75), _gradeRequiredExec(75)
{

}

AForm::AForm(const std::string name, bool sign, const int signGrade, const int execGrade): _name(name), _signed(sign), _gradeRequiredSign(signGrade), _gradeRequiredExec(execGrade)
{
	if (execGrade > 150 || signGrade > 150)
		throw GradeTooLowException();
	if (execGrade < 1 || signGrade < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& copy): _name(copy._name), _signed(copy._signed), _gradeRequiredSign(copy._gradeRequiredSign), _gradeRequiredExec(copy._gradeRequiredExec)
{

}


AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

AForm::~AForm()
{
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->getRequiredsign() < bureaucrat.getGrade())
		throw GradeTooLowException();
	else
		this->_signed = 1;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_gradeRequiredExec)
		throw GradeTooLowException();
	this->action();
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return("AForm is not signed");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return("AForm grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return("AForm grade too low");
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSign() const
{
	return (this->_signed);
}

int AForm::getRequiredsign() const
{
	return (this->_gradeRequiredSign);
}

int AForm::getRequiredExec() const
{
	return (this->_gradeRequiredExec);
}

std::ostream& operator<<(std::ostream& stream, const AForm& AForm)
{
	stream << "AForm " << AForm.getName() << ", signed: " << (AForm.getSign() ? "yes" : "no")
		<< ", grade to sign: " << AForm.getRequiredsign()
		<< ", grade to execute: " << AForm.getRequiredExec() << ".";
	return (stream);
}

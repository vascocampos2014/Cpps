#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("test") , _grade(75)
{

}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):  _name(other._name)
{
	if (other._grade > 150)
		throw GradeTooLowException();
	if (other._grade < 1)
		throw GradeTooHighException();
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if(this != &other)
		this->_grade = other._grade;
	return(*this);
}


Bureaucrat::~Bureaucrat()
{

}

void Bureaucrat::decrementGrade()
{			
	if ((this->_grade + 1) > 150)
		throw GradeTooLowException();
	else
		this->_grade += 1;
}

void Bureaucrat::incrementGrade()
{
	if ((this->_grade - 1) < 1)
		throw GradeTooHighException();
	else
		this->_grade -= 1;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return("grade too low(grade > 150)");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("grade too high(grade < 1)");
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (stream);
}

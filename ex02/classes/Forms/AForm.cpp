/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:03:11 by rabril-h          #+#    #+#             */
/*   Updated: 2023/11/01 18:52:00 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::GradeTooHighException::GradeTooHighException(std::string err_msg) : std::out_of_range(err_msg)
{
  return ;
}

AForm::GradeTooLowException::GradeTooLowException(std::string err_msg) : std::out_of_range(err_msg)
{
  return ;
}

AForm::FormNotSignedException::FormNotSignedException(std::string err_msg) : std::logic_error(err_msg)
{
  return ;
}

AForm::AForm() : _name("Undefined"), _gradeToSign(75), _gradeToExe(75)
{
	this->_formSigned = false;
}

AForm::AForm( const AForm &aform ) : _name(aform._name), _gradeToSign(aform._gradeToSign), _gradeToExe(aform._gradeToExe)
{
	this->_formSigned = aform._formSigned;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExe) : _name(name), _gradeToSign(gradeToSign), _gradeToExe(gradeToExe)
{
	check_grade_exceptions();
	this->_formSigned = false;
}

AForm::~AForm()
{
  return ;
}

AForm	&AForm::operator=( const AForm& aform )
{
	this->_formSigned = aform.getAFormSigned();
	return (*this);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_formSigned = true;
	else
		throw AForm::GradeTooLowException("grade is too low");
}

void	AForm::check_grade_exceptions() const
{
	if (this->_gradeToExe > 150)
		throw Bureaucrat::GradeTooHighException("Grade to exe is too high");
	if (this->_gradeToExe < 1)
		throw Bureaucrat::GradeTooLowException("Grade to exe is too low");
	if (this->_gradeToSign > 150)
		throw Bureaucrat::GradeTooHighException("Grade to sign is too high");
	if (this->_gradeToSign < 1)
		throw Bureaucrat::GradeTooLowException("Grade to sign is too low");
}

int	AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExe() const
{
	return (this->_gradeToExe);
}

bool		AForm::getAFormSigned() const
{
	return (this->_formSigned);
}

std::string	AForm::getName() const
{
	return (this->_name);
}

void		AForm::execute(Bureaucrat const & bureaucrat) const 
{
	if (this->_formSigned == false)
		throw AForm::FormNotSignedException("form is not signed");
	if (bureaucrat.getGrade() >= this->_gradeToExe)
		throw AForm::GradeTooLowException("grade is too low");
	exeForm();
}

std::ostream&	operator<<( std::ostream& out, const AForm& aform )
{
	out << "AForm name: " << aform.getName() << ", AForm sign grade: " \
		<< aform.getGradeToSign() << ", AForm exec grade: " \
		<< aform.getGradeToExe() << ", AForm is signed: " \
		<< (aform.getAFormSigned() ? "true" : "false");
	return ( out );
}
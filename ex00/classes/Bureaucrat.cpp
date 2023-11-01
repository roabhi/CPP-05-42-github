// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bureaucrat.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/29 17:40:34 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/29 18:31:26 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string err_msg) : std::out_of_range(err_msg)
{
	return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string err_msg) : std::out_of_range(err_msg)
{
	return ;
}

//Default constructor

Bureaucrat::Bureaucrat() : _name("Agent Smith"), _grade(GRADE_AVG)
{
	//this->_grade = GRADE_AVG;
	return ;
}

//Copy constructor

Bureaucrat::Bureaucrat(const Bureaucrat &inst) : _name(inst.getName()), _grade(inst.getGrade())
{
	//this->_grade = inst.getGrade();
	return ;
}

//Constructor with name and grade

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
	//this->_grade = grade;
	check_grade_exceptions();
	return ;
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &inst)
{
	this->_grade = inst.getGrade();
	return (*this);
}

void Bureaucrat::upGrade()
{
	this->_grade--;
	check_grade_exceptions();
}

void Bureaucrat::upGrade(int grade)
{
	this->_grade -= grade;
	check_grade_exceptions();
}

void Bureaucrat::downGrade()
{
	this->_grade++;
	check_grade_exceptions();
}

void Bureaucrat::downGrade(int grade)
{
	this->_grade += grade;
	check_grade_exceptions();
}

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::check_grade_exceptions()
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException(EXC_GTH);
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException(EXC_GTL);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &inst)
{
	out << inst.getName() << ", bureaucrat' s grade is " << inst.getGrade();
	return (out);
}

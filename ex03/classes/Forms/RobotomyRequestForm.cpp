/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:16:48 by rabril-h          #+#    #+#             */
/*   Updated: 2023/11/01 18:59:22 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 25, 5), _target("Undefined")
{
  return ;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &RobotomyRequestForm ) : AForm("RobotomyRequestForm", 25, 5), _target(RobotomyRequestForm.getTarget())
{
  return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 25, 5), _target(target)
{
  return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
  return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm& RobotomyRequestForm )
{
	this->_target = RobotomyRequestForm.getTarget();
	AForm::operator=(RobotomyRequestForm);
	return (*this);
}

std::string				RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void	RobotomyRequestForm::exeForm(void) const
{
	std::srand(std::time(0));

	if (rand() % 2)
		std::cout << this->_target << " has been Robotomized." << std::endl;
	else
		std::cout << this->_target << " robotomy failed..." << std::endl;
}
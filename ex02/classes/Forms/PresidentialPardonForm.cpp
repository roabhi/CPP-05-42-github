/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:11:01 by rabril-h          #+#    #+#             */
/*   Updated: 2023/11/01 18:55:46 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Undefined")
{
  return ;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &presidentialPardonForm ) : AForm("PresidentialPardonForm", 25, 5), _target(presidentialPardonForm.getTarget())
{
  return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
  return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
  return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm& presidentialPardonForm )
{
	this->_target = presidentialPardonForm.getTarget();
	AForm::operator=(presidentialPardonForm);
	return (*this);
}

std::string				PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::exeForm(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
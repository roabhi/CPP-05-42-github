/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:27:55 by rabril-h          #+#    #+#             */
/*   Updated: 2023/11/01 18:36:55 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Undefined")
{
  return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &shrubberyCreationForm ) : AForm("ShrubberyCreationForm", 72, 45), _target(shrubberyCreationForm.getTarget())
{
  return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
  return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
  return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm& shrubberyCreationForm )
{
	this->_target = shrubberyCreationForm.getTarget();
	AForm::operator=(shrubberyCreationForm);
	return (*this);
}

std::string				ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::exeForm(void) const
{
	std::string		file_name;
	file_name = this->getTarget().append("_shrubbery");
	std::ofstream	out_file(file_name);

	if (out_file.fail())
		return (std::cerr << "Error : " << std::strerror(errno) << std::endl, (void) 1);
	out_file << "       _-_ " << std::endl;
  out_file << "    #~~###~~# " << std::endl;
  out_file << " #~~#########~~# " << std::endl;
  out_file << "{################} " << std::endl;
  out_file << "    ###|||###   " << std::endl;
  out_file << "     # ||| # " << std::endl;
  out_file << "       ||| " << std::endl;
  out_file.close();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:07:56 by rabril-h          #+#    #+#             */
/*   Updated: 2023/11/01 18:45:54 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTMYREQUESTFORM_HPP
# define ROBOTMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {

  public:
		RobotomyRequestForm();
		RobotomyRequestForm( const RobotomyRequestForm &robotomyRequestForm );
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm	&operator=( const RobotomyRequestForm& robotomyRequestForm );
		std::string				getTarget() const;

  private:
    std::string	_target;
		void	exeForm(void) const;

};

#endif
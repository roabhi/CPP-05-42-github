/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:07:56 by rabril-h          #+#    #+#             */
/*   Updated: 2023/11/01 18:10:38 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

  public:
		PresidentialPardonForm();
		PresidentialPardonForm( const PresidentialPardonForm &presidentialPardonForm );
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm	&operator=( const PresidentialPardonForm& presidentialPardonForm );
		std::string				getTarget() const;

  private:
    std::string	_target;
		void	exeForm(void) const;

};


#endif
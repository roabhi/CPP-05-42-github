/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:06:38 by rabril-h          #+#    #+#             */
/*   Updated: 2023/11/01 21:14:05 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "./Forms/AForm.hpp"
# include "./Forms/PresidentialPardonForm.hpp"
# include "./Forms/RobotomyRequestForm.hpp"
# include "./Forms/ShrubberyCreationForm.hpp"

class AForm;

class Intern {
  public:
    Intern();
		Intern( const Intern &intern );
		~Intern();
		Intern	&operator=( const Intern& intern );
		AForm	*makeForm(std::string formType, std::string formTarget) const;

  private:
		AForm	*doPresidentialPardonForm(const std::string target) const;
		AForm	*doRobotomyRequestForm(const std::string target) const;
		AForm	*doShrubberyCreationForm(const std::string target) const;
};

#endif
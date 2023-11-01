/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:39:31 by rabril-h          #+#    #+#             */
/*   Updated: 2023/11/01 15:21:39 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# define GRADE_MIN 150
# define GRADE_MAX 1
# define GRADE_AVG ((GRADE_MAX - GRADE_MIN) / 2 + GRADE_AVG)
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				formSigned;
		const int			gradeToSign;
		const int			gradeToExe;
	public:
		Form();
		Form( const Form &form );
		Form(std::string name, int gradeToSign, int gradeToExe);
		~Form();
		Form		&operator=( const Form& form );
		void		beSigned(const Bureaucrat &bureaucrat);
		void		check_grade_exceptions() const;
		int			getGradeToSign() const;
		int			getGradeToExe() const;
		bool		getFormSigned() const;
		std::string	getName() const;
		class	GradeTooHighException: public std::out_of_range
		{
			public:
				GradeTooHighException(std::string err_msg);
		};
		class	GradeTooLowException: public std::out_of_range
		{
			public:
				GradeTooLowException(std::string err_msg);
		};

};

std::ostream&	operator<<( std::ostream& out, const Form& form );

#endif
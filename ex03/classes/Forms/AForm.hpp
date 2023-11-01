/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:58:50 by rabril-h          #+#    #+#             */
/*   Updated: 2023/11/01 18:45:15 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "../Bureaucrat.hpp"

class Bureaucrat;

class AForm {

  public:
		AForm();
		AForm( const AForm &form );
		AForm(std::string name, int gradeToSign, int gradeToExe);
		virtual ~AForm();
		AForm		&operator=( const AForm& aForm );
		void		beSigned(const Bureaucrat &bureaucrat);
		void		check_grade_exceptions() const;
		int			getGradeToSign() const;
		int			getGradeToExe() const;
		bool		getAFormSigned() const;
		std::string	getName() const;
		void		execute(Bureaucrat const & bureaucrat) const; 
		virtual std::string				getTarget() const = 0;
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
		class	FormNotSignedException: public std::logic_error
		{
			public:
				FormNotSignedException(std::string err_msg);
		};

    private:
      const std::string	  _name;
      bool				        _formSigned;
      const int			      _gradeToSign;
      const int			      _gradeToExe;
      virtual void	      exeForm(void) const = 0;

};

std::ostream&	operator<<( std::ostream& out, const AForm& aform );

#endif
// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bureaucrat.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/29 17:28:02 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/29 18:48:33 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef  BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# define GRADE_MIN 150
# define GRADE_MAX 1
# define GRADE_AVG ((GRADE_MAX - GRADE_MIN) / 2 + GRADE_MIN)
# define EXC_GTL "Exception. Grade Too LOW "
# define EXC_GTH "Exception. Grade Too HIGH "

class Bureaucrat
{

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &inst);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &inst);
	void                upGrade();
	void                upGrade(int grade);
	void                downGrade();
	void                downGrade(int grade);

	const std::string   getName() const;
	int                 getGrade() const;

	//classes

	class GradeTooHighException: public std::out_of_range
	{
	public:
		GradeTooHighException(std::string err_msg);
	};

	class GradeTooLowException: public std::out_of_range
	{
	public:
		GradeTooLowException(std::string err_msg);
	};

private:

	const std::string    _name;
	int                  _grade;
	void                 check_grade_exceptions();

	
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &inst);

#endif

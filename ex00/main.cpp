/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:39:50 by rabril-h          #+#    #+#             */
/*   Updated: 2023/10/31 16:39:51 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>
#include "./classes/Bureaucrat.hpp"

#define INCREMENT 0
#define DECREMENT 1

Bureaucrat	testConstructorGrade( unsigned int grade, int& catched )
{
	Bureaucrat	Joan( "Juan", GRADE_MIN );

	catched = 0;
	try
	{
		Bureaucrat	Juan( "Juan", grade );
		return ( Juan );
	}
	catch ( std::out_of_range& e )
	{
		std::cout << "\tcatch: " << e.what() << std::endl;
		catched = 1;
	}
	return ( Joan );
}

void	iterGrade( Bureaucrat& Juan, unsigned int n, unsigned int mode )
{
	for ( unsigned int i = 0; i < n; i++ )
	{
		if ( mode == DECREMENT )
		{
			std::cout << "\tDecrement grade by 1" << std::endl;
			Juan.downGrade();
		}
		else
		{
			std::cout << "\tIncrement grade by 1" << std::endl;
			Juan.upGrade();
		}
	}
}

void	testModifyGrade( unsigned int mode, unsigned int grade, unsigned int n )
{
	int			catched;
	Bureaucrat	Juan;

	catched = 0;
	Juan = testConstructorGrade( grade, catched );
	if ( catched == 1 )
		return ;
	std::cout << "\t[ START ]: Juan stats -> " << Juan << std::endl;
	try
	{
		iterGrade( Juan, n, mode );
	}
	catch ( std::out_of_range& e )
	{
		std::cout << "\tcatch: " << e.what() << std::endl;
	}
	std::cout << "\t[ END ]: Juan stats -> " << Juan << std::endl;
}

int	main( void )
{
	int	catched;

	//Constructor Tests
	
	//	Out of range Grades
	std::cout << "Test too low grade in constructor: Bureaucrat\tJuan( \"Juan\", 151 )"  << std::endl;
	testConstructorGrade( 151, catched );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test too high grade in constructor: Bureaucrat\tJuan( \"Juan\", 0 )"  << std::endl;
	testConstructorGrade( 0, catched );
	std::cout << "End of test\n"  << std::endl;
	
	//	Valid Grades
	std::cout << "Test GRADE_MAX (" << GRADE_MAX << ") constructor: Bureaucrat\tJuan( \"Juan\", " << GRADE_MAX << " )"  << std::endl;
	testConstructorGrade( GRADE_MAX, catched );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test GRADE_MIN (" << GRADE_MIN << ") constructor: Bureaucrat\tJuan( \"Juan\", " << GRADE_MIN << " )"  << std::endl;
	testConstructorGrade( GRADE_MIN, catched );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test GRADE_AVG " << GRADE_AVG << " constructor: Bureaucrat\tJuan( \"Juan\", " << GRADE_AVG << " )"  << std::endl;
	testConstructorGrade( GRADE_AVG, catched );
	std::cout << "End of test\n"  << std::endl;

	//Increment/Decrement Methods Tests
	
	//	Out of range Grades Iterations
	std::cout << "Test too low grade with decrement method: Bureaucrat\tJuan( \"Juan\", 150 )"  << std::endl;
	testModifyGrade( DECREMENT, 150, 1 );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test too high grade with increment method: Bureaucrat\tJuan( \"Juan\", 1 )"  << std::endl;
	testModifyGrade( INCREMENT, 1, 1 );
	std::cout << "End of test\n"  << std::endl;

	//	Valid Grades Iterations
	std::cout << "Test decrement method: Bureaucrat\tJuan( \"Juan\", " << GRADE_AVG << " )"  << std::endl;
	testModifyGrade( DECREMENT, GRADE_AVG, 1 );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test increment method: Bureaucrat\tJuan( \"Juan\", " << GRADE_AVG << " )"  << std::endl;
	testModifyGrade( INCREMENT, GRADE_AVG, 1 );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test decrement method, multiple iterations (10): Bureaucrat\tJuan( \"Juan\", " << GRADE_AVG << " )"  << std::endl;
	testModifyGrade( DECREMENT, GRADE_AVG, 10 );
	std::cout << "End of test\n"  << std::endl;

	std::cout << "Test increment method, multiple iterations (10): Bureaucrat\tJuan( \"Juan\", " << GRADE_AVG << " )"  << std::endl;
	testModifyGrade( INCREMENT, GRADE_AVG, 10 );
	std::cout << "End of test\n"  << std::endl;

	//Getter Methods Tests

	//	getName()
	Bureaucrat	Juan = testConstructorGrade( GRADE_AVG, catched );
	std::cout << "Test getName method: Bureaucrat\tJuan( \"Juan\", " << GRADE_AVG << " )"  << std::endl;
	std::cout << "Name: " << Juan.getName() << std::endl;
	std::cout << "End of test\n"  << std::endl;

	//	getGrade()
	std::cout << "Test getGrade method: Bureaucrat\tJuan( \"Juan\", " << GRADE_AVG << " )"  << std::endl;
	std::cout << "Grade: " << Juan.getGrade() << std::endl;
	std::cout << "End of test\n"  << std::endl;

	return ( 0 );
}

// MAIN FROM ERALONSO
// https://github.com/eralonso

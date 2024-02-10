/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:02:34 by rastie            #+#    #+#             */
/*   Updated: 2024/02/10 02:11:39 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
int main( void )
{


    try {
        Intern  someRandomIntern;
        Bureaucrat bureaucrat("ash", 2); // error with 200
        AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "home");;
        AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Bender");

        std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
        bureaucrat.signForm(*form1);
        bureaucrat.executeForm(*form1);
        std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
        bureaucrat.signForm(*form2);
        bureaucrat.executeForm(*form2);
        bureaucrat.executeForm(*form2);
        bureaucrat.executeForm(*form2);
        bureaucrat.executeForm(*form2);
        std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
        bureaucrat.signForm(*form3);
        bureaucrat.executeForm(*form3);
        delete form1;
        delete form2;
        delete form3;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
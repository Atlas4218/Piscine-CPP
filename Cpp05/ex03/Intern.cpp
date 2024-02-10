/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:59:16 by rastie            #+#    #+#             */
/*   Updated: 2024/02/10 02:12:16 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{

}

Intern::Intern(Intern &intern)
{
    *this = intern;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern &rhs)
{
    (void) rhs;
    return *this;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    AForm *form[] = {new PresidentialPardonForm(target), 
                    new RobotomyRequestForm(target),
                    new ShrubberyCreationForm(target)};
    std::string forms[] = {"presidential pardon",
                            "robotomy request",
                            "shrubbery creation"};
    AForm *result = NULL;
    for (int i = 0; i < 3; i++)
    {
        if (name == forms[i])
            result = form[i];
        else
            delete(form[i]);
    }
    if (!result)
        std::cout << "Unknown form type "  << name << std::endl;
    else
        std::cout << "Intern creates " << name << std::endl;
    return result;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:41:47 by rastie            #+#    #+#             */
/*   Updated: 2024/02/09 20:14:45 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &form): AForm("Robotomy request form", 72, 45), _target(form.getTarget())
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy request form", 72, 45), _target(target)
{
}

std::string RobotomyRequestForm::getTarget(void)
{
    return _target;
}

void RobotomyRequestForm::excecute(const Bureaucrat &executor) const
{
    if (!this->isSigned())
    {
        throw FormNonSigned();
        return ;
    }
    if (executor.getGrade() > this->getExecGrade())
    {
        throw GradeTooLowException();
        return ;
    }
    std::cout << "Robotomisation occuring" << std::endl;
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "The robotomy of " << _target << " failed." << std::endl;

}

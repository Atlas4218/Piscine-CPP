/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:41:47 by rastie            #+#    #+#             */
/*   Updated: 2024/02/09 20:08:31 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &form): AForm("Presidential pardon form", 25, 5), _target(form.getTarget())
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential pardon form", 25, 5), _target(target)
{
}

std::string PresidentialPardonForm::getTarget(void)
{
    return _target;
}

void PresidentialPardonForm::excecute(const Bureaucrat &executor) const
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
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

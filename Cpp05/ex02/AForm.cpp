/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:56:36 by rastie            #+#    #+#             */
/*   Updated: 2024/02/09 18:25:37 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): _signGrade(150), _execGrade(150)
{
}

AForm::AForm(const AForm &src) : _name(src.getName()), _signed(src.isSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &rhs)
{
    if (this != &rhs)
        _signed = rhs.isSigned();    
    return (*this); 
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

std::string AForm::getName(void) const
{
    return _name;
}

bool AForm::isSigned(void) const //=getSigned()
{
    return _signed;
}

int AForm::getSignGrade(void) const
{
    return _signGrade;
}

int AForm::getExecGrade(void) const
{
    return _execGrade;
}
void AForm::beSigned(Bureaucrat &maggot)
{
    if (maggot.getGrade() > _signGrade)
    {
        throw GradeTooLowException();
        return ;
    }
    _signed = 1;
}
std::ostream &operator<<(std::ostream &o, const AForm &i)
{
    o << "AForm " << i.getName() << ", sign grade " << i.getSignGrade() << ", exec grade " << i.getExecGrade();
    i.isSigned()? o << " is signed" : o << " is not signed";
    return (o);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:06:20 by rastie            #+#    #+#             */
/*   Updated: 2024/02/09 18:01:31 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
    *this = bureaucrat;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (this != &rhs)
        _grade = rhs.getGrade();
    return (*this);
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

std::string Bureaucrat::getName(void) const 
{
    return _name;
}

int Bureaucrat::getGrade(void) const 
{
    return _grade;
}

void Bureaucrat::setGrade(int grade)
{
    _grade = grade;
}

void Bureaucrat::promote(void)
{
  if (_grade == 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::demote(void)
{
    if (_grade == 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
    }
    catch(const AForm::GradeTooLowException &e)
    {
        std::cerr << *this << " couldn't sign " << form << " because " << e.what() << std::endl;
        return ;
    }
    std::cout << *this << " signed " << form << std::endl;
    
    
}

void Bureaucrat::executeForm(const AForm &form)
{
    try
    {
        form.excecute(*this);
    }
    catch(const std::exception &e)
    {
        std::cerr << *this << " couldn't excecute " << form << " because " << e.what() << std::endl;
        return ;
    }
    std::cout << *this << " excecuted " << form << std::endl;

}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
    o << i.getName() << ", bureaucrat grade " << i.getGrade();
    return o;
}

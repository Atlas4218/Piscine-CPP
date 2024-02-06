/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:06:20 by rastie            #+#    #+#             */
/*   Updated: 2024/02/02 10:59:03 by rastie           ###   ########.fr       */
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

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
    o << i.getName() << ", bureaucrat grade " << i.getGrade();
    return o;
}


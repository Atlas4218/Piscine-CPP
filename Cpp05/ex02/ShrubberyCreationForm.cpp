/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:41:47 by rastie            #+#    #+#             */
/*   Updated: 2024/02/20 18:31:31 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &form): AForm("Shrubbery creation form", 145, 137), _target(form.getTarget())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("Shrubbery creation form", 145, 137), _target(target)
{
}

std::string ShrubberyCreationForm::getTarget(void)
{
    return _target;
}

void ShrubberyCreationForm::excecute(const Bureaucrat &executor) const
{
    std::fstream file;
    std::string filename;

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
    filename = _target;
    filename.append("_shrubbery");
    file.open(filename.c_str(),  std::fstream::out);
    if (!file.is_open())
        throw std::exception();
    
    file << "       _-_" << std::endl;
    file << "    /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "   ~  \\\\ //  ~" << std::endl;
    file << "_- -   | | _- _" << std::endl;
    file << "  _ -  | |   -_" << std::endl;
    file << "      // \\\\" << std::endl;
    
    file.close();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:29:30 by rastie            #+#    #+#             */
/*   Updated: 2024/02/02 11:47:29 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
private:
    const std::string _name;
    bool _signed;
    const int _signGrade;
    const int _execGrade;
    Form(void);
public:
    Form(const Form &src);
    ~Form();
    Form &operator=(const Form &rhs);

    Form(const std::string name, const int signGrade, const int execGrade);

    std::string getName(void) const;
    bool isSigned(void) const; //getSigned()
    int getSignGrade(void) const;
    int getExecGrade(void) const;

    void beSigned(Bureaucrat &maggot);
    class GradeTooHighException : public std::exception
    {
   
    public:
        virtual const char* what() const throw() {return "Grade too high";}
    };
    class GradeTooLowException : public std::exception
    {
   
    public:
        virtual const char* what() const throw() {return "Grade too low";}
    };
};
std::ostream &operator<<(std::ostream &o, Form &i);



#endif
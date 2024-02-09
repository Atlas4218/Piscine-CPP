/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:29:30 by rastie            #+#    #+#             */
/*   Updated: 2024/02/09 18:13:23 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
private:
    const std::string _name;
    bool _signed;
    const int _signGrade;
    const int _execGrade;
public:
    AForm(void);
    AForm(const AForm &src);
    ~AForm();
    AForm &operator=(const AForm &rhs);

    AForm(const std::string name, const int signGrade, const int execGrade);

    std::string getName(void) const;
    bool isSigned(void) const; //getSigned()
    int getSignGrade(void) const;
    int getExecGrade(void) const;

    void beSigned(Bureaucrat &maggot);
    virtual void excecute(const Bureaucrat &excecutor) const = 0;
    
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
    class FormNonSigned : public std::exception
    {
        public:
            virtual const char* what() const throw() {return "Form isn't signed";}
    };
};
std::ostream &operator<<(std::ostream &o, const AForm &i);



#endif

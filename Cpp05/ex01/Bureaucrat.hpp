/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:17:53 by rastie            #+#    #+#             */
/*   Updated: 2024/02/02 11:47:27 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include "Form.hpp"

class Form;
class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
    Bureaucrat(void);
public:
    Bureaucrat(const Bureaucrat & bureaucrat);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat & rhs);

    Bureaucrat(const std::string name, int grade);
    
    std::string getName(void) const ;
    int getGrade(void) const ;

    void setGrade(int grade);

    void promote(void);
    void demote(void);

    void signForm(Form &form);

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

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i);
#endif
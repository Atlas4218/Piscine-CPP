/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:06:14 by rastie            #+#    #+#             */
/*   Updated: 2024/02/02 18:06:54 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
    const std::string _target;
    bool _signed;
    const int _signGrade;
    const int _execGrade;
    PresidentialPardonForm (void);
public:
    PresidentialPardonForm(PresidentialPardonForm &form);
    ~PresidentialPardonForm ();
    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
    
    PresidentialPardonForm(std::string target);

    std::string getTarget(void);

    virtual void excecute(const Bureaucrat &executor) const;


};


#endif
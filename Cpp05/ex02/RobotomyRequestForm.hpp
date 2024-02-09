/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:06:14 by rastie            #+#    #+#             */
/*   Updated: 2024/02/09 15:43:15 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
    const std::string _target;
    RobotomyRequestForm (void);
public:
    RobotomyRequestForm(RobotomyRequestForm &form);
    ~RobotomyRequestForm ();
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
    
    RobotomyRequestForm(std::string target);

    std::string getTarget(void);

    virtual void excecute(const Bureaucrat &executor) const;


};


#endif
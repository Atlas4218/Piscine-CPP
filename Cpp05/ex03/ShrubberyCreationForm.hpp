/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:06:14 by rastie            #+#    #+#             */
/*   Updated: 2024/02/09 15:43:15 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERYCREATIONFORM_HPP
# define SHRUBERYCREATIONFORM_HPP
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
private:
    const std::string _target;
    ShrubberyCreationForm (void);
public:
    ShrubberyCreationForm(ShrubberyCreationForm &form);
    virtual ~ShrubberyCreationForm();
    
    ShrubberyCreationForm(std::string target);

    std::string getTarget(void);

    virtual void excecute(const Bureaucrat &executor) const;


};


#endif
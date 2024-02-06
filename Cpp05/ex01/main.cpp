/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:02:34 by rastie            #+#    #+#             */
/*   Updated: 2024/02/02 11:41:46 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


int main( void )
{
    try {
        Bureaucrat bureaucrat("ash",11);
        Form form("formName", 12, 1);

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    } catch (std::exception &e) { // catch error on form or bureaucrat initiallisation
        std::cout << e.what() << std::endl;
    }
    return 0;
}
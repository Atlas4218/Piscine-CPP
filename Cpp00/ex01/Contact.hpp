/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:09:14 by rastie            #+#    #+#             */
/*   Updated: 2024/01/05 15:57:13 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>
class	Contact
{
	private :
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string secret;
	public :
		//constructeur/destructeur
		Contact();
		~Contact();
		//getters
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhoneNumber();
		std::string getSecret();
		//setters
		void setFirstName(std::string first_name);
		void setLastName(std::string last_name);
		void setNickname(std::string last_name);
		void setPhoneNumber(std::string phone_number);
		void setSecret(std::string secret);
};

#endif

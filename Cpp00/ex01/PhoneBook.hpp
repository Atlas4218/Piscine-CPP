/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:07:29 by rastie            #+#    #+#             */
/*   Updated: 2023/10/19 15:19:29 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
	private :
		Contact list[8];
		static int index_older;
	public :
		PhoneBook();
		~PhoneBook();
		void	add_contact(std::string fname, std::string lname,
				std::string nname, std::string num, std::string secret);
		void	print_content();
		void	print_contact(int index);
		void	print_contact_full(int index);
};

#endif

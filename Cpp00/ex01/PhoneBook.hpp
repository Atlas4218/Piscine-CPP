/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:07:29 by rastie            #+#    #+#             */
/*   Updated: 2023/10/26 00:53:30 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
	private :
		Contact list[8];
		int index_older;
	public :
		PhoneBook();
		~PhoneBook();
		void	add_contact(void);
		void	print_content(void);
		void	print_contact(int index);
		void	print_contact_full(int index);
		void	search(void);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:45:57 by ssoumill          #+#    #+#             */
/*   Updated: 2025/07/10 18:49:01 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

class PhoneBook
{
    private:
        Contact registry[8];
        int index;

    public:
        PhoneBook();
        ~PhoneBook();
        void add_contact();
        int get_index();
        void search_contacts(); 
        std::string resize_string(const std::string str);
};

#endif


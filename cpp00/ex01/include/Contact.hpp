/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:46:04 by ssoumill          #+#    #+#             */
/*   Updated: 2025/07/10 20:51:18 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string PhoneNumber;
        std::string DarkestSecret;
        
    public:
        Contact();
        ~Contact();
       void create_contact();
       const std::string &get_firstname() const;
       const std::string &get_lastname() const;
       const std::string &get_nickname() const;
       const std::string &get_phone_number() const;
       const std::string &get_darkest_secret() const;
};

#endif
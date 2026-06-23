/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:45:53 by ssoumill          #+#    #+#             */
/*   Updated: 2025/07/10 20:52:57 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"

Contact::Contact()
{
    // std::cout << "constru appele" << std::endl;
};

Contact::~Contact()
{
    //  std::cout << "destru appele" << std::endl;
};

void Contact::create_contact()
{
    while (this->firstname.empty())
    {
        std::cout << "Enter first name: ";
        std::getline(std::cin, this->firstname);
        if (std::cin.fail())
	    {
		    std::cin.clear();
		    std::cin.ignore();
		    std::cerr << "Exit failure : cin error" << std::endl;
		    exit (1);
	    }
    }
    while (this->lastname.empty())
    {
        std::cout << "Enter last name: ";
        std::getline(std::cin, this->lastname);
        if (std::cin.fail())
	    {
		    std::cin.clear();
		    std::cin.ignore();
		    std::cerr << "Exit failure : cin error" << std::endl;
		    exit (1);
	    }
    }
    while (this->nickname.empty())
    {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, this->nickname);
        if (std::cin.fail())
	    {
		    std::cin.clear();
		    std::cin.ignore();
		    std::cerr << "Exit failure : cin error" << std::endl;
		    exit (1);
	    }
    }
    while (this->PhoneNumber.empty())
    {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, this->PhoneNumber);
        if (std::cin.fail())
	    {
		    std::cin.clear();
		    std::cin.ignore();
		    std::cerr << "Exit failure : cin error" << std::endl;
		    exit (1);
	    }
    }
    while (this->DarkestSecret.empty())
    {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, this->DarkestSecret);
        if (std::cin.fail())
	    {
		    std::cin.clear();
		    std::cin.ignore();
		    std::cerr << "Exit failure : cin error" << std::endl;
		    exit (1);
	    }
    }
};

const std::string &Contact::get_firstname() const
{
    return this->firstname;
}

const std::string &Contact::get_lastname() const
{
    return this->lastname;
}

const std::string &Contact::get_nickname() const
{
    return this->nickname;
}

const std::string &Contact::get_phone_number() const
{
    return this->PhoneNumber;
}

const std::string& Contact::get_darkest_secret() const
{
    return this->DarkestSecret;
}

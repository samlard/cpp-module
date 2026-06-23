/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:45:46 by ssoumill          #+#    #+#             */
/*   Updated: 2025/07/10 20:52:37 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0)
{
    // std::cout << "PhoneBook has been created with a capacity for 8 contacts." << std::endl;
};

PhoneBook::~PhoneBook()
{
    // std::cout << "phonebook destructor called" << std::endl;
};


void PhoneBook::add_contact()
{
    int current_index = this->get_index();
    std::cout << "Adding a new contact..." << std::endl;
    Contact new_contact;
    
    new_contact.create_contact();
    this->registry[current_index] = new_contact;
    this->index++;
    std::cout << "Contact added successfully." << std::endl;
};

int PhoneBook::get_index()
{
    return this->index % 8;
}

void  PhoneBook::search_contacts()
{
    if (this->index == 0)
    {
        std::cout << "No contacts available. Please add a contact first." << std::endl;
        return;
    }
    std::string only_string = "012345678";
    std::string input;
    int contact_index;
    std::cout << "Searching for contacts..." << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "|INDEX     |FIRST NAME|LAST NAME |NICKNAME  |" << std::endl;
    for (int i = 0; i < this->index && i < 8; i++)
    {
        std::cout << "|         " << i << "|" 
                  << this->resize_string(this->registry[i].get_firstname()) << "|"
                  << this->resize_string(this->registry[i].get_lastname()) << "|"
                  << this->resize_string(this->registry[i].get_nickname()) << "|" << std::endl;
    }
    std::cout << "============================================" << std::endl;
    std::cout << "Enter the index of the contact you want to view:" << std::endl;
    while (1)
    {
        std::getline(std::cin, input);
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cerr << "Exit failure : cin error" << std::endl;
            exit (1);
        }
        if (input.empty())
            std::cout << "No input provided." << std::endl;
        else if (input.find_first_not_of(only_string) != std::string::npos)
        {
            std::cout << "Invalid input. Please enter a number." << std::endl;
        }
        else
        {
            contact_index = atoi(input.c_str());
            if (contact_index < 0 || contact_index >= this->index || contact_index >= 8)
                std::cout << "Invalid index. To big or to small." << std::endl;
            else
                break;
        }
    }
    std::cout << "Contact details:" << std::endl;
    std::cout << "First Name: " << this->registry[contact_index].get_firstname() << std::endl;
    std::cout << "Last Name: " << this->registry[contact_index].get_lastname() << std::endl;
    std::cout << "Nickname: " << this->registry[contact_index].get_nickname() << std::endl;
    std::cout << "Phone Number: " << this->registry[contact_index].get_phone_number() << std::endl;
    std::cout << "Darkest Secret: " << this->registry[contact_index].get_darkest_secret() << std::endl;
}

std::string PhoneBook::resize_string(std::string str)
{
    int length = str.length();
    std::string new_str;

    if (length > 10)
        return (str.substr(0, 9) + ".");
    else if (length < 10)
    {
        new_str = std ::string(10 - length, ' ');
        return (new_str + str);
    }
    else 
        return str; 
}


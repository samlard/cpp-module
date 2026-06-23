/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:53:10 by ssoumill          #+#    #+#             */
/*   Updated: 2025/07/10 20:54:21 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"

int main(void)
{
    PhoneBook phonebook;
    std::string input;

    while (1)
    {
        std::cout << "Enter a command (ADD, EXIT, SEARCH):" << std::endl;
        getline(std::cin, input) && input != "EXIT";
        if (std::cin.fail())
	    {
		    std::cin.clear();
		    std::cin.ignore();
		    std::cerr << std::endl <<"Exit failure : cin error" << std::endl;
		    exit (1);
	    }
        if (std::string(input) == "EXIT")
            break;
        else if (std::string(input) == "ADD")
            phonebook.add_contact();
        else if (std::string(input) == "SEARCH")
            phonebook.search_contacts();
        else
            std::cout << "Unknown command: " << input << std::endl;
    }
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:20:19 by ssoumill          #+#    #+#             */
/*   Updated: 2025/07/19 17:21:06 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"


Zombie::Zombie(std::string str) : _name(str)
{
    std::cout << "zombie crearted: " << std::endl;
    this->_name = str;
}

Zombie::~Zombie()
{
    std::cout << "zombie destroyed: " << this->_name << std::endl;
}

void Zombie::announce()
{
    std::cout << get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

const std::string &Zombie::get_name() const
{
    return this->_name;
}
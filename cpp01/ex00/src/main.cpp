/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:20:19 by ssoumill          #+#    #+#             */
/*   Updated: 2025/07/19 17:22:32 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main()
{
    Zombie zombie1("john");
    Zombie *zombie2 = newZombie("bob");
    
    zombie1.announce();
    zombie2->announce();
    randomChump("alice");
    delete(zombie2);
    return (0);
}

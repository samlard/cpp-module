/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:20:19 by ssoumill          #+#    #+#             */
/*   Updated: 2025/07/19 17:17:50 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie();
        Zombie(std::string str);
        ~Zombie();
        void announce();
        void set_name(std::string str);
        const std::string &get_name() const;
    };
    Zombie* zombieHorde( int N, std::string name );

#endif

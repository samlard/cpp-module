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
        Zombie(std::string str);
        ~Zombie();
        void announce();
        const std::string &get_name() const;
    };
    
    Zombie* newZombie(std::string name);
    void randomChump(std::string name);

#endif

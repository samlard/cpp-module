#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

    private :
        Brain *_brain;

    public :

        Dog();
        ~Dog();
        Dog(const std::string type);
        Dog(const Dog& copy);
        Dog& operator=(const Dog&other);
        void makeSound() const;
        Brain* getBrain() const;
};

#endif
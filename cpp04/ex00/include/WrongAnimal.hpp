#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

#include <iostream>

class WrongAnimal {

    protected :
        std::string _type;

    public :
        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal(const std::string type);
        WrongAnimal(const WrongAnimal& copy);
        WrongAnimal& operator=(const WrongAnimal& other);
        void makeSound() const;
        const std::string &getType() const;
};


#endif
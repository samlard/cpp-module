#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <iostream>

class Brain {

    private :
        std::string _ideas[100];

    public :

    Brain();
    ~Brain();
    Brain(const std::string ideas);
    Brain(const Brain& copy);
    Brain& operator=(const Brain&other);
    std::string getIdeas(int index) const;
    void setIdeas(int index, const std::string& ideas);
};


#endif
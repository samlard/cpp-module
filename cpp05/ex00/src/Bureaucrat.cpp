#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default name"), _grade(150) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &src) {
    if (this != &src)
        this->_grade = src._grade;
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    return *this;
}

const std::string &Bureaucrat::getName() const {
    return this->_name;
}

const int &Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade(){
    if (_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

std::ostream & operator<<(std::ostream &e, const Bureaucrat &src) {
    e << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
    return e;
}
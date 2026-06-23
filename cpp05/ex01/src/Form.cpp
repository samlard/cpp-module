#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeTosign(150), _gradeToexecute(150) {}
Form::~Form() {}
Form::Form(const std::string name, int gradeTosign, int gradeToexecute)
    : _name(name), _isSigned(false), _gradeTosign(gradeTosign), _gradeToexecute(gradeToexecute) {
    if (gradeTosign < 1 || gradeToexecute < 1)
        throw GradeTooHighException();
    if (gradeTosign > 150 || gradeToexecute > 150)
        throw GradeTooLowException();
}
Form::Form(const Form &src)
    : _name(src._name), _isSigned(src._isSigned), _gradeTosign(src._gradeTosign), _gradeToexecute(src._gradeToexecute) {
    }

Form & Form::operator=(const Form &src) {
    if (this != &src) {
        this->_isSigned = src._isSigned;
    }
    return *this;
}
const std::string &Form::getName() const {
    return _name;
}
bool Form::getIsSigned() const {
    return _isSigned;
}
const int &Form::getGradeTosign() const {
    return _gradeTosign;
}
const int &Form::getGradeToexecute() const {
    return _gradeToexecute;
}
void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeTosign)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream & operator<<(std::ostream &e, const Form &src) {
    if (src.getIsSigned())
    {
        e << "Form named: " << src.getName() << " is signed "
        << ", grade to be signed: " << src.getGradeTosign()
        << ", grade to execute: " << src.getGradeToexecute();
        return e;
    }
    else
    {
        e << "Form named: " << src.getName() << " is not signed : "
        << ", grade to be signed: " << src.getGradeTosign()
        << ", grade to execute: " << src.getGradeToexecute();
        return e;
    }
}

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeTosign(150), _gradeToexecute(150) {}
AForm::~AForm() {}
AForm::AForm(const std::string name, int gradeTosign, int gradeToexecute)
    : _name(name), _isSigned(false), _gradeTosign(gradeTosign), _gradeToexecute(gradeToexecute) {
    if (gradeTosign < 1 || gradeToexecute < 1)
        throw GradeTooHighException();
    if (gradeTosign > 150 || gradeToexecute > 150)
        throw GradeTooLowException();
}
AForm::AForm(const AForm &src)
    : _name(src._name), _isSigned(src._isSigned), _gradeTosign(src._gradeTosign), _gradeToexecute(src._gradeToexecute) {
    }

AForm & AForm::operator=(const AForm &src) {
    if (this != &src) {
        this->_isSigned = src._isSigned;
    }
    return *this;
}

const std::string &AForm::getName() const {
    return _name;
}
bool AForm::getIsSigned() const {
    return _isSigned;
}
const int &AForm::getGradeTosign() const {
    return _gradeTosign;
}
const int &AForm::getGradeToexecute() const {
    return _gradeToexecute;
}
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeTosign)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream & operator<<(std::ostream &e, const AForm &src) {
    if (src.getIsSigned())
    {
        e << "AForm named: " << src.getName() << " is signed "
        << ", grade to be signed: " << src.getGradeTosign()
        << ", grade to execute: " << src.getGradeToexecute();
        return e;
    }
    else
    {
        e << "AForm named: " << src.getName() << " is not signed : "
        << ", grade to be signed: " << src.getGradeTosign()
        << ", grade to execute: " << src.getGradeToexecute();
        return e;
    }
}

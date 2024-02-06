#include "Form.hpp"

Form::Form(const Form &src): _name(src.getName()), _signed(src.isSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
}

Form::~Form()
{
}

Form &Form::operator=(const Form &rhs)
{
    if (this != &rhs)
        _signed = rhs.isSigned();    
    return (*this); 
}

Form::Form(const std::string name, const int signGrade, const int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

std::string Form::getName(void) const
{
    return _name;
}

bool Form::isSigned(void) const //=getSigned()
{
    return _signed;
}

int Form::getSignGrade(void) const
{
    return _signGrade;
}

int Form::getExecGrade(void) const
{
    return _execGrade;
}
void Form::beSigned(Bureaucrat &maggot)
{
    if (maggot.getGrade() > _signGrade)
    {
        throw GradeTooLowException();
        return ;
    }
    this->_signed = 1;
}
std::ostream &operator<<(std::ostream &o, Form &i)
{
    o << "Form " << i.getName() << ", sign grade " << i.getSignGrade() << ", exec grade" << i.getExecGrade();
    i.isSigned()? o << " is signed" : o << " is not signed";
    return (o);
}
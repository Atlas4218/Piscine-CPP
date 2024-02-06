#include "AForm.hpp"

AForm::AForm(const AForm &src): _name(src.getName()), _signed(src.isSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &rhs)
{
    if (this != &rhs)
        _signed = rhs.isSigned();    
    return (*this); 
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

std::string AForm::getName(void) const
{
    return _name;
}

bool AForm::isSigned(void) const //=getSigned()
{
    return _signed;
}

int AForm::getSignGrade(void) const
{
    return _signGrade;
}

int AForm::getExecGrade(void) const
{
    return _execGrade;
}
void AForm::beSigned(Bureaucrat &maggot)
{
    if (maggot.getGrade() > _signGrade)
    {
        throw GradeTooLowException();
        return ;
    }
    _signed = 1;
}
void AForm::excecute(const Bureaucrat &excecutor) const
{
    if (excecutor.getGrade() > _execGrade)
        throw GradeTooLowException();
    else if (!_signed)
        throw  FormNonSigned();
    else
        std::cout << "Form " << _name << " executed" << std::endl;    
}
std::ostream &operator<<(std::ostream &o, AForm &i)
{
    o << "AForm " << i.getName() << ", sign grade " << i.getSignGrade() << ", exec grade" << i.getExecGrade();
    i.isSigned()? o << " is signed" : o << " is not signed";
    return (o);
}
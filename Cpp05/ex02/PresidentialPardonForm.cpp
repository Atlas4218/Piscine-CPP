#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &form): _target(form.getTarget()), _signed(false), _signGrade(25), _execGrade(5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    // TODO: insert return statement here
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
{
}

std::string PresidentialPardonForm::getTarget(void)
{
    return std::string();
}

void PresidentialPardonForm::excecute(const Bureaucrat &executor) const
{
}

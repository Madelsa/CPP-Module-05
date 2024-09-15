/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:32:58 by mahmoud           #+#    #+#             */
/*   Updated: 2024/09/13 17:20:25 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), isSigned(false), signGrade(150), execGrade(150) {}

AForm::AForm(const std::string &name, int signGrade, int execGrade)
    : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &copyTemplate)
    : name(copyTemplate.name), isSigned(copyTemplate.isSigned),
      signGrade(copyTemplate.signGrade), execGrade(copyTemplate.execGrade) {}

AForm &AForm::operator=(const AForm &initTemplate)
{
    if (this != &initTemplate)
    {
        this->isSigned = initTemplate.isSigned;
    }
    return *this;
}

const std::string &AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->isSigned;
}

int AForm::getSignGrade() const
{
    return this->signGrade;
}

int AForm::getExecGrade() const
{
    return this->execGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->signGrade)
        throw GradeTooLowException();
    this->isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

const char* AForm::ExecuteGradeTooLowException::what() const throw()
{
    return "Executor's grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << form.getName() << ": Sign grade " << form.getSignGrade()
        << ", Exec grade " << form.getExecGrade()
        << ", Is signed: " << (form.getIsSigned() ? "Yes" : "No");
    return out;
}

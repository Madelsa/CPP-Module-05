/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:52:11 by mabdelsa          #+#    #+#             */
/*   Updated: 2024/09/05 13:38:55 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): signGrade(150), execGrade(150){}

Form::~Form(){}

Form::Form(const std::string name, int signGrade, int execGrade) :
    name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &copyTemplate) :
    name(copyTemplate.name), isSigned(copyTemplate.isSigned),
    signGrade(copyTemplate.signGrade), execGrade(copyTemplate.execGrade)
{}

Form &Form::operator=(const Form &initTemplate)
{
    if (this != &initTemplate)
        this->isSigned = initTemplate.isSigned;
    return (*this);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->signGrade)
        throw GradeTooLowException();
    this->isSigned = true;
}

std::string Form::getName() const 
{ 
    return (name); 
}

bool Form::getIsSigned() const 
{
    return (isSigned); 
}

int Form::getSignGrade() const 
{
    return (signGrade); 
}

int Form::getExecGrade() const 
{
    return (execGrade); 
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form " << form.getName() << std::endl
        << "Sign grade: " << form.getSignGrade() << std::endl
        << "Exec grade: " << form.getExecGrade() << std::endl
        << "Is signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
    return (out);
}
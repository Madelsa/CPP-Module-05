/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:47:37 by mabdelsa          #+#    #+#             */
/*   Updated: 2024/09/15 19:52:25 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"


Bureaucrat::Bureaucrat(){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copyTemplate)
{
    *this = copyTemplate;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &initTemplate)
{
    if (this != &initTemplate)
        this->grade = initTemplate.grade;
    return (*this);
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::incGrade()
{
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decGrade()
{
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

const char* GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char* GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

void Bureaucrat::signForm(AForm &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &Aform) const
{
    try
    {
        Aform.execute(*this);
        std::cout << this->name << " executed " << Aform.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << this->name << " couldn't execute " << Aform.getName() << " because " << e.what() << std::endl;
    }
}


std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (out);
}

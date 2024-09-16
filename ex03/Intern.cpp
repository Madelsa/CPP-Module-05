/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:02:28 by mahmoud           #+#    #+#             */
/*   Updated: 2024/09/16 10:23:26 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &copyTemplate) 
{
    *this = copyTemplate;
}

Intern &Intern::operator=(const Intern &) 
{ 
    return *this; 
}

AForm *makeShrubberyForm(std::string target) 
{
    return new ShrubberyCreationForm(target);
}

AForm *makeRobotomyForm(std::string target) 
{
    return new RobotomyRequestForm(target);
}

AForm *makePresidentialPardonForm(std::string target) 
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target) const
{
    std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(*createForm[3])(std::string) = {makeShrubberyForm, makeRobotomyForm, makePresidentialPardonForm};

    for (int i = 0; i < 3; i++) {
        if (formTypes[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return createForm[i](target);
        }
    }
    std::cout << "Error: Form type " << formName << " does not exist." << std::endl;
    return NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:32:40 by mahmoud           #+#    #+#             */
/*   Updated: 2024/09/13 17:29:30 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copyTemplate)
    : AForm(copyTemplate), target(copyTemplate.target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &initTemplate)
{
    if (this != &initTemplate)
    {
        AForm::operator=(initTemplate);
        this->target = initTemplate.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw ExecuteGradeTooLowException();

    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:32:45 by mahmoud           #+#    #+#             */
/*   Updated: 2024/09/15 19:49:02 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copyTemplate)
    : AForm(copyTemplate), target(copyTemplate.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &initTemplate)
{
    if (this != &initTemplate)
    {
        AForm::operator=(initTemplate);
        this->target = initTemplate.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    srand(time(0));
    if (!this->getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw ExecuteGradeTooLowException();

    std::cout << "Drilling noises..." << std::endl;
    if (rand() % 2 == 0)
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed for " << this->target << "!" << std::endl;
}

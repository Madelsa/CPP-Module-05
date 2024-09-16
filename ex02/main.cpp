/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:47:39 by mabdelsa          #+#    #+#             */
/*   Updated: 2024/09/16 10:17:11 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
        Bureaucrat b1("A", 1);

        ShrubberyCreationForm sForm("Shrub");
        RobotomyRequestForm rForm("Robot");
        PresidentialPardonForm pForm("Adam");

        b1.signForm(sForm);
        b1.signForm(rForm);
        b1.signForm(pForm);

        b1.executeForm(sForm);
        b1.executeForm(rForm);
        b1.executeForm(pForm);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:47:39 by mabdelsa          #+#    #+#             */
/*   Updated: 2024/09/15 19:51:33 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
        Bureaucrat b1("A", 150);

        // Create forms with various targets
        ShrubberyCreationForm sForm("Shrub");
        RobotomyRequestForm rForm("Robot");
        PresidentialPardonForm pForm("Adam");

        // Attempt to sign forms with both bureaucrats
        b1.signForm(sForm);
        b1.signForm(rForm);
        b1.signForm(pForm);

       

        // Attempt to execute forms with both bureaucrats
        b1.executeForm(sForm);
        b1.executeForm(rForm);
        b1.executeForm(pForm);

     

}

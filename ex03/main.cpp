/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:47:39 by mabdelsa          #+#    #+#             */
/*   Updated: 2024/09/15 20:11:26 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() 
{
    Intern intern;
    Bureaucrat b1("John", 1);

    AForm *form = intern.makeForm("robotomy request", "Robot");
    if (form) 
    {
        b1.signForm(*form);
        b1.executeForm(*form);
        delete form;
    }

    form = intern.makeForm("shrubbery creation", "Shrub");
    if (form) 
    {
        b1.signForm(*form);
        b1.executeForm(*form);
        delete form;
    }
    
    form = intern.makeForm("presidential pardon", "Adam");
    if (form) 
    {
        b1.signForm(*form);
        b1.executeForm(*form);
        delete form;
    }

    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:47:39 by mabdelsa          #+#    #+#             */
/*   Updated: 2024/09/16 10:24:29 by mabdelsa         ###   ########.fr       */
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

    form = intern.makeForm("invalid", "none");
    if (form) 
    {
        delete form;
    }

    return 0;
}

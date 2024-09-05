/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:47:39 by mabdelsa          #+#    #+#             */
/*   Updated: 2024/09/05 14:56:27 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
        Bureaucrat b1("A", 50);

        Form f1("Form1", 51, 100);
        Form f2("Form2", 44, 50);

        b1.signForm(f1);
        b1.signForm(f2); 
}


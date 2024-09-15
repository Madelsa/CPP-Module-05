/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:47:36 by mabdelsa          #+#    #+#             */
/*   Updated: 2024/09/13 17:25:27 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &copyTemplate);
        Bureaucrat &operator=(const Bureaucrat &initTemplate);
        std::string getName() const;  
        int getGrade() const;
        void incGrade();
        void decGrade();
        void signForm(AForm &form) const;
        void executeForm(const AForm &form) const;
};

class GradeTooHighException : public std::exception
{
    public:
        const char* what() const throw();
};
class GradeTooLowException : public std::exception
{
    public:
        const char* what() const throw();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
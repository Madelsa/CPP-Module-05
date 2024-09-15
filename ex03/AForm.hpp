/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:32:59 by mahmoud           #+#    #+#             */
/*   Updated: 2024/09/15 19:54:42 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int execGrade;

public:
    AForm();
    AForm(const std::string &name, int signGrade, int execGrade);
    virtual ~AForm();
    AForm(const AForm &copyTemplate);
    AForm &operator=(const AForm &initTemplate);
    const std::string &getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;

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

    class FormNotSignedException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    class ExecuteGradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif


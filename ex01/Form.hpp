/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:52:10 by mabdelsa          #+#    #+#             */
/*   Updated: 2024/09/05 12:46:31 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP


#include "Bureaucrat.hpp"


class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    
    public:
        Form();
        ~Form();
        Form(const std::string  name, int signGrade, int execGrade);
        Form(const Form &copyTemplate);
        Form &operator=(const Form &initTemplate);
        void beSigned(const Bureaucrat &bureaucrat);
        std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;            
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
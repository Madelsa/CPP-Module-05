/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:32:49 by mahmoud           #+#    #+#             */
/*   Updated: 2024/09/16 10:16:06 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copyTemplate)
    : AForm(copyTemplate), target(copyTemplate.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &initTemplate)
{
    if (this != &initTemplate)
    {
        AForm::operator=(initTemplate);
        this->target = initTemplate.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::ExecuteGradeTooLowException();

    std::ofstream outfile((this->target + "_shrubbery").c_str());
    if (!outfile)
    {
        std::cerr << "Error: Could not open file " << this->target << "_shrubbery" << std::endl;
        return;
    }

    outfile << "      *      " << std::endl;
    outfile << "     ***     " << std::endl;
    outfile << "    *****    " << std::endl;
    outfile << "   *******   " << std::endl;
    outfile << "      |      " << std::endl;

    outfile.close();
    std::cout << "Shrubbery has been created at " << this->target << "_shrubbery" << std::endl;
}
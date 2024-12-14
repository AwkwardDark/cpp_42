#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
	private:
		static AForm*	makeShrubberyCreationForm(std::string target);
		static AForm*	makeRobotomyRequestForm(std::string target);
		static AForm*	makePresidentialPardonForm(std::string target);
	public:
		Intern(void);
		~Intern(void);
		Intern(Intern const &src);
		Intern &operator=(Intern const &src);
		AForm*	makeForm(std::string form, std::string target) const;
};

#endif

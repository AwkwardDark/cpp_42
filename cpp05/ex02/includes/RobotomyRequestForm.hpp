#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
	private:
		std::string		_target;
	
	public:
		// Canonical Orthodox Form
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &src);

		//Methods
		std::string	getTarget(void) const;
		void		execute(Bureaucrat const &executor) const;
};

#endif
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	private:
		std::string		_target;
	
	public:
		// Canonical Orthodox Form
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &src);

		//Methods
		std::string	getTarget(void) const;
		void		execute(Bureaucrat const &executor) const;
};

#endif

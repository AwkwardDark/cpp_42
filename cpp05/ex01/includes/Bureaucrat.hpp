#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class	Form;

class	Bureaucrat
{
	private:
		std::string	const	_name;
		int					_grade;

	public:
		// Canonical form
		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade);
		~Bureaucrat(void);
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat &operator=(Bureaucrat const &src);

		// Member functions
		std::string const	getName(void) const;
		int					getGrade(void) const;
		void				upGrade(void);
		void				downGrade(void);
		void				signForm(Form &form) const;

		// Exceptions
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &src);

#endif

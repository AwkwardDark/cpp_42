#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdbool.h>
# include <stdexcept>
# include "Bureaucrat.hpp"

# define END   	 "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"

class	Bureaucrat;

class	Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;

	public:
		// Orthodox Canonical Form
		Form(void);
		Form(std::string const name, int const signGrade, int const execGrade);
		Form(Form const &src);
		~Form(void);
		Form &operator=(Form const &src);

		// Getters
		std::string const	getName(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		bool				getSigned(void) const;

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		// Member function
		void	beSigned(Bureaucrat const &bur);

};

std::ostream &operator<<(std::ostream &stream, Form const &src);

#endif

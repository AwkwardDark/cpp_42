#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdbool.h>
# include <stdexcept>
# include "Bureaucrat.hpp"

# define END   	 "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"

class	Bureaucrat;

class	AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;

	public:
		// Orthodox Canonical Form
		AForm(void);
		AForm(std::string const name, int const signGrade, int const execGrade);
		AForm(AForm const &src);
		virtual ~AForm(void);
		AForm &operator=(AForm const &src);

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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		// Member function
		void			beSigned(Bureaucrat const &bur);
		virtual	void	execute(Bureaucrat const &executor) const = 0;

};

std::ostream &operator<<(std::ostream &stream, AForm const &src);

#endif

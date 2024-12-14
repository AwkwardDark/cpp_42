#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

# define ASCII_TREE "       ooo xxoo ooo oxxoo\n"\
"    ooxoxo oo  oxoxooo xoo\n"\
"   oooo xxoxoo ooo ooox xoxo\n"\
"  oxo o oxoxo  xoxxoxo oooox\n"\
"   oxo xooxoooo o oooox xxoo\n"\
"     ooxo oooooo oxoxo oooo\n"\
"        oooooooo  oooo xoox\n"\
"           oooooo  / /o\n"\
"              \\ \\ / /\n"\
"               |   /\n"\
"               |  |\n"\
"               |  |\n"\
"               |  |\n"\
"               |  |\n"\
"   ____________|__|___________\n"


class	ShrubberyCreationForm : public AForm
{
	private:
		std::string		_target;
	
	public:
		// Canonical Orthodox Form
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

		//Methods
		std::string	getTarget(void) const;
		void		execute(Bureaucrat const &executor) const;
};

#endif
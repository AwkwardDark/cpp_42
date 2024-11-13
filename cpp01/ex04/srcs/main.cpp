/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:52:18 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/11 18:15:42 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	replace(std::string filename, std::string s1, std::string s2)
{
	std::string		new_filename, buf, line;
	std::size_t		buf_index;
	std::ifstream	infile;
	std::ofstream	outfile;

	infile.open(filename.c_str(), std::ios::in);
	if (!infile)
	{
		std::cout << "Error while opening the infile" << std::endl;
		return (1);
	}
	new_filename = filename + ".replace";
	outfile.open(new_filename.c_str(), std::ios::out);
	if (!outfile)
	{
		std::cout << "Error while creating the outfile" << std::endl;
		infile.close();
		return (1);
	}
	
	while (!infile.eof())
	{
		std::getline(infile, buf);
		line = "";
		while (buf.find(s1, 0) != std::string::npos && s1.length() > 0)
        {
            buf_index = buf.find(s1, 0);
            line += buf.substr(0, buf_index) + s2;
            buf = buf.substr(buf_index + s1.length(), buf.length());
        }
        line += buf;
        outfile << line;
        if (!infile.eof())
            outfile << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments. Format is: ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	if (replace(argv[1], argv[2], argv[3]))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:51:40 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/16 16:10:07 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

	std::map<date, float>
	std::ifstream infile;
	if (argc < 2) {
		std::cout << "Error: bad arguments" << std:: endl;
		return 1;
	}
	infile.open(argv[1], std::ios_base::in);
	if (!infile.is_open()) {
		std::cout << "Error: the file does not exist or cannot be opened" << std::endl;
		return 2;
	}
	read_first_database();
	read_second_database(infile);
	infile.close();
	return 0;
}
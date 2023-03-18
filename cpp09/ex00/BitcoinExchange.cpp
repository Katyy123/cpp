/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:51:34 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/18 19:32:00 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int read_csv_database(std::ifstream & db, std::map<Date, float> & database_map) {

	std::string line;
	std::string sub_str;
	std::string sub_sub_str;
	std::size_t coma_pos;
	std::size_t dash_pos;
	long int	year;
	long int	month;
	long int	day;
	
	if (!db.is_open()) {
		std::cerr << "Error: the database does not exist or is not opened" << std::endl;
		return -1;
	}
	if (db.peek() == EOF) {
		std::cerr << "Error: the database is empty" << std::endl;
		return -1;
	}
	while (getline(db, line)) {
		// if (line.find_first_of("0123456789") != std::string::npos)
		// 	break;
		if (line.find_first_not_of("0123456789-,") != line.npos)
			continue;
		coma_pos = line.find(",");
		if (coma_pos == line.npos)
			continue;
		sub_str = line.substr(0, coma_pos);
		dash_pos = sub_str.find("-");
		if (dash_pos == sub_str.npos)
			continue;
		sub_sub_str = sub_str.substr(0, dash_pos);
		if (sub_sub_str.find_first_not_of("0123456789") != sub_sub_str.npos)
			continue;
		// converto il numero con una specie di atoi e controllo se non è maggiore del max int
		
	}
		
	
	return 0;
}

int read_infile(std::ifstream & infile, std::multimap<Date, float> infile_map) {

	//read input file

	return 0;
}
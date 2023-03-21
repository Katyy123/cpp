/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:51:34 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/21 18:30:56 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int read_csv_database(std::ifstream & db, std::map<Date, float> & database_map) {

	std::string line;
	std::string sub_str;
	std::string sub_sub_str;
	std::size_t coma_pos;
	std::size_t dash_pos;
	std::size_t temp_dash_pos;
	int			year;
	int			month;
	int			day;
	float		exchange_rate;
	std::size_t	i;
	int			count;
	
	if (!db.is_open()) {
		std::cerr << "Error: the database does not exist or is not opened" << std::endl;
		return -1;
	}
	if (db.peek() == EOF) {
		std::cerr << "Error: the database is empty" << std::endl;
		return -1;
	}
	while (getline(db, line)) {
		std::cout << std::endl;
		if (line.empty() || line.find_first_not_of("0123456789-,.") != line.npos)
			continue;
		std::cout << line << std::endl;
		coma_pos = line.find(",");
		if (coma_pos == line.npos)
			continue;
		std::cout << "check 1" << std::endl;
		sub_str = line.substr(0, coma_pos);
		std::cout << "sub_str: " << sub_str << std::endl;
		dash_pos = 0;
		temp_dash_pos = dash_pos;
		dash_pos = sub_str.find("-", temp_dash_pos);
		std::cout << "dash_pos: " << dash_pos<< std::endl;
		std::cout << "temp_dash_pos: " << temp_dash_pos << std::endl;
		sub_sub_str = sub_str.substr(0, dash_pos);
		std::cout << "sub_sub_str 1: " << sub_sub_str << std::endl;
		i = 0;
		while (dash_pos != sub_str.npos && i < 2) {
			std::cout << "@@@ ciclo @@@" << std::endl;
			if (sub_sub_str.find_first_not_of("0123456789") != sub_sub_str.npos || ft_is_toobig(sub_sub_str) == true)
				break;
			if (i == 0)
				year = ft_stoi(sub_sub_str);
			else
				month = ft_stoi(sub_sub_str);
			temp_dash_pos = dash_pos;
			dash_pos = sub_str.find("-", temp_dash_pos + 1);
			std::cout << "dash_pos: " << dash_pos<< std::endl;
			std::cout << "temp_dash_pos: " << temp_dash_pos << std::endl;
			sub_sub_str = sub_str.substr(temp_dash_pos + 1, dash_pos);
			std::cout << "sub_sub_str: " << sub_sub_str << std::endl;
			i++;
		}
		if (i != 2)
			continue;
		std::cout << "----- check 3" << std::endl;
		sub_sub_str = sub_str.substr(temp_dash_pos + 1, sub_str.npos);
		std::cout << sub_sub_str << std::endl;
		if (sub_sub_str.find_first_not_of("0123456789") != sub_sub_str.npos || ft_is_toobig(sub_sub_str) == true)
			continue;
		std::cout << "check 4" << std::endl;
		day = ft_stoi(sub_sub_str);
		
		sub_str = line.substr(coma_pos + 1, line.npos);
		count = 0;
		for (i = 0; i < sub_str.length(); i++) {
			if (sub_str[i] == '.')
				count++;
		}
		if (count > 1 || sub_str.find_first_not_of("0123456789."))
			continue;
		std::cout << "check 5" << std::endl;
		exchange_rate = ft_stof(sub_str);
		Date	date(year, month, day);
		database_map.insert(std::pair<Date, float>(date, exchange_rate));
		std::cout << "KEY\tELEMENT\n";
    	for (std::map<Date, float>::const_iterator itr = database_map.begin(); itr != database_map.end(); ++itr) {
        	std::cout << itr->first << '\t' << itr->second << '\n';
    }
	}
		
	
	return 0;
}

// int read_infile(std::ifstream & infile, std::multimap<Date, float> infile_map) {

// 	//read input file

// 	return 0;
// }
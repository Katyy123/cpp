/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:51:34 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/27 14:38:40 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int read_database(std::ifstream & db, std::map<Date, float> & database_map) {

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
	//checks if file is empty
	if (db.peek() == EOF) {
		std::cerr << "Error: the database is empty" << std::endl;
		return -1;
	}
	//reads one line at a time
	while (getline(db, line)) {
		
		if (line.empty() || line.find_first_not_of("0123456789-,.") != line.npos)
			continue;
		coma_pos = line.find(",");
		if (coma_pos == line.npos)
			continue;
		
		//checks the date
		sub_str = line.substr(0, coma_pos);
		dash_pos = 0;
		temp_dash_pos = dash_pos;
		dash_pos = sub_str.find("-", temp_dash_pos);
		sub_sub_str = sub_str.substr(0, dash_pos);
		i = 0;
		while (dash_pos != sub_str.npos && i < 2) {
			if (sub_sub_str.find_first_not_of("0123456789") != sub_sub_str.npos || ft_is_toobig(sub_sub_str) == true)
				break;
			if (i == 0)
				year = ft_stoi(sub_sub_str);
			else
				month = ft_stoi(sub_sub_str);
			temp_dash_pos = dash_pos;
			dash_pos = sub_str.find("-", temp_dash_pos + 1);
			sub_sub_str = sub_str.substr(temp_dash_pos + 1, dash_pos - (temp_dash_pos + 1));
			i++;
		}
		if (i != 2)
			continue;
		sub_sub_str = sub_str.substr(temp_dash_pos + 1, sub_str.npos);
		if (sub_sub_str.find_first_not_of("0123456789") != sub_sub_str.npos || ft_is_toobig(sub_sub_str) == true)
			continue;
		day = ft_stoi(sub_sub_str);
		if (year > 3000 || !(month >= 1 && month <= 12) || ! (day >= 1 && day <= 31))
			continue;
			
		//checks the exchange rate
		sub_str = line.substr(coma_pos + 1, line.npos);
		count = 0;
		for (i = 0; i < sub_str.length(); i++) {
			if (sub_str[i] == '.')
				count++;
		}
		if (count > 1 || sub_str.find_first_not_of("0123456789.") != sub_str.npos)
			continue;
		exchange_rate = ft_stof(sub_str);
		Date	date(year, month, day);

		//inserts the dates and the exchange rates inside the map
		database_map.insert(std::pair<Date, float>(date, exchange_rate));
	}
	
	//prints the elements of the map
	// std::cout << "KEY\tELEMENT\n";
    // for (std::map<Date, float>::const_iterator itr = database_map.begin(); itr != database_map.end(); ++itr)
    //     std::cout << itr->first << '\t' << itr->second << '\n';
	
	return 0;
}

void ft_print(Date & date, float value, std::map<Date, float> & database_map) {
	
	Date		first_date(database_map.begin()->first);
	Date		last_date(database_map.rbegin()->first);

	if (date < first_date)
		std::cout << first_date << " => " << value << " = " << value * database_map[first_date] << std::endl;
	else if (date > last_date)
		std::cout << last_date << " => " << value << " = " << value * database_map[last_date] << std::endl;
	else {
		std::cout << date << " => " << value << " = ";
		while (database_map.find(date) == database_map.end())
			--date;
		std::cout << value * database_map[date] << std::endl;
	}
}

int read_infile(std::ifstream & infile, std::map<Date, float> & database_map) {

	std::string line;
	std::string sub_str;
	std::string sub_sub_str;
	std::size_t pipe_pos;
	std::size_t dash_pos;
	std::size_t temp_dash_pos;
	int			year;
	int			month;
	int			day;
	float		value;
	std::size_t	i;
	int			count;
	int			count_2;
	
	if (!infile.is_open()) {
		std::cerr << "Error: the file does not exist or is not opened" << std::endl;
		return -1;
	}
	//checks if file is empty
	if (infile.peek() == EOF) {
		std::cerr << "Error: the file is empty" << std::endl;
		return -1;
	}
	//reads one line at a time
	while (getline(infile, line)) {
		
		if (line.empty())
			continue;
		if (line == "date | value")
			continue;
		if (line.find_first_not_of("0123456789-|., ") != line.npos) {
			std::cerr << "Error: wrong character" << std::endl;
			continue;
		}
		pipe_pos = line.find(" | ");
		if (pipe_pos == line.npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		//checks the date
		sub_str = line.substr(0, pipe_pos);
		dash_pos = 0;
		temp_dash_pos = dash_pos;
		dash_pos = sub_str.find("-", temp_dash_pos);
		sub_sub_str = sub_str.substr(0, dash_pos);
		i = 0;
		while (dash_pos != sub_str.npos && i < 2) {
			if (sub_sub_str.find_first_not_of("0123456789") != sub_sub_str.npos) {
				//std::cerr << "Error: bad input => " << line << std::endl;
				break;
			}
			if (ft_is_toobig(sub_sub_str) == true) {
				//std::cerr << "Error: too large number." << std::endl;
				break;
			}
			if (i == 0)
				year = ft_stoi(sub_sub_str);
			else
				month = ft_stoi(sub_sub_str);
			temp_dash_pos = dash_pos;
			dash_pos = sub_str.find("-", temp_dash_pos + 1);
			sub_sub_str = sub_str.substr(temp_dash_pos + 1, dash_pos - (temp_dash_pos + 1));
			i++;
		}
		if (i != 2) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		sub_sub_str = sub_str.substr(temp_dash_pos + 1, sub_str.npos);
		if (sub_sub_str.find_first_not_of("0123456789") != sub_sub_str.npos) {
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
		}
		if (ft_is_toobig(sub_sub_str) == true) {
			std::cerr << "Error: too large number." << std::endl;
			continue;
		}
		day = ft_stoi(sub_sub_str);
		if (year > 3000 || !(month >= 1 && month <= 12) || ! (day >= 1 && day <= 31)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		//checks the value
		sub_str = line.substr(pipe_pos + 3, line.npos);
		count = 0;
		count_2 = 0;
		for (i = 0; i < sub_str.length(); i++) {
			if (sub_str[i] == '.' || sub_str[i] == ',')
				count++;
		}
		for (i = 0; i < sub_str.length(); i++) {
			if (sub_str[i] == '-')
				count_2++;
		}
		if (count > 1 || count_2 > 1 || sub_str.find_first_not_of("0123456789.,-") != sub_str.npos ||
				(sub_str.find_first_of("-") != 0 && sub_str.find_first_of("-") != sub_str.npos)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (sub_str[0] == '-') {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (ft_is_toobig(sub_str) == true) {
			std::cerr << "Error: too large number." << std::endl;
			continue;
		}
		value = ft_stof(sub_str);
		if (value > 1000) {
			std::cerr << "Error: too large number." << std::endl;
			continue;
		}
		Date	date(year, month, day);

		//prints the output
		ft_print(date, value, database_map);
	}
	
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catia <catia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:51:34 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/20 20:40:22 by catia            ###   ########.fr       */
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
	int			i;
	Date		date;
	
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
		if (line.empty() || line.find_first_not_of("0123456789-,") != line.npos)
			continue;
		coma_pos = line.find(",");
		if (coma_pos == line.npos)
			continue;
		sub_str = line.substr(0, coma_pos);
		dash_pos = 0;
		temp_dash_pos = dash_pos;
		dash_pos = sub_str.find("-", temp_dash_pos);
		i = 0;
		while (dash_pos != sub_str.npos && i < 2) {
			sub_sub_str = sub_str.substr(0, dash_pos);
			if (sub_sub_str.find_first_not_of("0123456789") != sub_sub_str.npos || ft_is_toobig(sub_sub_str) == true)
				break;
			// converto il numero con una specie di atoi
			if (i == 0)
				year = ft_atoi(sub_sub_str);
			else
				month = ft_atoi(sub_sub_str);
			temp_dash_pos = dash_pos;
			dash_pos = sub_str.find("-", temp_dash_pos);
			i++;
		}
		if (i != 2)
			continue;
		sub_sub_str = sub_str.substr(temp_dash_pos + 1, sub_str.npos);
		if (sub_sub_str.find_first_not_of("0123456789") != sub_sub_str.npos || ft_is_toobig(sub_sub_str) == true)
			continue;
		// converto il numero con una specie di atoi
		day = ft_atoi(sub_sub_str);
		
		//considerare la sottostringa dopo la virgola (deve essere un float non negativo)
		//se è tutto ok con tutti i valori, creo un oggetto date e ci salvo le variabili year, month e day,
		// poi salvo date e exchange rate nella mappa.
	}
		
	
	return 0;
}

int read_infile(std::ifstream & infile, std::multimap<Date, float> infile_map) {

	//read input file

	return 0;
}
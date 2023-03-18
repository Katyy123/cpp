/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:51:37 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/18 18:35:28 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <unordered_map>
# include <iostream>
# include <fstream>
# include <string>
# include "Date.hpp"

int read_csv_database(std::ifstream & db_1, std::map<Date, float> & database_map);
int read_infile(std::ifstream & db, std::multimap<Date, float> infile_map);
//std::map<Date, float> read_database();

#endif
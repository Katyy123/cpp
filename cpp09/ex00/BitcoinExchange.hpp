/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catia <catia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:51:37 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/20 20:31:40 by catia            ###   ########.fr       */
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

/* BitcoinExchange.cpp */
int read_csv_database(std::ifstream & db_1, std::map<Date, float> & database_map);
int read_infile(std::ifstream & db, std::multimap<Date, float> infile_map);

/* utils.cpp */
bool ft_is_toobig(std::string const & str);
int	ft_atoi(std::string str);

#endif
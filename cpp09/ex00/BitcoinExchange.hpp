/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:51:37 by cfiliber          #+#    #+#             */
/*   Updated: 2023/03/22 17:48:45 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <unordered_map>
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include "Date.hpp"

/* BitcoinExchange.cpp */
int		read_database(std::ifstream & db_1, std::map<Date, float> & database_map);
int		read_infile(std::ifstream & db, std::map<Date, float> & database_map);
void	ft_print(Date & date, float value, std::map<Date, float> & database_map);

/* utils.cpp */
bool	ft_is_toobig(std::string const & str);
int		ft_stoi(std::string const & str);
float	ft_stof(std::string const & str);

#endif
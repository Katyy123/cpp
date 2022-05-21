/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:14:36 by cfiliber          #+#    #+#             */
/*   Updated: 2022/05/18 14:37:17 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "Account.hpp"

Account::Account(int initial_deposit) : _accountIndex(0), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {

    static int index = 0;
    this->_accountIndex = index;
    index++;
    Account::_nbAccounts = index;
    Account::_totalAmount += this->_amount;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}

Account::~Account(void) {

	Account::_nbAccounts --;
    Account::_totalAmount -= this->_amount;
    Account::_totalNbDeposits -= this->_nbDeposits;
    Account::_totalNbWithdrawals -= this->_nbWithdrawals;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;

}

int		Account::getNbAccounts( void ) {

	return Account::_nbAccounts;
}

int		Account::getTotalAmount( void ) {

	return Account::_totalAmount;
}

int		Account::getNbDeposits( void ) {
	
	return Account::_totalNbDeposits;
}

int		Account::getNbWithdrawals( void ) {

	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	
	Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit ) {

	Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    this->_amount += deposit;
    Account::_totalAmount += deposit;
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << this->_amount << ";";
    this->_nbDeposits ++;
    Account::_totalNbDeposits ++;
    std::cout << "nb_deposits:" << this->_nbDeposits << ";" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	bool    result;
    
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    this->_amount -= withdrawal;
    if (this->checkAmount() == 1) { 
        Account::_totalAmount -= withdrawal;
        std::cout << "withdrawal:" << withdrawal << ";";
        std::cout << "amount:" << this->_amount << ";";
        this->_nbWithdrawals ++;
        Account::_totalNbWithdrawals ++;
        std::cout << "nb_withdrawals:" << this->_nbWithdrawals << ";";
        result = 1;
    }
    else {
        this->_amount += withdrawal;
        std::cout << "withdrawal:refused";
        result = 0;
    }
    std::cout << std::endl;
    return result;
}

int		Account::checkAmount( void ) const {

	if (this->_amount < 0)
        return 0;
    else
        return 1;
}

void	Account::displayStatus( void ) const {

	Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ) {

    const time_t    time_in_sec = time(0);
    char            buff[16];
    strftime(buff, sizeof(buff), "%Y%m%d_%H%M%S", localtime(&time_in_sec));
    std::cout << "[" << buff << "] ";
}

Account::Account(void) {

	
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
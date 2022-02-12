/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:44:55 by twagner           #+#    #+#             */
/*   Updated: 2022/02/12 12:27:43 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

/*
** Non member attributes init
*/

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*
** Constructor & destructor
*/

Account::Account(int initial_deposit) : \
	_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts += 1;
	Account::_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
			  << ";amount:" << this->_amount \
			  << ";created" << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
			  << ";amount:" << this->_amount \
			  << ";closed" << std::endl;
	Account::_nbAccounts -= 1;
}

/*
** Accessors
*/
void	Account::_displayTimestamp(void)
{
	std::time_t	timestamp;
	std::tm		*now;

	timestamp = std::time(0);
	now = std::localtime(&timestamp);
	std::cout << "[" \
			  << now->tm_year + 1900 \
			  << std::setw(2) << std::setfill('0') << now->tm_mon + 1 \
			  << std::setw(2) << std::setfill('0') << now->tm_mday;
	std::cout << "_" \
			  << std::setw(2) << std::setfill('0') << now->tm_hour \
			  << std::setw(2) << std::setfill('0') << now->tm_min \
			  << std::setw(2) << std::setfill('0') << now->tm_sec \
			  << "] ";
}

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() \
			  << ";total:" << Account::getTotalAmount() \
			  << ";deposits:" << Account::getNbDeposits() \
			  << ";withdrawals:" << Account::getNbWithdrawals() \
			  << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
			  << ";p_amount:" << this->_amount \
			  << ";deposit:" << deposit \
			  << ";amount:" << this->_amount + deposit \
			  << ";nb_deposits:" << this->_nbDeposits \
			  << std::endl;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
			  << ";p_amount:" << this->_amount;
	if (this->_amount >= withdrawal)
	{
		this->_nbWithdrawals += 1;
		std::cout << ";withdrawal:" << withdrawal \
				  << ";amount:" << this->_amount - withdrawal \
				  << ";nb_withdrawals:" << this->_nbWithdrawals \
			      << std::endl;
		this->_amount -= withdrawal;
		Account::_totalNbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
		return (true);
	}
	else
	{
		std::cout << ";withdrawal:refused" \
			      << std::endl;
		return (false);
	}
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
			  << ";amount:" << this->_amount \
			  << ";deposits:" << this->_nbDeposits \
			  << ";withdrawals:" << this->_nbWithdrawals \
			  << std::endl;
}

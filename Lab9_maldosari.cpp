/**
 * @file Lab9_maldosari.cpp
 * @author Musab Aldosari
 * @date 2026-11-16
 * @brief A banking program using inheritance and polymorphism.
 */

#include <iostream>
#include "SavingsAccount.h"
using namespace std;

/**
 * @brief Creates a savings account with an interest rate.
 * @param accNum The account number.
 * @param initialBalance The starting balance.
 * @param customer The account owner.
 * @param rate The daily interest rate.
 * @return None
 */
SavingsAccount::SavingsAccount(const string& accNum, double initialBalance,
    const Customer& customer, double rate)
    : Account(accNum, initialBalance, customer) {
    dailyInterestRate = rate;
}

/**
 * @brief Processes transactions and adds interest.
 * @param None
 * @return None
 */
void SavingsAccount::closeOfBusiness() {
    double previousBalance = balance;
    double totalDeposits = 0;
    double totalWithdrawals = 0;

    for (int i = 0; i < deposits.size(); i++) {
        totalDeposits += deposits[i];
    }

    for (int i = 0; i < withdrawals.size(); i++) {
        totalWithdrawals += withdrawals[i];
    }

    balance = balance + totalDeposits - totalWithdrawals;

    if (balance >= 0) {
        balance = balance + (balance * dailyInterestRate);
    }

    printSummary(previousBalance, totalDeposits,
        totalWithdrawals, balance);

    deposits.clear();
    withdrawals.clear();
}

/**
 * @brief Prints account information and the interest rate.
 * @param None
 * @return None
 */
void SavingsAccount::printAccountInfo() const {
    Account::printAccountInfo();
    cout << "Interest Rate: " << dailyInterestRate * 100 << "%" << endl;
}
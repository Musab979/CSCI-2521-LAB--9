/**
 * @file SavingsAccount.h
 * @author Musab Aldosari
 * @date 2026-11-16
 * @brief Declares a savings account that inherits from Account.
 */

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
    double dailyInterestRate;

public:
    /**
     * @brief Creates a savings account with an interest rate.
     * @param accNum The account number.
     * @param initialBalance The starting balance.
     * @param customer The account owner.
     * @param rate The daily interest rate.
     * @return None
     */
    SavingsAccount(const string& accNum, double initialBalance,
        const Customer& customer, double rate);

    /**
     * @brief Processes transactions and adds interest.
     * @param None
     * @return None
     */
    void closeOfBusiness() override;

    /**
     * @brief Prints account information and the interest rate.
     * @param None
     * @return None
     */
    void printAccountInfo() const override;
};

#endif
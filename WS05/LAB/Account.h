//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop5_LAB
//==============================================
// Account.h

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
  class Account {
    int m_number;
    double m_balance;

    void setEmpty();

  public:
    Account();
    Account(const int number, const double balance);
    ~Account() {};

    std::ostream &display() const;

    // ====================== Member Operators ======================

    // ****************** Type Conversion Operators ******************
    // Check the member number is vaild
    operator bool() const;

    // Returns the account number
    operator int() const;

    // Returns the balance value
    operator double() const;

    // ******************** Unary member operator ********************
    // This operator returns true if the account number is zero
    bool operator~() const;

    // ******************* Binary member operators *******************
    // To add a double value to an account like depositing money into an account
    Account &operator+=(const double _into);

    // To reduce an account balance by a double value withdrawing money from an account
    Account &operator-=(const double _draw);

    // To move funds from the left account to the right
    Account &operator>>(Account &_move);

    // To move funds from the right account to the left
    Account &operator<<(Account &_move);

    // NEW account can be set to the _acc
    Account &operator=(const int _acc);

    // NEW account can be set to another Account object
    Account &operator=(Account &_move);

    // ====================== Helper functions ======================
    // Return the double value should be the sum of the balances of the two accounts
    friend double operator+(const Account &_left, const Account &_right);

    // The value of the balance of the right operand should be added to the left operand
    friend double operator+=(double &_value, const Account &_add);
  };
} // namespace sdds
#endif // SDDS_ACCOUNT_H_
//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop5_LAB
//==============================================
// Account.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
  void Account::setEmpty()
  {
    // An account is in an invalid state if invalid information is fed into the account.
    m_number = -1;
    m_balance = 0.0;
  }

  // New account
  Account::Account()
  {
    // This state of the Account class is flagged by setting the account number (m_number) to 0.
    m_number = 0;
    m_balance = 0.0;
  }

  Account::Account(const int number, const double balance)
  {
    // If an invalid account number or a negative balance is passed to the constructor,
    // the object will be set into an invalid empty state.
    setEmpty();

    if (number >= 10000 && number <= 99999 && balance >= 0)
    {
      m_number = number;
      m_balance = balance;
    }
  }

  std::ostream &Account::display() const
  {
    if (*this)
    {
      cout << " ";
      cout << m_number;
      cout << " | ";
      cout.width(12);
      cout.precision(2);
      cout.setf(ios::right);
      cout.setf(ios::fixed);
      cout << m_balance;
      cout.unsetf(ios::right);
      cout << " ";
    }

    // If the account is a new account, instead of the account number it will print New
    else if (~*this)
    {
      cout << "  NEW  |         0.00 ";
    }

    // If the account is invalid, it is going to print: Bad Account
    else
    {
      cout << "  BAD  |    ACCOUNT   ";
    }

    return cout;
  }

  // ====================== Member Operators ======================

  // ****************** Type Conversion Operators ******************
  Account::operator bool() const
  {
    bool result = false;

    if (m_number >= 10000 && m_number <= 99999 && m_balance >= 0.0)
      result = true;

    return result;
  }

  Account::operator int() const
  {
    return m_number;
  }

  Account::operator double() const
  {
    return m_balance;
  }

  // ******************** Unary member operator ********************
  bool Account::operator~() const
  {
    return m_number == 0;
  }

  // ******************* Binary member operators *******************
  Account &Account::operator+=(const double _into)
  {
    // If these conditions are vaild, do Depositing money
    if (m_number > 0 && m_balance >= 0.0 && _into > 0.0)
      m_balance += _into;

    return *this;
  }

  Account& Account::operator-=(const double _draw)
  {
    // If these conditions are vaild, do Withdrawing money
    if (m_number > 0 && m_balance >= _draw && _draw >= 0.0)
      m_balance -= _draw;

    return *this;
  }

  Account& Account::operator>>(Account &_move)
  {
    // To move funds from the "this" object to the "_move" object
    if (this->m_number > 0 && _move.m_number > 0 && this->m_number != _move.m_number) {
      _move.m_balance += this->m_balance;
      this->m_balance = 0;
    }

    return *this;
  }

  Account& Account::operator<<(Account &_move)
  {
    // To move funds from the the "_move" object to "this" objects
    if (this->m_number > 0 && _move.m_number > 0 && this->m_number != _move.m_number)
    {
      this->m_balance += _move.m_balance;
      _move.m_balance = 0;
    }

    return *this;
  }

  Account& Account::operator=(const int _acc)
  {
    if (m_number == 0)
      // "this" account can be set to the _acc
      m_number = _acc;

    // If _acc is an invalid account number, "this" object set to an invalid empty state
    else if (_acc < 0)
      setEmpty();

    return *this;
  }

  Account& Account::operator=(Account &_move)
  {
    if (this->m_number == 0 && _move.m_number > 0) {
      // "this" account can be set to another Account object
      this->m_number = _move.m_number;
      this->m_balance = _move.m_balance;

      // Set Another account to New account
      _move.m_number = 0;
      _move.m_balance = 0;
    }

    return *this;
  }

  // ====================== Helper functions ======================

  double operator+(const Account &_left, const Account &_right)
  {
    double sum = 0.0;

    // two accounts are vaild, Return the sum of the balances of both
    if (_left.m_number > 0 && _right.m_number > 0)
      sum = _left.m_balance + _right.m_balance;

    return sum;
  }

  double operator+=(double &_value, const Account &_add)
  {
    if (_add.m_number > 0)
      _value += _add.m_balance;

    return _value;
  }
} // namespace sdds
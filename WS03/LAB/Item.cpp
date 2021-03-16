//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop3_LAB
//==============================================

#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {

  void Item::setName(const char *name)
  {
    // Copy the string up to 20 characters to m_itemName
    strnCpy(m_itemName, name, 20);
  }

  void Item::setEmpty()
  {
    // Sets the Item to a recognizable safe Empty State.
    *m_itemName = '\0';
    m_price = 0.0;
  }

  void Item::set(const char *name, double price, bool taxed)
  {
    // Check price is less than 0 or name is null
    if (name != nullptr && price > 0)
    {
      // Enter the corresponding values.
      setName(name);
      m_price = price;
      m_taxed = taxed;
    }
  }

  void Item::display() const
  {
    // check the name and price are valid
    if (isValid()) {
      display(m_itemName);
      display(m_price);
      display(m_taxed);
    }
    else {
      cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" <<endl;
    }
  }

  void Item::display(const char *name) const
  {
    // left-justified in 20 spaces, padded with '.' (dots)
    char pad = cout.fill('.');
    cout << "| ";
    cout.setf(ios::left);
    cout.width(20);
    cout << m_itemName;
    cout.fill(pad);
    cout.unsetf(ios::left);
  }

  void Item::display(double price) const
  {
    // right-justified(default) in 7 spaces with two digits after the decimal point
    cout << " | ";
    cout.width(7);
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << m_price;
    cout.unsetf(ios::fixed);
  }

  void Item::display(bool tax) const
  {

    if (tax == 1)
      cout << " | Yes |" << endl;
    else if (tax == 0)
      cout << " | No  |" << endl;
  }

  bool Item::isValid() const
  {
    bool result = false;

    // check the name and price are valid
    if (*m_itemName != '\0' && m_price > 0)
      result = true;

    return result;
  }

  double Item::price() const
  {
    return m_price;
  }

  double Item::tax() const
  {
    double result = 0.0;

    if (m_taxed) {
      result = (m_price * 0.13);
    }

    return result;
  }
}
//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop3_LAB
//==============================================

#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

  double Bill::totalTax() const
  {
    double result = 0.0;
    // Adds all the taxes of the items
    for (int i = 0; i < m_noOfItems; i++) {
      result += m_items[i].tax();
    }

    return result;
  }

  double Bill::totalPrice() const
  {
    double result = 0.0;

    // Adds all the prices of the items
    for (int i = 0; i < m_noOfItems; i++) {
      result += m_items[i].price();
    }

    return result;
  }

  void Bill::Title() const
  {
    cout << "+--------------------------------------+" << endl;
    if (isValid()) {
      // left-justified in 36 spaces
      cout << "| ";
      cout.setf(ios::left);
      cout.width(36);
      cout << m_title << " |" << endl;
      cout.unsetf(ios::left);
    }
    else {
      cout << "| Invalid Bill                         |" << endl;
    }

    cout << "+----------------------+---------+-----+" << endl;
    cout << "| Item Name            | Price   + Tax |" << endl;
    cout << "+----------------------+---------+-----+" << endl;
  }

  void Bill::footer() const
  {
    cout << "+----------------------+---------+-----+" << endl;

    if (isValid()) {
      cout << "|                Total Tax: ";
      display(totalTax());
      cout << "|              Total Price: ";
      display(totalPrice());
      cout << "|          Total After Tax: ";
      display(totalTax() + totalPrice());
    }
    else {
      cout << "| Invalid Bill                         |" << endl;
    }

    cout << "+--------------------------------------+" << endl;
  }

  void Bill::setEmpty()
  {
    *m_title = '\0';
    m_items = nullptr;
  }

  bool Bill::isValid() const
  {
    bool result = true;
    bool flag = true;

    // Check m_title, m_items and all the Items in the m_items array are valid.
    for (int i = 0; i < m_noOfItems && flag; i++) {
      if (!m_items[i].isValid()) {
        result = false;
        flag = false;
      }
    }

    return result;
  }

  void Bill::init(const char *title, int noOfItems)
  {
    // Check any of the arguments are invalid
    if (title == nullptr || noOfItems < 0) {
      // it will set the Bill to an empty state
      setEmpty();
    }
    else {
      // set the m_noOfItems to the number of Items
      m_noOfItems = noOfItems;

      // sets m_itemsAdded to zero
      m_itemsAdded = 0;

      // Copy the entered title to the member variable of title.
      strnCpy(m_title, title, 36);

      // Then it will dynamically allocate an array of Items pointed by m_items member variable.
      // The length of this array will be m_noOfItems.
      m_items = new Item[noOfItems];

      // Make sure all the dynamically allocated Items are set to empty
      for (int i = 0; i < noOfItems; i++) {
        m_items[i].setEmpty();
      }
    }
  }

  bool Bill::add(const char *item_name, double price, bool taxed)
  {
    bool result = false;

    // check the number of m_itemsAdded is less than the length of the m_items array,
    if (m_itemsAdded < m_noOfItems) {
      // set the next available subject
      m_items[m_itemsAdded].set(item_name, price, taxed);

      // add one the number of added Items
      m_itemsAdded++;

      result = true;
    }

    return result;
  }

  void Bill::display() const
  {
    Title();

    for (int i = 0; i < m_noOfItems; i++)
    {
      m_items[i].display();
    }

    footer();
  }

  void Bill::display(double price) const
  {
    // right justified(default) in 10 spaces with two digits after the decimal point
    cout.width(10);
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << price << " |" << endl;
    cout.unsetf(ios::fixed);
  }

  void Bill::deallocate()
  {
    // Deallocates the m_items arrays
    delete[] m_items;
    m_items = nullptr;
  }
}

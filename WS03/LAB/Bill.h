//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop3_LAB
//==============================================

#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_
#include "Item.h"
namespace sdds {
  class Bill
  {
    // Private Variables:
    char m_title[37];
    Item *m_items;
    int m_noOfItems;
    int m_itemsAdded;

    // Private Member function:
    // Adds all the taxes of the items
    double totalTax() const;

    // Adds all the prices of the items
    double totalPrice() const;

    // Prints Title
    void Title() const;

    // Prints footer
    void footer() const;

    // Sets the Bill object to an empty state
    void setEmpty();

    // Check m_title, m_items and all the Items in the m_items array are valid.
    bool isValid() const;

  public:
    // if the incoming arguments are valid, it will dynamically allocate an array of Items
    void init(const char *title, int noOfItems);

    // this function will set the next available subject to the incoming argument values
    bool add(const char *item_name, double price, bool taxed);

    // Display title, all m_items element and footer
    void display() const;

    // Overloaded function to display total tax, price and final price wih tax
    void display(double price) const;

    // Deallocates the m_items arrays
    void deallocate();
  };
} // namespace sdds
#endif // !SDDS_TRANSCRIPT_H

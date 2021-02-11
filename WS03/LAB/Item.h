//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop3_LAB
//==============================================

#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds {
  class Item
  {
    // Private Variables:
    char m_itemName[21]; // holds the item name up to 20 chars
    double m_price;
    bool m_taxed;

    // Private Member function:
    // sets the itemName member Cstring variable to a m_itemName[21]
    void setName(const char *name);

  public:
    //Sets the Item to a recognizable safe Empty State.
    void setEmpty();

    // Enter the values delivered to the private Varialbes
    void set(const char *name, double price, bool taxed);

    // Display name, price and tax of item
    void display() const;

    // overloaded function to display name
    void display(const char *name) const;

    // overloaded function to display price
    void display(double price) const;

    // overloaded function to display tax
    void display(bool tax) const;

    // Check the all the Items are vaild
    bool isValid() const;

    // Returns the m_price attribute;
    double price() const;

    // Calculates tax if tax is true
    double tax() const;
  };
} // namespace sdds

#endif // !SDDS_SUBJECT_H

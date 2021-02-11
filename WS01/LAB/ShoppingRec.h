//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop1_LAB
//==============================================
// ShoppingRec.h

#ifndef SDDS_SHOPPINGRECH_H
#define SDDS_SHOPPINGRECH_H

namespace sdds {

  // Constant Value:
  const int MAX_TITLE_LENGTH = 50;

  // Structure:
  struct ShoppingRec {
    char m_title[MAX_TITLE_LENGTH + 1];
    int m_quantity;
    bool m_bought;
  };

  // Function Prototypes:
  ShoppingRec getShoppingRec();
  void displayShoppingRec(const ShoppingRec* shp);
  void toggleBoughtFlag(ShoppingRec* rec);
  bool isShoppingRecEmpty(const ShoppingRec* shp);
}
#endif // !SDDS_SHOPPINGRECH_H

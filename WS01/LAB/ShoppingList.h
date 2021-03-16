//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop1_LAB
//==============================================
// ShoppingList.h

#ifndef SDDS_SHOPPINGLIST_H
#define SDDS_SHOPPINGLIST_H

namespace sdds {

  // Function Prototypes:
  bool loadList();
  bool saveList();
  void removeItem(int index);
  void clearList();
  void toggleBought();
  void addItemToList();
  bool listIsEmpty();
  void removeItemfromList();
  void displayList();
  void removeBoughtItems();
}
#endif // !SDDS_SHOPPINGLIST_H

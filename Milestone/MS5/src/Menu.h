/*
 < Citation and Sources >

Final Project Milestone 5
Module: Menu
Filename: Menu.h
Version 1.0

Author:	        Jungjoo Kim
Student Number: 162 641 195
Email:          jkim594@myseneca.ca
Section:        NCC

Revision History
-----------------------------------------------------------
Date       Reason
2020/3/19  First creating coding
2020/3/19  Completed coding
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_

#include <iostream>

namespace sdds
{
  class Menu
  {
    char *m_text{nullptr}; // holds the menu content dynamically
    int m_noOfSel{0};      // holds the number of options displayed in menu content
    void display() const;

  public:
    Menu(const char* MenuContent, int NoOfSelections);
    virtual ~Menu();
    int &operator>>(int& Selection);

    // add safe copying logic
    // Make sure the Menu can be safely copied
    Menu(const Menu &src);

    // not be able to be assigned to another Menu object
    Menu &operator=(const Menu &) = delete;
  };
}
#endif
/*
 < Citation and Sources >

Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
Version 1.0

Author:	        Jungjoo Kim
Student Number: 162 641 195
Email:          jkim594@myseneca.ca
Section:        NCC

Revision History
-----------------------------------------------------------
Date       Reason
2021/3/19  First creating coding
2021/3/19  Completed coding
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include <string.h>

#include "Menu.h"
#include "utils.h"

using namespace std;

namespace sdds
{
  Menu::Menu(const char *MenuContent, int NoOfSelections)
  {
    if (MenuContent && MenuContent[0] != '\0') {
      m_text = new char[strlen(MenuContent) + 1];
      strcpy(m_text, MenuContent);
    }

    NoOfSelections > 0 ? m_noOfSel = NoOfSelections : m_noOfSel = 0;
  }

  Menu::~Menu()
  {
    // Deallocates the dynamically allocated memory
    if (m_text) {
      delete[] m_text;
      m_text = nullptr;
    }
  }

  void Menu::display() const
  {
    // Displays the Menu content and then in a new line
    cout << m_text << endl;
    cout << "0- Exit" << endl;
  }

  int& Menu::operator>>(int &Selection)
  {
    display();
    // receives the user's selection as an integer value
    return Selection = getInt(0, m_noOfSel, "> ", "Invalid option ");
  }

  Menu::Menu(const Menu &src)
  {
    this->m_noOfSel = src.m_noOfSel;

    if (src.m_text) {
      this->m_text = new char[strlen(src.m_text) + 1];
      strcpy(this->m_text, src.m_text);
    }
  }
}
//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop3_DIY
//==============================================

#include <iostream>
#include "CalorieList.h"

using namespace std;

namespace sdds {

  bool CalorieList::isValid() const
  {
    bool result = true;
    bool flag = true;

    // Check m_title, m_items and all the Items in the m_items array are valid.
    for (int i = 0; i < m_noOfFood && flag; i++)
    {
      if (!m_food[i].isValid())
      {
        result = false;
        flag = false;
      }
    }

    return result;
  }

  int CalorieList::totalCal() const
  {
    int result = 0;

    for (int i = 0; i < m_noOfFood; i++) {
      // Adds all the calories of the food
      result += m_food[i].calorie();
    }

    return result;
  }

  void CalorieList::Title() const
  {
    cout << "+----------------------------------------------------+" << endl;
    if (isValid()) {
      cout << "|  Daily Calorie Consumption                         |" << endl;
    }
    else {
      cout << "| Invalid Calorie Consumption list                   |" << endl;
    }

    // default printing
    cout << "+--------------------------------+------+------------+" << endl;
    cout << "| Food name                      | Cals | When       |" << endl;
    cout << "+--------------------------------+------+------------+" << endl;
  }

  void CalorieList::Footer() const
  {
    cout << "+--------------------------------+------+------------+" << endl;

    if (isValid()) {
      cout << "|    Total Calories for today:";
      cout.width(9);
      cout << totalCal() << " |            |" << endl;
    }
    else {
      cout << "|    Invalid Calorie Consumption list                |" << endl;
    }

    // default printing
    cout << "+----------------------------------------------------+" << endl;
  }


  CalorieList::CalorieList()
  {
    // Sets the CalorieList object to an empty state using constructor
    m_food = nullptr;
    m_noOfFood = 0;
    m_addedCount = 0;
  }

  CalorieList::~CalorieList()
  {
    // Double-check that the allocated memory has been properly deleted
    if (m_food != nullptr) {
      delete[] m_food;
      m_food = nullptr;
    }
  };

  void CalorieList::init(int noOfList)
  {
    // Check the number of List is valid
    if (noOfList > 0) {
      // set the noOfList to the number of m_noOfFood
      m_noOfFood = noOfList;

      // sets m_addedCount to zero
      m_addedCount = 0;

      // dynamically allocate an array of Food pointed by m_food member variable
      // up to noOfList
      m_food = new Food[noOfList];
    }
  }

  bool CalorieList::add(const char *food_name, int calNum, int consumTime)
  {
    bool result = false;

    // check the number of m_addedCount is less than the length of the m_noOfFood array,
    if (m_addedCount < m_noOfFood) {
      m_food[m_addedCount].set(food_name, calNum, consumTime);
      m_addedCount++;

      result = true;
    }

    return result;
  }

  void CalorieList::display() const
  {
    Title();

    for (int i = 0; i < m_noOfFood; i ++) {
      m_food[i].display();
    }

    Footer();
  }

  void CalorieList::deallocate()
  {
    // Deallocates the m_items arrays
    delete[] m_food;
    m_food = nullptr;
  }
}
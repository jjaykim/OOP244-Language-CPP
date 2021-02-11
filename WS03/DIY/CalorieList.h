//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop3_DIY
//==============================================

#include "Food.h"

#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
namespace sdds {
  class CalorieList
  {
    // Private Variables:
    int m_noOfFood;
    int m_addedCount;
    Food *m_food;

    bool isValid() const;
    int totalCal() const;
    void Title() const;
    void Footer() const;

  public:
    CalorieList(); // set Empty object
    ~CalorieList();

    void init(int noOfList);
    bool add(const char *food_name, int calNum, int consumTime);
    void display() const;
    void deallocate();
  };
} // namespace sdds
#endif
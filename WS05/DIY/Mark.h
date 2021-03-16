//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop5_DIY
//==============================================
// Mark.h

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_

#include <iostream>

namespace sdds
{
  class Mark
  {
    int _mark;

  public:
    // If this value is no-argument constructor, the value of the mark will be zero
    Mark();
    // Mark can be created using an integer value that sets the value of the mark
    Mark(const int input);
    ~Mark(){};

    // ====================== Membber Operators ======================
    // ****************** Type Conversion Operators ******************
    operator int() const;
    operator double() const;
    operator char() const;

    // ******************* Binary member operators *******************
    Mark &operator+=(const int input);
    Mark &operator=(const int input);

  };
  // ====================== Helper functions ======================
  int operator+=(int &_value, const Mark &_add);
}
#endif
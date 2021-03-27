//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop8_LAB
//==============================================
// Shape.h

#include <iostream>
#include "Shape.h"

namespace sdds
{
  std::ostream &operator<<(std::ostream &ostr, const Shape &src)
  {
    src.draw(ostr);
    return ostr;
  }
  std::istream &operator>>(std::istream &istr, Shape &src)
  {
    src.getSpecs(istr);
    return istr;
  }
}
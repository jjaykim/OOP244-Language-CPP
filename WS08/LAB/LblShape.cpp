//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop8_LAB
//==============================================
// LblShape.cpp

#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"

using namespace std;

namespace sdds
{
  const char *LblShape::label() const
  {
    return m_label;
  }

  LblShape::LblShape(const char *_label)
  {
    if (_label && _label[0] != '\0') {
      m_label = new char[strlen(_label) + 1];
      strcpy(m_label, _label);
    }
  }

  LblShape::~LblShape()
  {
    if (m_label) {
      delete[] m_label;
      m_label = nullptr;
    }
  }

  void LblShape::getSpecs(std::istream &istr)
  {
    string _label;

    // Reads a comma-delimited Cstring form istream
    getline (istr, _label, ',');

    // copy the Cstring into the newly allocated memory
    delete[] m_label;
    m_label = new char[strlen(_label.c_str()) + 1];
    strcpy(m_label, _label.c_str());
  }
}
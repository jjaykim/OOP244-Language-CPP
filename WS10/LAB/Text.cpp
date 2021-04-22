//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop10_LAB
//==============================================
// Text.cpp

#include <iostream>
#include <fstream>
#include "Text.h"
#include "cstring.h"

using namespace std;

namespace sdds {
  int Text::getFileLength() const {
    int len = 0;
    ifstream fin(m_filename);

    while (fin) {
      fin.get();
      len += !!fin;
    }

    // returns the length (size) of the text file on the disk.
    return len;
  }

  const char &Text::operator[](int index) const {
    if (index >= 0 || index < getFileLength())
      return m_content[index];
    // The behaviour of the operator is not defined if the index goes out of bounds.
    else
      return m_content[getFileLength()];
  }

  Text::Text(const char *filename) {
    if (filename) {
      m_filename = new char[strLen(filename) + 1];
      strCpy(m_filename, filename);
      read();
    }
  }

  // The rule of three
  Text::Text(const Text &src) {
    *this = src;
  }

  Text& Text::operator=(const Text &src) {
    if (this != &src) {
      if (m_filename) delete[] m_filename;

      if (src.m_filename) {
        m_filename = new char[strLen(src.m_filename) + 1];
        strCpy(m_filename, src.m_filename);
        read();
      }
      else {
        m_filename = nullptr;
        m_content = nullptr;
      }
    }

    return *this;
  }

  Text::~Text() {
    if (m_filename) {
      delete[] m_filename;
      m_filename = nullptr;
    }

    if (m_content) {
      delete[] m_content;
      m_content = nullptr;
    }
  }

  void Text::read() {
    char temp;
    int index = 0;

    // read the file
    ifstream _read(m_filename);

    // delete the current content of the file
    if (m_content) delete[] m_content;

    if (_read.is_open()) {
      // allocates memory to the size of the file on the disk + 1 (for the null byte).
      m_content = new char[getFileLength() + 1];

      // read the contents of the file character by character
      while (_read.get(temp)) {
        m_content[index] = temp;
        index++;
      }

      // terminates it with a null byte at the end.
      m_content[index] = '\0';
    }
    else m_content = nullptr;
  }

  void Text::write(std::ostream &os) const {
    if (m_content) os << m_content;
  }

  std::ostream &operator<<(std::ostream &os, const Text &src) {
    src.write(os);
    return os;
  }
}
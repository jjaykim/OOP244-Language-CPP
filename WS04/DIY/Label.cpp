//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop4_DIY
//==============================================
// Label.cpp

#include <iostream>
#include "Label.h"
#include "cstring.h"

using namespace std;

namespace sdds {
  Label::Label()
  {
    // Set to the frame to defaultSymbol
    strCpy(symbol, defaultSymbol);

    // Set to empty label
    oneLineText = nullptr;
  }

  Label::Label(const char *frameArg)
  {
    // Set to frame to framArg
    strCpy(symbol, frameArg);

    // Set to empty label
    oneLineText = nullptr;
  }

  Label::Label(const char *frameArg, const char *content)
  {
    // Set to frame to framArg
    strCpy(symbol, frameArg);

    // Check the length of content is valid
    if (strLen(content) < 71) {
      // Creat and copy as much dynamically memory as content entered + 1
      oneLineText = new char[strLen(content) + 1];
      strCpy(oneLineText, content);
    }
  }

  Label::~Label()
  {
    // if oneLineText has value, delete dynamically memory and
    // set to nullptr for safe
    if (oneLineText) {
      delete[] oneLineText;
      oneLineText = nullptr;
    }
  }

  void Label::readLabel()
  {
    char content[71];

    cout << "> ";
    // reads the label from console up to 70 characters
    cin.get(content, 71);

    // Make a clean in buffer
    cin.ignore(32767, '\n');

    // Create and copy as much dynamically memory as content entered + 1
    oneLineText = new char[strLen(content) + 1];
    strCpy(oneLineText, content);
  }

  std::ostream& Label::printLabel() const
  {
    // Only if oneLineText has a value
    if (oneLineText != nullptr) {
      int middleSpace = strLen(oneLineText);

      cout << symbol[0];
      cout.fill(symbol[1]);
      cout.width(middleSpace + 3);
      cout << symbol[2] << endl;

      cout << symbol[7];
      cout.fill(' ');
      cout.width(middleSpace + 3);
      cout << symbol[3] << endl;

      cout << symbol[7];
      cout.width(middleSpace + 1);
      cout << oneLineText;
      cout << " " << symbol[3] << endl;

      cout << symbol[7];
      cout.fill(' ');
      cout.width(middleSpace + 3);
      cout << symbol[3] << endl;

      cout << symbol[6];
      cout.fill(symbol[5]);
      cout.width(middleSpace + 3);
      cout << symbol[4];
    }

    return cout;
  }
}
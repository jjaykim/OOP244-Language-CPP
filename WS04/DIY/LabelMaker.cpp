//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop4_DIY
//==============================================
// LabelMaker.cpp

#include <iostream>
#include "LabelMaker.h"
#include "cstring.h"
using namespace std;

namespace sdds {
  LabelMaker::LabelMaker(int noOfLabels)
  {
    if (noOfLabels > 0) {
      totalLabels = noOfLabels;

      // creates a dynamic array of Labels to the size of noOfLabels
      listOfLabels = new Label[noOfLabels];
    }
    else {
      cout << "You can only input greater than zero" << endl;
      noOfLabels = 0;
    }
  }

  LabelMaker::~LabelMaker()
  {
    // Deallocates the memory and set to nullptr for safe
    delete[] listOfLabels;
    listOfLabels = nullptr;
  }

  void LabelMaker::readLabels()
  {
    if (totalLabels > 0) {
      cout << "Enter " << totalLabels << " labels:" << endl;

      for (int i = 0; i < totalLabels; i++) {
        cout << "Enter label number " << i + 1 << endl;
        listOfLabels[i].readLabel();
      }
    }
  }

  void LabelMaker::printLabels()
  {
    for (int i = 0; i < totalLabels; i++) {
      listOfLabels[i].printLabel();
      cout << endl;
    }
  }
}
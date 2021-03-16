//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop4_DIY
//==============================================
// LabelMaker.h

#ifndef SDDS_LABELMARKER_H_
#define SDDS_LABELMARKER_H_

#include "Label.h"

using namespace std;

namespace sdds {
  class LabelMaker
  {
    Label *listOfLabels;
    int totalLabels;

  public:
    // creates a dynamic array of Labels to the size of noOfLabels
    LabelMaker(int noOfLabels);

    // Deallocates the memory
    ~LabelMaker();

    // Gets the contents of the Labels
    void readLabels();

    // Prints the Labels
    void printLabels();
  };
}
#endif // !SDDS_LABELMARKER_H_
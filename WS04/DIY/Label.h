//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop4_DIY
//==============================================
// Label.h

#ifndef SDDS_LABEL_H_
#define SDDS_LABEL_H_
const char defaultSymbol[9] = "+-+|+-+|";

using namespace std;

namespace sdds {
  class Label
  {
    char symbol[9];
    char *oneLineText;

    // void setToDefault();

  public:
    // Creates an empty label and defaults the frame to defaultSymbol
    Label();

    // Creates an empty label and sets the frame to the frameArg argument
    Label(const char *frameArg);

    // Creates a Label with the frame set to frameArg
    // and the content of the Label set to the corresponding argument
    Label(const char *frmaeArg, const char *content);

    // Makes sure there is no memory leak when the label goes out of scope
    ~Label();

    // Reads the label from console up to 70 characters and stores it in the Label
    void readLabel();

    // Prints the label by drawing the frame around the content
    std::ostream &printLabel() const;
  };
}

#endif // !SDDS_LABEL_H_
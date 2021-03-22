// IOAble Tester:
// Version: 1.0
// Date: 2021-3-16
// Author: Fardad Soleimanloo
// Description:
// This file tests the IOAble Module of your project
/////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "Menu.h"
#include "IOAble.h"
using namespace std;
using namespace sdds;

class Box :public IOAble {
   int m_hieght, m_width;
public:
   bool csv;
   Box();
   ostream& csvWrite(std::ostream& ostr)const;
   istream& csvRead(std::istream& istr);
   ostream& write(ostream& ostr)const;
   istream& read(istream& istr);
   virtual ~Box();
};

void menuTester(Menu m);
void displayFile(const char* filename);
void IOAbleTester();

int main() {
   Menu m("Tester Options menu:\n1- Option one\n2- Option two\n3- Option three", 3);
   menuTester(m);
   IOAbleTester();
   return 0;
}

void IOAbleTester() {
   cout << "IOAble Tester ************************************" << endl;
   Box B;
   cout << "Getting information of an IOAble box from console: " << endl;
   cin >> B;
   cout << "Display the IOAble box on console: " << endl;
   cout << B << endl;
   B.csv = false;
   ifstream fboxes("boxes.txt");
   if (fboxes) {
      Box* Bp;
      ofstream bout("boxesOut.txt");
      B.csv = true;
      cout << "Saving " << B << " in the output file." << endl;
      bout << B << endl;
      cout << "Dynamically allocating a Box and holding it in an IOAble pointer..." << endl;
      IOAble* iop = Bp = new Box();
      cout << "Reading dimenstions from file using the IOAlbe pointer" << endl;;
      Bp->csv = true;
      fboxes >> *iop;
      cout << "Dimentions: " << endl;
      cout << *iop << endl;
      Bp->csv = false;
      cout << "What it looks like on screen:" << endl << *iop << endl;
      Bp->csv = true;
      cout << "Now save it in the file..." << endl;
      bout << *iop << endl;
      cout << "Reading the next dimenstions from file using the IOAble pointer" << endl;;
      fboxes >> *iop;
      cout << "Dimentions: " << endl;
      cout << *iop << endl;
      Bp->csv = false;
      cout << "What it looks like on screen:" << endl << *iop << endl;
      Bp->csv = true;
      cout << "Save this one in the output file too..." << endl;
      bout << *iop << endl;
      cout << "Close the file and display it..." << endl;
      bout.close();
      displayFile("boxesOut.txt");
      cout << "Removing the box from memory using the IOAble pointer..." << endl;
      delete Bp;
      bout.close();
   }
   else {
      cout << "Could not find the file \"boxes.txt\"." << endl;
   }
   cout << "Content of \"boxesOut.txt\" file" << endl;
   displayFile("boxesOut.txt");
}

/* Box *********************************************/
Box::Box() :m_hieght(0), m_width(0), csv(false) {
   cout << "defaulting Box" << endl;
};

ostream& Box::csvWrite(std::ostream& ostr)const {
   return ostr << m_hieght << "," << m_width;
}

istream& Box::csvRead(std::istream& istr) {
   istr >> m_hieght;
   istr.ignore();
   istr >> m_width;
   istr.ignore();
   return istr;
}

ostream& Box::write(ostream& ostr)const {
   if (csv) {
      csvWrite(ostr);
   }
   else {
      int i;
      for (int j = 0; j < m_hieght; j++) {
         for (i = 0; i < m_width * 2; i++, ostr << "*");
         ostr << endl;
      }
   }
   return ostr;
}

istream& Box::read(istream& istr) {
   if (csv) {
      csvRead(istr);
   }
   else {
      cout << "Height: ";
      istr >> m_hieght;
      cout << "Width: ";
      istr >> m_width;
   }
   return istr;
}

Box::~Box() {
   cout << "Box(" << m_hieght << "," << m_width << ") is gone!" << endl;
}

/* menuTester *********************************************/
void menuTester(Menu m) {
   cout << "Menu Tester **************************************" << endl;
   int selection;
   while (m >> selection) {
      switch (selection) {
      case 1:
         cout << "option one selected" << endl << endl;
         break;
      case 2:
         cout << "option two selected" << endl << endl;
         break;
      case 3:
         cout << "option three selected" << endl << endl;
         break;
      default:
         cout << "This will never happen!!!!" << endl;
         break;
      }
   }
   cout << "goodbye!" << endl;
}

/*  displayFile ***************************************/
void displayFile(const char* filename) {
   ifstream file(filename);
   cout << filename << "---------------------" << endl;
   char ch;
   while (file.get(ch) && cout << ch);
   cout << "---------------------------------" << endl;
}

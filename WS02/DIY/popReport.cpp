// Workshop 2:
// Version: 0.9
// Date: 2021/01/23
// Author: Fardad Soleimanloo
// Description:
// This file tests the DIY section of your workshop
// Do not modify your code
/////////////////////////////////////////////
#include "Population.h"
using namespace sdds;
int main() {
  if (load("PCpopulations.csv"))
  {
    display();
  }
   deallocateMemory();
   return 0;
}

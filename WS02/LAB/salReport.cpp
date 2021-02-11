// Workshop 2: 
// Version: 0.9
// Date: 2021/1/23
// Author: Fardad Soleimanloo
// Description:
// This file tests the lab section of your workshop
// Do not modify your code
/////////////////////////////////////////////
#include "Employee.h"
using namespace sdds;
int main() {
   if (load()) {
      display();
   }
   deallocateMemory();
   return 0;
}
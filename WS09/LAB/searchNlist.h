//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop9_LAB
//==============================================
// serchNlist.h

/*
==== Template type requirements ====
1. listArrayElements template function
  This function is a function that receives various types of arrays, titles, and number of arrays, and outputs them to the console.
  I can enter various types of arrays using <typename T> rather than one type of array.
  As CPP compiles, the template function determines the type of array received.
  The operator "<<" function of ReadWrite, which is an abstract base class, is called inside the function first.
  This is because Car, Employee and Student class are inherited from ReadWrite class.
  And then determines what the real object is and finally calls the display() function of the corresponding object.

2. search template function
  Collection is a template class. What is more surprising is that the Collection template class receives a Car or Student or Employee class as a type.
  Therefore, the collection and array use the same type name.
  The data was then added using the template member function defined in the template collection class.
  Also, key value is different type of from class to class, so I use another type name.
  As a result, as with the first template function, the types are determined during the compilation phase.
  Then, a "==" operator is called for each class to compare if it matches.
  If it matches, call the template function "add" in the Collection class to add the data.
*/

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

#include <iostream>
#include "Collection.h"
#include "Car.h"
#include "Student.h"
#include "Employee.h"

using namespace std;

namespace sdds
{
  // Using templates, receive different types of arrays
  template <typename T>
  void listArrayElements(const char *_title, const T *_arr, int _num) {
    cout << _title << endl;

    for (int i = 0; i < _num; i++) {
      cout << (i + 1) << ": ";
      // Call "<<" operator from the ReadWrite class that is abstract base class
      // and then compiler determines the actual object and Call the corresponding display()
      cout << _arr[i] << endl;
    }
  }

  // Receive the same typename in Collection and array
  // because to add the searched array to Collection
  // and use another typename to receive different key value
  template <typename T1, typename T2>
  bool search(Collection<T1> &_obj, const T1 *_arr, int _num, T2 _key) {
    bool result = false;

    for (int i = 0; i < _num; i++) {
      if (_arr[i] == _key) { // Call "==" operator corresponding to each type
        _obj.add(_arr[i]);   // Call the template function "add" in Collection template class
        result = true;
      }
    }
    return result;
  }
}
#endif // !SDDS_SEARCHNLIST_H_

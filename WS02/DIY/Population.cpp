//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop2_DIY
//==============================================
// Population.cpp

#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"

using namespace std;

namespace sdds
{
  // Global variables:
  int noOfPost;
  int noOfPopul;
  PostalCode *postcode;

  // Insertion sort
  // select key values in each loop and insert key value elements in the appropriate location
  // by comparing them with the elements on the left side of the key values.
  void sort()
  {
    int i , j;
    PostalCode key;

    for (i = 1; i < noOfPost; i++) {
      key = postcode[i];

      for (j = i - 1; j >= 0 && postcode[j].population > key.population; j--) {
        postcode[j + 1] = postcode[j];
      }

      postcode[j + 1] = key;
    }
  }

  // reads one Postalcode record from the file
  bool load(PostalCode &post)
  {
    bool check = false;
    char code[7];

    // if reading of postalcode and population are successful
    if (read(code) && read(post.population)) {

      // allocate memory to the size of the postalcode + 1
      post.code = new char[strLen(code) + 1];

      // copy the postalcode into the newly allocated memroy
      strCpy(post.code, code);

      check = true;
    }

    return check;
  }

  bool load(const char filename[])
  {
    bool check = false;
    int i = 0;

    if (openFile(filename)) {
      noOfPost = noOfRecords();

      // dynamically allocated the size of the noOfPost to Postalcode pointer
      postcode = new PostalCode[noOfPost];

      //  In a loop load the postalcode records from the file into the dynamic array.
      for (int j = 0; j < noOfPost; j++) {
        i += load(postcode[j]);
      }

      // If the number of the records does not match the number of reads print the message
      if (i != noOfPost)
      {
        cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
      }
      else {
        check = true;
      }

      closeFile();
    }
    else {
      cout << "Could not open data file: " << filename << endl;
    }

    return check;
  }

  void display(const PostalCode &code)
  {
    cout << code.code << ":  " << code.population << endl;
  }

  void display()
  {
    cout << "Postal Code: population" << endl;
    cout << "-------------------------" << endl;

    sort();

    for (int i = 0; i < noOfPost; i++) {
      cout << i + 1 << "- ";
      display(postcode[i]);
      noOfPopul += postcode[i].population;
    }

    cout << "-------------------------" << endl;
    cout << "Population of Canada: " << noOfPopul << endl;
  }

  void deallocateMemory()
  {
   // Firstly, delete the postalcode of each struct which memory was allocated
   for (int i = 0; i < noOfPost; i++) {
      delete[] postcode[i].code;
      postcode[i].code = nullptr;
    }

    // Lastly, delete the Postalcode pointer which memory was allocated
    delete[] postcode;
    postcode = nullptr;
  }
} // namespace sdds

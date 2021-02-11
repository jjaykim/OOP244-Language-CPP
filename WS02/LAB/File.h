//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop2_LAB
//==============================================
// File.h

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds {

  // openFile: Opens the data file for reading
  bool openFile(const char filename[]);

  // closeFile: Closes the data file
  void closeFile();

  // noOfRecords: Returns an integer that is the number of recoreds in the file
  int noOfRecords();

  // TODO: Declare read prototypes

  // Reads the name of the employee | Accepts as a parameter the address of an array of characters
  bool read(char *empName);

  // Reads employee number | Accepts as a parameter a reference to an integer
  bool read(int &empNumber);

  // Reads the employee salary | Acceptes as a parameter a reference to an floating point number
  // in double precision
  bool read(double &empSalary);
} // namespace sdds
#endif // !SDDS_FILE_H_

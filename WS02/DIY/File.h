//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop2_DIY
//==============================================
// File.h

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds
{
  bool openFile(const char filename[]);
  void closeFile();
  int noOfRecords();

  // Create Functions:
  bool read(char *code);
  bool read(int &population);

} // namespace sdds
#endif // !SDDS_FILE_H_

//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop2_DIY
//==============================================
// Population.h

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds
{
  struct PostalCode
  {
    char *code;
    int population;
  };

  // Create Functions:
  void sort();
  bool load(const char filename[]);
  bool load(PostalCode &post);
  void display(const PostalCode &code);
  void display();
  void deallocateMemory();

} // namespace sdds
#endif // SDDS_POPULATION_H_
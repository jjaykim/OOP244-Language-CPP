//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop6_DIY
//==============================================
// Stats.h

#ifndef SDDS_STATS_H_
#define SDDS_STATS_H_

#include <iostream>
namespace sdds
{
  const char m_prefix[3] = "C_";

  enum Sort
  {
    NON_SORT,
    ASC_ORDER,
    DESC_ORDER
  };

  class Stats
  {
    unsigned m_columnWidth;
    unsigned m_noOfColumns;
    unsigned m_precision;
    unsigned m_noOfList;
    unsigned m_sort;
    char     *m_filename{nullptr};
    double   *m_eachValue{nullptr};

    void setNoOfList();
    void loadValue();
    void saveAs(const char *main_fName, const char *sub_fName) const;

  public:
    Stats(unsigned _colWidth = 15, unsigned _numCol = 4, unsigned _precision = 2);
    Stats(const char *_filename, unsigned _colWidth = 15, unsigned _numCol = 4, unsigned _precision = 2);
    Stats(const Stats &src);
    Stats &operator=(const Stats &src);
    ~Stats();

    operator bool() const;
    double &operator[](unsigned idx);
    double operator[](unsigned idx) const;
    unsigned size() const;
    const char *name() const;
    std::ostream &display(std::ostream &ostr) const;

    unsigned occurrence(double min, double max, std::ostream &ostr = std::cout) const;
    // void sort(const char *str, const unsigned _colWidth, const unsigned _precision) const;
    void sort(const bool ascending);
    std::istream &getFile(std::istream &istr);

  };
  std::istream &operator>>(std::istream &istr, Stats &src);
  std::ostream &operator<<(std::ostream &ostr, const Stats &src);
}
#endif
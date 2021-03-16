//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop3_DIY
//==============================================

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {
  class Food {
    char m_foodName[31];
    int m_calNum;
    int m_timeOfConsum; // 1: Breakfast 2: Lunch 3: Dinner 4: Snack

  public:
    Food(); // set empty
    ~Food();

    void set(const char *name, int cal, int time);
    bool isValid() const;
    int calorie() const;
    void display() const;
    void display(const char *name) const;
    void display(int time) const;

  };
}
#endif
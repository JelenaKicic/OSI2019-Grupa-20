class Date
{
  private:
    int day;
    int month;
    int year;

  public:
    Date();
    Date(int, int, int);
    int getDate();
    void printDate();
    void setDate(int, int, int);
};

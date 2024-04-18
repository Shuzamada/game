#include <string>

class Field
{
  public:
    void draw(char x, char y, bool c);
    bool check(char x, char y);
    void move(std::string str);
    void drop();
  private:
    bool field[16][20][2] = {};
};

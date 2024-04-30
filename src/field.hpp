#ifndef FIELD_HPP
#define FIELD_HPP

#include <string>

class Field
{
  public:
    void draw(char x, char y, bool c);
    bool checkLight(char x, char y);
    bool checkMoveable(char x, char y);
    void move(std::string str);
    void fall(int angle);
  //private:
    bool field[16][20][2] = {};
    void clear();
    char length = 16;
    char height = 20;
};

#endif

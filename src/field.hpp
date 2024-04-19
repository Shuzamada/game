#ifndef FIELD_HPP
#define FIELD_HPP

#include <string>

class Field
{
  public:
    void draw(char x, char y, bool c);
    bool checkLight(char x, char y);
    void move(std::string str);
    void fall();
  private:
    void checkBlock();
    void block();
    void spawnNew();
    bool field[16][20][2] = {};
};

#endif

#ifndef FIELD_HPP
#define FIELD_HPP

#include "Arduino.h"

class Field
{
  public:
    void draw(char x, char y, bool c);
    bool checkLight(char x, char y) const;
    void move(String str);
    void fall();
    void rotate();
    void spawnNew();
  private:
    void checkBlock();
    void block();
    bool field[16][20][2] = {};
    char identifyShape();
    void clear();
    char cur_shape = 'J';
    int cur_shape_centre[2] = {};
    char cur_rotate_phase = 0;
};

#endif

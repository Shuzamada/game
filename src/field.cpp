#include "field.hpp"
#include <string>
#include <iostream>

void Field::draw(char x, char y, bool c)
{
  field[x][y][0] = c;
}

bool Field::check(char x, char y)
{
  return field[x][y][0];
}

void Field::move(std::string str)
{
  if (str == "left")
  {
    for (int i = 0; i < 16; i++)
    {
      for (int j = 0; j < 20; j++)
      {
        if (field[i][j][0])
        {
          if (i != 0 && !field[i-1][j][0])
          {
          field[i-1][j][0] = 1;
          field[i][j][0] = 0;
          }
        }
      }
    }
  }
  else if (str == "right")
  {
    for (int i = 0; i < 16; i++)
    {
      bool need_break = false;
      for (int j = 0; j < 20; j++)
      {
        if (field[i][j][0])
        {
          if (i != 15 && !field[i+1][j][0])
          {
            field[i+1][j][0] = 1;
            field[i][j][0] = 0;
            need_break = true;
          }
        }
      }
    }
  }
  else if (str == "down")
  {
    for (int i = 0; i < 16; i++)
    {
      for (int j = 0; j < 20; j++)
      {
        if (field[i][j][0] == 1)
        {
          if (j != 19 && !field[i][j+1][0])
          {
            field[i][j+1][0] = 1;
            field[i][j][0] = 0;
            break;
          }
        }
      }
    }
  }
  else if (str == "up")
  {
    for (int i = 0; i < 16; i++)
    {
      for (int j = 0; j < 20; j++)
      {
        if (field[i][j][0])
        {
          if (j != 0 && !field[i][j-1][0])
          {
          field[i][j-1][0] = 1;
          field[i][j][0] = 0;
          }
        }
      }
    }
  }
}
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
    for (int i = 1; i < 16; i++)
    {
      for (int j = 0; j < 20; j++)
      {
        if (field[i][j][0] && !field[i-1][j][0])
        {
          field[i-1][j][0] = 1;
          field[i][j][0] = 0;
        }
      }
    }
  }
  else if (str == "right")
  {
    for (int i = 14; i >= 0; i--)
    {
      for (int j = 0; j < 20; j++)
      {
        if (field[i][j][0] && !field[i+1][j][0])
        {
          field[i+1][j][0] = 1;
          field[i][j][0] = 0;
        }
      }
    }
  }
  else if (str == "down")
  {
    for (int i = 0; i < 16; i++)
    {
      for (int j = 18; j >= 0; j--)
      {
        if (field[i][j][0] && !field[i][j+1][0])
        {
          field[i][j+1][0] = 1;
          field[i][j][0] = 0;
        }
      }
    }
  }
  else if (str == "up")
  {
    for (int i = 0; i < 16; i++)
    {
      for (int j = 1; j < 20; j++)
      {
        if (field[i][j][0] && !field[i][j-1][0])
        {
          field[i][j-1][0] = 1;
          field[i][j][0] = 0;
        }
      }
    }
  }
}
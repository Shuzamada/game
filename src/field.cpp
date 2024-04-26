#include "field.hpp"
#include <string>
#include <iostream>
#include <ctime>

void Field::draw(char x, char y, bool c)
{
  field[x][y][0] = c;
  field[x][y][1] = c;
}

bool Field::checkLight(char x, char y)
{
  return field[x][y][0];
}

void Field::move(std::string str)
{
  if (str == "left")
  {
    for (char j = 0; j < 20; j++)
    {
      for (char i = 15; i > 0; i--)
      {
        if (field[i][j][1] && !field[i-1][j][0] && !field[i-1][j][1])
        {
          field[i-1][j][0] = 1;
          field[i][j][0] = 0;
          field[i-1][j][1] = 1;
          field[i][j][1] = 0;
          i--;
        }
      }
    }
  }
  else if (str == "right")
  {
    for (char j = 0; j < 20; j++)
    {
      for (char i = 0; i < 15; i++)
      {
        if (field[i][j][1] && !field[i+1][j][0] && !field[i+1][j][1])
        {
          field[i+1][j][0] = 1;
          field[i][j][0] = 0;
          field[i+1][j][1] = 1;
          field[i][j][1] = 0;
          i++;
        }
      }
    }
  }
  else if (str == "down")
  {
    for (char i = 0; i < 16; i++)
    {
      for (char j = 0; j < 19; j++)
      {
        if (field[i][j][1] && !field[i][j+1][0] && !field[i][j+1][1])
        {
          field[i][j+1][0] = 1;
          field[i][j][0] = 0;
          field[i][j+1][1] = 1;
          field[i][j][1] = 0;
          j++;
        }
      }
    }
  }
  else if (str == "up")
  {
    for (char i = 0; i < 16; i++)
    {
      for (char j = 19; j > 0; j--)
      {
        if (field[i][j][1] && !field[i][j-1][0] && !field[i][j-1][1])
        {
          field[i][j-1][0] = 1;
          field[i][j-1][1] = 1;
          field[i][j][0] = 0;
          field[i][j][1] = 0;
          j--;
        }
      }
    }
  }
  else if (str == "down_left")
  {
    for (char i = 1; i < 16; i++)
    {
      for (char j = 0; j < 19; j++)
      {
        if (field[i][j][1] && !field[i-1][j+1][0] && !field[i-1][j+1][1] && field[i][j+1][1])
        {
          field[i-1][j+1][0] = 1;
          field[i][j][0] = 0;
          field[i-1][j+1][1] = 1;
          field[i][j][1] = 0;
          j++;
          i--;
        }
      }
    }
  }
  else if (str == "down_right")
  {
    for (char i = 0; i < 15; i++)
    {
      for (char j = 0; j < 19; j++)
      {
        if (field[i][j][1] && !field[i+1][j+1][0] && !field[i+1][j+1][1] && field[i][j+1][1])
        {
          field[i+1][j+1][0] = 1;
          field[i][j][0] = 0;
          field[i+1][j+1][1] = 1;
          field[i][j][1] = 0;
          j++;
          i++;
        }
      }
    }
  }
}

void Field::fall()
{
  move("down");
  move("down_left");
  move("down_right");
}


void Field::clear()
{
  for (char y = 0; y < 20; y++)
  {
    bool need_clear = true;
    for (char x = 0; x < 16; x++)
    {
      if (!field[x][y][0])
      {
        need_clear = false;
        break;
      }
    }
    if (need_clear)
    {
      for (char i = y; i > 0; i--)
      {
        for (char j = 0; j < 16; j++)
        {
          field[j][i][0] = field[j][i-1][0];
        }
      }
    }
  }
}
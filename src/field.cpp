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
    for (char i = 1; i < 16; i++)
    {
      for (char j = 0; j < 20; j++)
      {
        if (field[i][j][1] && field[i-1][j][0])
        {
          break;
        }
        if (field[i][j][1] && !field[i-1][j][0])
        {
          bool can_move_left = true;
          for (char l = 0; l < 20; l++)
          {
            if (field[i][l][1] && field[i-1][l][0])
            {
              can_move_left = false;
              break;
            }
          }
          if (!can_move_left)
          {
            break;
          }
          field[i-1][j][0] = 1;
          field[i][j][0] = 0;
          field[i-1][j][1] = 1;
          field[i][j][1] = 0;
        }
      }
    }
  }
  else if (str == "right")
  {
    for (char i = 14; i >= 0; i--)
    {
      for (char j = 0; j < 20; j++)
      {
        if (field[i][j][1] && field[i+1][j][0])
        {
          break;
        }
        if (field[i][j][1] && !field[i+1][j][0])
        {
          bool can_move_right = true;
          for (char l = 0; l < 20; l++)
          {
            if (field[i][l][1] && field[i+1][l][0])
            {
              can_move_right = false;
              break;
            }
          }
          if (!can_move_right)
          {
            break;
          }
          field[i+1][j][0] = 1;
          field[i][j][0] = 0;
          field[i+1][j][1] = 1;
          field[i][j][1] = 0;
        }
      }
    }
  }
  else if (str == "down")
  {
    for (char i = 0; i < 16; i++)
    {
      for (char j = 18; j >= 0; j--)
      {
        if (field[i][j][1] && !field[i][j+1][0])
        {
          field[i][j+1][0] = 1;
          field[i][j][0] = 0;
          field[i][j+1][1] = 1;
          field[i][j][1] = 0;
        }
      }
    }
  }
  else if (str == "up")
  {
    for (char i = 0; i < 16; i++)
    {
      for (char j = 1; j < 20; j++)
      {
        if (field[i][j][0] && field[i][j][1] && !field[i][j-1][0])
        {
          field[i][j-1][0] = 1;
          field[i][j][0] = 0;
          field[i][j-1][1] = 1;
          field[i][j][1] = 0;
        }
      }
    }
  }
  checkBlock();
}

void Field::fall()
{
  move("down");
  checkBlock();
}

void Field::checkBlock()
{
  bool blocked = false;
  for (int i = 0; i < 16; i++)
  {
    for (int j = 1; j < 20; j++)
    {
      if (field[i][j][1] && j == 19)
      {
        block();
        blocked = true;
      }
      else if (field[i][j][1] && field[i][j+1][0] && !field[i][j+1][1])
      {
        block();
        blocked = true;
      }
    }
  }
  if (blocked)
  {
    spawnNew();
  }
}

void Field::block()
{
  for (int i = 0; i < 16; i++)
  {
    for (int j = 1; j < 20; j++)
    {
      field[i][j][1] = 0;
    }
  }
}
  // f.draw(4, 3, 1);
  // f.draw(4, 4, 1);
  // f.draw(5, 4, 1);
  // f.draw(6, 4, 1);
void Field::spawnNew()
{
  time_t t = std::time(0);
  if (t % 3 == 0)
  {
    draw(6, 1, 1);
    draw(7, 1, 1);
    draw(8, 1, 1);
    draw(9, 1, 1);
    last_spawned_shape_ = 'I';
  }
  else if (t % 3 == 1)
  {
    draw(7, 0, 1);
    draw(7, 1, 1);
    draw(8, 1, 1);
    draw(9, 1, 1);
    last_spawned_shape_ = 'J';
  }
  else if (t % 3 == 2)
  {
    draw(7, 0, 1);
    draw(7, 1, 1);
    draw(7, 2, 1);
    draw(8, 2, 1);
    last_spawned_shape_ = 'L';
  }
}

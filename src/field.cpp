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
  cur_rotate_phase = 0;
  if (t % 7 == 0)
  {
    draw(6, 3, 1);
    draw(7, 3, 1);
    draw(8, 3, 1);
    draw(9, 3, 1);
    cur_shape = 'I';
    cur_shape_centre[0] = 0;
    cur_shape_centre[1] = 0;
  }
  else if (t % 7 == 1)
  {
    draw(7, 2, 1);
    draw(7, 3, 1);
    draw(8, 3, 1);
    draw(9, 3, 1);
    cur_shape = 'J';
    cur_shape_centre[0] = 8;
    cur_shape_centre[1] = 3;
  }
  else if (t % 7 == 2)
  {
    draw(6, 3, 1);
    draw(7, 3, 1);
    draw(8, 3, 1);
    draw(8, 2, 1);
    cur_shape = 'L';
    cur_shape_centre[0] = 8;
    cur_shape_centre[1] = 3;
  }
  else if (t % 7 == 3)
  {
    draw(7, 3, 1);
    draw(7, 2, 1);
    draw(8, 3, 1);
    draw(8, 2, 1);
    cur_shape = 'O';
    cur_shape_centre[0] = 0;
    cur_shape_centre[1] = 0;
  }
  else if (t % 7 == 4)
  {
    draw(7, 2, 1);
    draw(8, 2, 1);
    draw(7, 3, 1);
    draw(6, 3, 1);
    cur_shape = 'S';
    cur_shape_centre[0] = 7;
    cur_shape_centre[1] = 3;
  }
  else if (t % 7 == 5)
  {
    draw(6, 2, 1);
    draw(7, 2, 1);
    draw(8, 2, 1);
    draw(7, 3, 1);
    cur_shape = 'T';
    cur_shape_centre[0] = 7;
    cur_shape_centre[1] = 2;
  }
  else if (t % 7 == 6)
  {
    draw(6, 2, 1);
    draw(7, 2, 1);
    draw(7, 3, 1);
    draw(8, 3, 1);
    cur_shape = 'Z';
    cur_shape_centre[0] = 7;
    cur_shape_centre[1] = 3;
  }
}

void Field::rotate()
{
  if (cur_shape == 'J')
  {

  }
}
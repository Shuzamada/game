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
  bool moved = false;
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
          if (!moved)
          {
            cur_shape_centre[0]--;
          }
          moved = true;
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
          if (!moved)
          {
            cur_shape_centre[0]++;
          }
          moved = true;
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
          if (!moved)
          {
            cur_shape_centre[1]++;
          }
          moved = true;
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
          field[i][j-1][1] = 1;
          field[i][j][0] = 0;
          field[i][j][1] = 0;
          if (!moved)
          {
            cur_shape_centre[1]--;
          }
          moved = true;
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
  clear();
  time_t t = std::time(0);
  if (t % 7 == 0)
  {
    draw(6, 3, 1);
    draw(7, 3, 1);
    draw(8, 3, 1);
    draw(9, 3, 1);
    cur_shape = 'I';
    cur_rotate_phase = 0;
    cur_shape_centre[0] = 7;
    cur_shape_centre[1] = 3;
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
    cur_shape_centre[0] = 7;
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
  if (cur_shape == 'O')
  {
    return;
  }

  char x = cur_shape_centre[0];
  char y = cur_shape_centre[1];
  if (cur_shape == 'I')
  {
    if (cur_rotate_phase == 0)
    {
      if (!field[x][y+1][0] && !field[x][y+2][0] && y < 18)
      {
        draw(x, y+1, 1);
        draw(x, y+2, 1);
        draw(x, y-1, 1);
        draw(x+1, y, 0);
        draw(x+2, y, 0);
        draw(x-1, y, 0);
        cur_rotate_phase = 1;
      }
    }
    else if (cur_rotate_phase == 1)
    {
      if (!field[x+1][y][0] && !field[x+2][y][0] && x > 1 && x < 15)
      {
        draw(x-1, y, 1);
        draw(x-2, y, 1);
        draw(x+1, y, 1);
        draw(x, y+1, 0);
        draw(x, y+2, 0);
        draw(x, y-1, 0);
        cur_rotate_phase = 2;
      }
    }
    else if (cur_rotate_phase == 2)
    {
      if (!field[x][y-1][0] && !field[x][y-2][0] && y < 19)
      {
        draw(x, y-1, 1);
        draw(x, y-2, 1);
        draw(x, y+1, 1);
        draw(x-1, y, 0);
        draw(x-2, y, 0);
        draw(x+1, y, 0);
        cur_rotate_phase = 3;
      }
    }
    else if (cur_rotate_phase == 3)
    {
      if (!field[x+1][y][0] && !field[x+2][y][0] && x < 14 && x > 0)
      {
        draw(x+1, y, 1);
        draw(x+2, y, 1);
        draw(x-1, y, 1);
        draw(x, y-1, 0);
        draw(x, y-2, 0);
        draw(x, y+1, 0);
        cur_rotate_phase = 0;
      }
    }
    return;
  }
  else
  {
    if (x != 0 && x != 15)
    {
      char count_movable = 0;
      for (char i = 0; i < 3; i++)
      {
        for (char j = 0; j < 3; j++)
        {
          count_movable += field[x+i-1][y+j-1][0];
        }
      }
      if (count_movable != 4)
      {
        return;
      }
      for (char i = 0; i < 2; i++)
      {
        bool temp_x = field[x-1][y][0];
        bool temp_y = field[x-1][y][1];
        field[x-1][y][0] = field[x-1][y+1][0];
        field[x-1][y][1] = field[x-1][y+1][1];
        field[x-1][y+1][0] = field[x][y+1][0];
        field[x-1][y+1][1] = field[x][y+1][1];
        field[x][y+1][0] = field[x+1][y+1][0];
        field[x][y+1][1] = field[x+1][y+1][1];
        field[x+1][y+1][0] = field[x+1][y][0];
        field[x+1][y+1][1] = field[x+1][y][1];
        field[x+1][y][0] = field[x+1][y-1][0];
        field[x+1][y][1] = field[x+1][y-1][1];
        field[x+1][y-1][0] = field[x][y-1][0];
        field[x+1][y-1][1] = field[x][y-1][1];
        field[x][y-1][0] = field[x-1][y-1][0];
        field[x][y-1][1] = field[x-1][y-1][1];
        field[x-1][y-1][0] = temp_x;
        field[x-1][y-1][1] = temp_y;
      }
    }
  }
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
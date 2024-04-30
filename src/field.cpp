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
  if (x >= length or y >= height or x < 0 or y < 0)
  {
    return true;
  }
  return field[x][y][0];
}

bool Field::checkMoveable(char x, char y)
{
  if (x >= length or y >= height or x < 0 or y < 0)
  {
    return false;
  }
  return field[x][y][1];
}

void Field::move(std::string str)
{
  // if (str == "left")
  // {
  //   for (char j = 0; j < 20; j++)
  //   {
  //     for (char i = 15; i > 0; i--)
  //     {
  //         std::cout << str << " " << int(i) << " " << int(j) <<'\n';
  //       if (field[i][j][1] && !field[i-1][j][0] && !field[i-1][j][1])
  //       {
  //         field[i-1][j][0] = 1;
  //         field[i][j][0] = 0;
  //         field[i-1][j][1] = 1;
  //         field[i][j][1] = 0;
  //         i--;
  //       }
  //     }
  //   }
  // }
  // else if (str == "right")
  // {
  //   for (char j = 0; j < 19; j++)
  //   {
  //     for (char i = 0; i < 15; i++)
  //     {
  //       std::cout << str << " " << int(i) << " " << int(j) << field[i][j][1] << !field[i+1][j][0] << !field[i+1][j][1] <<'\n' ;
  //       if (field[i][j][1] && !field[i+1][j][0] && !field[i+1][j][1]) 
  //       {
  //         std::cout << "wtf1";
  //         field[i+1][j][0] = 1;
  //         field[i][j][0] = 0;
  //         field[i+1][j][1] = 1;
  //         field[i][j][1] = 0;
  //         if (i == 14 || i == 15)
  //         {
  //           break;
  //         }
  //         i++;
  //       }
  //     }
  //   }
  // }
  // else if (str == "down")
  // {
  //   for (char i = 0; i < 16; i++)
  //   {
  //     for (char j = 0; j < 19; j++)
  //     {
  //         std::cout << str << " " << int(i) << " " << int(j) <<'\n';
  //       if (field[i][j][1] && !field[i][j+1][0] && !field[i][j+1][1])
  //       {
  //         field[i][j+1][0] = 1;
  //         field[i][j][0] = 0;
  //         field[i][j+1][1] = 1;
  //         field[i][j][1] = 0;
  //         j++;
  //       }
  //     }
  //   }
  // }
  // else if (str == "up")
  // {
  //   for (char i = 0; i < 16; i++)
  //   {
  //     for (char j = 19; j > 0; j--)
  //     {
  //         std::cout << str << " " << int(i) << " " << int(j) <<'\n';
  //       if (field[i][j][1] && !field[i][j-1][0] && !field[i][j-1][1])
  //       {
  //         field[i][j-1][0] = 1;
  //         field[i][j-1][1] = 1;
  //         field[i][j][0] = 0;
  //         field[i][j][1] = 0;
  //         if (j!=0)
  //         j--;
  //       }
  //     }
  //   }
  // }
  // else if (str == "down_left")
  // {
  //   for (char i = 1; i < 16; i++)
  //   {
  //     for (char j = 0; j < 19; j++)
  //     {
  //       if (i == 0)
  //       {
  //         break;
  //       }
  //         std::cout << str << " " << int(i) << " " << int(j) <<'\n';
  //       if (field[i][j][1] && !field[i-1][j+1][0] && !field[i-1][j+1][1] && field[i][j+1][1])
  //       {
  //         field[i-1][j+1][0] = 1;
  //         field[i][j][0] = 0;
  //         field[i-1][j+1][1] = 1;
  //         field[i][j][1] = 0;
  //         if (j!=19)
  //         j++;
  //         if (i!=0)
  //         i--;
  //       }
  //     }
  //   }
  // }
  // else if (str == "down_right")
  // {
  //   for (char i = 0; i < 15; i++)
  //   {
  //     for (char j = 0; j < 19; j++)
  //     {
  //       if (i == 15)
  //       {
  //         break;
  //       }
  //         std::cout << str << " " << int(i) << " " << int(j) <<'\n';
  //       if (field[i][j][1] && !field[i+1][j+1][0] && !field[i+1][j+1][1] && field[i][j+1][1])
  //       {
  //         field[i+1][j+1][0] = 1;
  //         field[i][j][0] = 0;
  //         field[i+1][j+1][1] = 1;
  //         field[i][j][1] = 0;
  //         if (j!=19)
  //         j++;
  //         if (i!=15)
  //         i++;
  //       }
  //     }
  //   }
  // }
  // else if (str == "up_left")
  // {
  //   for (char i = 1; i < 16; i++)
  //   {
  //     for (char j = 19; j > 1; j--)
  //     {
  //         std::cout << str << " " << int(i) << " " << int(j) <<'\n';
  //       if (field[i][j][1] && !field[i-1][j-1][0] && !field[i-1][j-1][1] && (field[i][j-1][1] || field[i-1][j][1]))
  //       {
  //         field[i-1][j-1][0] = 1;
  //         field[i][j][0] = 0;
  //         field[i-1][j-1][1] = 1;
  //         field[i][j][1] = 0;
  //         if (j!=0)
  //         j--;
  //         if (i!=0)
  //         i--;
  //       }
  //     }
  //   }
  // }
  // else if (str == "up_right")
  // {
  //   for (char i = 0; i < 14 ; i++)
  //   {
  //     for (char j = 19; j > 1; j--)
  //     {
  //         std::cout << str << " " << int(i) << " " << int(j) <<'\n';
  //       if (field[i][j][1] && !field[i+1][j-1][0] && !field[i+1][j-1][1] && (field[i][j-1][1] || field[i+1][j][1]))
  //       {
  //         field[i+1][j-1][0] = 1;
  //         field[i][j][0] = 0;
  //         field[i+1][j-1][1] = 1;
  //         field[i][j][1] = 0;
  //         if (j!=0)
  //         j--;
  //         if (i!=15)
  //         i++;
  //       }
  //     }
  //   }
  // }
  if (str == "down")
  {
    for (char i = 0; i < length; i++)
    {
      for (char j = 0; j < height - 1; j++)
      {
        std::cout << str << " " << int(i) << " " << int(j) <<'\n';
        if (checkMoveable(i, j) && !checkLight(i, j + 1) && !checkMoveable(i, j + 1))
        {
          draw(i, j, 0);
          draw(i, j + 1, 1);
          j++;
        }
      }
    }
  }
  else if (str == "left")
  {
    for (char j = 0; j < height; j++)
    {
      for (char i = length - 1; i > 0; i--)
      {
        std::cout << str << " " << int(i) << " " << int(j) <<'\n';
        if (checkMoveable(i, j) && !checkLight(i - 1, j) && !checkMoveable(i - 1, j))
        {
          draw(i, j, 0);
          draw(i - 1, j, 1);
          i--;
        }
      }
    }
  }
  else if (str == "right")
  {
    for (char j = 0; j < height; j++)
    {
      for (char i = 0 ; i < length - 1; i++)
      {
        std::cout << str << " " << int(i) << " " << int(j) <<'\n';
        if (checkMoveable(i, j) && !checkLight(i + 1, j) && !checkMoveable(i + 1, j))
        {
          draw(i, j, 0);
          draw(i + 1, j, 1);
          i++;
        }
      }
    }
  }
  else if (str == "up")
  {
    for (char i = 0; i < length; i++)
    {
      for (char j = height - 1; j > 0 ; j--)
      {
        std::cout << str << " " << int(i) << " " << int(j) <<'\n';
        if (checkMoveable(i, j) && !checkLight(i, j - 1) && !checkMoveable(i, j - 1))
        {
          draw(i, j, 0);
          draw(i, j - 1, 1);
          j--;
        }
      }
    }
  }
}

void Field::fall(int angle)
{
  if (angle < 225 && angle > 135)
  {
    move("down");
    move("down_left");
    move("down_right");
  }
  else if (angle < 270 && angle > 180)
  {
    move("down_left");
    move("down");
    move("left");
  }
  else if (angle < 315 && angle > 225)
  {
    move("left");
    move("down_left");
    move("up_left");
  }
  else if (angle < 360 && angle > 270)
  {
    move("up_left");
    move("up");
    move("left");
  }
  else if (angle < 90 && angle > 0)
  {
    move("up_right");
    move("up");
    move("right");
  }
  else if (angle < 135 && angle > 45)
  {
    move("right");
    move("up_right");
    move("down_right");

  }
  else if (angle < 180 && angle > 90)
  {
    move("down_right");
    move("down");
    move("right");
  }
  else
  {
    move("up");
    move("up_left");
    move("up_right");
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
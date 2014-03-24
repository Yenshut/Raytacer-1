/*
** rotate.c for rtv1 in /home/garcin_s/rendu/MUL_2013_rtv1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Mon Mar 10 18:06:48 2014 garcin_s
** Last update Tue Mar 11 14:35:44 2014 garcin_s
*/

#include "my.h"

void            rotate_z(double *x, double *y, double *z, double a)
{
  double        tmpx;
  double        tmpy;
  double        tmpz;

  if (a != 0.0)
    {
      a = (a * 3.141592654 ) / 180;
      tmpx = ((*x) * cos(a)) + ((*y) * -sin(a)) + ((*z) * 0.0);
      tmpy = ((*x) * sin(a)) + ((*y) * cos(a)) + ((*z) * 0.0);
      tmpz = ((*x) * 0.0) + ((*y) * 0.0) + ((*z) * 1.0);
      *x = tmpx;
      *y = tmpy;
      *z = tmpz;
    }
}

void            rotate_y(double *x, double *y, double *z, double a)
{
  double        tmpx;
  double        tmpy;
  double        tmpz;

  if (a != 0.0)
    {
      a = (a * 3.141592654 ) / 180;
      tmpx = ((*x) * cos(a)) + ((*y) * 0.0) + ((*z) * sin(a));
      tmpy = ((*x) * 0.0) + ((*y) * 1.0) + ((*z) * 0.0);
      tmpz = ((*x) * -sin(a)) + ((*y) * 0.0) + ((*z) * cos(a));
      *x = tmpx;
      *y = tmpy;
      *z = tmpz;
    }
}

void            rotate_x(double *x, double *y, double *z, double a)
{
  double        tmpx;
  double        tmpy;
  double        tmpz;

  if (a != 0.0)
    {
      a = (a * 3.141592654 ) / 180;
      tmpx = ((*x) * 1.0) + ((*y) * 0.0) + ((*z) * 0.0);
      tmpy = ((*x) * 0.0) + ((*y) * cos(a)) + ((*z) * -sin(a));
      tmpz = ((*x) * 0.0) + ((*y) * sin(a)) + ((*z) * cos(a));
      *x = tmpx;
      *y = tmpy;
      *z = tmpz;
    }
}

void            rotate(t_obj *vec, int x, int y, int z)
{
  rotate_z(&vec->x, &vec->y, &vec->z, z);
  rotate_y(&vec->x, &vec->y, &vec->z, y);
  rotate_x(&vec->x, &vec->y, &vec->z, x);
}

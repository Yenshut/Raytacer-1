/*
** light.c for rtv1 in /home/garcin_s/rendu/MUL_2013_rtv1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Tue Mar 11 08:46:01 2014 garcin_s
** Last update Sat Mar 22 16:23:56 2014 garcin_s
*/

#include "my.h"

int		light_sph(int color, double k, t_obj *vec)
{
  return (color);
}

int		luminosite_plan(int color, double k, t_obj *vec)
{
  double	cosi;
  t_obj		inter;
  t_obj		light;
  t_obj		normal;
  int		new_r;
  int		new_b;
  int		new_v;

  inter.x = -900 + k * vec->x;
  inter.y = 0 + k * vec->y;
  inter.z = 150 + k * vec->z;
  light.x = 0 - inter.x;
  light.y = 0 - inter.y;
  light.z = 500 - inter.z;
  normal.x = ((0 * light.x) + (0 * light.y) + (100 * light.z));
  normal.y = sqrt(POW(light.x) + POW(light.y) + POW(light.z));
  normal.z = sqrt(POW(0) + POW(0) + POW(100));
  cosi = normal.x / (normal.y * normal.z);
  cosi -= (sqrt(POW(light.x) + POW(light.y) + POW(light.z)) / 1000.000) / 2.3 ;
  if (cosi < 0)
    return (0);
  new_r = (int)(((double)((color >> 16) & 0xFF) * cosi));
  new_v = (int)(((double)((color >> 8) & 0xFF) * cosi));
  new_b = (int)(((double)((color) & 0xFF) * cosi));
  return ((new_r << 16)+(new_v << 8)+new_b);
}

int		light_cy(int color, double k, t_obj *vec)
{
  return (color);
}

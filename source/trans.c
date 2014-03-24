/*
** trans.c for rtv1 in /home/garcin_s/rendu/MUL_2013_rtv1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Mon Mar 10 18:09:52 2014 garcin_s
** Last update Tue Mar 11 14:33:57 2014 garcin_s
*/

#include "my.h"

void	translation(t_obj *vec, int x, int y, int z)
{
  vec->x = vec->x + x;
  vec->y = vec->y + y;
  vec->z = vec->z + z;
}

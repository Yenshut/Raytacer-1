/*
** calc.c for rtv1 in /home/garcin_s/rendu/MUL_2013_rtv1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Mon Mar 10 17:59:26 2014 garcin_s
** Last update Sun Mar 16 17:20:07 2014 garcin_s
*/

#include "my.h"

double          inter_cone(t_obj *vec, t_obj *eye, int rayon)
{
  double        a;
  double        b;
  double        c;
  double        delta;
  double        r;

  r = (double)rayon * (double)M_PI / 180.000;
  a = POW(vec->x) + POW(vec->y) - (POW(vec->z) * (POW(tan(r))));
  b = (2 * eye->x * vec->x) + (2 * eye->y * vec->y)
    - ((2 * eye->z * vec->z) * POW(tan(r)));
  c = POW(eye->x) + POW(eye->y) - (POW(eye->z) * POW(tan(r)));
  delta = (b * b) - (4 * (a * c));
  return (search_res(a, b, delta));
}

double		inter_cylindre(t_obj *vec, t_obj *eye, int rayon)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	r;

  r = (double)(rayon);
  a = POW(vec->x) + POW(vec->y);
  b = 2 * ((eye->x * vec->x) + (eye->y * vec->y));
  c = POW(eye->x) + POW(eye->y) - POW(r);
  delta = (b * b) - (4 * (a * c));
  return (search_res(a, b, delta));
}

/*
** Calcule les intersections avec le plan.
*/

double		inter_plan(t_obj *vec, t_obj *eye)
{
  double        k;

  if (vec->z >= 0.00001)
    return (-1);
  else
    {
      k = -1 * (eye->z / vec->z);
      if (k < 0.00001)
        return (-1);
    }
  return (k);
}

/*
** Cherche le plus grand K de la sphère.
*/

double		search_res(double a, double b, double d)
{
  double	res1;
  double	res2;

  if (d >= 0.0)
    {
      res1 = (-b - sqrt(d)) / (2 * a);
      res2 = (-b + sqrt(d)) / (2 * a);
      if (res1 < 0.0 && res2 < 0.0)
        return (-1.0);
      else if (res2 < res1 && res2 >= 0.0)
        return (res2);
      else
        return (res1);
    }
  else
    return (-1.0);
}

/*
** Cherche les intersection de la sphère.
*/

double          inter_sphere(t_obj *vec, t_obj *eye, int rayon)
{
  double        a;
  double        b;
  double        c;
  double        delta;
  double        r;

  r = (double)(rayon);
  a = POW(vec->x) + POW(vec->y) + POW(vec->z);
  b = 2 * ((eye->x * vec->x) + (eye->y * vec->y)
           + (eye->z * vec->z));
  c = POW(eye->x) + POW(eye->y) + POW(eye->z) - POW(r);
  delta = (b * b) - (4 * (a * c));
  return (search_res(a, b, delta));
}

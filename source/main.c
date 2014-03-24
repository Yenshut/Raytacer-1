/*
** main.c for TP in /home/garcin_s/rendu/MUL_2013_rtv1/TP
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Tue Feb  4 12:32:23 2014 garcin_s
** Last update Sun Mar 16 18:40:27 2014 garcin_s
*/

#include "my.h"

int		put_color_bis(double a, double b, double c, t_obj *vec)
{
  if ((c > 0 || a > 0) && b > 0)
    {
      if (c < b && a <= 0)
	return (light_cy(0xFF0000, c, vec));
      else if (a < b && c <= 0)
	return (light_sph(255000000, a, vec));
      else if (a > b)
	return (luminosite_plan(000000255, b, vec));
      else if (c > b)
	return (luminosite_plan(000000255, b, vec));
    }
  else if (a < c && a >= 0)
    return (light_sph(255000000, a, vec));
  else if (b < c && c > 0)
    return (light_cy(0xFF0000, c, vec));
  else if (a > 0 && b <= 0)
    return (light_sph(255000000, a, vec));
  else if (b > 0 && a <= 0)
    return (luminosite_plan(000000255, b, vec));
  return (0);
}

int		put_color(t_obj *eye, double c, double d, t_obj *vec)
{
  double	a;
  double	b;

  b = inter_plan(vec, eye);
  a = inter_sphere(vec, eye, 700);
  if (d > 0&& a < 0 && b < 0 && c < 0)
    return (000205205);
  if (d < a && d > 0 && b < 0)
    return (000205205);
  if (b < d && d > 0 && b > 0 && a < 0 && b < 0 && c > 0)
    return (luminosite_plan(000000255, b, vec));
  if ((c > 0 || a > 0) && b > 0)
    {
      if (c > 0 && a > 0)
	{
	  if (c < a && c < b)
	    return (light_cy(0xFF0000, c, vec));
	  else if (a < c && b > a)
	    return (light_sph(255000000, a, vec));
	  else if (b < c)
	    return (luminosite_plan(000000255, b, vec));
	}
    }
  return (put_color_bis(a, b, c, vec));
}

int		calc(t_data *data, t_obj *vec, t_obj *eye)
{
  double	c;
  double	d;

  vec->x = 100.000;
  vec->y = ((800 / 2.000) - data->x);
  vec->z = ((600 / 2.000) - data->y);
  rotate(vec, -50, 0, 0);
  translation(vec, 200, 70, 70);
  c = inter_cylindre(vec, eye, 200);
  translation(vec, -200, -70, -70);
  rotate(vec, 50, 0, 0);
  translation(vec, 200, 0, 50);
  d = inter_cone(vec, eye, 20);
  translation(vec, -200, 0, -50);
  translation(vec, -10, -10, -10);
  rotate(vec, 10, 10, 10);
  return (put_color(eye, c, d, vec));
}

/*
** Fonction principale.
*/

int		main()
{
  t_data	data;

  init_win(&data);
  color_img(&data);
  mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
  mlx_expose_hook(data.win_ptr, my_expose, &data);
  mlx_key_hook(data.win_ptr, &arrows, 0);
  mlx_loop(data.mlx_ptr);
  return (0);
}

/*
** color.c for rtv1 in /home/garcin_s/rendu/MUL_2013_rtv1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Mon Mar 10 17:56:06 2014 garcin_s
** Last update Tue Mar 11 09:22:15 2014 garcin_s
*/

#include "my.h"

/*
** Ajoute la couleur au pixel.
*/

void	my_put_color_to_img(int red, int green, int blue, t_data *data)
{
  data->img_data[(int)data->y * data->sl +
                 (int)data->x * data->bpp / 8 ] = blue;
  data->img_data[(int)data->y * data->sl +
                 (int)data->x * data->bpp / 8 + 1] = green;
  data->img_data[(int)data->y * data->sl +
                 (int)data->x * data->bpp / 8 + 2] = red;
}

void	color_img(t_data *data)
{
  int		a;
  int		b;
  t_obj         vec;
  t_obj         eye;

  init_struct(&vec, &eye, data);
  a = 10;
  data->y = 0;
  a=a;
  while (data->y < 600)
    {
      data->x = 0;
      while (data->x < 800)
        {
          b = calc(data, &vec, &eye);
          my_put_color_to_img((b / 1000000),
                              (b / 1000 % 1000), (b % 1000), data);
          data->x++;
        }
      data->y++;
    }
  mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

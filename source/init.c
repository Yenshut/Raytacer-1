/*
** init.c for rtv1 in /home/garcin_s/rendu/MUL_2013_rtv1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Mon Mar 10 17:52:46 2014 garcin_s
** Last update Sun Mar 16 18:43:39 2014 garcin_s
*/

#include "my.h"

/*
** Initialise la fenêtre.
*/

void	init_win(t_data *data)
{
  if ((data->mlx_ptr = mlx_init()) == NULL)
    exit(write(1, "Error on mlx_init()\n", 21));
  write(1, "Choose a title : ", 17);
  data->fr = read(0, data->win_name, 523);
  data->win_name[data->fr] = '\0';
  data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 600, data->win_name);
  data->img_ptr = mlx_new_image(data->mlx_ptr, 800, 600);
  data->img_data = mlx_get_data_addr(data->img_ptr,
                                     &(data->bpp), &(data->sl), &(data->en));
}

void	init_struct(t_obj *vec, t_obj *eye, t_data *data)
{
  eye->x = -900;
  eye->y = 0;
  eye->z = 150;
  vec->x = 100.000;
  vec->y = ((800 / 2.000) - data->x);
  vec->z = ((600 / 2.000) - data->y);
}

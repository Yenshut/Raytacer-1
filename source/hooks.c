/*
** hooks.c for rtv1 in /home/garcin_s/rendu/MUL_2013_rtv1
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Mon Mar 10 17:53:54 2014 garcin_s
** Last update Sun Mar 16 18:41:32 2014 garcin_s
*/

#include "my.h"

/*
** Gère l'expose.
*/

int	my_expose(t_data *data)
{
  mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
  return (0);
}

int             escape_key(int key)
{
  if (key == 65307)
    {
      write(1, "Exiting...\n", 12);
      exit(0);
    }
  return (0);
}

int             arrows(int key)
{
  if (key == 65307)
    escape_key(key);
  return (0);
}

/*
** my.h for TP in /home/garcin_s/rendu/MUL_2013_rtv1/TP/include
** 
** Made by garcin_s
** Login   <garcin_s@epitech.net>
** 
** Started on  Tue Feb  4 12:31:19 2014 garcin_s
** Last update Sun Mar 16 18:46:55 2014 garcin_s
*/

#ifndef _MY_H_
# define _MY_H_

/*
** INCLUDES
*/

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

/*
** MACROS
*/

# define POW(X) ((X)*(X))

/*
** STRUCTURES
*/

typedef struct	s_data
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  char		win_name[512];
  char		*img_data;
  int		sl;
  int		bpp;
  int		en;
  int		fr;
  double	x;
  double	y;
}		t_data;

typedef struct	s_obj
{
  double	x;
  double	y;
  double	z;
}		t_obj;

/*
** PROTOTYPES
*/

/*
** MAIN.C
*/

int	calc(t_data *data, t_obj *vec, t_obj *eye);
int	put_color(t_obj *eye, double c, double d, t_obj *vec);
int	put_color_bis(double a, double b, double c, t_obj *vec);

/*
** MY_PUT_NBR.C
*/

void	my_put_nbr(int nb);

/*
** MY_PUTCHAR.C
*/

void	my_putchar(char c);

/*
** INIT.C
*/

void	init_win(t_data *data);
void	init_struct(t_obj *vec, t_obj *eye, t_data *data);

/*
** LIGHT.C
*/

int             light_sph(int color, double k, t_obj *vec);
int             luminosite_plan(int color, double k, t_obj *vec);
int             light_cy(int color, double k, t_obj *vec);

/*
** HOOKS.C
*/

int	my_expose(t_data *data);
int	arrows(int key);
int	escape_key(int key);

/*
** COLOR.C
*/

void	my_put_color_to_img(int red, int green, int blue, t_data *data);
void	color_img(t_data *data);

/*
** CALC.C
*/

double	inter_plan(t_obj *vec, t_obj *eye);
double	inter_cone(t_obj *vec, t_obj *eye, int rayon);
double	search_res(double a, double b, double d);
double	inter_cylindre(t_obj *vec, t_obj *eye, int rayon);
double	inter_sphere(t_obj *vec, t_obj *eye, int rayon);

/*
** ROTATE.C
*/

void	rotate(t_obj *vec, int x, int y, int z);
void    rotate_x(double *x, double *y, double *z, double a);
void    rotate_y(double *x, double *y, double *z, double a);
void    rotate_z(double *x, double *y, double *z, double a);

/*
** TRANS.C
*/

void	translation(t_obj *vec, int x, int y, int z);

#endif

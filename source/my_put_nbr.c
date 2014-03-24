/*
** my_put_nbr.c for my_put_nbr in /home/garcin_s/rendu/Piscine-C-Jour_03/ref
** 
** Made by garcin
** Login   <garcin_s@epitech.net>
** 
** Started on  Sun Oct 28 11:51:40 2013 garcin
** Last update Tue Feb  4 14:38:29 2014 garcin_s
*/
#include "my.h"

void    	my_put_nbr(int nb)
{
  long long	nb2;
  int		count;
  long long	nb3;

  count = 1;
  nb2 = nb;
  if (nb2 < 0)
    {
      my_putchar('-');
      nb2 = nb2 * -1;
    }
  nb3 = nb2;
  while (nb3 >= 10)
    {
      nb3 = nb3 / 10;
      count = count * 10;
    }
  while (count >= 1)
    {
      my_putchar((nb2 / count) % 10 + 48);
      count = count / 10;
    }
}

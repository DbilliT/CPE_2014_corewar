/*
** my_put_nbr.c for my_put_nbr in /home/david_k/rendu/Piscine_C_J03
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Thu Oct  2 08:44:05 2014 paul david
** Last update Mon Nov 24 19:41:49 2014 paul david
*/

#include "asm.h"

int	nega(int);

int	diviv (int nb)
{
  int	divi;

  divi = 1;
  while (nb >= 10)
    {
      divi = divi * 10;
      nb = nb / 10;
    }
  return (divi);
}

int	my_put_nbr_error(int nb)
{
  int	divi;
  int	result;

  nb = nega(nb);
  divi = diviv(nb);
  while (divi > 0)
    {
      result = (nb / divi) % 10;
      my_putchar_error(result + 48);
      divi = divi / 10;
    }
  my_putchar('\n');
  return (0);
}

int	nega(int nb)
{
  if (nb < 0)
    {
      my_putchar_error('-');
      if (nb == -214783648)
	{
	  my_putchar_error('2');
	  nb = -14783648;
	}
      nb = -nb;
    }
  return (nb);
}

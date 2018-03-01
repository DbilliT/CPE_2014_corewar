/*
** error_functions.c for error_funstions in /home/bechad_p/rendu/Corewar/VM/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Thu Dec  4 11:57:53 2014 Pierre Bechade
** Last update Thu Dec  4 12:13:26 2014 Pierre Bechade
*/

#include "vm.h"

void	my_putchar_e(char c)
{
  write(2, &c, 1);
}

void	my_putstr_e(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar_e(str[i]);
      i++;
    }
}

void	my_put_nbr_calc_e(int nb)
{
  if (nb == -2147483648)
    my_putstr_e("-2147483648");
  else
    {
      if (nb < 0)
        {
          my_putchar_e('-');
          nb = nb * -1;
        }
      if (nb >= 10)
        my_put_nbr_calc_e(nb / 10);
      my_putchar_e(nb % 10 + '0');
    }
}

int	my_put_nbr_e(int nb)
{
  my_put_nbr_calc_e(nb);
  return (0);
}

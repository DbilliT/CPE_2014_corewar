/*
** tools4.c for tools4 in /home/bechad_p/rendu/Corewar/VM/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Dec  9 20:52:36 2014 Pierre Bechade
** Last update Sun Dec 14 01:31:10 2014 Pierre Bechade
*/

#include "vm.h"

int	my_calc_getnbr(char *str, int i, double nb_final, int nb_return)
{
  while (((str[i] != '\0') && ((str[i] >= '0') && (str[i] <= '9')))
         || ((str[i] == '-') || (str[i] == '+')))
    {
      if (str[i] >= '0' && str[i] <= '9')
        nb_final = (nb_final * 10) + (str[i] - 48);
      if (str[i] == '-')
        nb_return = nb_return + 1;
      i++;
    }
  if ((nb_return % 2) != 0)
    nb_final = nb_final - (2 * nb_final);
  if (nb_final > 2147483647 || nb_final < -2147483648)
    return (0);
  nb_return = nb_final;
  return (nb_return);
}

int		my_getnbr(char *str)
{
  int		result;
  double	nb_final;
  int		i;
  int		nb_return;

  result = 0;
  nb_final = 0;
  i = 0;
  nb_return = 0;
  result = my_calc_getnbr(str, i, nb_final, nb_return);
  return (result);
}

void	my_put_calc(int nb)
{
  if (nb == -2147483648)
    my_putstr("-2147483648");
  else
    {
      if (nb < 0)
        {
          my_putchar_e('-');
          nb = nb * -1;
        }
      if (nb >= 10)
        my_put_calc(nb / 10);
      my_putchar_e(nb % 10 + '0');
    }
}

int	my_put_nbr(int nb)
{
  my_put_calc(nb);
  return (0);
}

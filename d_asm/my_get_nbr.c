/*
** my_get_nbr.c for my_get_number in /home/david_k/rendu/Bistromathique/lib/my
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Tue Nov  4 20:47:17 2014 paul david
** Last update Tue Dec  9 15:28:41 2014 paul david
*/

#include "asm.h"

int	my_calcule2(char *str, int i, double nb_final, unsigned int nb_return)
{
  while ((str[i] != '\0') && ((str[i] >= '0' && str[i] <= '9')
			      || (str[i] == '-' || str[i] == '+')))
    {
      if (str[i] >= '0' && str[i] <= '9')
	nb_final = (nb_final * 10) + (str[i] - 48);
      if (str[i] == '-')
	nb_return = nb_return + 1;
      i++;
    }
  if ((nb_return % 2) != 0)
    nb_final = nb_final - (2 * nb_final);
  if (nb_final > 4294967295)
    return (0);
  nb_return = nb_final;
  return (nb_return);
}

int		my_getnbr(char *str)
{
  unsigned int	result;
  double	nb_final;
  int		i;
  unsigned int	nb_return;

  result = 0;
  nb_final = 0;
  i = 0;
  nb_return = 0;
  result = my_calcule2(str, i, nb_final, nb_return);
  return (result);
}

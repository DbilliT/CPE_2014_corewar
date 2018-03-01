/*
** check_dump_n.c for check_dump_n in /home/deluss_c/rendu/test/corewartest
** 
** Made by Cédric de Lussigny
** Login   <deluss_c@epitech.net>
** 
** Started on  Tue Dec  9 20:12:48 2014 Cédric de Lussigny
** Last update Sun Dec 14 15:45:33 2014 Pierre Bechade
*/

#include "vm.h"

void	is_error(char *message)
{
  my_putstr_e(message);
  exit (0);
}

int	check_dump(char *str)
{
  char	*check;

  check = my_strdup("-dump");
  if (my_strcmp(str, check) != 0)
    return (1);
  return (0);
}

void	check_dump_number(char *str)
{
  int	dump;
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	is_error("Problem nbr_cycle\n");
      i++;
    }
  if ((dump = my_getnbr(str)) == 0)
    is_error("Problem nbr_cycle\n");
  if (dump < 0)
    is_error("Negative value of nbr_cycle\n");
  if (dump > 2147483647)
    is_error("Error value of nbr_cycle\n");
  command->my_dump = dump;
}

int	check_n(char *str)
{
  char	*check;

  check = my_strdup("-n");
  if (my_strcmp(str, check) != 0)
    return (1);
  return (0);
}

int	check_prog_number(char *str)
{
  int	number;

  if ((number = my_getnbr(str)) == 0)
    is_error("Problem prog_number\n");
  if (number < 0)
    is_error("Negative value of prog_number\n");
  if (number > 4)
    is_error("Error value of prog_number\n");
  return (number);
}

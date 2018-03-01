/*
** check_load.c for check_load in /home/deluss_c/rendu/test/corewartest
** 
** Made by Cédric de Lussigny
** Login   <deluss_c@epitech.net>
** 
** Started on  Tue Dec  9 20:19:17 2014 Cédric de Lussigny
** Last update Sun Dec 14 21:19:21 2014 paul david
*/

#include "vm.h"

int	check_a(char *str)
{
  char	*check;

  check = my_strdup("-a");
  if (my_strcmp(str, check) != 0)
    return (1);
  return (0);
}

int	check_load_value(char *str)
{
  int	number;

  if ((number = my_getnbr(str)) == 0)
    is_error("Problem load_value\n");
  if (number < 0)
    is_error("Negative value of load_value\n");
  if (number > 2147483647)
    is_error("Error value of load_value\n");
  return (number);
}

int	check_cor(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '.' && str[i + 1] == 'c' && str[i + 2] == 'o'
          && str[i + 3] == 'r' && str[i + 4] == '\0')
        {
          return (0);
        }
      i++;
    }
  return (-1);
}

int		check_arg(char *str, char **av, int *j)
{
  static int	isdump = 0;
  static int	isn = 0;
  static int	isa = 0;
  static int	my_prog_number = 0;
  static int	my_load_value = -1;
  static int	nbr_cor = 0;

  if (check_dump(str) == 0)
    (isdump > 0) ? is_error("Multiple nbr_cycle\n") :
      (*j = *j + 1, (av[*j] == NULL)
       ? is_error("No dump value\n") : (check_dump_number(av[*j]), isdump++));
  else if (check_n(str) == 0)
    (isn > 0) ? is_error("Multiple prog_number\n") :
      (*j = *j + 1, (av[*j] == NULL) ? is_error("No prog number\n") :
       (my_prog_number = check_prog_number(av[*j]), isn++));
  else if (check_a(str) == 0)
    (isa > 0) ? is_error("Multiple load_value\n") :
      (*j = *j + 1, (av[*j] == NULL) ? is_error("No load_value\n") :
       (my_load_value = check_load_value(av[*j]), isa++));
  else if (check_cor(str) == 0)
    (1) ? add_end_code(&command->my_cor, str, my_prog_number, my_load_value),
      my_prog_number = 0, my_load_value = -1, isn = 0, isa = 0, nbr_cor++ : 0;
  else
    is_error("Error when opening file\n");
  return (nbr_cor);
}

void			check_number_used()
{
  t_command_list	*tmp;
  t_command_list	*tmp2;

  tmp = command->my_cor;
  tmp2 = command->my_cor;
  while (tmp->next != NULL)
    {
      tmp2 = tmp2->next;
      while (tmp2 != NULL)
        {
          if (tmp2->prog_nbr == tmp->prog_nbr && tmp2->prog_nbr != 0)
            is_error("prog_number already used\n");
          tmp2 = tmp2->next;
        }
      tmp = tmp->next;
      tmp2 = tmp;
    }
}

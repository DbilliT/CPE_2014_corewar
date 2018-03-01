/*
** main.c for main in /home/deluss_c/rendu/test/corewartest
** 
** Made by Cédric de Lussigny
** Login   <deluss_c@epitech.net>
** 
** Started on  Tue Dec  9 20:15:06 2014 Cédric de Lussigny
** Last update Sun Dec 14 20:56:04 2014 paul david
*/

#include "vm.h"

int	main(int ac, char **av)
{
  check_command(ac, av);
  command->live = 0;
  my_check_cor();
  my_battle(check_overlap(), -1, -1, -1);
  if (my_strcmp(command->winner, "No Winner") != 0)
    {
      while  (my_strcmp(command->winner, CURRENT->name_champ) != 0)
	CURRENT = CURRENT->next;
      my_putstr("joueur ");
      my_put_nbr(CURRENT->reg[0]);
      my_putchar('(');
      my_putstr(command->winner);
      my_putchar(')');
      my_putstr(" a gagne\n");
    }
  else
    {
      my_putstr(command->winner);
      my_putchar('\n');
    }
  return (0);
}

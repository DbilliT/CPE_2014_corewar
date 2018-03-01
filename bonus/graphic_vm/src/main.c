/*
** main.c for main in /home/deluss_c/rendu/test/corewartest
** 
** Made by Cédric de Lussigny
** Login   <deluss_c@epitech.net>
** 
** Started on  Tue Dec  9 20:15:06 2014 Cédric de Lussigny
** Last update Sat Dec 13 14:32:20 2014 Pierre Bechade
*/

#include "vm.h"

int	main(int ac, char **av)
{
  check_command(ac, av);
  command->live = 0;
  my_check_cor();
  my_battle(check_overlap());
  set_winner(command->winner);
  return (0);
}

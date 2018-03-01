/*
** add.c for add in /home/bechad_p/rendu/Corewar/VM/src/mnemonique
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Dec  9 17:47:29 2014 Pierre Bechade
** Last update Sat Dec 13 15:45:00 2014 Pierre Bechade
*/

#include "vm.h"

void	my_add(unsigned int rg, unsigned int rg2, unsigned int rg3)
{
  my_putstr("  -- add  --\n");
  command->my_cor->reg[rg3 - 1] = command->my_cor->reg[rg - 1]
    + command->my_cor->reg[rg2 - 1];
  command->my_cor->carry = 1;
  command->my_cor->global_time = 10;
}

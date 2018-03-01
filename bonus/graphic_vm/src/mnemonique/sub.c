/*
** sub.c for sub in /home/bechad_p/rendu/Corewar/VM/src/mnemonique
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Dec  9 17:54:02 2014 Pierre Bechade
** Last update Fri Dec 12 20:26:20 2014 Pierre Bechade
*/

#include "vm.h"

void	my_sub(unsigned int rg, unsigned int rg2, unsigned int rg3)
{
  my_putstr("  -- Sub  --\n");
  CURRENT->reg[rg3 - 1] = CURRENT->reg[rg - 1] - CURRENT->reg[rg2 - 1];
  CURRENT->carry = 1;
  CURRENT->global_time = 10;
}

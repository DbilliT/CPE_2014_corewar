/*
** zjmp.c for zjmp in /home/bechad_p/rendu/Corewar/VM/src/mnemonique
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Dec  9 18:54:42 2014 Pierre Bechade
** Last update Sun Dec 14 00:00:36 2014 Pierre Bechade
*/

#include "vm.h"

void	my_zjmp(unsigned int value)
{
  my_putstr("  -- zjump  --\n");
  //if (command->my_cor->carry == 1)
  PC = ((PC + (value % IDX_MOD)) % MEM_SIZE);
  command->my_cor->global_time = 20;
}

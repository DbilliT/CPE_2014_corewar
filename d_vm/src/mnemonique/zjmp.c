/*
** zjmp.c for zjmp in /home/bechad_p/rendu/Corewar/VM/src/mnemonique
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Dec  9 18:54:42 2014 Pierre Bechade
** Last update Sun Dec 14 21:00:04 2014 paul david
*/

#include "vm.h"

void	my_zjmp(unsigned int value)
{
  PC = ((PC + (value % IDX_MOD)) % MEM_SIZE);
  command->my_cor->global_time = 20;
}

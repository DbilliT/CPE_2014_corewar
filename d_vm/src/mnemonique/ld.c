/*
** ld.c for ld in /home/bechad_p/rendu/Corewar/VM/src/mnemonique
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Dec  9 16:07:12 2014 Pierre Bechade
** Last update Sun Dec 14 20:35:40 2014 paul david
*/

#include "vm.h"

void	my_ld(unsigned int data, unsigned int data2)
{
  int	bits;
  int	offset;

  offset = 0;
  if (gl_type[0] == 1)
    command->my_cor->reg[data2 - 1] = data;
  else
    {
      CURRENT->reg[data2 - 1] = 0;
      offset = (PC + (data % IDX_MOD)) % MEM_SIZE;
      bits = 24;
      while (bits != -8)
	{
	  command->my_cor->reg[data2 - 1] += (arena[offset] & 0xFF) << bits;
	  bits = bits - 8;
	  offset++;
	}
      if (is_big_endian() != 1)
	CURRENT->reg[data2 - 1] = convert_endian_int(CURRENT->reg[data2 - 1]);
    }
  command->my_cor->carry = 1;
  command->my_cor->global_time = 5;
}

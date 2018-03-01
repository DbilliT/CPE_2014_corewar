/*
** st.c for st in /home/bechad_p/rendu/Corewar/VM/src/mnemonique
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Dec  9 17:40:57 2014 Pierre Bechade
** Last update Sun Dec 14 01:06:15 2014 Pierre Bechade
*/

#include "vm.h"

void	my_st(unsigned int data1, unsigned int data2)
{
  int	offset;
  int	bits;

  my_putstr("  -- st  --\n");
  offset = 0;
  if (gl_type[1] == 2)
    {
      offset = (PC + (data2 % IDX_MOD)) % MEM_SIZE;
      if (is_big_endian() == 0)
	{
	  bits = 24;
	  while (bits != -8)
	    {
	      arena[offset] += (command->my_cor->reg[data1 - 1] << bits) & 0xFF;
	      bits = bits - 8;
	      offset++;
	    }
	}
      else
	{
	  bits = 0;
	  while (bits != 32)
	    {
	      arena[offset] += (command->my_cor->reg[data1 - 1] << bits) & 0xFF;
	      bits = bits + 8;
	      offset++;
	    }
	}
    }
  else
    command->my_cor->reg[data2 - 1] = command->my_cor->reg[data1 - 1];
  command->my_cor->global_time = 5;
}

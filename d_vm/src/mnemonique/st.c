/*
** st.c for st in /home/bechad_p/rendu/Corewar/VM/src/mnemonique
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Dec  9 17:40:57 2014 Pierre Bechade
** Last update Sun Dec 14 18:30:49 2014 paul david
*/

#include "vm.h"

void	set_st_zero(int offset)
{
  int	i;

  i = 0;
  if (gl_type[1] == 2)
    while (i != 4)
      {
	arena[offset] = 0;
	i++;
	offset++;
      }
}

void	my_st(unsigned int data1, unsigned int data2)
{
  int	offset;
  int	bits;

  offset = (PC + (data2 % IDX_MOD)) % MEM_SIZE;
  set_st_zero(offset);
  bits = 32;
  if (gl_type[1] == 2)
    if (is_big_endian() != 0)
      while ((bits = bits - 8) != -8)
	{
	  arena[offset] += (command->my_cor->reg[data1 - 1] >> bits) & 0xFF;
	  offset++;
	}
    else
      {
	bits = -8;
	while ((bits = bits + 8) != 32)
	  {
	    arena[offset] += (command->my_cor->reg[data1 - 1] >> bits) & 0xFF;
	    offset++;
	  }
      }
  else
    command->my_cor->reg[data2 - 1] = command->my_cor->reg[data1 - 1];
  command->my_cor->global_time = 5;
}

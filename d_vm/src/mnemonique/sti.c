/*
** sti.c for sti in /home/david_k/rendu/CPE_2014_corewar/d_vm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Sat Dec 13 15:56:09 2014 paul david
** Last update Sun Dec 14 19:31:59 2014 paul david
*/

#include "vm.h"

void	set_sti_zero(int offset)
{
  int	i;

  i = 0;
  while (i != 4)
    {
      arena[offset] = 0;
      i++;
      offset++;
    }
}

void		my_sti(unsigned int para, unsigned int para2, unsigned int para3)
{
  int		offfirst;
  int		offsecond;
  int		offset;
  int		bits;

  bits = 32;
  offfirst = (gl_type[1] == 3) ? (CURRENT->reg[para2 - 1] % IDX_MOD) : MPC2;
  offsecond = (gl_type[2] == 3) ? (CURRENT->reg[para3 - 1] % IDX_MOD) : MPC3;
  offset = (PC + offfirst + offsecond) % MEM_SIZE;
  set_sti_zero(offset);
  if (is_big_endian() != 0)
    while ((bits = bits - 8) != -8)
	{
	  arena[offset] += (CURRENT->reg[para - 1] >> bits) & 0xFF;
	  offset++;
	}
  else
    {
      bits = -8;
      while ((bits = bits + 8) != 32)
	{
	  arena[offset] += (CURRENT->reg[para - 1] >> bits) & 0xFF;
	  offset++;
	}
    }
}

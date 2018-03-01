/*
** sti.c for sti in /home/david_k/rendu/CPE_2014_corewar/d_vm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Sat Dec 13 15:56:09 2014 paul david
** Last update Sat Dec 13 23:59:16 2014 Pierre Bechade
*/

#include "vm.h"

void		my_sti(unsigned int para, unsigned int para2, unsigned int para3)
{
  int		offfirst;
  int		offsecond;
  int		offset;
  int		bits;

  bits = 32;
  offfirst = (gl_type[1] == 3) ?
    (CURRENT->reg[para2 - 1] % IDX_MOD) : (para2 % IDX_MOD);
  offsecond = (gl_type[2] == 3) ?
    (CURRENT->reg[para3 - 1] % IDX_MOD) : (para3 % IDX_MOD);
  offset = (PC + offfirst + offsecond) % MEM_SIZE;
  if (is_big_endian() == 1)
    while ((bits = bits - 8) != -8)
	{
	  arena[offset] += (CURRENT->reg[para - 1] << bits) & 0xFF;
	  offset++;
	}
  else
    {
      bits = -8;
	while ((bits = bits + 8) != 32)
	{
	  arena[offset] += (CURRENT->reg[para - 1] << bits) & 0xFF;
	  offset++;
	}
    }
}

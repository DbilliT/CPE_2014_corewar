/*
** check_instru_fill.c for check_instru_fill in /home/bechad_p/rendu/Corewar/VM/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Sat Dec 13 14:55:26 2014 Pierre Bechade
** Last update Sat Dec 13 15:54:14 2014 Pierre Bechade
*/

#include "vm.h"

void	fill_dir(unsigned int *para)
{
  int	bits;

  PC = PC + 1;
  bits = 24;
  while (bits != -8)
    {
      if (PC >= MEM_SIZE)
        PC = 0;
      *para += (arena[PC] & 0xFF) << bits;
      PC = PC + 1;
      bits = bits - 8;
    }
  if (is_big_endian() != 1)
    *para = convert_endian_int(*para);
}

void	fill_indir(unsigned int *para)
{
  int	bits;

  PC = PC + 1;
  bits = 24;
  while (bits != 8)
    {
      if (PC >= MEM_SIZE)
        PC = 0;
      *para += (arena[PC] & 0xFF) << bits;
      PC = PC + 1;
      bits = bits - 8;
    }
  if (is_big_endian() != 1)
    *para = convert_endian_int(*para);
}

void	fill_reg(unsigned int *para)
{
  PC = PC + 1;
  if (PC >= MEM_SIZE)
    PC = 0;
  *para += (arena[PC] & 0xFF) << 24;
  if (is_big_endian() != 1)
    *para = convert_endian_int(*para);
}

int	fill_duo_ind(int k, int *bits, unsigned int *para)
{
  if ((op_tab[k].type[gl_pos] & T_IND) == T_IND)
    fill_indir(&(*para));
  else
    {
      PC = gl_offset + 1;
      my_fail(0);
      *bits = 48;
      return (1);
    }
  return (0);
}

int	fill_duo_dir(int k, int *bits, unsigned int *para)
{
  if ((op_tab[k].type[gl_pos] & T_DIR) == T_DIR)
    if (instru_tab[k].oct == 4)
      fill_dir(&(*para));
    else
      fill_indir(&(*para));
  else
    {
      PC = gl_offset + 1;
      my_fail(0);
      *bits = 48;
      return (1);
    }
  return (0);
}

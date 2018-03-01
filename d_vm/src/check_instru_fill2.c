/*
** check_instru_fill2.c for check_instru_fill2 in /home/bechad_p/rendu/Corewar/VM/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Sat Dec 13 14:57:21 2014 Pierre Bechade
** Last update Sun Dec 14 12:34:51 2014 Pierre Bechade
*/

#include "vm.h"

int	fill_duo_reg(int k, int *bits, unsigned int *para)
{
  if ((op_tab[k].type[gl_pos] & T_REG) == T_REG)
    fill_reg(&(*para));
  else
    {
      PC = gl_offset + 1;
      my_fail(0);
      *bits = 48;
      return (1);
    }
  if (*para > 16 || *para == 0)
    {
      PC = gl_offset + 1;
      my_fail(0);
      *bits = 48;
      return (1);
    }
  return (0);
}

int	fill_tri_ind(int k, int *bits, unsigned int *para)
{
  if ((op_tab[k].type[gl_pos] & T_IND) == T_IND)
    fill_indir(&(*para));
  else
    {
      PC = gl_offset + 1;
      my_fail(0);
      *bits = 12;
      return (1);
    }
  return (0);
}

int	fill_tri_dir(int k, int *bits, unsigned int *para)
{
  if ((op_tab[k].type[gl_pos] & T_REG) == T_REG)
    if (instru_tab[k].oct == 4)
      fill_dir(&(*para));
    else
      fill_indir(&(*para));
  else
    {
      PC = gl_offset + 1;
      my_fail(0);
      *bits = 12;
      return (1);
    }
  return (0);
}

int	fill_tri_reg(int k, int *bits, unsigned int *para)
{
  if ((op_tab[k].type[gl_pos] & T_REG) == T_REG)
    fill_reg(&(*para));
  else
    {
      PC = gl_offset + 1;
      my_fail(0);
      *bits = 12;
      return (1);
    }
  if (*para > 16 || *para == 0)
    {
      PC = gl_offset + 1;
      my_fail(0);
      *bits = 12;
      return (1);
    }
  return (0);
}

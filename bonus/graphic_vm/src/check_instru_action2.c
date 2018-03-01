/*
** check_instru_action2.c for check_instru_action2 in /home/bechad_p/rendu/Corewar/VM/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Sat Dec 13 14:59:25 2014 Pierre Bechade
** Last update Sat Dec 13 15:55:42 2014 Pierre Bechade
*/

#include "vm.h"

void		check_instru_solo(int k)
{
  unsigned int	para;

  para = 0;
  if ((op_tab[k].type[0] & T_DIR) == T_DIR)
    {
      if (instru_tab[k].oct == 4)
        fill_dir(&para);
      else
        fill_indir(&para);
      exe_instru_solo(para, k);
    }
  if ((op_tab[k].type[0] & T_REG) == T_REG)
    {
      fill_reg(&para);
      if (para > 16)
	{
          PC = gl_offset + 1;
          my_fail(0);
        }
      else
        exe_instru_solo(para, k);
    }
}

int	check_instru_tri_part(int *bits, unsigned int *ptr, int k, int offset)
{
  if ((arena[offset] & *bits) == *bits)
    {
      gl_type[gl_pos] = 2;
      return (fill_tri_ind(k, &(*bits), &(*ptr)));
    }
  else if ((arena[offset] & *bits) == *bits / 1.5)
    {
      gl_type[gl_pos] = 1;
      return (fill_tri_dir(k, &(*bits), &(*ptr)));
    }
  else if ((arena[offset] & *bits) == *bits / 3)
    {
      gl_type[gl_pos] = 3;
      return (fill_tri_reg(k, &(*bits), &(*ptr)));
    }
  else
    {
      PC = gl_offset + 1;
      my_fail(0);
      *bits = 12;
      return (1);
    }
  return (0);
}

void		check_instru_tri(int k)
{
  unsigned int	para;
  unsigned int	para2;
  unsigned int	para3;
  unsigned int	*ptr;
  int		bits;
  int		exe;
  int		offset;

  bits = 192;
  gl_pos = 0;
  para = 0;
  para2 = 0;
  para3 = 0;
  offset = PC;
  while (bits != 3)
    {
      PC = (PC >= MEM_SIZE) ? 0 : PC;
      ptr = (bits == 192) ? &para : (bits == 48) ? &para2 : &para3;
      exe = check_instru_tri_part(&bits, &(*ptr), k, offset);
      bits = bits / 4;
      gl_pos++;
    }
  if (exe == 0)
    exe_instru_tri(para, para2, para3, k);
}

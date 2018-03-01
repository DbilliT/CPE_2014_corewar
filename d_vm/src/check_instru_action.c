/*
** check_instru_action.c for check_instru_action in /home/david_k/rendu/CPE_2014_corewar/d_vm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Tue Dec  9 17:06:17 2014 paul david
** Last update Sun Dec 14 16:00:26 2014 Pierre Bechade
*/

#include "vm.h"

int	gl_offset = 0;
int	gl_pos = 0;
int	gl_type[3];

int	check_instru_duo_part(int *bits, unsigned int *ptr, int k, int offset)
{
  if ((arena[offset] & *bits) == *bits)
    {
      gl_type[gl_pos] = 2;
      return (fill_duo_ind(k, &(*bits), &(*ptr)));
    }
  else if ((arena[offset] & *bits) == *bits / 1.5)
    {
      gl_type[gl_pos] = 1;
      return (fill_duo_dir(k, &(*bits), &(*ptr)));
    }
  else if ((arena[offset] & *bits) == *bits / 3)
    {
      gl_type[gl_pos] = 3;
      return (fill_duo_reg(k, &(*bits), &(*ptr)));
    }
  else
    {
      PC = gl_offset + 1;
      my_fail(0);
      *bits = 48;
      return (1);
    }
  return (0);
}

void		check_instru_duo(int k)
{
  unsigned int	para;
  unsigned int	para2;
  unsigned int	*ptr;
  int		bits;
  int		exe;
  int		offset;

  bits = 192;
  gl_pos = 0;
  para = 0;
  para2 = 0;
  offset = PC;
  while (bits != 12)
    {
      PC = (PC >= MEM_SIZE) ? 0 : PC;
      ptr = (bits == 192) ? &para : &para2;
      exe = check_instru_duo_part(&bits, &(*ptr), k, offset);
      bits = bits / 4;
      gl_pos++;
    }
  if (exe == 0)
    exe_instru_duo(para, para2, k);
}

void	check_instru_mul(int k)
{
  PC = PC + 1;
  PC = (PC >= MEM_SIZE) ? 0 : PC;
  if (op_tab[k].nbr_args == 2)
    check_instru_duo(k);
  else if (op_tab[k].nbr_args == 3)
    check_instru_tri(k);
}

void	check_instru()
{
  int	k;

  k = 0;
  my_memset(gl_type, 0, 3);
  PC = (PC % MEM_SIZE);
  gl_offset = PC;
  while (op_tab[k].code != 0 && arena[PC] != op_tab[k].code)
    k++;
  if (op_tab[k].code == 0)
    {
      PC = gl_offset + 1;
      my_fail(0);
    }
  else if (op_tab[k].nbr_args == 1)
    check_instru_solo(k);
  else
    check_instru_mul(k);
}

/*
** lldi.c for lldi in /home/bechad_p/rendu/Ultime/VM/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Sun Dec 14 14:07:48 2014 Pierre Bechade
** Last update Sun Dec 14 21:24:13 2014 paul david
*/

#include "vm.h"

void		my_lldi(unsigned int para, unsigned int para2, unsigned int para3)
{
  unsigned int	oct_read;
  int		bits;
  int		offset;

  oct_read = 0;
  offset = (gl_type[0] == 3) ? ((PC + CURRENT->reg[0]) % MEM_SIZE) : MPC;
  bits = 32;
  while ((bits = bits - 8) != 8)
    {
      oct_read += (arena[offset] & 0XFF) << bits;
      offset++;
    }
  oct_read = (is_big_endian() != 1) ? convert_endian_int(oct_read) : oct_read;
  oct_read = (gl_type[1] == 1) ? (oct_read + para2) :
    (gl_type[1] == 3) ? (oct_read + CURRENT->reg[para2 - 1]) : 0;
  offset = (PC + oct_read) % MEM_SIZE;
  bits = 32;
  oct_read = 0;
  while ((bits = bits - 8) != -8)
    {
      oct_read += (arena[offset] & 0XFF) << bits;
      offset++;
    }
  oct_read = (is_big_endian() != 1) ? convert_endian_int(oct_read) : oct_read;
  CURRENT->reg[para3 - 1] = oct_read;
}

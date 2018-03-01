/*
** xor.c for xor in /home/bechad_p/rendu/Corewar/VM/src/mnemonique
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Fri Dec 12 17:29:09 2014 Pierre Bechade
** Last update Sat Dec 13 15:49:07 2014 Pierre Bechade
*/

#include "vm.h"

void	my_xor(unsigned int p1, unsigned int p2, unsigned int r3)
{
  my_putstr("  -- xor  --\n");
  if (gl_type[0] == 1 && gl_type[1] == 1)
    CURRENT->reg[r3] = p1 ^ p2;
  if (gl_type[0] == 1 && gl_type[1] == 2)
    CURRENT->reg[r3] = p1 ^ arena[((PC + (p2 % IDX_MOD)) % MEM_SIZE)];
  if (gl_type[0] == 2 && gl_type[1] == 1)
    CURRENT->reg[r3] = arena[((PC + (p1 % IDX_MOD)) % MEM_SIZE)] ^ p2;
  if (gl_type[0] == 2 && gl_type[1] == 2)
    CURRENT->reg[r3] = arena[((PC + (p1 % IDX_MOD)) % MEM_SIZE)]
      ^ arena[((PC + (p2 % IDX_MOD)) % MEM_SIZE)];
  if (gl_type[0] == 2 && gl_type[1] == 3)
    CURRENT->reg[r3] = arena[((PC + (p1 % IDX_MOD)) % MEM_SIZE)]
      ^ CURRENT->reg[p2 - 1];
  if (gl_type[0] == 3 && gl_type[1] == 2)
    CURRENT->reg[r3] = CURRENT->reg[p1 - 1]
      ^ arena[((PC + (p2 % IDX_MOD)) % MEM_SIZE)];
  if (gl_type[0] == 3 && gl_type[1] == 3)
    CURRENT->reg[r3] = CURRENT->reg[p1 - 1] ^ CURRENT->reg[p2 - 1];
  if (gl_type[0] == 1 && gl_type[1] == 3)
    CURRENT->reg[r3] = p1 ^ CURRENT->reg[p2 - 1];
  if (gl_type[0] == 3 && gl_type[1] == 1)
    CURRENT->reg[r3] = CURRENT->reg[p1 - 1] ^ p2;
  CURRENT->global_time = 6;
}

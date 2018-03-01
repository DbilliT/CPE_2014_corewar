/*
** my_fail.c for my_fail in /home/bechad_p/rendu/Corewar/VM/src/mnemonique
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Fri Dec 12 14:07:41 2014 Pierre Bechade
** Last update Sat Dec 13 23:58:00 2014 Pierre Bechade
*/

#include "vm.h"

void	my_fail(int value)
{
  if (value == 0)
    command->my_cor->carry = 0;
  command->my_cor->global_time++;
}

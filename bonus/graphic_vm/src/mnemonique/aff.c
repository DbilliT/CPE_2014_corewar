/*
** aff.c for aff in /home/bechad_p/rendu/Corewar/VM/src/mnemonique
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Dec  9 19:34:46 2014 Pierre Bechade
** Last update Fri Dec 12 21:24:10 2014 Pierre Bechade
*/

#include "vm.h"

void	my_aff(unsigned int para)
{
  my_putchar(command->my_cor->reg[para - 1] % 256);
}

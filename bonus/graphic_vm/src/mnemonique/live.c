/*
** live.c for live in /home/bechad_p/rendu/Corewar/VM/src/mnemonique
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Dec  9 16:05:24 2014 Pierre Bechade
** Last update Sat Dec 13 15:49:48 2014 Pierre Bechade
*/

#include "vm.h"

void	aff_live()
{
  my_putstr("Le joueur ");
  my_putchar(command->my_cor->reg[0] + '0');
  my_putchar('(');
  my_putstr(command->my_cor->name_champ);
  my_putchar(')');
  my_putstr("est en vie\n");
  command->winner = my_strdup(CURRENT->name_champ);
}

void	live(unsigned int player)
{
  int			i;
  int			tmp;

  tmp = 0;
  i = command->nb_champ;
  my_putstr("  -- Live  --\n");
  while (i > 0)
    {
      if (command->my_cor->reg[0] == player)
	{
	  command->my_cor->is_alive = 1;
	  if (tmp == 0)
	    {
	      aff_live();
	      tmp++;
	    }
	}
      command->my_cor = command->my_cor->next;
      i--;
    }
  if (tmp > 0)
    command->live++;
  command->my_cor->global_time = 10;
}

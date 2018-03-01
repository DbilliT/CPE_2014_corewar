/*
** how_many_alive.c for how_many_alive in /home/bechad_p/rendu/Corewar/VM/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Sat Dec 13 16:44:31 2014 Pierre Bechade
** Last update Sat Dec 13 16:44:48 2014 Pierre Bechade
*/

#include "vm.h"

int     how_many_alive()
{
  int   nb;
  int   nb_alive;

  nb = command->nb_champ;
  nb_alive = 0;
  while (nb > 0)
    {
      if (command->my_cor->is_alive == 1)
        {
          nb_alive++;
          command->my_cor->is_alive = 0;
        }
      else
        my_kill_chain(&command->my_cor);
      command->my_cor = command->my_cor->next;
      nb--;
    }
  command->nb_champ = nb_alive;
  return (my_no_fork_champ());
}

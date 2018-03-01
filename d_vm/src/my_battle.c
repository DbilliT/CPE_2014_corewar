/*
** my_battle.c for my_battle in /home/bechad_p/rendu/Corewar/VM/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Wed Dec 10 18:23:25 2014 Pierre Bechade
** Last update Sun Dec 14 21:29:16 2014 paul david
*/

#include "vm.h"

unsigned char	*arena;

void	my_set_cmd(int over)
{
  command->nb_champ = over;
  command->no_fork_champ = over;
  (command->my_dump == 0) ? command->my_dump = -1 : 0;
}

int                     my_no_fork_champ()
{
  int                   nb;
  int                   i;
  t_command_list        *tmp;
  int                   true_champ[4];

  tmp = command->my_cor;
  nb = command->nb_champ;
  my_memset(&true_champ, 0, 4 * sizeof(int));
  while (nb > 0)
    {
      (tmp->reg[0] == 1) ? true_champ[0] = 1 : 0;
      (tmp->reg[0] == 2) ? true_champ[1] = 1 : 0;
      (tmp->reg[0] == 3) ? true_champ[2] = 1 : 0;
      (tmp->reg[0] == 4) ? true_champ[3] = 1 : 0;
      tmp = tmp->next;
      nb--;
    }
  nb = 0;
  i = 0;
  while (i < 4)
    {
      (true_champ[i] == 1) ? nb++ : 0;
      i++;
    }
  return (nb);
}

unsigned char	*my_unsdup(unsigned char *str)
{
  unsigned char *new;
  int		i;

  i = 0;
  new = my_xmalloc(sizeof(unsigned char) * MEM_SIZE);
  while (i != MEM_SIZE)
    {
      new[i] = str[i];
      i++;
    }
  return (new);
}

void			my_battle(unsigned char *map, int cycle, int die, int over)
{
  t_command_list	*new;
  int			size;
  int			cycle_die;

  command->winner = "No Winner";
  (1) ? new = command->my_cor, cycle_die = CYCLE_TO_DIE,
    arena = my_unsdup(map) : 0;
  while (++over, new != NULL)
    new = new->next;
  my_trans_circ(&command->my_cor);
  my_set_cmd(over);
  while (++die, over >= 1 && ++cycle != command->my_dump)
    {
      size = command->nb_champ;
      while (size-- > 0)
  	{
  	  (command->my_cor->global_time == 0) ? check_instru() :
	    (command->my_cor->global_time--);
  	  command->my_cor = command->my_cor->next;
	  command->no_fork_champ = my_no_fork_champ();
  	}
      (die >= cycle_die) ? over = how_many_alive(), die = 0 : 0;
      (command->live >= NBR_LIVE) ? cycle_die = cycle_die - CYCLE_DELTA,
	command->live = 0 : 0;
    }
}

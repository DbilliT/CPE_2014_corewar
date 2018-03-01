/*
** my_battle.c for my_battle in /home/bechad_p/rendu/Corewar/VM/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Wed Dec 10 18:23:25 2014 Pierre Bechade
** Last update Sat Dec 13 21:43:05 2014 Pierre Bechade
*/

#include "vm.h"

unsigned char	*arena;

void			my_aff_list(t_command_list *list)
{
  t_command_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_put_nbr_e(tmp->reg[0]);
      tmp = tmp->next;
    }
}

int			my_calc_champ(t_command_list *list)
{
  t_command_list	*tmp;
  int			i;

  i = 0;
  tmp = list;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

void			my_trans_circ(t_command_list **list)
{
  t_command_list	*tmp;

  tmp = *list;
  while (tmp->next != NULL)
    {
      tmp = tmp->next;
    }
  tmp->next = *list;
}

void			my_kill_chain(t_command_list **list)
{
  t_command_list	*tmp;

  tmp = *list;
  while (tmp->next != command->my_cor)
    {
      tmp = tmp->next;
    }
  tmp->next = command->my_cor->next;
}

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

  i = 0;
  tmp = command->my_cor;
  nb = command->nb_champ;
  true_champ[0] = 0;
  true_champ[1] = 0;
  true_champ[2] = 0;
  true_champ[3] = 0;
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

void			my_battle(unsigned char *map)
{
  t_command_list	*new;
  int			over;
  int			size;
  int			cycle;
  int			die;
  int			cycle_die;
  char			*inter[4];
  int			i;
  int			tmp;

  tmp = 0;
  i = 0;
  die = -1;
  over = -1;
  cycle = -1;
  command->winner = 0;
  (1) ? new = command->my_cor, cycle_die = CYCLE_TO_DIE, arena = map : 0;
  while (++over, new != NULL)
    new = new->next;
  my_trans_circ(&command->my_cor);
  while (i != over)
    {
      inter[tmp] = command->my_cor->name_champ;
      CURRENT = CURRENT->next;
      tmp++;
      i++;
    }
  inter[tmp] = NULL;
  create_win(inter);
  //mod_mem(inter_map);
  my_set_cmd(over);
  while (++die, over >= 1 && ++cycle != command->my_dump)
    {
      size = command->nb_champ;
      while (size-- > 0)
  	{
  	  (command->my_cor->global_time == 0) ? check_instru(), inter_map[command->my_cor->pc] = CURRENT->reg[0], mod_mem(inter_map, CURRENT->pc) :
	    (command->my_cor->global_time--);
	  usleep(3000);
	  //my_put_nbr(CURRENT->reg[0]);
	  //my_putchar('\n');
  	  command->my_cor = command->my_cor->next;
	  command->no_fork_champ = my_no_fork_champ();
  	}
      (die >= cycle_die) ? over = how_many_alive(), die = 0 : 0;
      (command->live >= NBR_LIVE) ? cycle_die = cycle_die - CYCLE_DELTA,
	command->live = 0 : 0;
    }
}

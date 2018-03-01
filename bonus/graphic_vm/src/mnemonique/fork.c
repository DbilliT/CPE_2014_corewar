/*
** fork.c for fork in /home/bechad_p/rendu/Corewar/VM/src/mnemonique
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Dec  9 20:24:43 2014 Pierre Bechade
** Last update Sun Dec 14 21:31:42 2014 paul david
*/

#include "vm.h"

void	my_test()
{
  int	i;

  i = 0;
  while (i != 10)
    {
      my_put_nbr_e(command->my_cor->reg[0]);
      my_putchar('\n');
      my_putstr(command->my_cor->name_champ);
      my_putchar('\n');
      CURRENT = CURRENT->next;
      i++;
    }
}

void			my_fork(int para)
{
  t_command_list	*tmp;
  int			i;

  my_putstr(" -- Fork --\n");
  tmp = NULL;
  tmp = my_xmalloc(sizeof(t_command_list));
  i = 0;
  while (i != REG_NUMBER)
    {
      tmp->reg[i] = CURRENT->reg[i];
      i++;
    }
  tmp->prog_nbr = CURRENT->prog_nbr;
  tmp->load_ad = CURRENT->load_ad;
  tmp->name_cor = my_strdup(CURRENT->name_cor);
  tmp->carry = CURRENT->carry;
  tmp->pc = (PC + (para % IDX_MOD)) % MEM_SIZE;
  tmp->is_alive = CURRENT->is_alive;
  tmp->global_time = 799;
  CURRENT->global_time = 800;
  tmp->name_champ = my_strdup(CURRENT->name_champ);
  tmp->desc_champ = my_strdup(CURRENT->desc_champ);
  tmp->next = CURRENT->next;
  CURRENT->next = tmp;
  //my_test();
}

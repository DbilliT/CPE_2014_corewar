/*
** lfork.c for lfork in /home/bechad_p/rendu/Corewar/VM/src/mnemonique
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Sun Dec 14 01:46:02 2014 Pierre Bechade
** Last update Sun Dec 14 21:31:54 2014 paul david
*/

#include "vm.h"

void			my_lfork(int para)
{
  t_command_list	*tmp;
  int			i;

  my_putstr(" -- Lfork --\n");
  tmp = NULL;
  tmp = my_xmalloc(sizeof(t_command_list));
  i = REG_NUMBER - 1;
  while (i >= 0)
    {
      tmp->reg[i] = CURRENT->reg[i];
      i--;
    }
  tmp->prog_nbr = CURRENT->prog_nbr;
  tmp->load_ad = CURRENT->load_ad;
  tmp->name_cor = my_strdup(CURRENT->name_cor);
  tmp->carry = CURRENT->carry;
  tmp->pc = (PC + para) % MEM_SIZE;
  tmp->is_alive = CURRENT->is_alive;
  tmp->global_time = 999;
  CURRENT->global_time = 1000;
  tmp->name_champ = my_strdup(CURRENT->name_champ);
  tmp->desc_champ = my_strdup(CURRENT->desc_champ);
  tmp->next = CURRENT->next;
  CURRENT->next = tmp;
  //my_test();
}

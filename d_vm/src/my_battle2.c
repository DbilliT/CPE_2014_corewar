/*
** my_battle2.c for my_battle2 in /home/david_k/rendu/CPE_2014_corewar/d_vm/src
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Sun Dec 14 20:38:39 2014 paul david
** Last update Sun Dec 14 20:39:47 2014 paul david
*/

#include "vm.h"

void                    my_aff_list(t_command_list *list)
{
  t_command_list        *tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_put_nbr_e(tmp->reg[0]);
      tmp = tmp->next;
    }
}

int                     my_calc_champ(t_command_list *list)
{
  t_command_list        *tmp;
  int                   i;

  i = 0;
  tmp = list;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

void                    my_trans_circ(t_command_list **list)
{
  t_command_list        *tmp;

  tmp = *list;
  while (tmp->next != NULL)
    {
      tmp = tmp->next;
    }
  tmp->next = *list;
}

void                    my_kill_chain(t_command_list **list)
{
  t_command_list        *tmp;

  tmp = *list;
  while (tmp->next != command->my_cor)
    {
      tmp = tmp->next;
    }
  tmp->next = command->my_cor->next;
}

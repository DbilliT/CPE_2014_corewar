/*
** free_list.c for free_list.c in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Tue Dec  9 15:00:19 2014 paul david
** Last update Tue Dec  9 15:01:28 2014 paul david
*/

#include "asm.h"

void	free_code(t_code **list)
{
  if ((*list)->next != NULL)
    free_code(&(*list)->next);
  free((*list));
}

void	free_label(t_label_list **list)
{
  if ((*list)->next != NULL)
    free_label(&(*list)->next);
  free((*list));
}

void		free_label_data(t_label_list **list)
{
  t_label_list	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      free(tmp->name);
      tmp = tmp->next;
    }
}

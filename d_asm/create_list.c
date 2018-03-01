/*
** create_list.c for create_list in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Mon Dec  1 16:05:00 2014 paul david
** Last update Sun Dec 14 21:27:48 2014 paul david
*/

#include "asm.h"

void		add_end_code(t_code **list, void *data, int size)
{
  t_code	*new;
  t_code	*temp;

  new = my_x_malloc(sizeof(t_code));
  new->data = data;
  new->size = size;
  new->next = NULL;
  if (*list == NULL)
    *list = new;
  else
    {
      temp = *list;
      while (temp->next != NULL)
        temp = temp->next;
      temp->next = new;
    }
}

void		add_end(t_label_list **list, char *name, int line)
{
  t_label_list	*new;
  t_label_list	*temp;

  new = my_x_malloc(sizeof(t_label_list));
  new->name = name;
  new->line = line;
  new->next = NULL;
  if (*list == NULL)
    *list = new;
  else
    {
      temp = *list;
      while (temp->next != NULL)
        temp = temp->next;
      temp->next = new;
    }
}

void		create_label_list(t_label_list **list, char *buffer, int *i, int j)
{
  char		*name;
  int		count;

  count = 0;
  name = my_x_malloc(sizeof(char) * 2);
  while (buffer[*i] != LABEL_CHAR)
    {
      name = my_x_realloc(&name, 2 + count);
      name[count] = buffer[*i];
      count++;
      *i = *i + 1;
    }
  name[count] = '\0';
  add_end(&(*list), name, j);
  while (buffer[*i] != '\n' && buffer[*i] != '\0' &&
	 buffer [*i] != ' ' && buffer[*i] != '\t')
    *i= *i + 1;
}

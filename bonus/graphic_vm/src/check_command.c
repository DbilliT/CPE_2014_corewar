/*
** corewar.c for corewar in /home/deluss_c/rendu/test/corewartest
** 
** Made by Cédric de Lussigny
** Login   <deluss_c@epitech.net>
** 
** Started on  Thu Dec  4 11:05:00 2014 Cédric de Lussigny
** Last update Sun Dec 14 21:32:25 2014 paul david
*/

#include "vm.h"

t_command *command = NULL;

void            add_end_sort(t_command_list **list, t_command_list *node)
{
  t_command_list        *temp;

  node->next = NULL;
  if (*list == NULL)
    *list = node;
  else
    {
      temp = *list;
      while (temp->next != NULL)
        temp = temp->next;
      temp->next = node;
    }
}

void            add_end_code(t_command_list **list, char *data, int a, int b)
{
  t_command_list        *new;
  t_command_list        *temp;

  new = my_xmalloc(sizeof(t_command_list));
  new->name_cor = data;
  new->prog_nbr = a;
  new->load_ad = b;
  new->carry = 0;
  new->global_time = 0;
  new->is_alive = 1;
  new->name_champ = NULL;
  new->desc_champ = NULL;
  new->action = NULL;
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

int	check_command(int ac, char **av)
{
  int	j;
  int	i;

  command = my_xmalloc(sizeof(t_command));
  command->my_dump = 0;
  command->my_cor = NULL;
  j = 0;
  i = 0;
  if (ac == 1)
    {
      my_putstr_e("Syntaxe : corewar [-dump nbr_cycle]");
      my_putstr_e(" [-n prog_number] [-a load_address] [prog_name]...\n");
      exit (0);
    }
  while (av[++j] != NULL)
    i = check_arg(av[j], av, &j);
  if (i < 2 || i > 4)
    is_error("wrong number of champ\n");
  check_number_used();
  return (0);
}

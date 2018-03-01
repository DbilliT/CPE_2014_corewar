/*
** fill_champ.c for fill_champ in /home/bechad_p/rendu/Corewar/VM/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Sat Dec 13 14:35:12 2014 Pierre Bechade
** Last update Sat Dec 13 16:43:23 2014 Pierre Bechade
*/

#include "vm.h"

int                     number_of_champ()
{
  t_command_list        *tmp;
  int                   i;

  tmp = command->my_cor;
  i = 0;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  return (i);
}

void    fill_struct_champ1(LIST *tmp, unsigned char *my_tab, int champ_nbr, char *mapi)
{
  int   offset;
  int   i;

  offset = (MEM_SIZE / champ_nbr) * (tmp->prog_nbr - 1);
  tmp->pc = offset;
  tmp->reg[0] = tmp->prog_nbr;
  i = 0;
  while (i != tmp->size_act)
    {
      if (my_tab[offset] != '\0')
        is_error("Overlap");
      mapi[offset] = tmp->prog_nbr;
      my_tab[offset] = tmp->action[i];
      offset++;
      if (offset == MEM_SIZE)
        offset = 0;
      i++;
    }
}

void    fill_struct_champ2(t_command_list *tmp, unsigned char *my_tab, char *mapi)
{
  int   offset;
  int   i;

  offset = tmp->load_ad;
  tmp->pc = offset;
  tmp->reg[0] = tmp->prog_nbr;
  i = 0;
  while (i != tmp->size_act)
    {
      if (my_tab[offset] != '\0')
        is_error("Overlap");
      mapi[offset] = tmp->prog_nbr;
      my_tab[offset] = tmp->action[i];
      offset++;
      if (offset == MEM_SIZE)
        offset = 0;
      i++;
    }
}

void    fill_struct_champ3(t_command_list *tmp2, unsigned char *my_tab, int j, char *mapi)
{
  int   offset;
  int   i;

  offset = tmp2->load_ad;
  tmp2->pc = offset;
  tmp2->reg[0] = j + 1;
  i = 0;
  while (i != tmp2->size_act)
    {
      if (my_tab[offset] != '\0')
        is_error("Overlap");
      mapi[offset] = j + 1;
      my_tab[offset] = tmp2->action[i];
      offset++;
      if (offset == MEM_SIZE)
        offset = 0;
      i++;
    }
}

void    fill_struct_champ4(LIST *tmp2, UNS_C *my_tab, int j, int champ_nbr, char *mapi)
{
  int   offset;
  int   i;

  offset = 0;
  offset = (MEM_SIZE / champ_nbr) * j;
  tmp2->pc = offset;
  tmp2->reg[0] = j + 1;
  i = 0;
  while (i != tmp2->size_act)
    {
      if (my_tab[offset] != '\0')
        is_error("Overlap");
      mapi[offset] = j + 1;
      my_tab[offset] = tmp2->action[i];
      offset++;
      if (offset == MEM_SIZE)
        offset = 0;
      i++;
    }
}

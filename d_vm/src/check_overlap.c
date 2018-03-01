/*
** check_overlap.c for check_overlap in /home/deluss_c/rendu/test/corechamp/VM/src
** 
** Made by Cédric de Lussigny
** Login   <deluss_c@epitech.net>
** 
** Started on  Tue Dec  9 22:37:59 2014 Cédric de Lussigny
** Last update Sun Dec 14 11:39:51 2014 Pierre Bechade
*/

#include "vm.h"

unsigned char	*my_set_zero(unsigned char *my_tab)
{
  int		i;

  i = 0;
  while (i < MEM_SIZE)
    {
      my_tab[i] = '\0';
      i++;
    }
  return (my_tab);
}

unsigned char	*creat_tab()
{
  unsigned char	*my_tab;

  my_tab = my_xmalloc(sizeof(char) * (MEM_SIZE));
  my_tab = my_set_zero(my_tab);
  return (my_tab);
}

unsigned char	*class_champ2(UNS_C *my_tab, int champ_nbr, char *order)
{
  LIST		*tmp2;
  int		j;

  tmp2 = command->my_cor;
  j = 0;
  while (tmp2 != NULL)
    {
      if (tmp2->prog_nbr == 0)
        {
          while (order[j] == '1')
            j++;
          order[j] = '1';
          if (tmp2->load_ad != -1)
            fill_struct_champ3(tmp2, my_tab, j);
          else if (tmp2->load_ad == -1)
            fill_struct_champ4(tmp2, my_tab, j, champ_nbr);
        }
      tmp2 = tmp2->next;
    }
  return (my_tab);
}

unsigned char		*class_champ(unsigned char *my_tab, int champ_nbr)
{
  t_command_list	*tmp;
  char			*order;

  tmp = command->my_cor;
  order = my_strdup("0000");
  while (tmp != NULL)
    {
      if (tmp->prog_nbr != 0)
	{
	  order[tmp->prog_nbr - 1] = '1';
	  if (tmp->load_ad == -1)
	    fill_struct_champ1(tmp, my_tab, champ_nbr);
	  else if (tmp->load_ad != -1)
	    fill_struct_champ2(tmp, my_tab);
	}
      tmp = tmp->next;
    }
  my_tab = class_champ2(my_tab, champ_nbr, order);
  return (my_tab);
}

unsigned char		*check_overlap()
{
  unsigned char		*my_tab;
  int			champ_nbr;

  my_tab = creat_tab();
  champ_nbr = number_of_champ();
  my_tab = class_champ(my_tab, champ_nbr);
  return (my_tab);
}

/*
** my_check_cor.c for my_check_cor in /home/bechad_p/rendu/Corewar/VM/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Dec  9 21:02:03 2014 Pierre Bechade
** Last update Sun Dec 14 21:21:23 2014 paul david
*/

#include "vm.h"

void			my_check_cor()
{
  t_command_list	*new;

  new = command->my_cor;
  while (new != NULL)
    {
      my_vm(new->name_cor);
      new = new->next;
    }
}

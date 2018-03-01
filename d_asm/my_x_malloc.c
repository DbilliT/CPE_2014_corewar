/*
** my_x_malloc.c for xmalloc in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Sun Nov 30 13:24:42 2014 paul david
** Last update Mon Dec  8 15:20:27 2014 paul david
*/

#include "asm.h"

void	*my_x_malloc(int size)
{
  void	*new;

  if ((new = malloc(size)) == NULL)
    {
      my_putstr_error("Can't perform malloc");
      exit(0);
    }
  return (new);
}

void	*my_x_realloc(char **str, int size)
{
  void	*new;

  if ((new = realloc(*str, size)) == NULL)
    {
      my_putstr_error("Can't perform malloc");
      exit(0);
    }
  else
    *str = new;
  return (new);
}

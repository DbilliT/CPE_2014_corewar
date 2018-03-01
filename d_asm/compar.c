/*
** compar.c for compar in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Sat Nov 29 15:22:24 2014 paul david
** Last update Mon Dec  8 17:16:36 2014 paul david
*/

#include "asm.h"

int	is_number(char c)
{
  if (c >= '0' && c <= '9')
    return (0);
  return (1);
}

void	is_s(char *pathname)
{
  if (pathname[my_strlen(pathname) - 1] != 's' ||
      pathname[my_strlen(pathname) - 2] != '.')
    {
      my_putstr_error("The file is not a '.s'\n");
      exit(0);
    }
}

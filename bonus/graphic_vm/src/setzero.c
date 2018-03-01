/*
** setzero.c for zetsero in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Tue Dec  9 14:23:34 2014 paul david
** Last update Sat Dec 13 10:49:44 2014 Pierre Bechade
*/

#include "vm.h"

void		my_memset(void	*s, int value, int size)
{
  unsigned char	*str;

  str = s;
  while (size > 0)
    {
      *str = (unsigned char)value;
      str++;
      size--;
    }
}

void	setzero_uns(unsigned char *str, int j)
{
  int	i;

  i = 0;
  while (i != j)
    {
      str[i] = 0;
      i++;
    }
}

void	setzero(char *str, int j)
{
  int	i;

  i = 0;
  while (i != j)
    {
      str[i] = 0;
      i++;
    }
}

/*
** aff.c for affichage in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Sun Nov 23 16:02:10 2014 paul david
** Last update Mon Nov 24 19:40:27 2014 paul david
*/

#include "asm.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putstr_error(char *str)
{
  write(2, str, my_strlen(str));
}

void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

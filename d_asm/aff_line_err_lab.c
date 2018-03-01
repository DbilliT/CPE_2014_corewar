/*
** aff_line_err_lab.c for aff_line_err_lab in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Thu Dec  4 11:37:58 2014 paul david
** Last update Mon Dec  8 18:00:02 2014 paul david
*/

#include "asm.h"

void	label_error_line(int j, char *buffer, int i)
{
  char	*label;
  int	count;

  count = 0;
  label = my_x_malloc(sizeof(char) * 2);
  while (buffer[i] != ' ' && buffer[i] != '\t' && buffer[i] != ','
	 && buffer[i] != '\n' && buffer[i] != '\0')
    {
      label = my_x_realloc(&label, 2 + count);
      label[count] = buffer[i];
      count++;
      i++;
    }
  label[count] = '\0';
  my_putstr_error("label ");
  my_putstr_error(label);
  my_putstr_error(" undefine line ");
  my_put_nbr_error(j);
  free(label);
  exit(0);
}

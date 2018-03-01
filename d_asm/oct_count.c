/*
** oct_count.c for oct_count.c in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Mon Dec  8 15:36:19 2014 paul david
** Last update Sun Dec 14 16:32:36 2014 paul david
*/

#include "asm.h"

int	oct_count_part(char *buffer, int *i, int j, int k)
{
  if (buffer[*i] == '\n')
    return (-1);
  if (is_label_def(buffer, *i, j) == 0)
    {
      while (buffer[*i] != ' ' && buffer[*i] != '\t' &&
             buffer[*i] != '\n' && buffer[*i] != '\0')
	*i = *i + 1;
      return (-1);
    }
  while (op_tab[k].mnemonique != 0 &&
	 (my_strncmp(op_tab[k].mnemonique, buffer,
		     my_strlen(op_tab[k].mnemonique), *i) != 0
	  || (buffer[*i + my_strlen(op_tab[k].mnemonique)] != ' '
	      && buffer[*i + my_strlen(op_tab[k].mnemonique)] != '\t')))
    k++;
  if (op_tab[k].mnemonique == 0)
    {
      while (buffer[*i] != ' ' && buffer[*i] != '\t' &&
             buffer[*i] != '\n' && buffer[*i] != '\0')
        *i = *i + 1;
      return (-1);
    }
  return (k);
}

int	oct_count(char *buffer, int *i, int j, int oct)
{
  int	k;

  if ((k = oct_count_part(buffer, &(*i), j, 0)) == -1)
    return (0);
  *i = *i + my_strlen(op_tab[k].mnemonique);
  oct = (instru_tab[k].codage == 1) ? oct + 2 : oct + 1;
  while ((buffer[*i] == ' ' || buffer[*i] == '\t' || buffer[*i] == ',')
         && (buffer[*i] != '\n' && buffer[*i] != '\0'))
    {
      while ((buffer[*i] == ' ' || buffer[*i] == '\t' || buffer[*i] == ',')
             && (buffer[*i] != '\n' && buffer[*i] != '\0'))
        *i = *i + 1;
      if (buffer[*i] == 'r' && (buffer[*i - 1] == ',' ||
				buffer[*i - 1] == ' ' || buffer[*i - 1] =='\t'))
        oct++;
      else if (buffer[*i] == '%' && instru_tab[k].oct == 4)
        oct = oct + 4;
      else if ((buffer[*i - 1] == ',' || buffer[*i - 1] == ' ' ||
		buffer[*i - 1] == '\t') && (buffer[*i] == LABEL_CHAR
					    || is_number(buffer[*i]) == 0 || buffer[*i] == '%'))
	oct = oct + 2;
      while (buffer[*i] != ' ' && buffer[*i] != '\t' && COND)
	*i = *i + 1;
    }
  return (oct);
}

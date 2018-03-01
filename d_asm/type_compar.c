/*
** type_compar.c for type_compar in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Tue Dec  2 12:27:11 2014 paul david
** Last update Tue Dec  9 15:13:59 2014 paul david
*/

#include "asm.h"

char	is_reg(char *buffer, int i, int j)
{
  char	*nbr;
  int	count;

  count = 0;
  nbr = my_x_malloc(sizeof(char) * 3);
  nbr[2] = '\0';
  while (buffer[i] != '\0' && buffer[i] != '\n' && buffer[i] != ','
	 && buffer[i] != ' ' && buffer[i] != '\t')
    {
      if (buffer[i] < '1' && buffer[i] > '9')
        message_error_line(j);
      if (count >= 2)
        message_error_line(j);
      nbr[count] = buffer[i];
      i++;
      count++;
    }
  nbr[count] = '\0';
  if (my_getnbr(nbr) > 16)
    message_reg_line(j);
  free(nbr);
  return (T_REG);
}

void	is_dir_part(char *buffer, int i, int j)
{
  if (buffer[i] != LABEL_CHAR && is_number(buffer[i]) != 0 && buffer[i] != '-')
    message_error_line(j);
}

char	is_dir(char *buffer, int i, int j, int k)
{
  char	*nbr;
  int	count;

  count = 0;
  is_dir_part(buffer, i, j);
  if (buffer[i] != LABEL_CHAR)
    {
      nbr = my_x_malloc(sizeof(char) * 50);
      while (buffer[i] != '\0' && buffer[i] != '\n' &&
	     buffer[i] != ',' && buffer[i] != ' ' && buffer[i] != '\t')
        {
          if (is_number(buffer[i]) != 0 && buffer[i] != '-')
            message_error_line(j);
          nbr[count++] = buffer[i++];
        }
      nbr[count] = '\0';
      if ((instru_tab[k].oct == 2 && my_getnbr(nbr) > 65535) ||
          (my_getnbr(nbr) == 0 && my_strlen(nbr) != 1))
        warning_dir_line(j);
      if (my_getnbr(nbr) == 0 && my_strlen(nbr) != 1)
        warning_dir_line(j);
      free(nbr);
      return (T_DIR);
    }
  return (is_label_call(buffer, ++i, j) == 0 ? T_DIR : 0);
}

char	is_indir(char *buffer, int i, int j)
{
  char	*nbr;
  int	count;

  count = 0;
  if (buffer[i] == LABEL_CHAR)
    if (is_label_call(buffer, ++i, j) == 0)
      return (T_IND);
  nbr = my_x_malloc(sizeof(char) * 50);
  while (buffer[i] != '\0' && buffer[i] != ',' && buffer[i] != ' '
	 && buffer[i] != '\t' && buffer[i] != '\n')
    {
      if (is_number(buffer[i]) != 0 && buffer[i] != '-')
	message_error_line(j);
      nbr[count] = buffer[i];
      i++;
      count++;
    }
  nbr[count] = '\0';
  if (my_getnbr_sh(nbr) > IDX_MOD)
    warning_indir_line(j);
  free(nbr);
  return (T_IND);
}

/*
** check_error.c for check_error in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Tue Dec  2 12:32:21 2014 paul david
** Last update Sun Dec 14 00:44:45 2014 paul david
*/

#include "asm.h"

void	check_instru_line_part(char *buffer, int *i, int j)
{
  while (buffer[*i] == ' ' || buffer[*i] == '\t')
    {
      if (buffer[*i] == '\0' && buffer[*i] == '\n' && buffer[*i] == ',')
	message_error_line(j);
      *i = *i + 1;
    }
}

void	is_point(char *buffer, int *i, int j)
{
  if (buffer[*i] == COMMENT_CHAR)
    {
      while (buffer[*i + 1] != '\n')
	*i = *i + 1;
    }
  else if ((buffer[*i - 1] == ' ' || buffer [*i - 1] == '\t')
	   && (buffer[*i] != ' ' && buffer[*i] != '\t'))
    {
      message_error_line(j);
      exit(0);
    }
}

void	check_instru_line(char *buffer, int i, int j, int nbr_instru)
{
  int	k;
  char	t_instru;

  k = 0;
  while (buffer[i] != '\0' && buffer[i] != '\n')
    {
      check_instru_line_part(buffer, &i, j);
      if (buffer[i] == 'r')
        t_instru = is_reg(buffer, ++i, j);
      else if (buffer[i] == DIRECT_CHAR)
        t_instru = is_dir(buffer, ++i, j, nbr_instru);
      else if (buffer[i] == LABEL_CHAR || is_number(buffer[i]) == 0
	       || buffer[i] == '-')
        t_instru = is_indir(buffer, i, j);
      else
        message_error_line(j);
      if ((op_tab[nbr_instru].type[k] & t_instru) != t_instru)
	message_error_line(j);
      while (buffer[i] != '\0' && buffer[i] != '\n' && buffer[i] != ',')
	{
	  (op_tab[nbr_instru].nbr_args == k + 1) ? is_point(buffer, &i, j) : 0;
	  i++;
	}
      (buffer[i] == ',') ? k++, i++ : 0;
    }
}

void	check_prog_line(char *buffer, int *i, int j)
{
  int	k;
  int	offset;
  int	nbr_instru;

  k = 0;
  nbr_instru = 1;
  while (op_tab[k].mnemonique != 0 &&
	 (my_strncmp(op_tab[k].mnemonique, buffer, my_strlen(op_tab[k].mnemonique),
		     *i) != 0 || (buffer[*i + my_strlen(op_tab[k].mnemonique)] != ' ' &&
	  buffer[*i + my_strlen(op_tab[k].mnemonique)] != '\t')))
    k++;
  if (op_tab[k].mnemonique == 0 || (buffer[*i + my_strlen(op_tab[k].mnemonique)]
				    != ' ' && buffer[*i + my_strlen(op_tab[k].mnemonique)] != '\t'))
    message_error_line(j);
  *i = *i + my_strlen(op_tab[k].mnemonique);
  offset = *i;
  while (buffer[*i] && buffer[*i] != '\n')
    if (buffer[(*i)++] == ',')
      nbr_instru++;
  if (op_tab[k].nbr_args != (char)nbr_instru)
    message_error_line(j);
  check_instru_line(buffer, offset, j, k);
  while (buffer[*i] != '\n' && buffer[*i] != '\0')
    (*i)++;
}

int		check_prog(char *buffer, int i, int j, t_label_list **label_list)
{
  static int	rec = 0;

  while ((buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n')
	 && buffer[i] != '\0')
    if (buffer[i++] == '\n')
      j++;
  if (buffer[i] == '\0' && rec == 0)
    no_instru_err();
  else if (buffer[i] == '\0' && rec == 1)
    return (0);
  if (buffer[i] == COMMENT_CHAR)
    while (buffer[i] != '\n')
      i++;
  else
    {
      rec = 1;
      if (is_label_def(buffer, i, j) == 0)
	create_label_list(&(*label_list), buffer, &i, j);
      else
	check_prog_line(buffer, &i, j);
    }
  if (buffer[i] != '\0' && buffer[i + 1] != '\0')
    check_prog(buffer, i, j, &(*label_list));
  return (0);
}

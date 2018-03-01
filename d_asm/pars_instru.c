/*
** pars_instru.c for pars_instru in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Mon Dec  8 16:09:50 2014 paul david
** Last update Mon Dec  8 17:28:02 2014 paul david
*/

#include "asm.h"

int	pars_instru_line_part(char *buffer, int i)
{
  int	k;

  k = 0;
  while ((my_strncmp(op_tab[k].mnemonique, buffer,
                     my_strlen(op_tab[k].mnemonique), i) != 0 &&
          op_tab[k].mnemonique != 0) ||
         (buffer[i + my_strlen(op_tab[k].mnemonique)] != ' ' &&
          buffer[i + my_strlen(op_tab[k].mnemonique)] != '\t'))
    k++;
  return (k);
}

t_code		*pars_instru_line(char *buffer, int i, int j, t_label_list *label_list)
{
  int		k;
  static t_code	*code_list = NULL;

  k = pars_instru_line_part(buffer, i);
  instru_code(buffer, i, k, &code_list);
  i = i + my_strlen(op_tab[k].mnemonique);
  while (buffer[i] != '\0' && buffer[i] != '\n')
    {
      while (buffer[i] == ' ' || buffer[i] == '\t')
        i++;
      if (buffer[i] == 'r')
        encode_reg(buffer, ++i, &code_list);
      else if (buffer[i] == '%' && instru_tab[k].oct == 4)
        add_end_code(&code_list, encode_dir(buffer, ++i, j, label_list), 4);
      else if (buffer[i] == '%' && instru_tab[k].oct == 2)
        add_end_code(&code_list, encode_indir(buffer, ++i, j, label_list), 2);
      else
        add_end_code(&code_list, encode_indir(buffer, i, j, label_list), 2);
      while (buffer[i] != '\0' && buffer[i] != '\n' && buffer[i] != ',')
        i++;
      if (buffer[i] == ',')
	i++;
    }
  return (code_list);
}

t_code		*pars_instru(char *buffer, int i, int j, t_label_list *label_list)
{
  static t_code	*code_list = NULL;

  while ((buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n')
         && buffer[i] != '\0')
    if (buffer[i++] == '\n')
      j++;
  if (buffer[i] == '\0')
    return (code_list);
  if (is_label_def(buffer, i, j) == 0)
    while (buffer[i] != '\n' && buffer[i] != '\0' &&
           buffer [i] != ' ' && buffer[i] != '\t')
      i++;
  else if (buffer[i] == COMMENT_CHAR)
    while (buffer[i] != '\n' && buffer[i] != '\0')
      i++;
  else
    {
      code_list = pars_instru_line(buffer, i, j, label_list);
      while (buffer[i] != '\n' && buffer[i] != '\0')
        i++;
    }
  if (buffer[i] != '\0' || buffer[i + 1] != '\0')
    pars_instru(buffer, i, j, label_list);
  return (code_list);
}

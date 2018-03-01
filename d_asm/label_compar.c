/*
** label_compar.c for label_compar in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Sun Nov 30 13:37:38 2014 paul david
** Last update Mon Dec  8 15:19:44 2014 paul david
*/

#include "asm.h"

int	is_label_chars(char c, int j)
{
  int	i;

  i = 0;
  while (LABEL_CHARS[i] != '\0')
    {
      if (c == LABEL_CHARS[i])
        return (0);
      i++;
    }
  if (c != LABEL_CHAR && c != ' ' && c != '\t' && c != COMMENT_CHAR)
    message_error_line(j);
  return (1);
}

int	is_label_call(char *buffer, int i, int j)
{
  int	k;

  k = 0;
  while (buffer[i] != '\0' && buffer[i] != ',' && buffer[i] != ' ' &&
         buffer[i] != '\t' && LABEL_CHARS[k] != '\0')
    {
      while (LABEL_CHARS[k] != '\0' && buffer[i] != LABEL_CHARS[k])
        k++;
      if (LABEL_CHARS[k] != '\0')
        {
          k = 0;
          i++;
        }
    }
  if (LABEL_CHARS[k] == '\0' && buffer[i] != ' ' &&
      buffer[i] != '\t' && buffer[i] != ',' && buffer[i] != '\n')
    message_error_line(j);
  return (0);
}

int	is_label_def(char *buffer, int i, int j)
{
  while (buffer[i] != '\0' && is_label_chars(buffer[i], j) == 0)
    i++;
  return ((buffer[i] == LABEL_CHAR) ? 0 : 1);
}

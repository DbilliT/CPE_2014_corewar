/*
** encoding_label.c for encoding_label in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Mon Dec  8 15:50:56 2014 paul david
** Last update Sat Dec 13 12:33:55 2014 paul david
*/

#include "asm.h"

int	label_after(char *buffer, int j, t_label_list *list)
{
  int	i;
  int	line;
  int	oct;

  i = 0;
  line = 1;
  oct = 0;
  while ((line != list->line || buffer[i] == ' ' ||
          buffer[i] == '\t') && buffer[i] != '\0')
    if (buffer[i++] == '\n')
      line++;
  while (line != j)
    {
      if (buffer[i] == COMMENT_CHAR)
        while (buffer[i] != '\n' && buffer[i] != '\0')
          i++;
      oct = oct + oct_count(buffer, &i, line, 0);
      while (buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n')
        {
          if (buffer[i] == '\n')
            line++;
          i++;
        }
    }
  return (oct);
}

int	label_before(char *buffer, int j, t_label_list  *list)
{
  int	i;
  int	line;
  int	oct;

  i = 0;
  line = 1;
  oct = 0;
  while ((line != j || buffer[i] == ' ' || buffer[i] == '\t') &&
         buffer[i] != '\0')
    if (buffer[i++] == '\n')
      line++;
  while (line != list->line)
    {
      if (buffer[i] == COMMENT_CHAR)
        while (buffer[i] != '\n' && buffer[i] != '\0')
          i++;
      oct = oct + oct_count(buffer, &i, line, 0);
      while (buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n')
        {
          if (buffer[i] == '\n')
            line++;
          i++;
        }
    }
  return (oct);
}

unsigned short		encode_label_sh(char *buffer, int i, int j, t_label_list *list)
{
  unsigned short	oct;

  oct = 0;
  while (list != NULL &&
         (my_strncmp(list->name, buffer, my_strlen(list->name), i) != 0 ||
          (buffer[i + my_strlen(list->name)] != ' ' &&
           buffer[i + my_strlen(list->name)] != '\t'
           && buffer[i + my_strlen(list->name)] != ',' &&
           buffer[i + my_strlen(list->name)] != '\n')))
    list = list->next;
  if (list == NULL)
    label_error_line(j, buffer, i);
  if (list->line > j)
    oct = label_before(buffer, j, list);
  else if (list->line < j)
    oct = -1 * label_after(buffer, j, list);
  else
    oct = 0;
  return (oct);
}

unsigned int	encode_label_int(char *buffer, int i, int j, t_label_list *list)
{
  unsigned int	oct;

  oct = 0;
  while (list != NULL &&
         (my_strncmp(list->name, buffer, my_strlen(list->name), i) != 0 ||
          (buffer[i + my_strlen(list->name)] != ' ' &&
           buffer[i + my_strlen(list->name)] != '\t'
           && buffer[i + my_strlen(list->name)] != ',' &&
           buffer[i + my_strlen(list->name)] != '\n')))
    list = list->next;
  if (list == NULL)
    label_error_line(j, buffer, i);
  if (list->line > j)
    oct = label_before(buffer, j, list);
  else if (list->line < j)
    oct = -1 * label_after(buffer, j, list);
  else
    oct = 0;
  return (oct);
}

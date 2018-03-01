/*
** pars_head.c for pars_head in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Wed Nov 26 10:04:36 2014 paul david
** Last update Mon Dec  8 18:44:10 2014 paul david
*/

#include "asm.h"

void	line_head_comment(header_t *head, char *buffer, int i)
{
  int	j;

  j = 0;
  setzero(head->comment, COMMENT_LENGTH + 2);
  while (j != COMMENT_LENGTH + 2 && buffer[i] != '"' &&
        buffer[i] != '\0' && buffer[i] != '\n')
    {
      head->comment[j] = buffer[i];
      i++;
      j++;
    }
}

void	line_head_name(header_t *head, char *buffer, int i)
{
  int	j;

  j = 0;
  setzero(head->prog_name, PROG_NAME_LENGTH + 4);
  while (j != PROG_NAME_LENGTH + 4 && buffer[i] != '"' &&
        buffer[i] != '\0' && buffer[i] != '\n')
    {
      head->prog_name[j] = buffer[i];
      i++;
      j++;
    }
}

int	pars_comment_check(char *buffer, int *j, int *i, header_t *head)
{
  while (buffer[*i] == ' ' || buffer[*i] == '\t' || buffer[*i] == '\n')
    {
      if (buffer[*i] == '\n')
        *j = *j + 1;
      *i = *i + 1;
    }
  if (my_strncmp(COMMENT_CMD_STRING, buffer, 8, *i) != 0)
    {
      warning_comment_line(*j);
      return (0);
    }
  *i = *i + 8;
  while ((buffer[*i] != '"' && buffer [*i] != '\0' && buffer[*i] != '\n') &&
         (buffer[*i] == ' ' || buffer[*i] == '\t'))
    *i = *i + 1;
  if (buffer[*i] != '"' || buffer[*i + 1] == '"')
    message_error_line(*j);
  *i = *i + 1;
  line_head_comment(&(*head), buffer, *i);
  while (buffer[*i] != '"' && buffer[*i] != '\0' && buffer [*i] != '\n')
    *i = *i + 1;
  if (buffer[*i] != '"')
    message_error_line(*j);
  return (0);
}

void	pars_before_name(char *buffer, int *j, int *i)
{
  while (buffer[*i] == ' ' || buffer[*i] == '\t' ||
	 buffer[*i] == '#' || buffer[*i] == '\n')
    {
      if (buffer[*i] == '#')
        while (buffer[*i] != '\n' && buffer[*i] != '\0')
          *i = *i + 1;
      if (buffer[*i] == '\n')
        *j = *j + 1;
      *i = *i + 1;
    }
}

void	pars_name_check(char *buffer, int *j, int *i, header_t *head)
{
  pars_before_name(buffer, &(*j), &(*i));
  if (my_strncmp(NAME_CMD_STRING, buffer, 5, *i) != 0)
    message_error_line(*j);
  *i = *i + 5;
  while ((buffer[*i] != '"' && buffer [*i] != '\0' && buffer[*i] != '\n') &&
         (buffer[*i] == ' ' || buffer[*i] == '\t'))
    *i = *i + 1;
  if (buffer[*i] != '"' || buffer[*i + 1] == '"')
    message_error_line(*j);
  *i = *i + 1;
  line_head_name(&(*head), buffer, *i);
  while (buffer[*i] != '"' && buffer[*i] != '\0' && buffer[*i] != '\n')
    *i = *i + 1;
  if (buffer[*i] != '"')
    message_error_line(*j);
  *i = *i + 1;
  pars_comment_check(buffer, &(*j), &(*i), &(*head));
  *i = *i + 1;
}

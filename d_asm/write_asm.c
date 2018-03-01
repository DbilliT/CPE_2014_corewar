/*
** write_asm.c for write_asm in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Mon Dec  8 16:32:09 2014 paul david
** Last update Tue Dec  9 14:18:12 2014 paul david
*/

#include "asm.h"

char	*create_newpath(char *pathname)
{
  int	i;
  char	*newpath;

  i = 0;
  newpath = my_x_malloc(sizeof(char) * (my_strlen(pathname) + 3));
  newpath[my_strlen(pathname) + 2] = '\0';
  while (pathname[i + 1] != '\0')
    {
      newpath[i] = pathname[i];
      i++;
    }
  newpath[i] = 'c';
  newpath[i + 1] = 'o';
  newpath[i + 2] = 'r';
  return (newpath);
}

int		count_prog_size(t_code *code_list)
{
  t_code	*tmp;
  int		count;

  count = 0;
  tmp = code_list;
  while (tmp != NULL)
    {
      count = count + tmp->size;
      tmp = tmp->next;
    }
  return (count);
}

void	write_asm(header_t head, t_code *code_list, char *pathname)
{
  char	*newpath;
  int	fd;

  newpath = create_newpath(pathname);
  if (is_big_endian() == 1)
    head.prog_size = count_prog_size(code_list);
  else
    head.prog_size = convert_endian(count_prog_size(code_list));
  if ((fd = open(newpath, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)) == -1)
    {
      my_putstr_error("Failed to open\n");
      exit(0);
    }
  write(fd, &head, sizeof(header_t));
  while (code_list != NULL)
    {
      write(fd, code_list->data, code_list->size);
      free(code_list->data);
      code_list = code_list->next;
    }
  close(fd);
  free(newpath);
}

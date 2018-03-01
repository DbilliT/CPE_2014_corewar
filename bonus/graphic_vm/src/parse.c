/*
** parse.c for parse in /home/bechad_p/rendu/Corewar/VM
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Thu Dec  4 11:30:45 2014 Pierre Bechade
** Last update Sat Dec 13 23:55:51 2014 Pierre Bechade
*/

#include "vm.h"

void		my_fill_cmd(LIST **list, header_t head, unsigned char *act)
{
  static int	i = 0;
  int		j;
  LIST		*tmp;

  j = i;
  tmp = *list;
  while (j > 0)
    {
      tmp = tmp->next;
      j--;
    }
  tmp->name_champ = my_strdup(head.prog_name);
  tmp->desc_champ = my_strdup(head.comment);
  if (is_big_endian() == 0)
    tmp->size_act = convert_endian(head.prog_size);
  else
    tmp->size_act = head.prog_size;
  tmp->action = act;
  i++;
}

void			my_vm(const char *pathname)
{
  int			fd;
  int			rd;
  int			i;
  unsigned char		*buff;
  header_t		check;

  i = 0;
  buff = my_xmalloc(sizeof(unsigned char) * 4097);
  while (pathname[i] != '.')
    i++;
  (pathname[i + 1] != 'c' || pathname[i + 2] != 'o' ||
   pathname[i + 3] != 'r' || pathname[i + 4] != '\0') ? check_file() : (0);
  ((fd = open(pathname, O_RDONLY)) < 0) ? check_access(pathname, fd) : (0);
  ((rd = read(fd, &check, COMMENT_LENGTH + PROG_NAME_LENGTH + 16))
   != COMMENT_LENGTH + PROG_NAME_LENGTH + 16) ? check_header(fd) : (0);
  if (is_big_endian() == 0)
    ((rd = read(fd, buff, convert_endian(check.prog_size)))
     != convert_endian(check.prog_size)) ? check_prog_size(rd, fd) : (0);
  else
    if ((rd = read(fd, buff, check.prog_size)) != check.prog_size)
      check_prog_size(rd, fd);
  buff[rd] = '\0';
  close(fd);
  my_fill_cmd(&command->my_cor, check, buff);
  (check.magic != -209458688) ? my_check_magic() : 0;
}

/*
** asm.c for asm in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Sun Nov 23 15:32:40 2014 paul david
** Last update Tue Dec  9 15:04:46 2014 paul david
*/

#include "asm.h"
#include "op.h"

void		pars_header(char *buffer, char *pathname)
{
  header_t	head;
  t_label_list	*label_list;
  t_code	*code_list;
  int		i;
  int		j;

  i = 0;
  j = 1;
  label_list = NULL;
  code_list = NULL;
  my_memset(&head, 0, sizeof(header_t));
  head.magic = (is_big_endian() == 1) ? COREWAR_EXEC_MAGIC
    : convert_endian(COREWAR_EXEC_MAGIC);
  head.prog_size = 0;
  pars_name_check(buffer, &j, &i, &head);
  check_prog(buffer, i, j, &label_list);
  code_list = pars_instru(buffer, i, j, label_list);
  write_asm(head, code_list, pathname);
  free_code(&code_list);
  free_label_data(&label_list);
  free_label(&label_list);
}

int	my_asm(char *pathname)
{
  int	fd;
  int	r;
  char	buffer[4096];

  is_s(pathname);
  if ((fd = open(pathname, O_RDONLY)) == -1)
    {
      my_putstr_error("File ");
      my_putstr_error(pathname);
      my_putstr_error(" not accessible\n");
      exit(0);
    }
  if ((r = read(fd, buffer, 4096)) == -1)
    {
      my_putstr_error("Read error\n");
      exit(0);
    }
  buffer[r] = '\0';
  close(fd);
  pars_header(buffer, pathname);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac != 2)
    {
      my_putstr_error("Error, usage : ./asm pathname\n");
      return (-1);
    }
  else
    my_asm(av[1]);
  return (0);
}

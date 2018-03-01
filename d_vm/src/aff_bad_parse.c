/*
** aff_bad_parse.c for aff_bad_parse in /home/bechad_p/rendu/Corewar/VM/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Sat Dec 13 11:33:51 2014 Pierre Bechade
** Last update Sat Dec 13 11:35:06 2014 Pierre Bechade
*/

#include "vm.h"

void	check_file()
{
  my_putstr_e("This file is not a .cor\n");
  exit(0);
}

void	check_access(const char *pathname, int fd)
{
  my_putstr_e("File ");
  my_putcons_e(pathname);
  my_putstr_e(" not accessible\n");
  close(fd);
  exit(-1);
}

void	check_header(int fd)
{
  my_putstr_e("Bad .cor : size header different.\n");
  close(fd);
  exit(0);
}

void	check_prog_size(int rd, int fd)
{
  my_putstr_e("Bad .cor : size prog_size different.\n");
  my_put_nbr_e(rd);
  close(fd);
  exit(0);
}

void	my_check_magic()
{
  my_putstr_e("Bad magic number\n");
  exit(0);
}

/*
** aff_err.c for aff_err in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Wed Nov 26 09:58:39 2014 paul david
** Last update Sun Nov 30 14:37:53 2014 paul david
*/

#include "asm.h"

void	warning_comment_line(int  j)
{
  my_putstr_error("Warning no comment at line ");
  my_put_nbr_error(j);
}

void	message_error_line(int  j)
{
  my_putstr_error("Syntaxe error line ");
  my_put_nbr_error(j);
  exit(0);
}

void	message_reg_line(int j)
{
  my_putstr_error("no such register line ");
  my_put_nbr_error(j);
  exit(0);
}

void	warning_dir_line(int j)
{
  my_putstr_error("Warning Direct too big line ");
  my_put_nbr_error(j);
}

void	warning_indir_line(int j)
{
  my_putstr_error("Warning Indirection to far line ");
  my_put_nbr_error(j);
}

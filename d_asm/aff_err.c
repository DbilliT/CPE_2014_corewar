/*
** aff_err.c for aff_err in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Tue Dec  2 11:51:27 2014 paul david
** Last update Tue Dec  2 11:55:29 2014 paul david
*/

#include "asm.h"

void	no_instru_err()
{
  my_putstr_error("No instruction\n");
  exit(0);
}

/*
** instru.c for instru in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Mon Dec  1 12:46:01 2014 paul david
** Last update Mon Dec  8 15:19:22 2014 paul david
*/

#include "asm.h"

t_instru	instru_tab[] =
  {
    {"live", 4, 0},
    {"ld", 4, 1},
    {"st", 4, 1},
    {"add", 4, 1},
    {"sub", 4, 1},
    {"and", 4, 1},
    {"or", 4, 1},
    {"xor", 4, 1},
    {"zjmp", 2, 0},
    {"ldi", 2, 1},
    {"sti", 2, 1},
    {"fork", 2, 0},
    {"lld", 4, 1},
    {"lldi", 2, 1},
    {"lfork", 2, 0},
    {"aff", 4, 1},
    {NULL, 0, 0}
  };

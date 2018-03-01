/*
** my_strncmp.c for my_strncmp in /home/david_k/rendu/Piscine_C_J06
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Mon Oct  6 15:48:20 2014 paul david
** Last update Sat Dec  6 17:30:27 2014 paul david
*/

#include "asm.h"

int	my_strncmp(char *s1, char *s2, int n, int k)
{
  int	i;

  n = n - 1;
  i = 0;
  if (n < 0)
    return (n * -1);
  else
    {
      while (n != 0 || (s1[i] != '\0' || s2[k] != '\0'))
	{
	  if (s1[i] != s2[k])
	    return (s1[i] - s2[k]);
	  i = i + 1;
	  k++;
	  n = n - 1;
	  if ((s1[i] == s2[k]) && n == 0)
	    return (0);
	}
    }
  return (0);
}

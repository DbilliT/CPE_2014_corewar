/*
** tools3.c for tools3 in /home/bechad_p/rendu/Corewar/VM/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Thu Dec  4 11:57:00 2014 Pierre Bechade
** Last update Mon Dec  8 13:43:04 2014 Pierre Bechade
*/

#include "vm.h"

void	*my_xmalloc(int size)
{
  void	*tmp;

  if ((tmp = malloc(size)) == NULL)
    {
      write(2, "Error malloc\n", 13);
      exit(0);
    }
  return (tmp);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	size;

  i = 0;
  if (my_strlen(s1) > my_strlen(s2))
    size = my_strlen(s2);
  else
    size = my_strlen(s1);
  while (size >= 0)
    {
      if (s1[i] > s2[i] && s2[i] != '*')
	return (s1[i] - s2[i]);
      if (s1[i] < s2[i] && s2[i] != '*')
	return (s1[i] - s2[i]);
      i++;
      size--;
    }
  return (0);
}

char	*my_strdup(char *src)
{
  int	i;
  char	*dest;

  i = 0;
  dest = my_xmalloc(sizeof(char) * (my_strlen(src) + 1));
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_b_zero(char *str, int size)
{
  int	i;

  i = 0;
  while (i != size)
    {
      str[i] = '\0';
      i++;
    }
  return (str);
}


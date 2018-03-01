/*
** tools2.c for tools2 in /home/bechad_p/rendu/Corewar/VM/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Thu Dec  4 11:56:45 2014 Pierre Bechade
** Last update Mon Dec  8 14:09:05 2014 Pierre Bechade
*/

#include "vm.h"

int	compt_word(char *str)
{
  int	i;
  int	compteur;

  i = 0;
  compteur = 0;
  while (str[i] == ' ')
    i = i + 1;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' && (str[i + 1] != ' ' || str[i + 1] == '\0'))
        {
          compteur = compteur + 1;
          i = i + 1;
        }
      i = i + 1;
    }
  return (compteur + 1);
}

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && n > 0)
    {
      dest[i] = src[i];
      i++;
      n--;
    }
  if (n != 0)
    dest[i] = '\0';
  return (dest);
}

char	**my_str_to_wordtab(char *str, char c)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  (1) ? i = 0, j = 0, k = 0 : 0;
  tab = my_xmalloc(sizeof(char *) * (my_strlen(str) + 1));
  while (str[i])
    {
      while (str[i] == c && str[i] != '\0')
        i++;
      if (str[i] != c && str[i] != '\0')
        {
          j = i;
          while (str[i] != c && str[i] != '\0')
            i++;
          tab[k] = my_xmalloc(sizeof(char) * (my_strlen(str) + 1));
          my_strncpy(tab[k], &str[j], (i - j));
          k++;
        }
      else
        i++;
    }
  tab[k] = NULL;
  return (tab);
}

void	my_putcons_e(const char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      write(2, &str[i], 1);
      i++;
    }
}

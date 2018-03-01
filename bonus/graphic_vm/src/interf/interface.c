#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "vm.h"

SDL_Surface *screen;
Mix_Music *music;

void my_pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

void	sreen_write(char *str, int x, int y, int size)
{
  SDL_Surface *text = NULL;
  SDL_Rect pos;
  TTF_Font *police = NULL;
  SDL_Color color = {255, 255, 255};
  
  TTF_Init();
  pos.x = x;
  pos.y = y;
  police = TTF_OpenFont("old_school_united.ttf", size);
  text = TTF_RenderText_Blended(police, str, color);
  SDL_BlitSurface(text, NULL, screen, &pos);
  TTF_CloseFont(police);
  SDL_FreeSurface(text);
  TTF_Quit();
}

void	set_mem()
{
  int	i;
  int	j;
  SDL_Surface *mem;
  SDL_Rect pos;

  j = 0;
  pos.x = 19;
  pos.y = 19;
  while (j != 64)
    {
      i = 0;
      while (i != 96)
	{
	  mem = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
	  SDL_FillRect(mem, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); 
	  SDL_BlitSurface(mem, NULL, screen, &pos);
	  pos.x++;
	  pos.y++;
	  mem = SDL_CreateRGBSurface(SDL_HWSURFACE, 8, 8, 32, 0, 0, 0, 0);
	  SDL_FillRect(mem, NULL, SDL_MapRGB(screen->format, 0, 0, 0)); 
	  SDL_BlitSurface(mem, NULL, screen, &pos);
	  pos.x--;
	  pos.y--;
	  pos.x += 12;
	  i = i + 1;
	}
      pos.x = 19;
      pos.y += 12;
      j = j + 1;
    }
  SDL_FreeSurface(mem);
}

void	place_chp(int x, int y, int i, char *str)
{
  SDL_Surface *chp;
  SDL_Rect pos;

  pos.x = x;
  pos.y = y;
  chp = SDL_CreateRGBSurface(SDL_HWSURFACE, 380, 104, 32, 0, 0, 0, 0);
  SDL_FillRect(chp, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); 
  SDL_BlitSurface(chp, NULL, screen, &pos);
  SDL_FreeSurface(chp);
  pos.x = x + 2;
  pos.y = y + 2;
  chp = SDL_CreateRGBSurface(SDL_HWSURFACE, 376, 100, 32, 0, 0, 0, 0);
  SDL_FillRect(chp, NULL, SDL_MapRGB(screen->format, 0, 0, 0)); 
  SDL_BlitSurface(chp, NULL, screen, &pos);
  SDL_FreeSurface(chp);
  pos.x = x + 25;
  pos.y = y + 25;
  chp = SDL_CreateRGBSurface(SDL_HWSURFACE, 50, 50, 32, 0, 0, 0, 0);
  SDL_FillRect(chp, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); 
  SDL_BlitSurface(chp, NULL, screen, &pos);
  SDL_FreeSurface(chp);
  pos.x = pos.x + 2;
  pos.y = pos.y + 2;
  chp = SDL_CreateRGBSurface(SDL_HWSURFACE, 46, 46, 32, 0, 0, 0, 0);
  if (i == 1)
    SDL_FillRect(chp, NULL, SDL_MapRGB(screen->format, 255, 34, 0));//rouge
  else if (i == 2)
    SDL_FillRect(chp, NULL, SDL_MapRGB(screen->format, 34, 0, 204));//bleu
  else if (i == 3)
    SDL_FillRect(chp, NULL, SDL_MapRGB(screen->format, 0, 170, 0));//vert
  else
    SDL_FillRect(chp, NULL, SDL_MapRGB(screen->format, 255, 204, 68));//jaune
  SDL_BlitSurface(chp, NULL, screen, &pos);
  sreen_write(str, (x + 95), (y + 25), 45);
  SDL_FreeSurface(chp);
}

char	*reg_nm(char *str, int sizemax)
{
  if (my_strlen(str) > sizemax)
    {
      str[sizemax - 2] = '.';
      str[sizemax - 1] = '.';
      str[sizemax] = '.';
      str[sizemax + 1] = '\0';
    }
  return (str);
}

void	set_menu(char **name)
{
  int	i;
  SDL_Surface *spc;
  SDL_Rect pos;

  i = 0;
  pos.x = 1204;
  pos.y = 14;
  spc = SDL_CreateRGBSurface(SDL_HWSURFACE, 380, 238, 32, 0, 0, 0, 0);
  SDL_FillRect(spc, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); 
  SDL_BlitSurface(spc, NULL, screen, &pos);
  pos.x = 1206;
  pos.y = 16;
  spc = SDL_CreateRGBSurface(SDL_HWSURFACE, 376, 234, 32, 0, 0, 0, 0);
  SDL_FillRect(spc, NULL, SDL_MapRGB(screen->format, 0, 0, 0)); 
  SDL_BlitSurface(spc, NULL, screen, &pos);
  sreen_write("Corewar .", 1230, 17, 68);
  sreen_write("- P. David", 1235, 85, 30);
  sreen_write("- P. Bechade", 1235, 125, 30);
  sreen_write("- C. de lussigny", 1235, 165, 30);
  sreen_write("- A. Tanyeres", 1235, 205, 30);
  while (name[i] != NULL)
    {
      name[i] = reg_nm(name[i], 13);
      if (i == 0)
	place_chp(1205, 283, 1, name[i]);
      if (i == 1)
	place_chp(1205, 417, 2, name[i]);
      if (i == 2)
	place_chp(1205, 553, 3, name[i]);
      if (i == 3)
	place_chp(1205, 687, 4, name[i]);
      i = i + 1;
    }
  SDL_FreeSurface(spc);
}

void	set_arena()
{
  SDL_Surface *ar;
  SDL_Rect pos;

  pos.x = 14;
  pos.y = 14;
  ar = SDL_CreateRGBSurface(SDL_HWSURFACE, 1160, 776, 32, 0, 0, 0, 0);
  SDL_FillRect(ar, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); 
  SDL_BlitSurface(ar, NULL, screen, &pos);
  SDL_FreeSurface(ar);
  pos.x = 15;
  pos.y = 15;
  ar = SDL_CreateRGBSurface(SDL_HWSURFACE, 1158, 774, 32, 0, 0, 0, 0);
  SDL_FillRect(ar, NULL, SDL_MapRGB(screen->format, 0, 0, 0)); 
  SDL_BlitSurface(ar, NULL, screen, &pos);
  SDL_FreeSurface(ar);
  set_mem();
  SDL_FreeSurface(ar);
}

void	create_win(char **nm_chp)
{
    SDL_Surface *imgf;
    SDL_Rect pos;
    Mix_Chunk *fight;

    pos.x = 0;
    pos.y = 0;
    SDL_Init(SDL_INIT_VIDEO);
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    fight = Mix_LoadWAV("Synth_nrt_115_wav.aax_0000.wav");
    Mix_PlayChannel(-1, fight, 0);
    music = Mix_LoadMUS("verdi-requiem.wav");
    Mix_PlayMusic(music, -1);
    screen = SDL_SetVideoMode(1600, 806, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Machine virtuelle - Corouxwar", NULL);
    imgf = SDL_LoadBMP("Bois-sombre.bmp");
    SDL_BlitSurface(imgf, NULL, screen, &pos);
    SDL_FreeSurface(imgf);
    set_arena();
    set_menu(nm_chp);
    SDL_Flip(screen);
    SDL_FreeSurface(imgf);
}

char	*my_cpy_dup(char *str, int size)
{
  int	i;
  char	*new;

  i = 0;
  new = malloc(sizeof(char) * MEM_SIZE + 1);
  while (i != MEM_SIZE + 1)
    {
      new[i] = str[i];
      i++;
    }
  return (new);
}

void	mod_mem(char *tmp, int pc)
{
  int	i;
  int	j;
  int	k;
  SDL_Surface *mem;
  SDL_Rect pos;
  char	*str;

  str = my_cpy_dup(tmp, MEM_SIZE);
  str[pc] = 5;
  j = 0;
  k = 0;
  pos.x = 20;
  pos.y = 20;
  while (j != 64)
    {
      i = 0;
      while (i != 96)
	{
	  mem = SDL_CreateRGBSurface(SDL_HWSURFACE, 8, 8, 32, 0, 0, 0, 0);
	  if (str[k] == 1)
	    SDL_FillRect(mem, NULL, SDL_MapRGB(screen->format, 255, 34, 0));//rouge
	  else if (str[k] == 2)
	    SDL_FillRect(mem, NULL, SDL_MapRGB(screen->format, 34, 0, 204));//bleu
	  else if (str[k] == 3)
	    SDL_FillRect(mem, NULL, SDL_MapRGB(screen->format, 0, 170, 0));//vert
	  else if (str[k] == 4)
	    SDL_FillRect(mem, NULL, SDL_MapRGB(screen->format, 255, 204, 68));//jaune
	  else if (str[k] == 5)
	    SDL_FillRect(mem, NULL, SDL_MapRGB(screen->format, 0, 0, 0));//jaune
	  else
	    SDL_FillRect(mem, NULL, SDL_MapRGB(screen->format, 255, 255, 255));//blanc
	  SDL_BlitSurface(mem, NULL, screen, &pos);
	  SDL_FreeSurface(mem);
	  pos.x += 12;
	  k = k + 1;
	  i = i + 1;
	}
      pos.x = 20;
      pos.y += 12;
      j = j + 1;
    }
  SDL_Flip(screen);
}

void	set_winner(char *str)
{
  SDL_Surface *spc;
  SDL_Rect pos;
  Mix_Chunk *ko;

  Mix_FreeMusic(music);
  Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
  ko = Mix_LoadWAV("Synth_nrt_119_wav.aax_0000.wav");
  Mix_PlayChannel(-1, ko, 0);
  str = reg_nm(str, 15);
  pos.x = 119;
  pos.y = 277;
  spc = SDL_CreateRGBSurface(SDL_HWSURFACE, 952, 252, 32, 0, 0, 0, 0);
  SDL_FillRect(spc, NULL, SDL_MapRGB(screen->format, 0, 0, 0)); 
  SDL_BlitSurface(spc, NULL, screen, &pos);
  pos.x = 120;
  pos.y = 278;
  spc = SDL_CreateRGBSurface(SDL_HWSURFACE, 950, 250, 32, 0, 0, 0, 0);
  SDL_FillRect(spc, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); 
  SDL_BlitSurface(spc, NULL, screen, &pos);
  pos.x = 125;
  pos.y = 283;
  spc = SDL_CreateRGBSurface(SDL_HWSURFACE, 940, 240, 32, 0, 0, 0, 0);
  SDL_FillRect(spc, NULL, SDL_MapRGB(screen->format, 0, 0, 0)); 
  SDL_BlitSurface(spc, NULL, screen, &pos);
  sreen_write("Winner :", (pos.x + 50), (pos.y + 20), 50);  
  sreen_write(str, (pos.x + 35), (pos.y + 80), 125);  
  SDL_Flip(screen);
  SDL_FreeSurface(spc);
  Mix_CloseAudio();
  my_pause();
}

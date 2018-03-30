#include "graphics.hpp"

void CreateWindow(SDL_Window*& window, SDL_Renderer*& renderer)
{
  //Generating window
  window = SDL_CreateWindow("MageRunner", 0, 0, 16*80, 9*80, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);

  if (window == NULL)
  {
        printf("Could not create window: %s\n", SDL_GetError());
  }
}

void DestroyWindow(SDL_Window* window, SDL_Renderer* renderer)
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

void DisplayHero(SDL_Renderer* renderer, int& spritePosition, bool& goingUp)
{
  SDL_Surface* heroSurface;
  SDL_Texture* heroTexture;

  heroSurface = SDL_LoadBMP("hero.bmp");
  heroTexture = SDL_CreateTextureFromSurface(renderer, heroSurface);
  SDL_FreeSurface(heroSurface);

  if(goingUp)
  {
    ++spritePosition;
  }
  else
  {
    --spritePosition;
  }

  if(spritePosition == 20 || spritePosition == 0)
  {
    goingUp = !goingUp;
  }

  SDL_Rect heroTransform;
  heroTransform.x = -20;
  heroTransform.y = 220 + spritePosition;
  heroTransform.w = 320;
  heroTransform.h = 240;

  SDL_RenderCopy(renderer, heroTexture, NULL, &heroTransform);
  SDL_DestroyTexture(heroTexture);
}

void DisplayEnemy(SDL_Renderer* renderer, int& sprEnemyPosition, float enemyPosition, int id)
{
  SDL_Surface* enemySurface;
  SDL_Texture* enemyTexture;

  if(id == 0)
  {
    enemySurface = IMG_Load("demonrouge.png");
  }
  else if(id == 1)
  {
    enemySurface = IMG_Load("demonbleu.png");
  }
  else
  {
    enemySurface = IMG_Load("demonvert.png");
  }

  enemyTexture = SDL_CreateTextureFromSurface(renderer, enemySurface);
  SDL_FreeSurface(enemySurface);

  sprEnemyPosition = enemyPosition * 9.8F;

  SDL_Rect enemyTransform;
  enemyTransform.x = 300 + sprEnemyPosition;
  enemyTransform.y = 220;
  enemyTransform.w = 320;
  enemyTransform.h = 240;

  SDL_RenderCopy(renderer, enemyTexture, NULL, &enemyTransform);
  SDL_DestroyTexture(enemyTexture);
}

void UpdateGraphics(SDL_Window* window, SDL_Renderer* renderer, int& sprHeroPosition, bool& goingUp, int& sprEnemyPosition, float enemyPosition, int enemyId)
{
  //Nettoyage de l'écran
  SDL_RenderClear(renderer);
  //Choix de ce qui va être afficher et où
  DisplayHero(renderer, sprHeroPosition, goingUp);
  DisplayEnemy(renderer, sprEnemyPosition, enemyPosition, enemyId);
  //Affichage de l'écran
  SDL_RenderPresent(renderer);
}

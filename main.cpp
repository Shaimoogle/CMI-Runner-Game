#include <iostream>
#include "input.hpp"
#include "environnement.hpp"
#include "graphics.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  //Initialisation de la SDL et création de la fenêtre
  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_PNG);
  SDL_Window* window;
  SDL_Renderer* renderer;
  CreateWindow(window, renderer);

  //Initializing input
  int input;
  input = -1;

  //Initializing game environment
  float enemyPosition;
  enemyPosition = 100.0F;
  bool gameover;
  gameover = false;
  int enemyId;
  enemyId = 0;
  int spellId;
  spellId = -1;
  bool canCast;
  canCast = true;
  int enemyWeaknesses[3];
  enemyWeaknesses[0] = 1;
  enemyWeaknesses[1] = 2;
  enemyWeaknesses[2] = 3;
  bool enemyAlive;
  enemyAlive = true;
  float gameSpeed;
  gameSpeed = 3.0F;

  //Initializing graphics variables
  int heroSpritePositionY;
  heroSpritePositionY = 0;
  bool heroSpriteGoingUp;
  heroSpriteGoingUp = true;
  int enemySpritePositionX;
  enemySpritePositionX = 0;

  //gameloop
  while(input != 0 && !gameover)
  {
    UpdateInput(input);
    UpdateEnvironment(input, enemyPosition, gameover, enemyId, spellId, canCast, enemyWeaknesses, enemyAlive, gameSpeed);
    PrintEnvironment(input, enemyPosition, gameover, enemyId, spellId, canCast, enemyAlive, gameSpeed);
    UpdateGraphics(window, renderer, heroSpritePositionY, heroSpriteGoingUp, enemySpritePositionX, enemyPosition, enemyId);
  }

  cout << "OUT OF LOOP" << endl;

  //Pause de 1 secondes
  SDL_Delay(1000);

  //Destruction de la fenêtre et fermeture du programme
  DestroyWindow(window, renderer);
  IMG_Quit();
  SDL_Quit();
  return 0;
}

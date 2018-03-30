#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

void CreateWindow(SDL_Window*& window, SDL_Renderer*& renderer);
void DestroyWindow(SDL_Window* window, SDL_Renderer* renderer);

void DisplayHero(SDL_Renderer* renderer, int& spritePosition, bool& goingUp);
void DisplayEnemy(SDL_Renderer* renderer, int& sprEnemyPosition, float enemyPosition, int id);

void UpdateGraphics(SDL_Window* window, SDL_Renderer* renderer, int& heroPosition, bool& goingUp, int& sprEnemyPosition, float enemyPosition, int enemyId);

#include "environnement.hpp"

void moveEnemy(float &position, int speed)
{
  position = position - speed;
  if(position < 0)
  {
    position = 0;
  }
}

void checkDefeat(bool &gamestatus, float position)
{
  gamestatus = (position == 0);
  if(gamestatus)
  {
    cout << "GAME OVER : YOU LOOSE" << endl;
  }
}

void checkEnemyDeath(int* weaknessesArray, int enemyId, int& spellId, bool &enemyState)
{
  if(weaknessesArray[enemyId] == spellId)
  {
    enemyState = false;
  }
  spellId = -1;
}

void generateEnemy(float &position, int &id, bool &enemyState, bool& cast)
{
  id = rand () % 3;
  position = 100.0F;
  enemyState = true;
  cast = true;
}

void castSpell(int input, int& id, bool& cast)
{
  if(cast && input != -1)
  {
    id = input;
    cast = false;
  }
}

void UpdateEnvironment(int input, float& enemyPosition, bool& gameover, int& enemyId, int& spellId, bool& canCast, int* enemyWeaknesses, bool& enemyAlive, float& gameSpeed)
{
  moveEnemy(enemyPosition, gameSpeed);
  castSpell(input, spellId, canCast);
  checkEnemyDeath(enemyWeaknesses, enemyId, spellId, enemyAlive);
  if(!enemyAlive)
  {
    generateEnemy(enemyPosition, enemyId, enemyAlive, canCast);
  }
  else
  {
    checkDefeat(gameover, enemyPosition);
  }
}

void PrintEnvironment(int input, float enemyPosition, bool gameover, int enemyId, int spellId, bool canCast, bool enemyAlive, float gameSpeed)
{
  cout << "Input : " << input << endl;
  cout << "gameover : " << gameover << endl;

  cout << "enemyPosition : " << enemyPosition << endl;
  cout << "enemyId : " << enemyId << endl;
  cout << "spellId : " << spellId << endl;
  cout << "canCast : " << canCast << endl;

  cout << "enemyAlive : " << enemyAlive << endl;
  cout << "gameSpeed : "  << gameSpeed << endl;
  cout << "----------------------" << endl;
}

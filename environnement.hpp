#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void moveEnemy(float& position, int speed);

void checkDefeat(bool& gamestatus, float position);

void checkEnemyDeath(int* weaknessesArray, int enemyId, int& spellId, bool& enemyState);

void generateEnemy(float& position, int& id, bool& enemyState, bool& cast);

void castSpell(int input, int& id, bool& cast);

void UpdateEnvironment(int input, float& enemyPosition, bool& gameover, int& enemyId, int& spellId, bool& canCast, int* enemyWeaknesses, bool& enemyAlive, float& gameSpeed);

void PrintEnvironment(int input, float enemyPosition, bool gameover, int enemyId, int spellId, bool canCast, bool enemyAlive, float gameSpeed);

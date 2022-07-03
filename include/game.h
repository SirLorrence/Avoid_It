#ifndef GAME_H
#define GAME_H

#include "../include/collider.h"
#include "../include/axe.h"
#include "../include/player.h"
#include "../include/goal.h"
#include "raylib.h"

// bool game_over;
bool CollisionDetection(Collider& collider, Player& player);
void SetLevel(Player& player,Axe& axe, int level_index);
void SetupWindow();
void DisplayGameOver(int& value);
void DisplayHUD(int& value);


// enum state{
// STATE_
// };


#endif
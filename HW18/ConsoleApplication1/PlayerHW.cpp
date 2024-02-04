#include "Player.h"
#include "Weapon.h"
#include "PlayerClass.h"
#include <iostream>

int main()
{
    Player player1("OnePunchMan", new SniperRifle, new AttackerClass);
    Player player2("JohnCena", new Axe, new DefenderClass);
    Player player3("SuperSpy", new Pistol, new LuckyManClass);
    Player player4("Tank", new AssaultRifle, new DefenderClass);

    player1.attack(player2, 1500);
    player2.attack(player3, 2); 
    player2.attack(player3, 20);
    player3.attack(player4, 5000);
    player4.attack(player1, 2500);
    
    return 0;
}
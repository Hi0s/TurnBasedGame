#include <stdio.h>
#include <stdlib.h>
void playerTurn(Character *player, Character *enemy)
{
}
void enemyTurn(Character *enemy, Character *player)
{
}
void attack(Character *attacker, Character *defender)
{
    double damage = attacker->attackPower * rng(2) - defender->defensePower;
    if (damage < 1)
        damage = 1;
    defender->currentHp -= (int)round(damage);
    printf("%s attacks %s for %d damage!\n", attacker->unitName, defender->unitName, (int)round(damage));
}

void heal(Character *character)
{
    double heal = character->attackPower * rng(0.5);
    character->currentHp += (int)round(heal);
    if (character->currentHp > character->maxHp)
        character->currentHp = character->maxHp;
    printf("%s heals for %d HP!\n", character->unitName, (int)round(heal));
}

double rng(int range)
{
    return rand() % (range + 1);
}

typedef struct
{
    char unitName[50];
    int currentHp;
    int maxHp;
    int attackPower;
    int defensePower;

} Character;
int main(void)
{
    // Initial Player
    Character player;
    player.maxHp = 50;
    player.currentHp = player.maxHp;
    player.attackPower = 10;
    player.defensePower = 5;

    // Initial Enemy
    Character enemy;
    strcpy(enemy.unitName, "Alakrth");
    enemy.maxHp = 50;
    enemy.currentHp = enemy.maxHp;
    enemy.attackPower = 10;
    enemy.defensePower = 5;

    // Initial value
    int turn = 1;
    printf("Welcome to the turn-based game!!!");
    printf("Please enter your character name: ");
    scanf("%[^\n]s", &player.unitName);

    // Game start & print initial stats
    printf("-- BATTLE STARTS --");
    printf("%s: HP:%d, ATK=%d, DEF=%d\n", &player.unitName, &player.currentHp, &player.attackPower, &player.defensePower);
    printf("%s: HP:%d, ATK=%d, DEF=%d\n", &enemy.unitName, &enemy.currentHp, &enemy.attackPower, &enemy.defensePower);
    while (player.currentHp > 0 && enemy.currentHp > 0)
    {
        printf("\n-- Turn %d --\n", &turn);
        printf("%s HP: %d| %s HP: %d\n", &player.unitName, &player.currentHp, &enemy.unitName, &enemy.currentHp);
        // Player turn
        printf("Player's turn...\n");

        // Enemy turn
        printf("Enemy's turn...\n");

        // Check win-lose condition
        if (player.currentHp <= 0)
        {
            printf("Player %s has been defeated!!!\n", &player.unitName);
            break;
        }
        if (enemy.currentHp <= 0)
        {
            printf("%s has been defeated!!!\n", &enemy.unitName);
            printf("You win!!!\n");
            break;
        }
        turn++;
    }
    return 0;
}

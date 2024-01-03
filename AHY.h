#ifndef AHY_H
#define AHY_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Player {
    std::string name;
    std::string team;
    std::string position;
    double value;
    bool used;  // Yeni eklenen 'used' üyesi
};

struct Team {
    std::string name;
    std::vector<Player> players;
    double totalValue;
};

bool comparePlayers(const Player& a, const Player& b);
void createTeams(std::vector<Player>& players, std::vector<Team>& teams);
void printTeams(const std::vector<Team>& teams);

#endif


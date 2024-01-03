#include "AHY.h"

const double MAX_TOTAL_VALUE_PER_TEAM = 300000000.00;  // Örnek bir deðer, ihtiyaca göre ayarlayabilirsiniz.

bool comparePlayers(const Player& a, const Player& b) {
  return a.value > b.value;
}

void createTeams(std::vector<Player>& players, std::vector<Team>& teams) {
  std::sort(players.begin(), players.end(), comparePlayers);

  for (auto& player : players) {
    player.used = false;
  }

// Her takmda önce kaleciler olmalý
  for (int i = 0; i < 4; ++i) {
    for (auto& player : players) {
      if (player.position == "Kaleci" && !player.used) {
        teams[i].players.push_back(player);
        teams[i].totalValue += player.value;
        player.used = true;
        break;
      }
    }
  }

  for (auto& player : players) {
    if (player.position != "Kaleci" && !player.used) {
      int minIndex = 0;
      double minTotalValue = teams[0].totalValue;

// Pozisyon baþýna max 2 oyuncu ekleniyor.
      for (int i = 1; i < 4; ++i) {
        if (teams[i].totalValue < minTotalValue && teams[i].players.size() < 11) {
          if (std::count_if(teams[i].players.begin(), teams[i].players.end(),
                            [player](const Player& p) { return p.position == player.position; }) < 2) {
            minTotalValue = teams[i].totalValue;
            minIndex = i;
          }
        }
      }

      if (teams[minIndex].players.size() < 11) {
          if (teams[minIndex].totalValue + player.value <= MAX_TOTAL_VALUE_PER_TEAM) {
          teams[minIndex].players.push_back(player);
          teams[minIndex].totalValue += player.value;
          player.used = true;
        }
      }
    }
  }
}

void printTeams(const std::vector<Team>& teams) {
  for (const auto& team : teams) {
    std::cout << "\n\t\t" << team.name << ":\n\n";
    for (const auto& player : team.players) {
      std::cout << " " << player.name << " - " << player.team << " - " << player.position << " - " << std::fixed << std::setprecision(2) << player.value << " EURO \n";
    }
    std::cout << "\n\t" << team.name << " 'in Toplam Piyasa Deðeri: " << std::fixed << std::setprecision(2) << team.totalValue << " EURO \n\n";
  }
}


#include <iostream>

#include "src/player.hpp"
#include "src/farm.hpp"
#include "src/farm_printer.hpp"
#include "src/carrot.hpp"
#include "src/ansi_clear.hpp"

int main() {
  Player player;
  Farm farm(7, 8, &player);
  FarmPrinter printer(&farm);
  bool game_in_progress = true;
  std::string player_input;

  while(game_in_progress) {
    ansi_clear();
    std::cout << "[w]up, [s]down, [a]left, [d]right, [c]plant carrot, [h]harvest, [e]end day, [q]quit" << std::endl;
    std::cout << "Day: " << farm.get_current_day() << std::endl;
    std::cout << printer.pp() << std::endl;
    std::cin >> player_input;

    if(player_input == "q") {
      game_in_progress = false;
    } else if(player_input == "d") {
      player.move_right();
    } else if(player_input == "s") {
      player.move_down();
    } else if(player_input == "a") {
      player.move_left();
    } else if(player_input == "w") {
      player.move_up();
    } else if(player_input == "c") {
      if(farm.can_plant(player.row(), player.column())) {
        Carrot *carrot = new Carrot();
        farm.plant(player.row(), player.column(), carrot);
      }
    } else if(player_input == "h") {
      if(farm.can_harvest(player.row(), player.column())) {
        farm.harvest(player.row(), player.column());
      }
    } else if(player_input == "e") {
      farm.end_day();
    }
  }
}
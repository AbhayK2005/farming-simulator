#include <string>
#include <vector>

#include "farm.hpp"
#include "soil.hpp"

Farm::Farm(int rows, int columns, Player *player) : rows(rows), columns(columns), player(player) {
  player->boundaries(rows, columns);
  for(int i = 0; i < rows; i++) {
    std::vector<Plot *> row;
    for(int j = 0; j < columns; j++) {
      Soil *soil = new Soil();
      row.push_back(soil);
    }
    plots.push_back(row);
  }
}

int Farm::number_of_rows() {
  return rows;
}

int Farm::number_of_columns() {
  return columns;
}

std::string Farm::get_symbol(int row, int column) {
  if(player->row() == row && player->column() == column) {
    return "@";
  } else {
    return plots.at(row).at(column)->symbol();
  }
}

void Farm::plant(int row, int column, Plot *plot) {
  Plot *current_plot = plots.at(row).at(column);
  plots.at(row).at(column) = plot;
  delete current_plot;
}

void Farm::end_day() {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      plots.at(i).at(j)->end_day();
    }
  }
}

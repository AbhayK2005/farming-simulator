#include "player.hpp"

int Player::row() {
    return current_row;
}

int Player::column() {
    return current_column;
}

void Player::boundaries(int max_r, int max_c) {
    max_rows = max_r;
    max_columns = max_c;
}

void Player::move_right() {
    if (current_column < max_columns - 1) {
        current_column += 1;
    }
}

void Player::move_down() {
    if (current_row < max_rows - 1) {
        current_row += 1;
    }
}

void Player::move_left() {
    if (current_column > 0) {
        current_column -= 1;
    }
}

void Player::move_up() {
    if (current_row > 0) {
        current_row -= 1;
    }
}
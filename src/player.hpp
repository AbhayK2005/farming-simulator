#pragma once

class Player {
private:
    int current_row = 0;
    int current_column = 0;
    int max_rows = 0;
    int max_columns = 0;

public:
    int row();
    int column();
    void boundaries(int max_r, int max_c);
    void move_right();
    void move_down();
    void move_left();
    void move_up();
};
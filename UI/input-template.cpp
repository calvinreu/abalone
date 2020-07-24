#include "input.cpp"

template bool handle_input<player0> (const map &board, bool &running, position &first, size_t &ammount, direction &row_direction);
template bool handle_input<player1> (const map &board, bool &running, position &first, size_t &ammount, direction &row_direction);
template action get_move<player0>(const position &first, size_t &ammount, direction &move_direction, direction &row_direction);
template action get_move<player1>(const position &first, size_t &ammount, direction &move_direction, direction &row_direction);
template void mouse_event<player0>(position &selected, size_t &ammount, direction &move_direction, direction &row_direction, const pair<int> &cursorPosition, const map &board);
template void mouse_event<player1>(position &selected, size_t &ammount, direction &move_direction, direction &row_direction, const pair<int> &cursorPosition, const map &board);
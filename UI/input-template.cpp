#include "input.cpp"

template bool handle_input<player0> (game &game_info, position &first, size_t &ammount, direction &row_direction);
template bool handle_input<player1> (game &game_info, position &first, size_t &ammount, direction &row_direction);
template action get_move<player0>(const position &first, size_t &ammount, direction &move_direction, direction &row_direction);
template action get_move<player1>(const position &first, size_t &ammount, direction &move_direction, direction &row_direction);
template void mouse_event<player0>(position &selected, size_t &ammount, direction &move_direction, direction &row_direction, const pair<int> &cursorPosition, const game &game_info);
template void mouse_event<player1>(position &selected, size_t &ammount, direction &move_direction, direction &row_direction, const pair<int> &cursorPosition, const game &game_info);
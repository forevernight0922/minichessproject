#pragma once
#include "../state/state.hpp"

struct Node{
    Move move;
    double value;
};
/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class Minimax{
public:
  static Move get_move(State *state, int depth);
  static Node tracing(State *state,int round,int player,std::vector<Move> actions);
};
#pragma once
#include "../state/state.hpp"

struct Node{
    Move move;
    int value;
};
/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class Submit{
public:
  static Move get_move(State *state, int depth);
  static int tracing(State *state,int round,int player);
};
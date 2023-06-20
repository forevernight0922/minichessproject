#include <cstdlib>

#include "../state/state.hpp"
#include "./alphabeta.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
  */
int  alphabeta::counting_alpha_beta(State *state,int round,int nowplayer,int prea,int preb){
    if(round==4){
       return -state->evaluate(nowplayer); 
    }
    if(!state->legal_actions.size())
        state->get_legal_actions();
    if(round%2==1){
        int a=prea,b=preb;
        auto actions=state->legal_actions;
        for(auto i:actions){
            int value=counting_alpha_beta(state->next_state(i),round+1,state->player,a,b);
            if(value<=b){
                b=value;
            }
            if(b<=a)
                return b;
        }
        return b;
    }
     if(round%2==0){
        int a=prea,b=preb;
        auto actions=state->legal_actions;
        for(auto i:actions){
            int value=counting_alpha_beta(state->next_state(i),round+1,state->player,a,b);
            if(value>=a){
                a=value;
            }
            if(a>=b)
                return a;
        }
        return a;
    }

}
Move alphabeta::get_move(State *state, int depth){
  if(!state->legal_actions.size())
  state->get_legal_actions();
  
  auto actions = state->legal_actions;
  Move rtmove;
  int a=-2e8,b=2e8;
  for(auto i:actions){
    int value=counting_alpha_beta(state->next_state(i),1,state->player,a,b);
    if(value>=a){
        a=value;
        rtmove=i;
    }
  }
  return rtmove;
}
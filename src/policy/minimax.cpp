//[TODO] Design your own policy
#include <cstdlib>
#include <cstdint>
#include <sstream>
#include <fstream>  
#include "../state/state.hpp"
#include "./minimax.hpp"
const std::string file_log = "gamelog.txt";

/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */


int Minimax::tracing(State *state,int round,int nowplayer){
    Move RtAction;
    
    if(round==4){
       
       return state->evaluate(nowplayer);
        
    }
    if(!state->legal_actions.size())
    state->get_legal_actions();
    if(state->player==nowplayer){
        int value=-2e8;
        for(auto i:state->legal_actions){
            State *newstate=state->next_state(i);
            
            value=std::max(value,tracing(newstate,round+1,nowplayer));
           
        }
        return value;
        
    }
    else{
        int value=2e8;
        Node rtnode;
        
         for(auto i:state->legal_actions){
            State *newstate=state->next_state(i);
            value=std::min(value,tracing(newstate,round+1,nowplayer));
           
        }
        return value;
    }
    
}
Move Minimax::get_move(State *state, int depth){
    if(!state->legal_actions.size())
    state->get_legal_actions();
    int nowplayer=state->player;
    std::vector<Move> actions = state->legal_actions;
    int max=-2e8;
    Move rtmove;
    for(auto i:actions){
            State* nextstate=state->next_state(i);
            int value=tracing(nextstate,1,nowplayer);
            if(value>max){
                rtmove=i;
                max=value;    
            }

    }
    return rtmove;

}
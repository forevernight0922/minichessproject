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


Node Minimax::tracing(State *state,int round,int player,std::vector<Move> actions){
    Move RtAction;
    Node rtnode;
    if(round==2){
       
        double max=-1e19;
        for(auto i:actions){
            State *newstate=state->next_state(i);
            if(newstate->evaluate()>max){
                max=newstate->evaluate();
                RtAction=i;
                rtnode.value=max;
                rtnode.move=RtAction;
            }
        }
        return rtnode;
    }
    else if(round==1){
        double min=1e19;
        for(auto i:actions){
            State *newstate=state->next_state(i);
            if(!state->legal_actions.size())
                    state->get_legal_actions();
            Node get=tracing(newstate,round+1,player,newstate->legal_actions);
            if(get.value<min){
                min=get.value;
                rtnode.value=min;
                rtnode.move=i;
            }
        }
        return rtnode;
    }
    else if(round==0){
        double max=-1e19;
        for(auto i:actions){
            State *newstate=state->next_state(i);
            if(!state->legal_actions.size())
                state->get_legal_actions();
            Node get=tracing(newstate,round+1,player,newstate->legal_actions);
            if(get.value>max){
                max=get.value;
                rtnode.value=max;
                rtnode.move=i;
            }
        }
        return rtnode;
    }
}
Move Minimax::get_move(State *state, int depth){
    if(!state->legal_actions.size())
    state->get_legal_actions();
    int nowplayer=state->player;
    std::vector<Move> actions = state->legal_actions;
    Node rtnode=tracing(state,0,nowplayer,actions);
    
    std::ofstream ofs ("test.txt", std::ofstream::out);
    ofs <<rtnode.value;

    ofs.close();
    return rtnode.move;

}
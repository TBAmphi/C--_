#include <cstdlib>
#include <iostream>

void StartTurn(int remainingTurn, int playerId);
void SwitchPlayer(int remainingTurn, int &playerId);
void EndTurn(int &remainingTurn, int playerId);

int main(){
int remainingTurn = 5;
int playerId = 0;
while(remainingTurn >= 1)
{
StartTurn(remainingTurn , playerId);
SwitchPlayer(remainingTurn, playerId);
EndTurn(remainingTurn, playerId);
}
return 0;
}

void StartTurn(int remainingTurn, int playerId) {
std::cout << "Starting turn for player : " << playerId << "." << std::endl;
}
void SwitchPlayer(int remainingTurn, int &playerId) {
playerId = (playerId+1)%2;
std::cout << "Player " << playerId << " has played. Switching player." << std::endl;
}
void EndTurn(int &remainingTurn, int playerId) {
remainingTurn--;
std::cout << "End of turn. " << remainingTurn << " turns left." << std::endl;
}
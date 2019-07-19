#include<bits/stdc++.h>
#include"Game.h"
using namespace std;

int main()
{
 srand(time(0));
 int Choice=1;
 Game game;

   cout<<"1. Play the Game\n";
   cout<<"2. Build your Own Game\n";
   cin>>Choice;
   switch(Choice){
     case 1:
           game=Game("bollywood.txt",266);
           game.startGame();
           break;
     case 2:
          game.initialize();
          break;
     default:
          cout<<"You Chooses Invalid Option\n";
          break;
   }

}

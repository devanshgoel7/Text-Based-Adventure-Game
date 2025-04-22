#include"puzzle.h"
#include<iostream>
#include <chrono>
using namespace std;

bool puzzles::getpuzzle(){
    srand(time(0));
    int index=rand()%(puzzle.size()-1);
    cout<<puzzle[index].first<<endl;
    cout<<"ENTER YOUR ANSWER TO PROCEED -"<<endl;
    string answer;
    cin>>answer;
    if(answer==puzzle[index].second){
        return true;
    }
   return false;

}
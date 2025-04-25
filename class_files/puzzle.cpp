#include"puzzle.h"
#include<iostream>
#include <chrono>
using namespace std;

bool puzzles::getpuzzle(int index){
    
    
    cout<<puzzle[index].first<<endl;
    cout<<"ENTER YOUR ANSWER TO PROCEED -"<<endl;
    string answer;
    cin>>answer;
    if(answer==puzzle[index].second){
        return true;
    }
   return false;

}
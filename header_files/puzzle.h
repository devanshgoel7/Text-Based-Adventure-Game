#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>
#include <vector>
using namespace std;
class puzzles{
   protected:
   vector<pair<string, string>> puzzle = {
      {"I have keys but open no locks. I have space but no room. You can enter, but you can't go outside. What am I?", "keyboard"},
      {"The more you take, the more I leave behind. What am I?", "footsteps"},
      {"Born of flame, I devour the dark. Without me, secrets remain hidden. What am I?", "torch"},
      {"Etched in stone or inked in blood, I carry ancient power. Only the wise may read me.", "rune"},
      {"A prison and a palace both, filled with echoes of thought. Locked from sight, yet always with you.", "mind"},
      {"When I arrive, all fades. I am feared in the halls of the brave and the weak. What am I?", "silence"},
      {"I walk with you till the final gate, then stab you in the back. My name brings dread in loyal hearts.", "betrayal"}
  };
   public:
         bool getpuzzle();
   

};
#endif
#ifndef WORKOUT
#define WORKOUT
#include <vector>
#include <string>

using namespace std;


class workout{
public:
  workout(string name, int weight, int sets, int reps);
  //void makeWorkout(int weight, int sets, int reps);

  void increaseDifficulty();

  string name;
  int weight;
  int sets;
  int reps;


};


#endif

//want to create a program that can give me a workout schedule with reps
#include <iostream>
#include "workout.h"
#include <vector>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;


workout::workout(string name, int weight, int sets, int reps){
  //workout* work = new workout;
  //return;
  this->name = name;
  this->weight = weight;
  this->sets = sets;
  this->reps = reps;
}

// void workout::makeWorkout(int weight, int sets, int reps){
//
//   this->weight = weight;
//   this->sets = sets;
//   this->reps = reps;
// }

void workout::increaseDifficulty(){
  srand (time(NULL));
  int randomnumber = rand() % 10 + 1;
  if(randomnumber < 5){
    //increase the reps
    this->reps = this->reps + 2;
    if(this->reps > 15){
      this->reps = 6;
      this->sets++;
      //increase the sets and
    }
  }
  else if(randomnumber < 8){
    this->weight = this->weight + 5;
    //increase the weight
  }
  else{
    if(this->sets < 5 && this->weight >= 10){
      this->weight = this->weight - 10;
      this->sets++;
    }
    else{
      this->sets = 3;
      this->weight = this->weight + 10;
    }
    //maybe lower weight or reps and increase sets
  }
}

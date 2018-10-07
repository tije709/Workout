#include "workout.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sys/stat.h>
#include <ctime>

using namespace std;

int main(){

  // Here we will create the different workout vectors to help classify them
  vector<workout> upperBody;
  vector<workout> chest;
  vector<workout> shoulders;
  vector<workout> triceps;

  vector<workout> back;
  vector<workout> biceps;
  vector<workout> traps;
  vector<workout> rearShoulders;

  vector<workout> legs;
  vector<workout> calves;
  vector<workout> abs;
  vector<workout> weightedAbs;

  //This will be our randomization location #1
  srand (time(NULL));
  int firstrand = rand();

  cout << "Hello, enter your name." << endl;
  string name;
  cin >> name;

  //This will be our randomization location #2
  srand (time(NULL));
  int thirdrand = rand();
  string workoutTxt = "Profiles/" + name + "Workouts.txt";

  ifstream inFile;
  inFile.open(workoutTxt);

  //If profile isn't found create new profile and add weights in
  if(inFile.fail()){
    inFile.close();
    string makeNewAccount;
    cout << "Profile not found. Would you like to make a new account? (yes/no)" << endl;
    cin >> makeNewAccount;
    if(makeNewAccount == "no"){
      cerr << "Have a nice day!" << endl;
      return 0;
    }

    cout << "created new file" << endl;

    //Go through the masterWorkoutList file and enter in the weights for
    //the different workouts into the workout vectors
    string wrkout;
    string group;
    int number;
    vector <workout> things;
    ifstream practice ("masterWorkoutList.txt");
    ofstream outFile (workoutTxt);

    while(true){
      practice >> wrkout >> group;
      if(practice.eof())
        break;
//TODO do not ask for bodyweight exercises
      if(wrkout == "bodyWeightChestFly"){
        workout temp(wrkout, 0, 3, 8);
        chest.push_back(temp);
        outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
      }
      else if(wrkout == "pullupShrug"){
        workout temp(wrkout, 0, 3, 8);
        traps.push_back(temp);
        outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
      }
      else if(group == "abs"){
        workout temp(wrkout, 0, 2, 20);
        abs.push_back(temp);
        outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
      }
      else{
          cout << "enter starting weight for " << wrkout << " for 3 sets of 8 reps? (enter number)" << endl;
          cin >> number;
          workout temp(wrkout, number, 3, 8);


        if(group ==  "upperBody"){
          upperBody.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else if(group ==  "chest"){
          chest.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else if(group ==  "shoulders"){
          shoulders.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else if(group ==  "triceps"){
          triceps.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else if(group ==  "back"){
          back.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else if(group ==  "biceps"){
          biceps.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else if(group ==  "traps"){
          traps.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else if(group ==  "rearShoulders"){
          rearShoulders.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else if(group ==  "legs"){
          legs.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else if(group ==  "calves"){
          calves.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else if(group ==  "weightedAbs"){
          weightedAbs.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }

        else
        cerr << "did not find " << group << endl;
      }

    }
    practice.close();
  }

  //If the user already has a profile, read from the file in their profile
  else{
    string wkout;
    string type;
    int w;
    int n;
    int s;
    while(inFile.good()){

      inFile >> wkout >> type >> w >> n >> s;
      if(inFile.eof())
        break;
      workout t(wkout, w, n, s);

      if(type ==  "upperBody"){
        upperBody.push_back(t);
      }
      else if(type ==  "chest"){
        chest.push_back(t);
      }
      else if(type ==  "shoulders"){
        shoulders.push_back(t);
      }
      else if(type ==  "triceps"){
        triceps.push_back(t);
      }
      else if(type ==  "back"){
        back.push_back(t);
      }
      else if(type ==  "biceps"){
        biceps.push_back(t);
      }
      else if(type ==  "traps"){
        traps.push_back(t);
      }
      else if(type ==  "rearShoulders"){
        rearShoulders.push_back(t);
      }
      else if(type ==  "legs"){
        legs.push_back(t);
      }
      else if(type ==  "calves"){
        calves.push_back(t);
      }
      else if(type == "abs"){
        abs.push_back(t);
      }
      else if(type == "weightedAbs"){
        weightedAbs.push_back(t);
      }
    }
    inFile.close();
  }


  cout << endl <<"Hello, ready to get fit " << name << "?" << endl;
  cout << "What body group would you like to work out today? (upperBody, back, legs, abs, or set)" << endl;

  ofstream outFile("Profiles/" + name + "Log.txt", ios::app);

  string workoutType;
  cin >> workoutType;

  //This will be our randomization location #3
  srand (time(NULL));
  int secondrand = rand();

  time_t currentTime = time(0);
  char* dt = ctime(&currentTime);

  while(workoutType != "upperBody" && workoutType != "back" && workoutType != "legs" && workoutType !="abs" && workoutType != "set"){
    cerr << "Invalid Answer, try again (upperBody, back, legs, abs, or set)" << endl;
    cin >> workoutType;
  }
  cout << "You want to work out " << workoutType << ". Gotcha!" << endl;

  //This will be our randomization location #4
  srand (time(NULL));
  int fourthrand = rand();

  string increase;
  int one;
  int two;
  int three;
  int four;

  //create the upperBody workout
  if(workoutType == "upperBody"){
    cout << endl << "_________________________________________________________________" << endl;
    outFile << dt;
    outFile << "------------------------" << endl;;

    outFile << upperBody[firstrand % 3].name << ": " << upperBody[firstrand % 3].weight << "lbs x " << upperBody[firstrand % 3].sets << " sets x " << upperBody[firstrand % 3].reps << " reps" << endl;
    outFile << chest[secondrand % 3].name << ": " << chest[secondrand % 3].weight << "lbs x " << chest[secondrand % 3].sets << " sets x " << chest[secondrand % 3].reps << " reps" << endl;
    outFile << shoulders[thirdrand % 3].name << ": " << shoulders[thirdrand % 3].weight << "lbs x " << shoulders[thirdrand % 3].sets << " sets x " << shoulders[thirdrand % 3].reps << " reps" << endl;
    outFile << triceps[fourthrand % 2].name << ": " << triceps[fourthrand % 2].weight << "lbs x " << triceps[fourthrand % 2].sets << " sets x " << triceps[fourthrand % 2].reps << " reps" << endl << endl << endl;

    cout << upperBody[firstrand % 5].name << ": " << upperBody[firstrand % 5].weight << "lbs x " << upperBody[firstrand % 5].sets << " sets x " << upperBody[firstrand % 5].reps << " reps" << endl;
    cout << chest[secondrand % 3].name << ": " << chest[secondrand % 3].weight << "lbs x " << chest[secondrand % 3].sets << " sets x " << chest[secondrand % 3].reps << " reps" << endl;
    cout << shoulders[thirdrand % 3].name << ": " << shoulders[thirdrand % 3].weight << "lbs x " << shoulders[thirdrand % 3].sets << " sets x " << shoulders[thirdrand % 3].reps << " reps" << endl;
    cout << triceps[fourthrand % 2].name << ": " << triceps[fourthrand % 2].weight << "lbs x " << triceps[fourthrand % 2].sets << " sets x " << triceps[fourthrand % 2].reps << " reps" << endl;
    cout << "_________________________________________________________________" << endl << endl;

    cout << "Post Workout" << endl << "How did the workout go?" << endl;
    cout << "Did " << upperBody[firstrand % 5].name << " go well? (yes/no)" << endl;
    cin >> increase;
    if(increase == "yes"){
      upperBody[firstrand % 5].increaseDifficulty();
    }
    cout << "Did " << chest[secondrand % 3].name << " go well? (yes/no)" << endl;
    cin >> increase;
    if(increase == "yes"){
      chest[secondrand % 3].increaseDifficulty();
    }
    cout << "Did " << shoulders[thirdrand % 3].name << " go well? (yes/no)" << endl;
    cin >> increase;
    if(increase == "yes"){
      shoulders[thirdrand % 3].increaseDifficulty();
    }
    cout << "Did " << triceps[fourthrand % 2].name << " go well? (yes/no)" << endl;
    cin >> increase;
    if(increase == "yes"){
      triceps[fourthrand % 2].increaseDifficulty();
    }

  }

  //create the back workout
  else if(workoutType == "back"){
    outFile << dt;
    outFile << "------------------------" << endl;

    cout << endl << "_________________________________________________________________" << endl;
    outFile << back[firstrand % 4].name << ": " << back[firstrand % 4].weight << "lbs x " << back[firstrand % 4].sets << " sets x " << back[firstrand % 4].reps << " reps" << endl;
    outFile << biceps[secondrand % 4].name << ": " << biceps[secondrand % 4].weight << "lbs x " << biceps[secondrand % 4].sets << " sets x " << biceps[secondrand % 4].reps << " reps" << endl;
    outFile << traps[thirdrand % 3].name << ": " << traps[thirdrand % 3].weight << "lbs x " << traps[thirdrand % 3].sets << " sets x " << traps[thirdrand % 3].reps << " reps" << endl;
    outFile << rearShoulders[fourthrand % 2].name << ": " << rearShoulders[fourthrand % 2].weight << "lbs x " << rearShoulders[fourthrand % 2].sets << " sets x " << rearShoulders[fourthrand % 2].reps << " reps" << endl  << endl << endl;

    cout << back[firstrand % 4].name << ": " << back[firstrand % 4].weight << "lbs x " << back[firstrand % 4].sets << " sets x " << back[firstrand % 4].reps << " reps" << endl;
    cout << biceps[secondrand % 4].name << ": " << biceps[secondrand % 4].weight << "lbs x " << biceps[secondrand % 4].sets << " sets x " << biceps[secondrand % 4].reps << " reps" << endl;
    cout << traps[thirdrand % 3].name << ": " << traps[thirdrand % 3].weight << "lbs x " << traps[thirdrand % 3].sets << " sets x " << traps[thirdrand % 3].reps << " reps" << endl;
    cout << rearShoulders[fourthrand % 2].name << ": " << rearShoulders[fourthrand % 2].weight << "lbs x " << rearShoulders[fourthrand % 2].sets << " sets x " << rearShoulders[fourthrand % 2].reps << " reps" << endl;
    cout << "_________________________________________________________________" << endl << endl;

    cout << "Post Workout" << endl << "How did the workout go?" << endl;
    cout << "Did " << back[firstrand % 4].name << " go well? (yes/no)" << endl;
    cin >> increase;
    if(increase == "yes"){
      back[firstrand % 4].increaseDifficulty();
    }
    cout << "Did " << biceps[secondrand % 4].name << " go well? (yes/no)" << endl;
    cin >> increase;
    if(increase == "yes"){
      biceps[secondrand % 4].increaseDifficulty();
    }
    cout << "Did " << traps[thirdrand % 3].name << " go well? (yes/no)" << endl;
    cin >> increase;
    if(increase == "yes"){
      traps[thirdrand % 3].increaseDifficulty();
    }
    cout << "Did " << rearShoulders[fourthrand % 2].name << " go well? (yes/no)" << endl;
    cin >> increase;
    if(increase == "yes"){
      rearShoulders[fourthrand % 2].increaseDifficulty();
    }

  }

  //create the legs workout
  else if(workoutType == "legs"){
    cout << endl << "_________________________________________________________________" << endl;

    cout << legs[firstrand % 3].name << ": " << legs[firstrand % 3].weight << "lbs x " << legs[firstrand % 3].sets << " sets x " << legs[firstrand % 3].reps << " reps" << endl;
    cout << legs[((firstrand % 3) +1) %3].name << ": " << legs[((firstrand % 3) +1) %3].weight << "lbs x " << legs[((firstrand % 3) +1) %3].sets << " sets x " << legs[((firstrand % 3) +1) %3].reps << " reps" << endl;
    cout << calves[secondrand % 2].name << ": " << calves[secondrand % 2].weight << "lbs x " << calves[secondrand % 2].sets << " sets x " << calves[secondrand % 2].reps << " reps" << endl;
    outFile << dt;
    outFile << "------------------------" << endl;

    outFile << legs[firstrand % 3].name << ": " << legs[firstrand % 3].weight << "lbs x " << legs[firstrand % 3].sets << " sets x " << legs[firstrand % 3].reps << " reps" << endl;
    outFile << legs[(firstrand % 3) +1 %3].name << ": " << legs[(firstrand % 3) +1 %3].weight << "lbs x " << legs[(firstrand % 3) +1 %3].sets << " sets x " << legs[(firstrand % 3) +1 %3].reps << " reps" << endl;
    outFile << calves[secondrand % 2].name << ": " << calves[secondrand % 2].weight << "lbs x " << calves[secondrand % 2].sets << " sets x " << calves[secondrand % 2].reps << " reps" << endl  << endl << endl;

    cout << "_________________________________________________________________" << endl << endl;

    cout << "Post Workout" << endl << "How did the workout go?" << endl;
    cout << "Did " << legs[firstrand % 3].name << " go well? (yes/no)" << endl;
    cin >> increase;
    if(increase == "yes"){
      legs[firstrand % 3].increaseDifficulty();
    }
    cout << "Did " << legs[((firstrand % 3) +1) %3].name << " go well? (yes/no)" << endl;
    cin >> increase;
    if(increase == "yes"){
      legs[((firstrand % 3) +1) %3].increaseDifficulty();
    }
    cout << "Did " << calves[secondrand % 2].name << " go well? (yes/no)" << endl;
    cin >> increase;
    if(increase == "yes"){
      calves[secondrand % 2].increaseDifficulty();
    }
  }

  //create the abs workout
  else if(workoutType == "abs"){

    outFile << dt;
    outFile << "------------------------" << endl;
    one = firstrand % 3;
    two = secondrand % 3;
    three = thirdrand % 9;
    four = fourthrand % 9;
    if(one == two){
      two = (one +1) % 3;
    }
    if(three == four){
      four = three/four;
    }
    cout << endl << "_________________________________________________________________" << endl;
    outFile << weightedAbs[one].name << ": " << weightedAbs[one].weight << "lbs x " << weightedAbs[one].sets << " sets x " << weightedAbs[one].reps << " reps" << endl;
    outFile << weightedAbs[two].name << ": " << weightedAbs[two].weight << "lbs x " << weightedAbs[two].sets << " sets x " << weightedAbs[two].reps << " reps" << endl;
    outFile << abs[three].name << ": " << abs[three].weight << "lbs x " << abs[three].sets << " sets x " << abs[three].reps << " reps" << endl;
    outFile << abs[four].name << ": " << abs[four].weight << "lbs x " << abs[four].sets << " sets x " << abs[four].reps << " reps" <<  endl  << endl << endl;

    cout << weightedAbs[one].name << ": " << weightedAbs[one].weight << "lbs x " << weightedAbs[one].sets << " sets x " << weightedAbs[one].reps << " reps" << endl;
    cout << weightedAbs[two].name << ": " << weightedAbs[two].weight << "lbs x " << weightedAbs[two].sets << " sets x " << weightedAbs[two].reps << " reps" << endl;
    cout << abs[three].name << ": " << abs[three].sets << " sets x " << abs[three].reps << " reps" << endl;
    cout << abs[four].name << ": " << abs[four].sets << " sets x " << abs[four].reps << " reps" << endl;

    cout << "_________________________________________________________________" << endl << endl;

    cout << "Post Workout" << endl << "How did the workout go?" << endl;
    cout << "Did " << weightedAbs[one].name << " go well? (yes/no)" << endl;
    cin >> increase;
    if(increase == "yes"){
      weightedAbs[one].increaseDifficulty();
    }
    cout << "Did " << weightedAbs[two].name << " go well? (yes/no)" << endl;
    cin >> increase;
    if(increase == "yes"){
      weightedAbs[two].increaseDifficulty();
    }
    cout << "Did " << abs[three].name << " go well? (yes/no)" << endl;
    cin >> increase;
    if(increase == "yes"){
      abs[three].increaseDifficultyAbs();
    }
    cout << "Did " << abs[four].name << " go well? (yes/no)" << endl;
    cin >> increase;
    if(increase == "yes"){
      abs[four].increaseDifficultyAbs();
    }
  }
  //this was the 'set' workout which consisted of upperBody legs and back
  // else if(workoutType == "set"){
  //   cout << endl << "____________________________Day 1________________________________" << endl;
  //
  //   cout << upperBody[firstrand % 5].name << ": " << upperBody[firstrand % 5].weight << "lbs x " << upperBody[firstrand % 5].sets << " sets x " << upperBody[firstrand % 5].reps << " reps" << endl;
  //   cout << chest[secondrand % 3].name << ": " << chest[secondrand % 3].weight << "lbs x " << chest[secondrand % 3].sets << " sets x " << chest[secondrand % 3].reps << " reps" << endl;
  //   cout << shoulders[thirdrand % 3].name << ": " << shoulders[thirdrand % 3].weight << "lbs x " << shoulders[thirdrand % 3].sets << " sets x " << shoulders[thirdrand % 3].reps << " reps" << endl;
  //   cout << triceps[fourthrand % 2].name << ": " << triceps[fourthrand % 2].weight << "lbs x " << triceps[fourthrand % 2].sets << " sets x " << triceps[fourthrand % 2].reps << " reps" << endl;
  //   outFile << dt;
  //   outFile << "------------------------" << endl;
  //   outFile << upperBody[firstrand % 5].name << ": " << upperBody[firstrand % 5].weight << "lbs x " << upperBody[firstrand % 5].sets << " sets x " << upperBody[firstrand % 5].reps << " reps" << endl;
  //   outFile << chest[secondrand % 3].name << ": " << chest[secondrand % 3].weight << "lbs x " << chest[secondrand % 3].sets << " sets x " << chest[secondrand % 3].reps << " reps" << endl;
  //   outFile << shoulders[thirdrand % 3].name << ": " << shoulders[thirdrand % 3].weight << "lbs x " << shoulders[thirdrand % 3].sets << " sets x " << shoulders[thirdrand % 3].reps << " reps" << endl;
  //   outFile << triceps[fourthrand % 2].name << ": " << triceps[fourthrand % 2].weight << "lbs x " << triceps[fourthrand % 2].sets << " sets x " << triceps[fourthrand % 2].reps << " reps" << endl;
  //   cout << "_________________________________________________________________" << endl << endl;
  //   cout << endl << "____________________________Day 2________________________________" << endl;
  //
  //   cout << back[firstrand % 4].name << ": " << back[firstrand % 4].weight << "lbs x " << back[firstrand % 4].sets << " sets x " << back[firstrand % 4].reps << " reps" << endl;
  //   cout << biceps[secondrand % 4].name << ": " << biceps[secondrand % 4].weight << "lbs x " << biceps[secondrand % 4].sets << " sets x " << biceps[secondrand % 4].reps << " reps" << endl;
  //   cout << traps[thirdrand % 3].name << ": " << traps[thirdrand % 3].weight << "lbs x " << traps[thirdrand % 3].sets << " sets x " << traps[thirdrand % 3].reps << " reps" << endl;
  //   cout << rearShoulders[fourthrand % 3].name << ": " << rearShoulders[fourthrand % 3].weight << "lbs x " << rearShoulders[fourthrand % 3].sets << " sets x " << rearShoulders[fourthrand % 3].reps << " reps" << endl;
  //
  //   outFile << back[firstrand % 4].name << ": " << back[firstrand % 4].weight << "lbs x " << back[firstrand % 4].sets << " sets x " << back[firstrand % 4].reps << " reps" << endl;
  //   outFile << biceps[secondrand % 4].name << ": " << biceps[secondrand % 4].weight << "lbs x " << biceps[secondrand % 4].sets << " sets x " << biceps[secondrand % 4].reps << " reps" << endl;
  //   outFile << traps[thirdrand % 3].name << ": " << traps[thirdrand % 3].weight << "lbs x " << traps[thirdrand % 3].sets << " sets x " << traps[thirdrand % 3].reps << " reps" << endl;
  //   outFile << rearShoulders[fourthrand % 3].name << ": " << rearShoulders[fourthrand % 3].weight << "lbs x " << rearShoulders[fourthrand % 3].sets << " sets x " << rearShoulders[fourthrand % 3].reps << " reps" << endl;
  //
  //   cout << "_________________________________________________________________" << endl << endl;
  //
  //   cout << endl << "____________________________Day 3________________________________" << endl;
  //
  //   cout << legs[firstrand % 3].name << ": " << legs[firstrand % 3].weight << "lbs x " << legs[firstrand % 3].sets << " sets x " << legs[firstrand % 3].reps << " reps" << endl;
  //   cout << calves[secondrand % 2].name << ": " << calves[secondrand % 2].weight << "lbs x " << calves[secondrand % 2].sets << " sets x " << calves[secondrand % 2].reps << " reps" << endl;
  //
  //   outFile << legs[firstrand % 3].name << ": " << legs[firstrand % 3].weight << "lbs x " << legs[firstrand % 3].sets << " sets x " << legs[firstrand % 3].reps << " reps" << endl;
  //   outFile << calves[secondrand % 2].name << ": " << calves[secondrand % 2].weight << "lbs x " << calves[secondrand % 2].sets << " sets x " << calves[secondrand % 2].reps << " reps" << endl << endl;
  //
  //   cout << "_________________________________________________________________" << endl << endl;
  //
  // }

  outFile.close();

  //Write the updated weights, sets, and reps to log file
  ofstream report;
  report.open(workoutTxt);
  for(size_t i = 0; i < upperBody.size(); i++){
    report << upperBody[i].name << ' ' << "upperBody" << ' ' << upperBody[i].weight << ' ' << upperBody[i].sets << ' ' << upperBody[i].reps << endl;
  }
  for(size_t i = 0; i < chest.size(); i++){
    report << chest[i].name << ' ' << "chest" << ' ' << chest[i].weight << ' ' << chest[i].sets << ' ' << chest[i].reps << endl;
  }
  for(size_t i = 0; i < shoulders.size(); i++){
    report << shoulders[i].name << ' ' << "shoulders" << ' ' << shoulders[i].weight << ' ' << shoulders[i].sets << ' ' << shoulders[i].reps << endl;
  }
  for(size_t i = 0; i < triceps.size(); i++){
    report << triceps[i].name << ' ' << "triceps" << ' ' << triceps[i].weight << ' ' << triceps[i].sets << ' ' << triceps[i].reps << endl;
  }
  for(size_t i = 0; i < back.size(); i++){
    report << back[i].name << ' ' << "back" << ' ' << back[i].weight << ' ' << back[i].sets << ' ' << back[i].reps << endl;
  }
  for(size_t i = 0; i < biceps.size(); i++){
    report << biceps[i].name << ' ' << "biceps" << ' ' << biceps[i].weight << ' ' << biceps[i].sets << ' ' << biceps[i].reps << endl;
  }
  for(size_t i = 0; i < traps.size(); i++){
    report << traps[i].name << ' ' << "traps" << ' ' << traps[i].weight << ' ' << traps[i].sets << ' ' << traps[i].reps << endl;
  }
  for(size_t i = 0; i < rearShoulders.size(); i++){
    report << rearShoulders[i].name << ' ' << "rearShoulders" << ' ' << rearShoulders[i].weight << ' ' << rearShoulders[i].sets << ' ' << rearShoulders[i].reps << endl;
  }
  for(size_t i = 0; i < legs.size(); i++){
    report << legs[i].name << ' ' << "legs" << ' ' << legs[i].weight << ' ' << legs[i].sets << ' ' << legs[i].reps << endl;
  }
  for(size_t i = 0; i < calves.size(); i++){
    report << calves[i].name << ' ' << "calves" << ' ' << calves[i].weight << ' ' << calves[i].sets << ' ' << calves[i].reps << endl;
  }
  for(size_t i = 0; i < weightedAbs.size(); i++){
    report << weightedAbs[i].name << ' ' << "weightedAbs" << ' ' << weightedAbs[i].weight << ' ' << weightedAbs[i].sets << ' ' << weightedAbs[i].reps << endl;
  }
  for(size_t i = 0; i < abs.size(); i++){
    report << abs[i].name << ' ' << "abs" << ' ' << abs[i].weight << ' ' << abs[i].sets << ' ' << abs[i].reps << endl;
  }
  cout << "Good Job :)" << endl << endl << endl;
  report.close();

  return 0;
}

#include "workout.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include <sys/stat.h>
#include <ctime>
#include <algorithm>    // std::random_shuffle

//#include <filesystem>



using namespace std;

int main(){


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



  // workout barbellPress("barbellPress", 135, 3, 10);
  // upperBody.push_back(barbellPress);
  // upperBody.push_back(barbellPress);
  //
  //
  // workout dumbellPress("dumbellPress", 50, 3, 10);
  // upperBody.push_back(dumbellPress);
  // upperBody.push_back(dumbellPress);
  //
  //
  // workout weightedDips("weightedDips", 25, 3, 10);
  // upperBody.push_back(weightedDips);
  //
  // workout powerFly("powerFly", 20, 3, 10);
  // chest.push_back(powerFly);
  //
  // workout bodyWeightChestFly("bodyWeightChestFly", 0, 3, 10);
  // chest.push_back(bodyWeightChestFly);
  //
  // workout machineFly("machineFly", 80, 3, 10);
  // chest.push_back(machineFly);
  //
  // workout facePull("facePull", 20, 3, 10);
  // shoulders.push_back(facePull);
  //
  // workout wideUprightRow("wideUprightRow", 20, 3, 10);
  // shoulders.push_back(wideUprightRow);
  //
  // workout lateralRaises("lateralRaises", 20, 3, 10);
  // shoulders.push_back(lateralRaises);
  //
  // workout closeGripBenchPress("closeGripBenchPress", 60, 3, 8);
  // triceps.push_back(closeGripBenchPress);
  //
  // workout overheadTricepExtensions("overheadTricepExtensions", 20, 3, 8);
  // triceps.push_back(overheadTricepExtensions);
  //
  // workout yatesRow("yatesRow", 75, 3, 8);
  // back.push_back(yatesRow);
  //
  // workout deadlift("deadlift", 165, 3, 8);
  // back.push_back(deadlift);
  //
  // workout pullup("pullup", 0, 3, 8);
  // back.push_back(pullup);
  //
  // workout latPulldown("latPulldown", 100, 3, 8);
  // back.push_back(latPulldown);
  //
  // workout closeGripPullups("closeGripPullups", 0, 3, 8);
  // biceps.push_back(closeGripPullups);
  //
  // workout barbellCurl("barbellCurl", 50, 3, 8);
  // biceps.push_back(barbellCurl);
  //
  // workout dumbellCurl("dumbellCurl", 30, 3, 8);
  // biceps.push_back(dumbellCurl);
  //
  // workout dragCurl("dragCurl", 30, 3, 8);
  // biceps.push_back(dragCurl);
  //
  // workout dumbellShrugs("dumbellShrugs", 45, 3, 8);
  // traps.push_back(dumbellShrugs);
  //
  // workout pullupShrug("pullupShrug", 0, 3, 10);
  // traps.push_back(pullupShrug);
  //
  // workout barbellRow("barbellRow", 65, 3, 10);
  // traps.push_back(barbellRow);
  //
  // rearShoulders.push_back(facePull);
  //
  // workout reversePecDecFly("reversePecDecFly", 40, 3, 10);
  // rearShoulders.push_back(reversePecDecFly);
  //
  // workout cableRearRaises("cableRearRaises", 20, 3, 10);
  // rearShoulders.push_back(cableRearRaises);
  //
  // workout barbellSquats("barbellSquats", 135, 3, 12);
  // legs.push_back(barbellSquats);
  //
  // workout legPress("legPress", 310, 3, 9);
  // legs.push_back(legPress);
  //
  // workout bulgarianSquats("bulgarianSquats", 30, 3, 8);
  // legs.push_back(bulgarianSquats);
  //
  // workout standingCalfRaises("standingCalfRaises", 100, 3, 10);
  // calves.push_back(standingCalfRaises);
  //
  // workout seatedCalfRaises("seatedCalfRaises", 100, 3, 10);
  // calves.push_back(seatedCalfRaises);

////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
  cout << "Hello, enter your name." << endl;
  string name;
  cin >> name;
  string workoutTxt = "Profiles/" + name + "Workouts.txt";
  // cout << "firstrand: " << firstrand << endl;
  // cout << "thirdrand: " << thirdrand << endl;
  // cout << "secondrand: " << secondrand << endl;
  // cout << "fourthrand: " << fourthrand << endl;


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

    // ofstream outFile (workoutTxt);
    // outFile.close();
    // fstream to (workoutTxt);
    // ifstream from ("masterWorkoutList.txt");
    // to << from.rdbuf();
    // to.close();
    // from.close();

    cout << "created new file" << endl;
    //copy_file("masterWorkoutList", file);

    //practice reading from file
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
      cout << "enter starting weight for " << wrkout << " for 3 sets of 8 reps? (enter number)" << endl;
      cin >> number;
      workout temp(wrkout, number, 3, 8);
      //string namex = temp.name;
      //group.push_back(temp);
      //switch(group){
        if(group ==  "upperBody"){
          //cout << "added " << wrkout << " to " << group << endl;
          upperBody.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else if(group ==  "chest"){
          //cout << "added " << wrkout << " to " << group << endl;
          chest.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else if(group ==  "shoulders"){
          //cout << "added " << wrkout << " to " << group << endl;
          shoulders.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else if(group ==  "triceps"){
          //cout << "added " << wrkout << " to " << group << endl;
          triceps.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else if(group ==  "back"){
          //cout << "added " << wrkout << " to " << group << endl;
          back.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else if(group ==  "biceps"){
          //cout << "added " << wrkout << " to " << group << endl;
          biceps.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else if(group ==  "traps"){
          //cout << "added " << wrkout << " to " << group << endl;
          traps.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else if(group ==  "rearShoulders"){
          //cout << "added " << wrkout << " to " << group << endl;
          rearShoulders.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else if(group ==  "legs"){
          //cout << "added " << wrkout << " to " << group << endl;
          legs.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else if(group ==  "calves"){
          //cout << "added " << wrkout << " to " << group << endl;
          calves.push_back(temp);
          outFile << temp.name << ' ' << group << ' ' << temp.weight << ' ' << temp.sets << ' ' << temp.reps << endl;
        }
        else
        cout << "did not find " << group << endl;

    }
    practice.close();
  }

  //If the user already has a profile, read from the file
  else{
    //cout << "already has profile" << endl;
    string wkout;
    string type;
    int w;
    int n;
    int s;
    while(inFile.good()){
      inFile >> wkout >> type >> w >> n >> s;
      workout t(wkout, w, n, s);
      //string namex = temp.name;
      //group.push_back(temp);
      //switch(group){
      if(type ==  "upperBody"){
        //cout << "added " << wkout << " to " << type << endl;
        upperBody.push_back(t);
        //outFile << t.name << ' ' << t.weight << ' ' << t.sets << ' ' << t.reps << endl;
      }
      else if(type ==  "chest"){
        //cout << "added " << wkout << " to " << type << endl;
        chest.push_back(t);
        //outFile << t.name << ' ' << t.weight << ' ' << t.sets << ' ' << t.reps << endl;
      }
      else if(type ==  "shoulders"){
        //cout << "added " << wkout << " to " << type << endl;
        shoulders.push_back(t);
        //outFile << t.name << ' ' << t.weight << ' ' << t.sets << ' ' << t.reps << endl;
      }
      else if(type ==  "triceps"){
        //cout << "added " << wkout << " to " << type << endl;
        triceps.push_back(t);
        //outFile << t.name << ' ' << t.weight << ' ' << t.sets << ' ' << t.reps << endl;
      }
      else if(type ==  "back"){
        //cout << "added " << wkout << " to " << type << endl;
        back.push_back(t);
        //outFile << t.name << ' ' << t.weight << ' ' << t.sets << ' ' << t.reps << endl;
      }
      else if(type ==  "biceps"){
        //cout << "added " << wkout << " to " << type << endl;
        biceps.push_back(t);
        //outFile << t.name << ' ' << t.weight << ' ' << t.sets << ' ' << t.reps << endl;
      }
      else if(type ==  "traps"){
        //cout << "added " << wkout << " to " << type << endl;
        traps.push_back(t);
        //outFile << t.name << ' ' << t.weight << ' ' << t.sets << ' ' << t.reps << endl;
      }
      else if(type ==  "rearShoulders"){
        //cout << "added " << wkout << " to " << type << endl;
        rearShoulders.push_back(t);
        //outFile << t.name << ' ' << t.weight << ' ' << t.sets << ' ' << t.reps << endl;
      }
      else if(type ==  "legs"){
        //cout << "added " << wkout << " to " << type << endl;
        legs.push_back(t);
        //outFile << t.name << ' ' << t.weight << ' ' << t.sets << ' ' << t.reps << endl;
      }
      else if(type ==  "calves"){
        //cout << "added " << wkout << " to " << type << endl;
        calves.push_back(t);
        //outFile << t.name << ' ' << t.weight << ' ' << t.sets << ' ' << t.reps << endl;
      }
      //else
      //cout << "did not find " << type << endl;


    }
    inFile.close();
  }




  cout << endl <<"Hello, ready to get fit " << name << "?" << endl;
  srand (time(NULL));
  int firstrand = rand();
  srand (firstrand);
  int thirdrand = rand();
  cout << "What body group would you like to work out today? (upperBody, back, legs, or set)" << endl;

  ofstream outFile("Profiles/" + name + "Log.txt", ios::app);

  string workoutType;
  cin >> workoutType;
  srand (time(NULL));
  int secondrand = rand();
  srand (secondrand);
  int fourthrand = rand();
  //
  // random_shuffle ( upperBody.begin(), upperBody.end() );
  // random_shuffle ( chest.begin(), chest.end() );
  // random_shuffle ( shoulders.begin(), shoulders.end() );
  // random_shuffle ( triceps.begin(), triceps.end() );
  // random_shuffle ( back.begin(), back.end() );
  // random_shuffle ( biceps.begin(), biceps.end() );
  // random_shuffle ( traps.begin(), traps.end() );
  // random_shuffle ( rearShoulders.begin(), rearShoulders.end() );
  // random_shuffle ( calves.begin(), calves.end() );
  // random_shuffle ( legs.begin(), legs.end() );
  //
  //
  //




  // current date/time based on current system
   time_t now = time(0);

   // convert now to string form
   char* dt = ctime(&now);

   //cout << "The local date and time is: " << dt << endl;

  //Possibly have 3 different hash tables relating workout to weights
  //reps and sets. upload all the information into the hash tables then
  //lookup and find the values. wonder how hard it would be to then write
  //the changes?

  //read each line on masterWorkoutList and ask for starting weights
  //for 3 sets of 8 reps

  while(workoutType != "upperBody" && workoutType != "back" && workoutType != "legs" && workoutType != "set"){
    cout << "Invalid Answer, try again (upperBody, back, legs, or set)" << endl;
    cin >> workoutType;
  }
  cout << "You want to work out " << workoutType << ". Gotcha!" << endl;
  string increase;


  if(workoutType == "upperBody"){
    //randomly choose an option from upperBody vector
    cout << endl << "_________________________________________________________________" << endl;
    //outFile.write(upperBody[firstrand % 5].name);
    //outFile.write(upperBody[firstrand % 5].name + ": " + upperBody[firstrand % 5].weight + "lbs x " + upperBody[firstrand % 5].sets + " sets x " + upperBody[firstrand % 5].reps + " reps" + endl);
    outFile << dt;
    outFile << "------------------------" << endl;;
    //
    // outFile << upperBody[0].name << ": " << upperBody[0].weight << "lbs x " << upperBody[0].sets << " sets x " << upperBody[0].reps << " reps" << endl;
    // outFile << chest[0].name << ": " << chest[0].weight << "lbs x " << chest[0].sets << " sets x " << chest[0].reps << " reps" << endl;
    // outFile << shoulders[0].name << ": " << shoulders[0].weight << "lbs x " << shoulders[0].sets << " sets x " << shoulders[0].reps << " reps" << endl;
    // outFile << triceps[0].name << ": " << triceps[0].weight << "lbs x " << triceps[0].sets << " sets x " << triceps[0].reps << " reps" << endl << endl << endl;
    //
    // cout << upperBody[0].name << ": " << upperBody[0].weight << "lbs x " << upperBody[0].sets << " sets x " << upperBody[0].reps << " reps" << endl;
    // cout << chest[0].name << ": " << chest[0].weight << "lbs x " << chest[0].sets << " sets x " << chest[0].reps << " reps" << endl;
    // cout << shoulders[0].name << ": " << shoulders[0].weight << "lbs x " << shoulders[0].sets << " sets x " << shoulders[0].reps << " reps" << endl;
    // cout << triceps[0].name << ": " << triceps[0].weight << "lbs x " << triceps[0].sets << " sets x " << triceps[0].reps << " reps" << endl;

    outFile << upperBody[firstrand % 5].name << ": " << upperBody[firstrand % 5].weight << "lbs x " << upperBody[firstrand % 5].sets << " sets x " << upperBody[firstrand % 5].reps << " reps" << endl;
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


    ofstream inFile;
    inFile.open(workoutTxt);
    for(size_t i = 0; i < upperBody.size(); i++){
      inFile << upperBody[i].name << ' ' << "upperBody" << ' ' << upperBody[i].weight << ' ' << upperBody[i].sets << ' ' << upperBody[i].reps << endl;
    }
    for(size_t i = 0; i < chest.size(); i++){
      inFile << chest[i].name << ' ' << "chest" << ' ' << chest[i].weight << ' ' << chest[i].sets << ' ' << chest[i].reps << endl;
    }
    for(size_t i = 0; i < shoulders.size(); i++){
      inFile << shoulders[i].name << ' ' << "shoulders" << ' ' << shoulders[i].weight << ' ' << shoulders[i].sets << ' ' << shoulders[i].reps << endl;
    }
    for(size_t i = 0; i < triceps.size(); i++){
      inFile << triceps[i].name << ' ' << "triceps" << ' ' << triceps[i].weight << ' ' << triceps[i].sets << ' ' << triceps[i].reps << endl;
    }
    for(size_t i = 0; i < back.size(); i++){
      inFile << back[i].name << ' ' << "back" << ' ' << back[i].weight << ' ' << back[i].sets << ' ' << back[i].reps << endl;
    }
    for(size_t i = 0; i < biceps.size(); i++){
      inFile << biceps[i].name << ' ' << "biceps" << ' ' << biceps[i].weight << ' ' << biceps[i].sets << ' ' << biceps[i].reps << endl;
    }
    for(size_t i = 0; i < traps.size(); i++){
      inFile << traps[i].name << ' ' << "traps" << ' ' << traps[i].weight << ' ' << traps[i].sets << ' ' << traps[i].reps << endl;
    }
    for(size_t i = 0; i < rearShoulders.size(); i++){
      inFile << rearShoulders[i].name << ' ' << "rearShoulders" << ' ' << rearShoulders[i].weight << ' ' << rearShoulders[i].sets << ' ' << rearShoulders[i].reps << endl;
    }
    for(size_t i = 0; i < legs.size(); i++){
      inFile << legs[i].name << ' ' << "legs" << ' ' << legs[i].weight << ' ' << legs[i].sets << ' ' << legs[i].reps << endl;
    }
    for(size_t i = 0; i < calves.size(); i++){
      inFile << calves[i].name << ' ' << "calves" << ' ' << calves[i].weight << ' ' << calves[i].sets << ' ' << calves[i].reps << endl;
    }
    cout << "Good Job :)" << endl;




    //randomly choose one chest, one shoulder, one tricep.
  }

  else if(workoutType == "back"){
    //randomly choose an option from upperBody vector
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


    ofstream inFile;
    inFile.open(workoutTxt);
    for(size_t i = 0; i < upperBody.size(); i++){
      inFile << upperBody[i].name << ' ' << "upperBody" << ' ' << upperBody[i].weight << ' ' << upperBody[i].sets << ' ' << upperBody[i].reps << endl;
    }
    for(size_t i = 0; i < chest.size(); i++){
      inFile << chest[i].name << ' ' << "chest" << ' ' << chest[i].weight << ' ' << chest[i].sets << ' ' << chest[i].reps << endl;
    }
    for(size_t i = 0; i < shoulders.size(); i++){
      inFile << shoulders[i].name << ' ' << "shoulders" << ' ' << shoulders[i].weight << ' ' << shoulders[i].sets << ' ' << shoulders[i].reps << endl;
    }
    for(size_t i = 0; i < triceps.size(); i++){
      inFile << triceps[i].name << ' ' << "triceps" << ' ' << triceps[i].weight << ' ' << triceps[i].sets << ' ' << triceps[i].reps << endl;
    }
    for(size_t i = 0; i < back.size(); i++){
      inFile << back[i].name << ' ' << "back" << ' ' << back[i].weight << ' ' << back[i].sets << ' ' << back[i].reps << endl;
    }
    for(size_t i = 0; i < biceps.size(); i++){
      inFile << biceps[i].name << ' ' << "biceps" << ' ' << biceps[i].weight << ' ' << biceps[i].sets << ' ' << biceps[i].reps << endl;
    }
    for(size_t i = 0; i < traps.size(); i++){
      inFile << traps[i].name << ' ' << "traps" << ' ' << traps[i].weight << ' ' << traps[i].sets << ' ' << traps[i].reps << endl;
    }
    for(size_t i = 0; i < rearShoulders.size(); i++){
      inFile << rearShoulders[i].name << ' ' << "rearShoulders" << ' ' << rearShoulders[i].weight << ' ' << rearShoulders[i].sets << ' ' << rearShoulders[i].reps << endl;
    }
    for(size_t i = 0; i < legs.size(); i++){
      inFile << legs[i].name << ' ' << "legs" << ' ' << legs[i].weight << ' ' << legs[i].sets << ' ' << legs[i].reps << endl;
    }
    for(size_t i = 0; i < calves.size(); i++){
      inFile << calves[i].name << ' ' << "calves" << ' ' << calves[i].weight << ' ' << calves[i].sets << ' ' << calves[i].reps << endl;
    }
    cout << "Good Job :)" << endl;







    //randomly choose one chest, one shoulder, one tricep.
  }

  else if(workoutType == "legs"){
    //randomly choose an option from upperBody vector
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

    ofstream inFile;
    inFile.open(workoutTxt);
    for(size_t i = 0; i < upperBody.size(); i++){
      inFile << upperBody[i].name << ' ' << "upperBody" << ' ' << upperBody[i].weight << ' ' << upperBody[i].sets << ' ' << upperBody[i].reps << endl;
    }
    for(size_t i = 0; i < chest.size(); i++){
      inFile << chest[i].name << ' ' << "chest" << ' ' << chest[i].weight << ' ' << chest[i].sets << ' ' << chest[i].reps << endl;
    }
    for(size_t i = 0; i < shoulders.size(); i++){
      inFile << shoulders[i].name << ' ' << "shoulders" << ' ' << shoulders[i].weight << ' ' << shoulders[i].sets << ' ' << shoulders[i].reps << endl;
    }
    for(size_t i = 0; i < triceps.size(); i++){
      inFile << triceps[i].name << ' ' << "triceps" << ' ' << triceps[i].weight << ' ' << triceps[i].sets << ' ' << triceps[i].reps << endl;
    }
    for(size_t i = 0; i < back.size(); i++){
      inFile << back[i].name << ' ' << "back" << ' ' << back[i].weight << ' ' << back[i].sets << ' ' << back[i].reps << endl;
    }
    for(size_t i = 0; i < biceps.size(); i++){
      inFile << biceps[i].name << ' ' << "biceps" << ' ' << biceps[i].weight << ' ' << biceps[i].sets << ' ' << biceps[i].reps << endl;
    }
    for(size_t i = 0; i < traps.size(); i++){
      inFile << traps[i].name << ' ' << "traps" << ' ' << traps[i].weight << ' ' << traps[i].sets << ' ' << traps[i].reps << endl;
    }
    for(size_t i = 0; i < rearShoulders.size(); i++){
      inFile << rearShoulders[i].name << ' ' << "rearShoulders" << ' ' << rearShoulders[i].weight << ' ' << rearShoulders[i].sets << ' ' << rearShoulders[i].reps << endl;
    }
    for(size_t i = 0; i < legs.size(); i++){
      inFile << legs[i].name << ' ' << "legs" << ' ' << legs[i].weight << ' ' << legs[i].sets << ' ' << legs[i].reps << endl;
    }
    for(size_t i = 0; i < calves.size(); i++){
      inFile << calves[i].name << ' ' << "calves" << ' ' << calves[i].weight << ' ' << calves[i].sets << ' ' << calves[i].reps << endl;
    }

    cout << "Good Job :)" << endl;




    //randomly choose one chest, one shoulder, one tricep.
  }

  else if(workoutType == "set"){
    cout << endl << "____________________________Day 1________________________________" << endl;

    cout << upperBody[firstrand % 5].name << ": " << upperBody[firstrand % 5].weight << "lbs x " << upperBody[firstrand % 5].sets << " sets x " << upperBody[firstrand % 5].reps << " reps" << endl;
    cout << chest[secondrand % 3].name << ": " << chest[secondrand % 3].weight << "lbs x " << chest[secondrand % 3].sets << " sets x " << chest[secondrand % 3].reps << " reps" << endl;
    cout << shoulders[thirdrand % 3].name << ": " << shoulders[thirdrand % 3].weight << "lbs x " << shoulders[thirdrand % 3].sets << " sets x " << shoulders[thirdrand % 3].reps << " reps" << endl;
    cout << triceps[fourthrand % 2].name << ": " << triceps[fourthrand % 2].weight << "lbs x " << triceps[fourthrand % 2].sets << " sets x " << triceps[fourthrand % 2].reps << " reps" << endl;
    outFile << dt;
    outFile << "------------------------" << endl;
    outFile << upperBody[firstrand % 5].name << ": " << upperBody[firstrand % 5].weight << "lbs x " << upperBody[firstrand % 5].sets << " sets x " << upperBody[firstrand % 5].reps << " reps" << endl;
    outFile << chest[secondrand % 3].name << ": " << chest[secondrand % 3].weight << "lbs x " << chest[secondrand % 3].sets << " sets x " << chest[secondrand % 3].reps << " reps" << endl;
    outFile << shoulders[thirdrand % 3].name << ": " << shoulders[thirdrand % 3].weight << "lbs x " << shoulders[thirdrand % 3].sets << " sets x " << shoulders[thirdrand % 3].reps << " reps" << endl;
    outFile << triceps[fourthrand % 2].name << ": " << triceps[fourthrand % 2].weight << "lbs x " << triceps[fourthrand % 2].sets << " sets x " << triceps[fourthrand % 2].reps << " reps" << endl;
    cout << "_________________________________________________________________" << endl << endl;
    cout << endl << "____________________________Day 2________________________________" << endl;

    cout << back[firstrand % 4].name << ": " << back[firstrand % 4].weight << "lbs x " << back[firstrand % 4].sets << " sets x " << back[firstrand % 4].reps << " reps" << endl;
    cout << biceps[secondrand % 4].name << ": " << biceps[secondrand % 4].weight << "lbs x " << biceps[secondrand % 4].sets << " sets x " << biceps[secondrand % 4].reps << " reps" << endl;
    cout << traps[thirdrand % 3].name << ": " << traps[thirdrand % 3].weight << "lbs x " << traps[thirdrand % 3].sets << " sets x " << traps[thirdrand % 3].reps << " reps" << endl;
    cout << rearShoulders[fourthrand % 3].name << ": " << rearShoulders[fourthrand % 3].weight << "lbs x " << rearShoulders[fourthrand % 3].sets << " sets x " << rearShoulders[fourthrand % 3].reps << " reps" << endl;

    outFile << back[firstrand % 4].name << ": " << back[firstrand % 4].weight << "lbs x " << back[firstrand % 4].sets << " sets x " << back[firstrand % 4].reps << " reps" << endl;
    outFile << biceps[secondrand % 4].name << ": " << biceps[secondrand % 4].weight << "lbs x " << biceps[secondrand % 4].sets << " sets x " << biceps[secondrand % 4].reps << " reps" << endl;
    outFile << traps[thirdrand % 3].name << ": " << traps[thirdrand % 3].weight << "lbs x " << traps[thirdrand % 3].sets << " sets x " << traps[thirdrand % 3].reps << " reps" << endl;
    outFile << rearShoulders[fourthrand % 3].name << ": " << rearShoulders[fourthrand % 3].weight << "lbs x " << rearShoulders[fourthrand % 3].sets << " sets x " << rearShoulders[fourthrand % 3].reps << " reps" << endl;

    cout << "_________________________________________________________________" << endl << endl;

    cout << endl << "____________________________Day 3________________________________" << endl;

    cout << legs[firstrand % 3].name << ": " << legs[firstrand % 3].weight << "lbs x " << legs[firstrand % 3].sets << " sets x " << legs[firstrand % 3].reps << " reps" << endl;
    cout << calves[secondrand % 2].name << ": " << calves[secondrand % 2].weight << "lbs x " << calves[secondrand % 2].sets << " sets x " << calves[secondrand % 2].reps << " reps" << endl;

    outFile << legs[firstrand % 3].name << ": " << legs[firstrand % 3].weight << "lbs x " << legs[firstrand % 3].sets << " sets x " << legs[firstrand % 3].reps << " reps" << endl;
    outFile << calves[secondrand % 2].name << ": " << calves[secondrand % 2].weight << "lbs x " << calves[secondrand % 2].sets << " sets x " << calves[secondrand % 2].reps << " reps" << endl << endl;

    cout << "_________________________________________________________________" << endl << endl;


    //NEXT TO DO - use text files to hold different accounts and update stats
  }
  outFile.close();

  return 0;
}

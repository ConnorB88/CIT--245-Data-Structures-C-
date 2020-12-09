#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "hoist.cpp"

using namespace std;
  // declare vector with zero elements
  // in global scope
  vector<string> candList;

// read a name in from console
// and write it to the end of candidateList
void getCandidateName() {
  // loop over entry logic until "stop" is read
  //temporaplements the most rudimentary functionality as brain food fory holding
  string candName = "";
while(true){
    cout << "Enter candidate name then enter; 'stop' to end" << '\n';
    // read value from user, store in codeName
    cin >> candName;
    if(candName == "stop"){
      break;
    }
    // test input by reading the console
    cout << "Pushing " << candName << " onto list " <<'\n';
    // write name to candidate list (global)
    candList.push_back(candName);
   }
   cout << "exiting loop" << '\n';
}

// Ireates over candidateList and writes to cout
void displayCandidateList(){
   cout << "Printing list" << '\n';
   // Print contents of list with for
   for(int i = 0; i<candList.size() ; ++i){
     cout << candList[i] << '\n';
   }
}
// test container for maps
void mapPractice(){
// create a new empty map string:int
map<string,int> ageMap;
// write in a key "edith" mapped to value 2
ageMap["edith"] = 2;
ageMap["sylvia"] = 15;
ageMap["delores"] = 22;
ageMap["sylvia"] = 98;
// lookup the value of key "sylvia"
//cout << ageMap["delores"] << '\n';

// Go into ageMap, give me key-value pairs
// one at a time until I have seen all of them 
// each key-value pair in a variable called
// kvPair
for(const auto& kvPair:ageMap){
  // kvPair is a pair object in which .first is the key
  // and .second gives us the value
   cout << kvPair.first << ":"<< '\t' << '\t'<< kvPair.second << '\n';
  }
}


// front door to program
int main() {
  //mapPractice();
  // call our functions in logical order
//getCandidateName();
//displayCandidateList();
}
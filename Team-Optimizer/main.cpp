#include <iostream>
  #include <string>
#include <vector>
#include <map>
using namespace std;
// declaring a typedef pair map and all of the variables
typedef pair<string,int> programmer;
typedef pair<string,string> artist;
typedef pair<string,int> levelDesigner;

 string programmerName = "";
  int years;
  int salary;
  string artistName = "";
  string style = "";
  int years2;
  string leveldesignerName = "";
  int years3;
  string engine = "";

// function will get all the candidates infromation for each one
void getCandidateInformation() {
  cout << "Welcome to the game dev team! You are going to need to fill out 3 roles, programmer, artist, and level designer by anwsering questions for each one to see if each one fits the criteria." << '\n';

    cout << "Enter your name as the programmer: " << '\n';
    cin >> programmerName;
    cout << "Enter your years of experience with programming: " << '\n';
    cin >> years;
    cout << "What salary do you expect for working here?" << '\n';
    cin >> salary;
    // lets them know when they finished a candidate
    cout << "All questions have been anwsered for this candidate please continue to the next candidate." << '\n';

    cout << "Enter your name as the artist:" << '\n';
    cin >> artistName;
    cout << "What is your favorite art stlye?" << '\n';
    cin >> style;
    cout << "Enter years of experience with this art style: " << '\n';
    cin >> years2;
    cout << "All questions have been anwsered for this candidate please continue to the next candidate." << '\n';

    cout << "Enter your name as the level designer:" << '\n';
    cin >> leveldesignerName;
    cout << "Enter years of experience with level designing: " << '\n';
    cin >> years3;
    cout << "Enter your the game engine you level design on: " << '\n';
    cin >> engine;
   
  }
  

// stores all of the information into this map
void mapData(){
  // making a map and using the typedef pair map with this one to 
  // get all of the information
  map <programmer,int> infoMap1 = { 
    {
    make_pair(programmerName, years), salary
    }
  };
  if(years >= 2){
    // for loop that runs through all of the information from the map
  for (const auto &entry: infoMap1)
    {
        auto key_pair = entry.first;
        cout << key_pair.first << " has "  << key_pair.second << " years of experience as a programmer and expects " << entry.second <<" salary."<< '\n';
       }
    }else{
      cout << "The programmer must have 2 or more years of experience to fit this role for us. We can not accept them." << '\n';
    }
  map <artist,int> infoMap2 = { 
    {
    make_pair(artistName, style),years2
    }
  };
   if(years2 >= 1){
  for (const auto &entry: infoMap2)
    {
        auto key_pair = entry.first;
        cout << key_pair.first << " likes the art style "  << key_pair.second << " as a artist and has " << entry.second <<" years of experience with it. "<< '\n';
       }
    }else{
      cout << "The artist must have 1 or more years of experience to fit this role for us. We can not accept them." << '\n';
    }
  map <levelDesigner,string> infoMap3 = { 
    {
    make_pair(leveldesignerName, years3), engine
    }
  };
   if(engine == "Unreal Engine" || "unreal engine"){
   if(years3 >= 2){
  for (const auto &entry: infoMap3)
    {
        auto key_pair = entry.first;
        cout << key_pair.first << " has "  << key_pair.second << " years of experience as a level designer and level designs in " << entry.second << '\n';
       }
   }else{
      cout << "The level designer must have 2 or more experience to fit this role we can not accept them" << '\n';
   }
    }else{
      cout << "The level designer must level design in unreal engine for them to be accepted. We can not accept them." << '\n';
    }
}
int main() {
// calling the different functions
getCandidateInformation();
mapData();
}
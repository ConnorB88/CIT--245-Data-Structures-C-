#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include "Phones.cpp"

using namespace std;
// Making a vector to store all of the seperate phones
vector<Phones> phone;

void createBunchOfPhones(){
  // creating vars
 string Name1 = "Iphone 6";
 string Name2 = "Iphone 7";
 string Name3 = "Iphone 8";
 string Name4 = "Iphone 10";
 int anwser;
// creating each phone with its own information
Phones* Phone1 = new Phones(4,Name1,false,2006,200,true,false,1000,false,true,10);
Phones* Phone2 = new Phones(3,Name2,true,2007,230,true,false,1200,false,true,20);
Phones* Phone3 = new Phones(2,Name3,true,2008,260,true,true,1400,true,true,23);
Phones* Phone4 = new Phones(1,Name4,true,2010,300,true,true,2000,true,true,29);

// pushing the phones on the list
phone.push_back(*Phone3);
phone.push_back(*Phone1);
phone.push_back(*Phone4);
phone.push_back(*Phone2);

cout << "Number of Phones: " << phone.size() << '\n';
// printing them out
phone[0].printPhoneStatus();
phone[1].printPhoneStatus();
phone[2].printPhoneStatus();
phone[3].printPhoneStatus();

cout << "The phones are out of order please auto sort them by the newest model to oldest model by pressing 1: "<<'\n';

cin >> anwser;

if(anwser == 1){
  // sorting the phones
sort(phone.begin(),phone.end(),[](const Phones& lhs, const Phones& rhs){
      return lhs.key < rhs.key;
   });
phone[0].printPhoneStatus();
phone[1].printPhoneStatus();
phone[2].printPhoneStatus();
phone[3].printPhoneStatus();
    }
  }

int main() {
 createBunchOfPhones();
}
#include <iostream>
#include <string>
#include <vector>
#include "WaterTank.cpp"

vector<WaterTank> tanks;

void createBunchOfTanks(){
  for(int c=0; c<30; c++){
    string tempName = "Tank" + to_string(c);
    WaterTank* tempTank = new WaterTank(tempName, false, 100+c, "shop1");
    tanks.push_back(*tempTank);
  }
  cout << "Num of tanks: " << tanks.size() << '\n';
  tanks[3].printTankStatus();
  tanks[23].printTankStatus();
  }


int main(){
  createBunchOfTanks();
  // instantiate a tank, use constructor
  //WaterTank t1{"collector1",false,250,"outside, rear"};
 //WaterTank t2{"tinyPressure"};

// simulating  tank manipulation
// t1.printTankStatus();
// t1.fillTank(34);
 //t1.drainTank(12);
 //t1.printTankStatus();
// t1.fillTank(340);
// t1.printTankStatus();
// t1.fillTank(360); 
//t1.printTankStatus();
}
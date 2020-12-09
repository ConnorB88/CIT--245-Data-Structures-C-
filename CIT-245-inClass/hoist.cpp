#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Crane{
  public:
    string style;
    int maxHoistWeightlbs;
    int swingRadiusDeg;
    bool isPowered;
  private:
    double cost;
};
// declaring a global 
vector<Crane> craneList;

void craneDemo(){
  // create instance of Crane
  Crane firstCrane;
  // assigning values to public members
    firstCrane.style = "cable hoist";
    firstCrane.maxHoistWeightlbs = 784;
    firstCrane.swingRadiusDeg = 0;
    firstCrane.isPowered = true;

    craneList.push_back(firstCrane);

}

int main(){
  // call our test method
  craneDemo();
  
  // remove the first Crane object
  // from the list and show that it 
  // has the contents we wrote in the function
  Crane c = craneList[0];
  cout << "Removed crane from Vector"<< '\n';
  cout << c.style << '\n';
  cout << c.maxHoistWeightlbs << '\n';
}
#include<string>
#include<iostream>

using namespace std;

class WaterTank{
    public:
    // Constructor function: Called automatically during object
    // instantiation and will require values for each param
      WaterTank(string id, bool psrizd, double cap, string loc)
            // C++ constructor -- used :, then memeber var {initial value}
             :pressurized{psrizd}, maxCapacity{cap}, location{loc}
            {
              tankID = id;
              currentCapacity = 0.0;
              // no other work to be done here in constructor
            }
      WaterTank(string id)
          :tankID{id}
          {
            currentCapacity = 0.0;
            // no other work to be done here
          }
          
          string getLocation(){
            return location;
          }
          string getID(){
            return tankID;
          }

          int getTankMaxCapacity(){
          return maxCapacity;
        }

        // Accessors
        // avoid over filling tank by interrogating input values
        void fillTank(int gals){
          // do not fill tank over max capacity
          // Embellish with throw and client must use try/catch
          if((currentCapacity + gals) > maxCapacity){
            currentCapacity = maxCapacity;
          }else{
            // add incoming gallons to current capacity
            currentCapacity = currentCapacity + gals;
          }
        }

        void drainTank(int gals){
           currentCapacity = currentCapacity - gals;
           if(currentCapacity < 0){
             currentCapacity = 0.0;
           }
        }

          // retrieve tank capacity based on current and max volume
        double getTankLevelPercent(){
            return (currentCapacity / maxCapacity) * 100;
        }

       
      void printTankStatus(){
        cout << "*********" << tankID << "*********" << '\n';
        cout << "Location: " << location << '\n';
        cout << "Max Capacity: " << maxCapacity << '\n';
        cout << "Current Level %: " << getTankLevelPercent() << '\n';
        cout << "**************" << '\n';
      }
         
      private:
          string tankID;
          string location;
          bool inService;
          bool pressurized;
          double maxCapacity;
          double currentCapacity;
          int pressure;
          int maxPressure;
};
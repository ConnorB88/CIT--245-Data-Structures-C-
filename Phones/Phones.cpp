#include<string>
#include<iostream>

using namespace std;

class Phones{
  
  public:
  
  int key;
     Phones(int ky,string type, bool data, int yr, int sz, bool smrtph, bool wrk, int tgh, bool cse, bool cam, int ap)
      :key{ky}, phoneType{type}, hasCellularData{data}, year{yr}, size{sz}, isSmartPhone{smrtph},isWorking{wrk}, toughness{tgh}, hasCase{cse}, hasCamera{cam}, apps{ap}
     {

     }
    void setKey(int ke){
      this->key = ke;
    }
    int getKey(){
      return key;
    }
    void setType(string Type){
      this->phoneType = Type;
    }
    string getType(){
      return phoneType;
    }
    void setCellData(bool data){
      this->hasCellularData = data;
    }
    bool getCellData(){
      return hasCellularData;
    }
     void setYear(int yr){
      this->year = yr;
    }
    int getYear(){
      return year;
    }
     void setSize(int sz){
      this->size = sz;
    }
    int getSize(){
      return size;
    }
     void setSmartPhone(bool smart){
      this->isSmartPhone = smart;
    }
    bool getSmartPhone(){
      return isSmartPhone;
    }
     void setWorking(bool work){
      this->isWorking = work;
    }
    bool getWorking(){
      return isWorking;
    }
     void setToughness(int tough){
      this->toughness = tough;
    }
    int getToughness(){
      return toughness;
    }
     void setCase(bool cse){
      this->phoneType = cse;
    }
    bool getCase(){
      return hasCase;
    }
     void setCamera(bool cam){
      this->hasCamera = cam;
    }
    bool getCamera(){
      return hasCamera;
    }
     void setApps(int app){
      this->apps = app;
    }
    bool getApps(){
      return apps;
    }
    
    void printPhoneStatus(){
        cout << "*****************************"<< '\n';
        cout << "Phone Type: " << phoneType << '\n';
        cout << "Celluar Data Status: " << hasCellularData << '\n';
        cout << "Year: " << year << '\n';
        cout << "Size in cm (L & W): " << size << '\n';
        cout << "Smart Phone?: " << isSmartPhone << '\n';
        cout << "Working?: " << isWorking << '\n';
        cout << "Toughness points: " << toughness << '\n';
        cout << "Has case?: " << hasCase << '\n';
        cout << "Has camera?: " << hasCamera << '\n';
        cout << "Number of apps: " << apps << '\n';
    }
  private:
  string phoneType;
  bool hasCellularData;
  int year; 
  int size;
  bool isSmartPhone;
  bool isWorking;
  int toughness;
  bool hasCase;
  bool hasCamera;
  int apps;
};
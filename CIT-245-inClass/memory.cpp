#include <iostream>
#include<string>
#include<vector>
// Pass by "copy" / i.e. pass by value
void scaleVector(std::vector<double> vec){
    // iterate over an incoming vector and divide each
    // value by 100
    std::cout << "Scaling vector passed in by copy....";
    for(int i=0; i  < vec.size(); i++){
      vec[i] = vec[i] * 100;
    }
}

// our input parameters are pointers to underlying vector and int objects
void scaleVectorWithPointer(std::vector<double>* vecPoint){
     std::cout << "Scaling vector passed in by pointer....";
   for(int i=0; i < vecPoint->size(); i++){
     double s = vecPoint->at(i) * 100.0;
     // assign to the memory location pointed to by i
     // the value s
       vecPoint->operator[](i) = s;
    }
}

void demoMemoryAddresses(){
  int daysinweek = 7;
  double pi = 3.1415923;

//std::cout <<"Size of an int: " << sizeof(daysinweek) <<  '\n';
//std::cout <<"Size of an double: " << sizeof(pi) <<  '\n';


// create an arry of 4 doubles in memory (8bytes x 4 = 32 bytes)
// and we'll access that array through a pointer-type
// object called multipi

double* multipi = new double[4];
multipi[0] = pi * 1;
multipi[1] = pi * 2;
multipi[2] = pi * 3;  
multipi[3] = pi * 4;
// show that I can access memory locations at arbtrairy
//std::cout<<"value at index 0: " <<multipi[0]<< '\n';
//std::cout<<"value at index 3: " <<multipi[3]<< '\n';
//std::cout<<"value at index 7: " <<multipi[7]<< '\n';
//std::cout<<"value at index -6: " <<multipi[-6]<< '\n';
}


void demoPointerToPointers(){

// pointer variables have a post-fix * 
 double sqrt2 = 1.4142;
 // & means "get me the address in memory of the object that comes next"
 // we can only store references in pointer-type variables*
 double* sameSqrt = &sqrt2;
 //  prove that pointers allow access to the same underlying object
 std::cout<< "value of sqrt2" << sqrt2 << '\n';
 std::cout<< "value of sameSqrt" << *sameSqrt<< '\n';

 // manipulate underlying object through the second pointer
  *sameSqrt = *sameSqrt / 5;
    std::cout << "manipulating through second pointer" << '\n';
    std::cout << "value of squrt2: " << sqrt2 << '\n';
  std::cout << "value of sameSqrt: " << *sameSqrt << '\n';
}

int main(){
 std::vector<double> pis(4);
 double pi = 3.14;
 pis[0] = pi;
pis[0] = pi;
pis[1] = pi * 2;
pis[2] = pi * 3;  
pis[3] = pi * 4;

//calling scaleVector with "pass by copy"
scaleVector(pis);
std::cout << "Display of pis in main after call with pass-by-copy"<< '\n';
for(int i=0; i < pis.size(); i++){
  std::cout << pis[i] << '\n';
   }

//calling scaleVectorwithpointer with "pass by reference"
scaleVectorWithPointer(&pis);
std::cout << "Display of pis in main after call with pass-by-reference "<< '\n';
for(int i=0; i < pis.size(); i++){
  std::cout << pis[i] << '\n';
   }
}
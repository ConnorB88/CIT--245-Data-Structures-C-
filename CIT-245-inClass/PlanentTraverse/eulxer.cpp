#include<iostream>
#include<string>

int main() {

	// "non-pointer variable e of type double"
	double e = 2.71828;
	// use the address of operator & to get the location
	// in memory of our double e and assign that location
	// to our double pointer type

	double* e_ptr = &e;
	
	printf("Address of e: %x, Value of e: %f\n", &e, e);
	printf("Address of e: %x, Value of e_ptr: %f\n", &e_ptr, *e_ptr);
}
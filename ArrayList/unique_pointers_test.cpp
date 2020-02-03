#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>

using namespace std;

int main()
{	
	vector<int> v;
	for(int i=0; i<10; i++)
		v.push_back(i);

	unique_ptr<int[]> u = make_unique<int[]>(10);
	u = make_unique<int[]>(20); // Checking if the previous segment is cleared
	// Re-allocating unique_ptr removes the previous instance!

	unique_ptr<int[]>& r = u; // make_unique<int[]>(10);

	for(int i=0; i<10; i++){
		u[i] = v[i];
	}

	int *arr = (int*)malloc(sizeof(int)*10);
	for(int i=0; i<10; i++)
		arr[i] = v[i];

	v[0] = 100;
	v[5] = 1000;

	u[0] = 99;
	u[9] = 999;

	for(int i=0; i<10; i++){
		cout << &u.get()[i] <<  " " << u.get()[i] << " " << &v[i] << " " << v[i] << endl;
		cout << &r.get()[i] <<  " " << r.get()[i] << " " << &v[i] << " " << v[i] << endl;
	}

	cout << endl;
	for(int i=0; i<10; i++)
		cout << &arr[i] <<  " " << arr[i] << " " << &v[i] << " " << v[i] << endl;
	free(arr);
	
	int z = 100;
	int *x = &z; // The pointer points to the same location as z;
	int *y = (int*)malloc(sizeof(int)); // This allocates space in the memory
	*y = z; // This copies the value of z into that location
	int *w;
	w = &z; //This again holds a reference to z and is equivalent to x;

	z = 20;
	cout << z << " " << *x << " " << *y << endl;
	
}

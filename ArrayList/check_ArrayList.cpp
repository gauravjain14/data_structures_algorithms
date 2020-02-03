#include "array_list.h"

int main(){
	ArrayList<int> arr(20);

	for(u32 i=0; i<20; i++){
		arr[i] = i;
	}
	for(u32 i=0; i<20; i++)
		cout << arr[i] << endl;

	ArrayList<int> arr2(arr);
	for(u32 i=0; i<20; i++)
		cout << arr2[i] << endl;

	cout << arr2.size() << " " << arr.size() << endl;

	ArrayList<int> arr3;
	arr3 = arr2;
	for(u32 i=0; i<20; i++)
		cout << arr3[i] << endl;

	arr3.insert(100,20);
	arr3.insert(-5,5);
	arr3.push_back(2000);

	arr3[10] = 121212;

	for(u32 i=0; i<arr3.size(); i++)
		cout << arr3[i] << endl;

	u32 init_sz = arr3.size();
	for(u32 i=0; i<init_sz; i++)
		arr3.pop_back();

	cout << arr3.size() << endl;

	// arraylist container is empty. Undefined behaviour
	//arr3.pop_back();
	for(u32 i=0; i<arr3.size(); i++)
		cout << arr3[i] << endl;//for(

	arr2.clear();
	cout << arr2.size() << endl;
	for(u32 i=0; i<25; i++)
	{
		arr2.push_back(i*i);
	}

	for(u32 i=0; i<arr2.size(); i++)
		cout << arr2[i] << endl;//for(

	arr2.reset();
	arr2.reserve(30);
	for(u32 i=0; i<30; i++)
		arr2.push_back(i);
}

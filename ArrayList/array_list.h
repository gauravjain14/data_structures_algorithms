#ifndef _ARRAYLIST_
#define _ARRAYLIST_

#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

typedef unsigned int u32;


// Not taking care of exception handling
template<typename T>
class ArrayList
{
public:
	ArrayList() = default;

	ArrayList(const size_t& size): mContents{new T[size]}, mSize(size), mMaxSize(size) {}

	ArrayList(const ArrayList<T> &other): mSize(other.mSize),
						mMaxSize(other.mMaxSize),
						mContents(copy_array(other.mContents,other.mSize,other.mMaxSize)) {}

	// overriding assignment 
	ArrayList<T>& operator=(const ArrayList<T>& other)
	{
		ArrayList<T> copy(other);
		swap(mContents,copy.mContents); // Don't think there's anyother way to copy contents without iterating!
		swap(mSize,copy.mSize);
		swap(mMaxSize,copy.mMaxSize);

		return *this;
	}

	// overriding index 
	T& operator[](const size_t &i) const 
	{	
		return mContents[i]; // equivalent to contents.get()[i]
	}

	void push_back(const T& data)
	{
		insert(data,mSize); // insert at the back
	}	

	// return the positon at which the element was entered
	void insert(const T& data, const size_t& index)
	{
		if(index > mMaxSize)
		{
			throw std::out_of_range("Index greater than max size");
		}
		// needs reallocation
		if(mSize == mMaxSize) {
			cout << "Expanding array\n";
			unique_ptr<T[]> newContents = copy_array(mContents,mSize,mMaxSize+1); // should add more?
			swap(mContents,newContents);
			mMaxSize++;
		} 
		for(size_t i=mSize; i>index; i--)
		{
			mContents[i] = mContents[i-1];	
		}	
		mContents[index] = data;
		mSize++;
	}

	void pop_back()
	{
		std::destroy_at(&(mContents[--mSize]));
	}

	void reserve(const size_t& size)
	{
		mMaxSize = size;
		mSize = 0; // reserving new space?
		mContents = make_unique<T[]>(size);
	}

	void clear() { mSize = 0; } // Just overwrite the existing container

	// if reset should, in a sane world, not delete the object owned 
	// by the unique_ptr, then I think just using clear is a better alternate.
	// The current implementation forces the user to call reserve after reset!
	void reset()
	{
		mContents.reset();
		mSize = 0;

		if (mContents == nullptr) { cout << "It nulls the contents\n"; }
	}

	size_t size() const{
		return mSize;
	}

private:
	const size_t starting_size = 8;
	size_t mSize = 0;
	size_t mMaxSize = starting_size;

	unique_ptr<T[]> mContents = make_unique<T[]>(starting_size);

	unique_ptr<T[]> copy_array(const unique_ptr<T[]>& other,size_t size,size_t new_size)
	{
		unique_ptr<T[]> copy = make_unique<T[]>(new_size); // reserve extra space
		for(size_t i=0; i<size; i++){
			copy[i] = other[i];
		}

		return copy;
	}
};


#endif

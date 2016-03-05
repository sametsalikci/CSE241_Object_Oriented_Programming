/* sortedsetcontainer.cpp
# 
# AUTHOR : MEHMET MAZHAR SALIKCI
# NUMBER : 111044050
# HOMEWORK : 08
# FILE : sortedsetcontainer.cpp
# ------INTRODUCTION:
#	Elemanları sıralı olarak ve aynı elemanın sadece bir tanesini tutmasını sağlayab fonksiyonların
# implementlerini yaptık.
*/

# include <iostream>
# include "sortedsetcontainer.h"

using namespace std;

namespace MMS
{
	//Constructor
	template<class T>
	SortedSetContainer<T>::SortedSetContainer()
	:size(0),capacity(100), index(0){
		set = new T[capacity];
	}
	//constructor
	template<class T>
	SortedSetContainer<T>::SortedSetContainer(int theCapacity)
	:size(0),capacity(theCapacity),index(0){
		set = new T[capacity];
	}
	//Destructor
	template<class T>
	SortedSetContainer<T>::~SortedSetContainer(){
		delete [] set;
	}
	//copy constructor
	template<class T>
	SortedSetContainer<T>::SortedSetContainer(const SortedSetContainer<T>& cont){

		set = new T[cont.capacity];
		for (int i = 0; i < cont.getSize(); ++i)
		{
			set[i] = cont.set[i];
		}
		cont.capacity = capacity;
	}
	//overload of Assigment operator
	template<class T>
	SortedSetContainer<T>& SortedSetContainer<T>::operator = (const SortedSetContainer<T>& cont){
		
		if(this == &cont){
			return *this;
		}
		capacity = cont.getCapacity();
		size = cont.getSize();
		delete [] set;
		set = new T[capacity];
		for (int i = 0; i < cont.getSize(); ++i)
		{
			set[i] = cont.set[i];
		}
		return*this;
	}
	//return capacity of container array
	template<class T>
	int SortedSetContainer<T>::getCapacity()const{
		return capacity;
	}
	//adds an element to the container, throws exception if there is an error
	template<class T>
	bool SortedSetContainer<T>::add(const T& theNewElement) throw (ExceptionClass){

		if (this->hasEnoughCapacity())
		{	
			if (!(this->search(theNewElement)))
			{	
				set[size] = theNewElement;
				++size;
				sort(set);
				return true;
			}
			return false;
		}
		
		if(this->resize(set,capacity,50) == NULL)
			throw ExceptionClass("Not Enough Memory size!!!");

		if (!(this->search(theNewElement)))
		{
			set[size] = theNewElement;
			sort(set);
			++size;
			return true;
		}
		return false;
	}
	//removes an element from the container, throws exception if there is an error
	template<class T>
	void SortedSetContainer<T>::remove(const T& oldElement) throw (ExceptionClass){

		if (this->getSize() == 0)
			throw ExceptionClass("No Element of the Array!!!");
		if (!(search(oldElement)))
			return;

		T*temset = new T[capacity];
		for (int i = 0; i < this->getSize(); ++i)
		{
			temset[i] = set[i];
		}
		delete [] set;
		set = new T[capacity];
		
		int j = 0;
		for (int i = 0; i < this->getSize(); ++i)
		{
			if (temset[i] == oldElement)
			{
				++i;
			}
			set[j] = temset[i];
			++j;
		}
		--size;
		delete [] temset;
	}
	//searches an element in the container, throws exception if there is an error
	template<class T>
	bool SortedSetContainer<T>::search(const T& findElement) throw (ExceptionClass){
		if (getSize() < 0)
			throw ExceptionClass("No Element of the Array!!!");
		for (int i = 0; i < this->getSize(); ++i)
		{
			if (this->getElement(i) == findElement)
			{
				return true;
			}
		}
		return false;
	}
	//returns the first element of the Container
	template<class T>
	T SortedSetContainer<T>::first(){
		return set[0];
	}
	//returns the next element of the Container since the last call to the function next. If function
	// first is called before this function, it returns the second element.
	template<class T>
	T SortedSetContainer<T>::next() throw (ExceptionClass){
		if(index == size)
			throw ExceptionClass("Out Of Range Array!!!");
		return set[index++];
	}
	//Return size
	template<class T>
	int SortedSetContainer<T>::getSize()const{
		return size;
	}
	// is array empty?
	template<class T>
	bool SortedSetContainer<T>::empty()const{
		if (getSize() == 0)
		{
			return true;
		}
		return false;
	}

	template<class T>
	//control of capacity of array
	bool SortedSetContainer<T>::hasEnoughCapacity(){//is there capacity?

		if (capacity >= size)
		{
			return true;
		}
		return false;
	}
	//sort of array elements
	template<class T>
	void SortedSetContainer<T>::sort(T*set){

		T temp ;
		int indicator = 1;
		while(indicator){

			indicator = 0;
			for (int i = 1; i < this->getSize(); ++i)
			{
				if (set[i] < set[i-1])
				{
					temp = set[i],
					set[i] = set[i-1];
					set[i-1] = temp;
					indicator = 1;
				}
			}
		}	
	}
	//return element
	template<class T>
	T SortedSetContainer<T>::getElement(const int index) const{
		return set[index];
	}

}
/* setcontainer.cpp
# 
# AUTHOR : MEHMET MAZHAR SALIKCI
# NUMBER : 111044050
# HOMEWORK : 08
# FILE : setcontainer.cpp
# ------INTRODUCTION:
#	SetContaiener sınıfımıza ait fonksiyonların implementasyonunun içeririr.
# bu sınıfın bir küme gibi davranabilmesi için gerekli tüm fonksiyonların impleemntleri
# yapıldı. 
*/
# include <iostream>
# include "setcontainer.h"

using namespace std;

namespace MMS
{
	//Default Constructor
	template<class T>
	SetContainer<T>::SetContainer()
	:size(0),capacity(100), index(0){
		set = new T[capacity];
	}
	//constructor
	template<class T>
	SetContainer<T>::SetContainer(int theCapacity)
	:size(0),capacity(theCapacity),index(0){
		set = new T[capacity];
	}
	//Destructor
	template<class T>
	SetContainer<T>::~SetContainer(){
		delete [] set;
	}
	//copy constructor
	template<class T>
	SetContainer<T>::SetContainer(const SetContainer<T>& cont){

		set = new T[cont.capacity];
		for (int i = 0; i < cont.getSize(); ++i)
		{
			set[i] = cont.set[i];
		}
		cont.capacity = capacity;
	}
	//overload of Assigment operator
	template<class T>
	SetContainer<T>& SetContainer<T>::operator = (const SetContainer<T>& cont){
		
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
	int SetContainer<T>::getCapacity()const{
		return capacity;
	}
	//adds an element to the container, throws exception if there is an error
	template<class T>
	bool SetContainer<T>::add(const T& theNewElement) throw (ExceptionClass){

		if (this->hasEnoughCapacity())
		{	
			if (!(this->search(theNewElement)))
			{	
				set[size] = theNewElement;
				++size;
				return true;
			}
			return false;
		}
		
		if(this->resize(set,capacity,50) == NULL)
			throw ExceptionClass("Not Enough Memory size!!!");

		if (!(this->search(theNewElement)))
		{
			set[size] = theNewElement;
			++size;
			return true;
		}
		return false;
	}
	//removes an element from the container, throws exception if there is an error
	template<class T>
	void SetContainer<T>::remove(const T& oldElement) throw (ExceptionClass){

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
	bool SetContainer<T>::search(const T& element) throw (ExceptionClass) {

		if (getSize() < 0)
			throw ExceptionClass("No Element of the Array!!!");
		for (int i = 0; i < this->getSize(); ++i)
		{
			if (this->getElement(i) == element)
			{
				return true;
			}
		}
		return false;
	}
	// first: returns the first element of the Container
	template<class T>
	T SetContainer<T>::first(){
		return set[0];
	}
	// next: returns the next element of the Container since the last call to the function next. If function
	// first is called before this function, it returns the second element.
	template<class T>
	T SetContainer<T>::next() throw (ExceptionClass){
		if(index == size)
			throw ExceptionClass("Out Of Range Array!!!");
		return set[index++];
	}
	//Return size of container array
	template<class T>
	int SetContainer<T>::getSize()const{
		return size;
	}
	// ıs array empty? ,return true or false
	template<class T>
	bool SetContainer<T>::empty()const{
		if (getSize() == 0)
		{
			return true;
		}
		return false;
	}
	//control of capacity of array
	template<class T>
	bool SetContainer<T>::hasEnoughCapacity(){//is there capacity?

		if (capacity >= size)
		{
			return true;
		}
		return false;
	}
	//return alement
	template<class T>
	T SetContainer<T>::getElement(const int index) const{
		return set[index];
	}
}
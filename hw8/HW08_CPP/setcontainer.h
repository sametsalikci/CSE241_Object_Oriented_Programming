/* setcontainer.cpp
# 
# AUTHOR : MEHMET MAZHAR SALIKCI
# NUMBER : 111044050
# HOMEWORK : 08
# FILE : setcontainer.cpp
# ------INTRODUCTION:
#	Bu  clasımız da bir küme gibi davranır.İçinde aynı elemandan birden fazla olamaz ve
# ve elemanlar rastgele dağılım sağlar.Bu sınıfımızı da Container clasından derived ettik. 
*/
# ifndef SETCONTAINER_H
# define SETCONTAINER_H

# include <iostream>
# include <vector>
# include "container.h"

using namespace std;

namespace MMS
{
	template<class T>
	class SetContainer : public Container<T>
	{
	public:
		//Constructors
		SetContainer();
		SetContainer(int theCapacity);
		//Destructor
		virtual~SetContainer();
		//copy constructor
		SetContainer(const SetContainer<T>& set);
		//overload of Assigment operator
		SetContainer& operator = (const SetContainer<T>& cont);
		//add : adds an element to the container, throws exception if there is an error
		virtual bool add(const T& theNewElement) throw (ExceptionClass);
		// remove: removes an element from the container, throws exception if there is an error
		virtual void remove(const T& oldElement) throw (ExceptionClass);
		// search: searches an element in the container, throws exception if there is an error
		virtual bool search(const T& findElement) throw (ExceptionClass);
		// first: returns the first element of the Container
		virtual T first();
		//return element
		virtual T getElement(const int index) const;
		// next: returns the next element of the Container since the last call to the function next. If function
		// first is called before this function, it returns the second element.
		virtual T next()throw (ExceptionClass);
		//Return size
		virtual int getSize()const;
		virtual int getCapacity()const;
		virtual bool empty()const;
	private:
		T*set;
		int capacity;
		int size;
		int index;
		bool hasEnoughCapacity();//is there capacity?	
	};
}
#endif
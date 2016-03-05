/* sortedcontainer.h
# 
# AUTHOR : MEHMET MAZHAR SALIKCI
# NUMBER : 111044050
# HOMEWORK : 08
# FILE : sortedcontainer.h
# ------INTRODUCTION:
#	Bu Clasımız sıralı elemanlar dizisi tutan bir sınıfdır.Bu sınıfta elemanlardan birden fazla olabilir.
# sınıfımıza ait fonksiyon prototipleri ve gerekli dataları tutar.Bu sınıfımızı da Container classından derived ettik.
*/
# ifndef SORTEDCONTAINER_H
# define SORTEDCONTAINER_H

# include <iostream>
# include <vector>
# include "container.h"

using namespace std;

namespace MMS
{
	template<class T>
	class SortedContainer : public Container<T>
	{
	public:
		//Constructors
		SortedContainer();
		SortedContainer(int theCapacity);
		//Destructor
		virtual~SortedContainer();
		//copy constructor
		SortedContainer(const SortedContainer<T>& set);
		//overload of Assigment operator
		SortedContainer& operator = (const SortedContainer<T>& cont);
		//add : adds an element to the container, throws exception if there is an error
		virtual bool add(const T& theNewElement) throw (ExceptionClass);
		// remove: removes an element from the container, throws exception if there is an error
		virtual void remove(const T& oldElement) throw (ExceptionClass);
		// search: searches an element in the container, throws exception if there is an error
		virtual bool search(const T& findElement) throw (ExceptionClass);
		// first: returns the first element of the Container
		virtual T first();
		// next: returns the next element of the Container since the last call to the function next. If function
		// first is called before this function, it returns the second element.
		virtual T next() throw (ExceptionClass);
		//Return size
		virtual int getSize()const;
		virtual bool empty()const;
		virtual int getCapacity()const;
		virtual T getElement(const int index) const;	
	private:
		T*set;
		int capacity;
		int size;
		int index;
		bool hasEnoughCapacity();//is there capacity?
		void sort(T*set);//will be sorted array elements
	};
}
#endif//SORTEDCONTAINER_H
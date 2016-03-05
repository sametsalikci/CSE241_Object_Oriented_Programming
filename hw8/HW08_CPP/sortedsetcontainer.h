/* sortedsetcontainer.h
# 
# AUTHOR : MEHMET MAZHAR SALIKCI
# NUMBER : 111044050
# HOMEWORK : 08
# FILE : sortedsetcontainer.h
# ------INTRODUCTION:
#	Bu containerimız bir küme gibi davranır.Bu containerın  içeriğinde
# tutalan aynı elemanların sadece bir tanesini barındıryor.Bu tutulan elemanlar aynı zamanda containerda
# küçükten büyüğe sıralı olarak tutuluyor.Bu SortedSetContainer classı Container clasından derived edildi.
*/
# ifndef SORTEDSETCONTAINER_H
# define SORTEDSETCONTAINER_H

# include <iostream>
# include <vector>
# include "container.h"

using namespace std;

namespace MMS
{
	template<class T>
	class SortedSetContainer : public Container<T>
	{
	public:
		//Constructors
		SortedSetContainer();
		SortedSetContainer(int theCapacity);
		//Destructor
		virtual~SortedSetContainer();
		//copy constructor
		SortedSetContainer(const SortedSetContainer<T>& set);
		//overload of Assigment operator
		SortedSetContainer& operator = (const SortedSetContainer<T>& cont);
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
		void sort(T*set);//will be sorted array elements
		bool hasEnoughCapacity();//is there capacity?
	};
}
#endif//SORTEDSETCONTAINER_H
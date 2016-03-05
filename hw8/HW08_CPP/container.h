/* container.h
# 
# AUTHOR : MEHMET MAZHAR SALIKCI
# NUMBER : 111044050
# HOMEWORK : 08
# FILE : container.h
# ------INTRODUCTION:
#	COntainer template classı implement ettik,Bu class bir container gibi davranır ve bu sınıfımızın
# objelerini yapamıyoruz.Bu sınıfı abstract olarak implement ettik.Bu sınıf publcic,pure virtual
# fonksiyonlar içeriyor.
*/
# ifndef CONTAINER_H
# define CONTAINER_H

# include <iostream>
# include <vector>
# include "exception.h"

using namespace std;

namespace MMS
{
	template<class T>
	class Container
	{
	public:
		//add : adds an element to the container, throws exception if there is an error
		virtual bool add(const T& theNewElement) throw (ExceptionClass) = 0;
		// remove: removes an element from the container, throws exception if there is an error
		virtual void remove(const T& oldElement) throw (ExceptionClass) = 0;
		// search: searches an element in the container, throws exception if there is an error
		virtual bool search(const T& findElement) throw (ExceptionClass) = 0;
		// first: returns the first element of the Container
		virtual T first() = 0;
		// next: returns the next element of the Container since the last call to the function next. If function
		// first is called before this function, it returns the second element.
		virtual T next() throw (ExceptionClass) = 0;
		//Return size
		virtual int getSize() const = 0;
		virtual int getCapacity() const = 0;
		//return element
		virtual T getElement(const int index) const = 0;
		virtual bool empty() const = 0;
		//addAll: takes a Container reference as parameter and adds the contents of the other Container to
		//this Container
		void addAll(Container<T>& container);
		//removeAll: takes a Container reference as parameter and removes the contents of the other
		//Container from this Container
		void removeAll(Container<T>& container);
		//toVector: converts the Container to an STL vector and returns it
		vector<T> toVector();
		//return container index
		//index operator overloadin
		template<class V>
		friend ostream& operator<<(ostream& out, const Container<T>& cont);
	protected:
		T* resize(T*set,int& capacity,int resizeAmount);
	};
}
#endif//CONTAINER_H
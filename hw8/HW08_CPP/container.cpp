/* container.cpp
# 
# AUTHOR : MEHMET MAZHAR SALIKCI
# NUMBER : 111044050
# HOMEWORK : 08
# FILE : container.cpp
# ------INTRODUCTION:
#	Bu kısımda Contaniner sınıfına ait public ve private fonksiyonların implementlerini yaptık.
# 
*/
# include <iostream>
# include <vector>
# include "container.h"

using namespace std;

namespace MMS
{
	//takes a Container reference as parameter and adds the contents of the other Container to
	//this Container
	template<class T>
	void Container<T>::addAll(Container<T> & container){

		for (int i = 0; i < container.getSize(); ++i)
		{
			if(this->search(container.getElement(i)) == false)
				this->add(container.getElement(i));
		}
	}
	//takes a Container reference as parameter and removes the contents of the other
	//Container from this Container
	template<class T>
	void Container<T>::removeAll(Container<T>& container){
		for (int i = 0; i < container.getSize(); ++i)
		{
			if(this->search(container.getElement(i)) == true){
				this->remove(container.getElement(i));
			}
		}
	}
	//from container array to vector array
	template<class T>
	vector<T> Container<T>::toVector(){

		vector<T> v;
		for (int i = 0; i < this->getSize(); ++i)
		{
			v.push_back( this->getElement(i));
		}
		return v;
	}
	//increase of capacity of array
	template<class T>
	T* Container<T>::resize(T*set,int& capacity,int resizeAmount){

		T*tempSet = new T[capacity + resizeAmount];
		if (tempSet == NULL)
			return NULL;
		for (int i = 0; i < this->getSize(); ++i)
		{
			tempSet[i] = set[i];
		}
		delete [] set;
		set = new T[capacity + resizeAmount];
		if (set == NULL)
			return NULL;
		capacity = capacity + resizeAmount;
		for (int i = 0; i < this->getSize(); ++i)
		{
			set[i] = tempSet[i];
		}
		capacity = capacity + resizeAmount;
		delete [] tempSet;
		return set;
	}
	//Output stream operator overloading
	template<class T>
	std::ostream& operator << (std::ostream& out, const Container<T>& cont){
		for(int i = 0; i < cont.getSize(); ++i){
			cout <<"Element " << i+1 << " : " << cont.getElement(i) << endl;
		}
		cout << endl;
		return out;
	}
}
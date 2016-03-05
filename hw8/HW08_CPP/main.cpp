/* main.cpp
# 
# AUTHOR : MEHMET MAZHAR SALIKCI
# NUMBER : 111044050
# HOMEWORK : 08
# FILE : main.cpp
# ------INTRODUCTION:
#		Burada Container Class,SortedSetContainer class,SetContainer class,
#	SortedContainer Class'ların teslerini yapıyor.
#		
*/
# include <iostream>
# include <exception>
# include <cstdlib>

# include "container.h"
# include "container.cpp"
# include "setcontainer.h"
# include "setcontainer.cpp"
# include "sortedsetcontainer.h"
# include "sortedsetcontainer.cpp"
# include "sortedcontainer.h"
# include "sortedcontainer.cpp"
# include "exception.h"

using namespace MMS;
using namespace std;

/*GLOBAL FUNCTION*/
template<class T> 
int sumSizeOfContainers(Container<T>*cont,int size);

/*
*
*      MAIN FUNCTION
*
*/
int main(int argc, char const *argv[])
 {
 	//For SetContainer template class
 	SetContainer<int> setContTest1;
 	SetContainer<int> setContTest2;
 	SetContainer<double> setContTest3;
 	SetContainer<double> setContTest4;
 	SetContainer<char> setContTest5;
 	SetContainer<char> setContTest6;
 	//For SortedSetContainer tepmlate class
 	SortedSetContainer<int>sortSetContTest1;
 	SortedSetContainer<int>sortSetContTest2;
 	SortedSetContainer<double>sortSetContTest3;
 	SortedSetContainer<double>sortSetContTest4;
 	SortedSetContainer<char>sortSetContTest5;
 	SortedSetContainer<char>sortSetContTest6;
 	//For SortedContainer template class
 	SortedContainer<int> sortContTest1;
 	SortedContainer<int> sortContTest2;
 	SortedContainer<double> sortContTest3;
 	SortedContainer<double> sortContTest4;
 	SortedContainer<char> sortContTest5;
 	SortedContainer<char> sortContTest6;

 	try{

 		/*TESTING FOR SetContainer TEMPLATE CLASS*/
 		
 		cout << "/******************** Tests for SetContainer Class ************************/" << endl << endl;
 		cout << "/*----------------------------addAll for integer-------------------------------*/" << endl;
 		//FOR INTEGER CONTAINER
 		setContTest1.add(2);
 		setContTest1.add(3);
 		setContTest1.add(5);
 		setContTest1.add(7);
 		setContTest1.add(11);

 		for (int i = 1; i < 5; ++i)
 		{
 			setContTest2.add(i*i);//
 		}
        
        setContTest1.addAll(setContTest2);//HERE
 		
 		cout << setContTest1;
 		// for (int i =0; i < setContTest1.getSize(); ++i)
 		// {
 		// 	cout << setContTest1.next() << endl;
 		// }
 		cout << "/*------------------------------removeAll for double---------------------------*/" << endl;
 		
 		//FOR DOUBLE CONTAINER
 		setContTest3.add(5.5);
 		setContTest3.add(6.0);
 		setContTest3.add(1.2);
 		setContTest3.add(40.3);
 		setContTest3.add(19.9);

 		for (int i = 1; i < 6; ++i)
 		{
 			setContTest4.add(i*i*5.5);
 		}
 		setContTest3.removeAll(setContTest4);//HERE
 		for (int i =0; i < setContTest3.getSize(); ++i)
 		{
 			cout << setContTest3.next() << endl;
 		}
 		cout << "/*-------------------------------toVector for caharacter--------------------------*/"<< endl;
 		
 		//FOR CHARACTER CONTAINER
 		setContTest5.add('S');
 		setContTest5.add('a');
 		setContTest5.add('t');
 		setContTest5.add('e');
 		setContTest5.add('m');
 		setContTest5.add('t');

 		setContTest6.add('h');
 		setContTest6.add('a');
 		setContTest6.add('v');
 		setContTest6.add('l');
 		setContTest6.add('e');
 		setContTest6.add('e');

 		setContTest5.toVector();//HERE
 		for (int i =0; i < setContTest5.getSize(); ++i)
 		{
 			cout << setContTest5.next() << endl;
 		}


 		/*TESTING FOR SetContainer TEMPLATE CLASS*/
 		
 		cout << endl;
 		cout << "/******************** Test  for SortedSetContainer Class ************************/" << endl << endl;
 		cout << "/*----------------------------removeAll for integer-------------------------------*/" << endl;
 		//FOR INTEGER CONTAINER
 		sortSetContTest1.add(13);
 		sortSetContTest1.add(15);
 		sortSetContTest1.add(16);
 		sortSetContTest1.add(19);
 		sortSetContTest1.add(21);

 		for (int i = 1; i < 5; ++i)
 		{
 			sortSetContTest2.add(i*i);//
 		}
        
        sortSetContTest1.removeAll(sortSetContTest2);//HERE
 		
 		for (int i =0; i < sortSetContTest1.getSize(); ++i)
 		{
 			cout << sortSetContTest1.next() << endl;
 		}
 		cout << "/*------------------------------toVector for double---------------------------*/" << endl;
 		
 		//FOR DOUBLE CONTAINER
 		sortSetContTest3.add(100.3);
 		sortSetContTest3.add(6.7);
 		sortSetContTest3.add(1.9);
 		sortSetContTest3.add(40.3);
 		sortSetContTest3.add(12.9);

 		for (int i = 1; i < 6; ++i)
 		{
 			sortSetContTest4.add(i*i*3.3);
 		}
 		sortSetContTest3.toVector();//HERE
 		for (int i =0; i < sortSetContTest3.getSize(); ++i)
 		{
 			cout << sortSetContTest3.next() << endl;
 		}
 		cout << "/*-------------------------------for caharacter--------------------------*/"<< endl;
 		
 		//FOR CHARACTER CONTAINER
 		sortSetContTest5.add('b');
 		sortSetContTest5.add('i');
 		sortSetContTest5.add('n');
 		sortSetContTest5.add('g');
 		sortSetContTest5.add('l');
 		sortSetContTest5.add('t');

 		sortSetContTest6.add('s');
 		sortSetContTest6.add('a');
 		sortSetContTest6.add('v');
 		sortSetContTest6.add('d');
 		sortSetContTest6.add('e');
 		sortSetContTest6.add('f');

 		sortSetContTest5.addAll(sortSetContTest6);//HERE
 		for (int i =0; i < sortSetContTest5.getSize(); ++i)
 		{
 			cout << sortSetContTest5.next() << endl;
 		}

 		cout << endl;
 		cout << "/******************** Test  for SortedSetContainer Class ************************/" << endl << endl;
 		cout << "/*----------------------------addAll for integer-------------------------------*/" << endl;
 		//FOR INTEGER CONTAINER
 		sortContTest1.add(13);
 		sortContTest1.add(15);
 		sortContTest1.add(11);
 		sortContTest1.add(19);
 		sortContTest1.add(11);
 		sortContTest1.add(13);
 		sortContTest1.add(15);
 		sortContTest1.add(11);
 		sortContTest1.add(19);
 		sortContTest1.add(11);


 		for (int i = 1; i < 5; ++i)
 		{
 			sortContTest2.add(i*i);//
 		}
        
        sortContTest1.addAll(sortContTest2);//HERE
 		
 		for (int i =0; i < sortContTest1.getSize(); ++i)
 		{
 			cout << sortContTest1.next() << endl;
 		}
 		cout << "/*------------------------------toVector for double---------------------------*/" << endl;
 		
 		//FOR DOUBLE CONTAINER
 		sortContTest3.add(100.3);
 		sortContTest3.add(6.7);
 		sortContTest3.add(1.9);
 		sortContTest3.add(40.3);
 		sortContTest3.add(12.9);

 		for (int i = 1; i < 6; ++i)
 		{
 			sortContTest4.add(i*i*3.3);
 		}
 		sortContTest3.toVector();//HERE
 		for (int i =0; i < sortContTest3.getSize(); ++i)
 		{
 			cout << sortContTest3.next() << endl;
 		}
 		cout << "/*-------------------------------removeAll for caharacter--------------------------*/"<< endl;
 		
 		//FOR CHARACTER CONTAINER
 		sortContTest5.add('x');
 		sortContTest5.add('y');
 		sortContTest5.add('s');
 		sortContTest5.add('g');
 		sortContTest5.add('k');
 		sortContTest5.add('t');

 		sortContTest6.add('b');
 		sortContTest6.add('a');
 		sortContTest6.add('v');
 		sortContTest6.add('u');
 		sortContTest6.add('e');
 		sortContTest6.add('g');

 		sortContTest5.removeAll(sortContTest6);//HERE
 		for (int i =0; i < sortContTest5.getSize(); ++i)
 		{
 			cout << sortContTest5.next() << endl;
 		}


 		cout << endl;
 		cout << "/******************** OTHER TESTS FOR CHARACTER ************************/" << endl << endl;

 		SetContainer<char> set;
 		set.add('x');
 		set.add('y');
 		set.add('s');
 		set.add('g');
 		set.add('k');
 		set.add('t');

 		cout << "/*-------------------------------search test--------------------------*/"<< endl;
 		cout << set.search('y') << endl;
 		cout << "/*-------------------------------first test--------------------------*/"<< endl;
 		cout << set.first() << endl;
 		cout << "/*-------------------------------remove test--------------------------*/"<< endl;
 		cout << "before: " << endl;
 		for (int i = 0; i < set.getSize(); ++i)
 		{
 			cout << set.getElement(i) << endl;
 		}
 		cout << "after: " << endl;
 		set.remove('g');
 		for (int i = 0; i < set.getSize(); ++i)
 		{
 			cout << set.getElement(i) << endl;
 		}

 		cout << endl;
 		cout << "/******************** OTHER TESTS FOR INTEGER************************/" << endl << endl;


 		SortedSetContainer<int> set1;
 		set1.add(12);
 		set1.add(23);
 		set1.add(6);
 		set1.add(9);
 		set1.add(3);
 		set1.add(100);

 		cout << "/*-------------------------------search test--------------------------*/"<< endl;
 		cout << set1.search(23) << endl;
 		cout << "/*-------------------------------first test--------------------------*/"<< endl;
 		cout << set1.first() << endl;
 		cout << "/*-------------------------------remove test--------------------------*/"<< endl;
 		cout << "before: " << endl;
 		for (int i = 0; i < set1.getSize(); ++i)
 		{
 			cout << set1.getElement(i) << endl;
 		}
 		cout << "after: " << endl;
 		set1.remove(100);
 		for (int i = 0; i < set1.getSize(); ++i)
 		{
 			cout << set1.getElement(i) << endl;
 		}
 		cout << endl;
 		cout << "/******************** OTHER TESTS FOR DOUBLE************************/" << endl << endl;


 		SortedContainer<double> set2;
 		for (int i = 1; i < 20; ++i)
 		{
 			set2.add(i*i* 2.5);
 		}

 		cout << "/*-------------------------------search test--------------------------*/"<< endl;
 		cout << set2.search(25) << endl;
 		cout << "/*-------------------------------first test--------------------------*/"<< endl;
 		cout << set2.first() << endl;
 		cout << "/*-------------------------------remove test--------------------------*/"<< endl;
 		cout << "before: " << endl;
 		for (int i = 0; i < set2.getSize(); ++i)
 		{
 			cout << set2.getElement(i) << endl;
 		}
 		cout << "after: " << endl;
 		set2.remove(250);
 		for (int i = 0; i < set2.getSize(); ++i)
 		{
 			cout << set2.getElement(i) << endl;
 		}
 		
	}

 	catch(ExceptionClass except)
 	{
 		cout << endl,
 		except.printMesseage();
 		cout << except.what() << endl << endl;
 		exit(1);
 	}

 	return 0;
 }
template<class T> 
int sumSizeOfContainers(Container<T>*cont,int size){

	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += cont[i].getSize();
	}
	return sum;
}
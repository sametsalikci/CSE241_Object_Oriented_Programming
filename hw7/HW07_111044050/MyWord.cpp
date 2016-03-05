/* MyWord.cpp
# 
# AUTHOR : MEHMET MAZHAR SALIKCI
# NUMBER : 111044050
# HOMEWORK : 07
# FILE : MyWord.cpp
# ------INTRODUCTION:
#
*/
# include <iostream>
# include <fstream>
# include "MyWord.h"

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;

namespace HW7Space
{	//Tek parametreli constructor
	MyWord::MyWord(int theCapacity)
	:used(0),capacity(theCapacity),str(" ")
	{
		indexArray = new int[capacity];
	}
	//Parametresiz constructor
	MyWord::MyWord()
	:used(0),capacity(5000),str(" ")
	{
		indexArray = new int[capacity];
	}
	//Destructor
	MyWord::~MyWord(){
		delete [] indexArray;		
	}
	//Copy constructor
	MyWord::MyWord(MyWord&word)
	:used(word.used),capacity(word.capacity),str(word.str)
	{
		indexArray = new int[capacity];
		for (int i = 0; i < used; ++i)
		{
			indexArray[i] = word.indexArray[i];
		}
	}
	//Assignment operator
	// MyWord& MyWord::operator = (MyWord& word){
	// 	if (this == &word)
	// 	{
	// 		return *this;
	// 	}
	// 	capacity = word.capacity;
	// 	used = word.used;
	// 	str = word.str;
	// 	for (int i = 0; i < used; ++i)
	// 	{
	// 		word.indexArray[i] = indexArray[i];
	// 	}
	// 	delete [] indexArray;
	// 	indexArray = new int[capacity];
	// 	for (int i = 0; i < used; ++i)
	// 	{
	// 		indexArray[i] = word.indexArray[i];
	// 	}
	// 	return *this;
	// }
	void MyWord::setString(const string str1){

		str = str1;
	}
	void MyWord::setUsed(int theUsed){
		used = theUsed;
	}
	//Bir integer değer alıp arraye atacak
	void MyWord::pushBackElement(int element){

		indexArray[used] = element;
		++used;
	}
	//indexArray in capacity sin artıracak
	void MyWord::extendSize(int theCapacity){

		MyWord temp;

		temp.capacity = capacity;
		temp.used = used;

		for (int i = 0; i < used; ++i)
		{
			temp.indexArray[i] = indexArray[i];
		}

		delete [] indexArray;
		indexArray = new int[theCapacity + 2];

		for (int j = 0; j < used; ++j)
		{
			indexArray[j] = temp.indexArray[j];
		}
		capacity = theCapacity + 2;
		used = temp.used;
	}
	//String dönderecek
	string MyWord::getString()const{
		return str;
	}
	int MyWord::getUsed()const{
		return used;
	}
	//bir index alıp o index teki değeri dönderir
	int MyWord::returnIndex(int index){

		return indexArray[index];
	}
	//Array dönderecek
	int& MyWord::returnIndexArray(){

		return(*indexArray);
	}
	ostream& operator << (ostream& outStream,const MyWord& other){

		for (int i = 0; i < other.used; ++i)
		{
			outStream << "  "<< other.indexArray[i] + 1; 
		}
		cout << endl;
		return outStream;
	}
	//return capacity
	int MyWord::getCapacity()const{

		return capacity;
	}
	//Yeni bir kelime ve indexlerini ekleyecek
	void MyWord::pushBackLinesArray(int lines[],int size){

		MyWord temp;
		temp.capacity = capacity;
		temp.used = used;

		for (int i = 0; i < used; ++i)
		{
			temp.indexArray[i] = indexArray[i];
		}

		delete [] indexArray;
		temp.capacity += size;
		temp.used += size;

		indexArray = new int[temp.capacity];
		for (int j = 0; j < used; ++j)
		{
			indexArray[j] = temp.indexArray[j];
		}
		int z = 0;
		for (int k = used; k < temp.used; ++k)
		{
			indexArray[k] = lines[z];
			++z;
		}
		used = temp.used;
		capacity = temp.capacity;

	}
}
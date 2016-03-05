/* hw7.cpp
# 
# AUTHOR : MEHMET MAZHAR SALIKCI
# NUMBER : 111044050
# HOMEWORK : 07
# FILE : hw7.cpp
# ------INTRODUCTION:
# 
#
*/
# include <iostream>
# include <cstdlib>
# include  <fstream>
# include "hw7.h"

using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;

namespace HW7Space
{
  	 //copy constructor
	DocumentIndex::DocumentIndex(DocumentIndex& other)
	:used(other.used),capacity(other.capacity),maxRowSize(other.maxRowSize)
	{
		wordArray = new MyWord[capacity];
		sentences = new string[maxRowSize];

		for (int i = 0; i < maxRowSize; ++i)
		{
			sentences[i] = other.sentences[i];
		}

		for (int j = 0; j < used; ++j)
		{
			wordArray[j] = other.wordArray[j];
		}
	}
  	 //Destructor
  	 DocumentIndex::~DocumentIndex(){

  		delete [] wordArray;
  		delete [] sentences;
	}
  	//Default constructor
	DocumentIndex::DocumentIndex()
	:used(0),capacity(500),maxRowSize(250)
	{
		wordArray = new MyWord[capacity];
		sentences = new string[maxRowSize];
	}
	//iki parametreli constructor
	DocumentIndex::DocumentIndex(const char*filename,int theCapacity)
	:maxRowSize(theCapacity),used(0),capacity(500)
	{	
		ifstream inStream;
		inStream.open(filename);
		if (inStream.fail())
		{
			cout << "Input file opening failed and object cannot be created!!!" << endl;
		}
		wordArray = new MyWord[capacity];
		sentences = new string[maxRowSize];
	}
	//Assignment operator
	DocumentIndex& DocumentIndex::operator= (DocumentIndex& other){

		if (this == &other)
		{
			return *this;
		}

		maxRowSize = other.maxRowSize;
		used = other.used;
		capacity = other.capacity;
		delete [] wordArray;

		wordArray = new MyWord[capacity];

		for (int i = 0; i < used; ++i)
		{
			wordArray[i] = other.wordArray[i];		
		}
		
		delete [] sentences;

		sentences = new string[maxRowSize];
		for (int k = 0; k < maxRowSize; ++k)
		{
			sentences[k] = other.sentences[k]; //new string[maxColumnSize];
		}
		return*this;
	}
	//Dosyadaki satır sayısını bulur
	int DocumentIndex::findRowSize(const char*filename){

		ifstream inStream;
		inStream.open(filename);
		if (inStream.fail())
		{
			cout << "Input file opening failed!!!" << endl;
		}
		int i = 0;
		string line;
		while(getline(inStream,line)){
			++i;
		}
		inStream.close();
		return i;
	}
	//Dosyadaki en uzun satırın uzunluğunu bulma
	int DocumentIndex::findMaxColumnSize(const char*filename){

		ifstream inStream;
		inStream.open(filename);
		if (inStream.fail())
		{
			cout << "Input file opening failed!!!" << endl;
		}
		int i = 0;
		string line;
		int maxColSize = 0;
		while(getline(inStream,line)){

			if (line.length() >maxColSize)
			{
				maxColSize = line.length();
			}

		}
		inStream.close();
		return maxColSize;
	}
	//Dosyadan veri okuyup string arrayine atar
	void DocumentIndex::readfile(const char *filename){

		int rowSize = findRowSize(filename);

		ifstream inStream;
		inStream.open(filename);
		if (inStream.fail())
		{
			cout << "Input file opening failed!!!" << endl;
			return;
		}

		delete [] sentences;

		maxRowSize = rowSize;

		sentences = new string[maxRowSize];

		int i = 0;
		string line;
		while(getline(inStream,line)){

			sentences[i] = line;
			++i;
		}
		inStream.close();
	}
	//Dosyadan kelime okur ve wordArrayin içine atar
	void DocumentIndex::readWordFromFile(const char*filename){

		int wordSize = findWordSize(filename);
		reSize(wordSize);//Kelime sayısı kadar yer ayırdık

		string word;
		ifstream inStream;
		inStream.open(filename);
		
		if (inStream.fail())
		{
			cout << "Input file opening failed!!!" << endl;
			return;
		}
		int j = 0;
		int m = 1;
		while(inStream >> word){
			if ( !(isThereWord(word)))
			{	
				++used;
				wordArray[j].setString(word);
				++j;
			}	
		}
	}
	//wordArrayin içinde word araryacak 
	bool DocumentIndex::isThereWord(string str){

		for (int i = 0; i < used; ++i)
		{
			if (wordArray[i].getString().compare(str) == 0 )
			{
				return true;
			}	
		}
		return false;
	}
	//Kelimeleri tutan arrayin size nı değiştirecek
	void DocumentIndex::reSize(int size){

		DocumentIndex temp;

		temp.used = used;
		temp.capacity = capacity;

		for (int i = 0; i < used; ++i)
		{
			temp.wordArray[i] = wordArray[i]; 
		}
		delete [] wordArray;
		wordArray = new MyWord[size];
		for (int j = 0; j < temp.used; ++j)
		{
			wordArray[j] = temp.wordArray[j];
		}
		used = temp.used;
		capacity = size;
	}
	//Dosyadaki tüm kelimelerin sayısını bulur
	int DocumentIndex::findWordSize(const char* filename){

		string word;
		ifstream inStream;
		inStream.open(filename);
		if (inStream.fail())
		{
			cout << "Input file opening failed!!!" << endl;
			return -1;
		}
		int i = 0;
		while(inStream >> word)
			++i;
		inStream.close();
		return i;
	}
	//sentences array inden index okuma
	void DocumentIndex::readIndex(){

		string word;
		for(int k = 0; k < used ; ++k){	
			wordArray[k].extendSize(maxRowSize);
			word = wordArray[k].getString();
			for (int i = 0; i < maxRowSize; ++i)
			{	
				if (sentences[i].find(word) != -1)
				{
					if ( (isThereWord(word)))
					{	
						wordArray[k].pushBackElement(i);
					}
				}	
			}
			cout << endl;
		}	
	}
	//Harf dışındaki diğer karakterler iptal edilir
	void DocumentIndex::ignorePunctuation(){

		int pos;
		for (int i = 0; i < used; ++i)
		{	
			string str = wordArray[i].getString();
			pos = str.find(".");
			if (pos >= 0)
			{
				str.erase(pos,1);
			}

			pos = str.find(",");
			if (pos >= 0)
			{
				str.erase(pos,1);
			}

			pos = str.find("(");
			if (pos >= 0)
			{
				str.erase(pos,1);
			}

			pos = str.find(")");
			if (pos >= 0)
			{
				str.erase(pos,1);
			}

			pos = str.find("...");
			if (pos >= 0)
			{
				str.erase(pos,3);
			}

			pos = str.find("!");
			if (pos >= 0)
			{
				str.erase(pos,1);
			}

			pos = str.find("!!!");
			if (pos >= 0)
			{
				str.erase(pos,3);
			}
			
			pos = str.find(";");
			if (pos >= 0)
			{
				str.erase(pos,1);
			}
			
			pos = str.find(":");
			if (pos >= 0)
			{
				str.erase(pos,1);
			}
			pos = str.find("'");
			if (pos >= 0)
			{
				str.erase(pos,1);
			}
			wordArray[i].setString(str);
		}
	}
	//Array deki kelmeleri alfabetik sıraya koyuyor
	void DocumentIndex::alphabeticalOrderWord(){

		MyWord temp;
		string str;
		string str1;
		for (int i = 0; i < used; ++i) {
	     	for (int j = i + 1; j < used-1; ++j)
	   		{
	         	str = wordArray[i].getString();
	         	str1 = wordArray[j].getString();
	         	if ( str.compare( str1 ) >= 1)
	         	{
	         		temp = wordArray[j];
	         		wordArray[j] = wordArray[i];
	         		wordArray[i] = temp;  	
	         	}
	     	}
		}
	}
	//Index operator overloading:string alacak ve geçtii satırları dönderecek
	int* DocumentIndex::operator [] (string str1){

		int *ans = NULL;
		for (int i = 0; i < used; ++i)
		{	
			if (wordArray[i].getString().compare(str1) == 0)
			{	
				return &(wordArray[i].returnIndexArray());
				
			}
		}
		return ans;
	}
	//Index operator overloading: satır numarası alacak o numarada geçen kelimeleri dönderecek
	string DocumentIndex::operator [] (int lineNumber){

		string str = " ";
		if (lineNumber <= maxRowSize)
		{
			return sentences[lineNumber];
		}
		return str;
	}
	//Stream extraction operator overloading
	ostream& operator << (ostream& outStream,DocumentIndex& other){
		cout << "test " << endl;
		char filename[20];
		ofstream outputfile;
		cout << "Yazdırmak için bir dosya adı giriniz: ";
		cin >> filename;
		outputfile.open(filename);
		if (outputfile.fail())
		{
			cout << "Input file opening failed!!!" << endl;
		}

		for (int i = 0; i < other.used; ++i)
		{
			outputfile << other.wordArray[i].getString();
			for (int j = 0; j < other.wordArray[i].getUsed(); ++j)
			{
				outputfile << "  "<< (int)other.wordArray[i].returnIndex(j) + 1;
			}
			outputfile << "\n";
			outputfile << "\n";
		}
		return outStream;
	}
	//Ekrana yazar
	void DocumentIndex::printScreen(){

		for (int i = 0; i < used; ++i)
		{
			cout << wordArray[i].getString() << " " ;
			cout << wordArray[i];
		}
		cout << endl;
	}
	//Stream insertion operator overloading
	istream& operator >> (istream& inpStream,DocumentIndex& other){


		ifstream inStream;
		char filename [20];
		cout << "bir input dosya adı girin: ";
		inpStream >> filename;
		int rowSize =other.findRowSize(filename);
		inStream.open(filename);
		if (inStream.fail())
		{
			cout << "Input file opening failed!!!" << endl;
		}

		delete [] other.sentences;

		other.maxRowSize = rowSize;

		other.sentences = new string[other.maxRowSize];

		int i = 0;
		string line;
		while(getline(inStream,line)){

			other.sentences[i] = line;
			++i;
		}
		inStream.close();
		return inpStream;
	}
	//iki obje alıp birleştirecek ve yeni bir obje return edecek
	DocumentIndex DocumentIndex::operator + (DocumentIndex& other){

		DocumentIndex combineObj;
		int tempCapacity = capacity + other.capacity;
		int tempUsed = used + other.used;
		int tempMaxRowSize = maxRowSize + other.maxRowSize;

		delete [] combineObj.sentences;
		delete [] combineObj.wordArray;

		combineObj.sentences = new string[tempCapacity];

		for (int i = 0; i < maxRowSize; ++i)
		{
			combineObj.sentences[i] = sentences[i];
		}
		for (int j =maxRowSize ; j < tempMaxRowSize; ++j)
		{
			combineObj.sentences[j] = other.sentences[j];
		}
		combineObj.maxRowSize = tempMaxRowSize;

		
		for (int i = 0; i < used; ++i)
		{
			combineObj.wordArray[i] = wordArray[i];
		}
		for (int i = used; i < tempUsed; ++i)
		{
			combineObj.wordArray[i] = other.wordArray[i];
		}
		combineObj.capacity = tempCapacity;
		combineObj.used = tempUsed;

		return combineObj;
	}
	//// iki obje alıp birleştirecek ve yeni bir obje return edecek
	DocumentIndex DocumentIndex::operator += (DocumentIndex& other){

		DocumentIndex combineObj;
		int tempCapacity = capacity + other.capacity;
		int tempUsed = used + other.used;
		int tempMaxRowSize = maxRowSize + other.maxRowSize;

		delete [] combineObj.sentences;
		delete [] combineObj.wordArray;


		combineObj.sentences = new string[tempMaxRowSize];

		for (int i = 0; i < maxRowSize; ++i)
		{	
			combineObj.sentences[i] = sentences[i];
		}

		int x = 0;
		for (int j =maxRowSize ; j < tempMaxRowSize; ++j)
		{
			combineObj.sentences[j] = other.sentences[x];
			++x;
		}

		wordArray = new MyWord[tempCapacity];
		for (int i = 0; i < used; ++i)
		{
			combineObj.wordArray[i] = wordArray[i];
		}
		
		int y = 0;
		for (int i = used; i < tempUsed; ++i)
		{
			combineObj.wordArray[i] = other.wordArray[y];
			++y;
		}
		combineObj.capacity = tempCapacity;
		combineObj.used = tempUsed;
		combineObj.maxRowSize = tempMaxRowSize;

		sentences = new string[tempMaxRowSize];
		for (int i = 0; i < tempMaxRowSize; ++i)
		{
			sentences[i] = combineObj.sentences[i];
		}
		wordArray = new MyWord[tempCapacity];
		for (int i = 0; i < tempUsed; ++i)
		{
			wordArray[i] = combineObj.wordArray[i];
		}
		capacity = tempCapacity;
		used = tempUsed;
		maxRowSize = tempMaxRowSize;

		return *this;	
	}
	//Kelime ve lines alacak ve objenin word arrayine ekleyecek
	void DocumentIndex::addWordAndNumbers(string str,int *lines,int size){

		DocumentIndex temp;
		temp.used = used;
		temp.capacity = capacity;

		for (int i = 0; i < used; ++i)
		{	
			temp.wordArray[i] = wordArray[i]; 
		}

		delete [] wordArray;
		wordArray = new MyWord[capacity + 1];
		for (int j = 0;j < used; ++j)
		{	
			wordArray[j] = temp.wordArray[j];	
		}

		wordArray[used].setString(str);
		wordArray[used].pushBackLinesArray(lines,size);

		used = temp.used;
		capacity = temp.capacity;
		++used;
	}
	int DocumentIndex::returnSizeForSearchWord(string str){

		for (int i = 0; i < used; ++i)
		{
			if ( (wordArray[i].getString()).compare(str) == 0)
			{
				int size = wordArray[i].getUsed();
				return size;
			}
		}

	}

}

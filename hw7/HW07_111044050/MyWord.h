/* MyWord.h
# 
# AUTHOR   : MEHMET MAZHAR SALIKCI
# NUMBER   : 111044050
# HOMEWORK : 07
# FILE     : MyWord.h
# ------INTRODUCTION:
# Bu sınıf bir dosyadaki kelimenin geçtiği satırların indexlerini ve kelimenin kendisini tutan
# tutan string tpinde bir değişkene,int tipinde indexArray ve bu index arrayin kapasite ve kulla
# kullanılan kısmın verisini tutan değişkenlere sahip bir sınıdır.
*/
# ifndef MY_WORD_H
# define MY_WORD_H

# include <iostream>
# include <fstream>
# include <string>

using std::istream;
using std::ostream;
using std::string;
using std::cout;
using std::cin;
using std::endl;

namespace HW7Space
{
	class MyWord
	{
	public:
		MyWord();//constructor
		MyWord(int theCapacity);
		~MyWord();//Desryctor
		MyWord(MyWord&word);//Copy constructor 
		//MyWord& operator = (MyWord& word);//Assignment operator
		friend ostream& operator << (ostream& outStream,const MyWord& other);//stream extraction operator
		void setString(const string str1);//string alıp stringi güncelleyecek
		void setUsed(int theUsed);//yeni değer alıp kullanılan miktarı güncelleyecek
		void pushBackElement(int element);
		string getString()const;//string i dönderecek
		void extendSize(int theCapacity);//Satır sayısı kadar yer ayıracak
		int getUsed()const;//Kullanılmış sayısını dönderecek
		int getCapacity()const;//IndexArray inin indexlerini dönderecek
		int& returnIndexArray();//Class ın array ını döndereck
		int returnIndex(int index);////bir index alıp o indexteki değeri dönderir
		void pushBackLinesArray(int lines[],int size);//Lines arrayi ekler
	private:
		string str;//Dökümandaki herhangi bir kelimeyi tutacak
		int *indexArray;//Dökümandaki herhangi bir kelimenin geçtiği satır sayısı indexlerini tutacak
		int used;//index sayısını tutacak
		int capacity;
	};



}



#endif //MY_WORD_H
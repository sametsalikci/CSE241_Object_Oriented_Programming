/* hw7.h
# 
# AUTHOR : MEHMET MAZHAR SALIKCI
# NUMBER : 111044050
# HOMEWORK : 07
# FILE : hw7.h
# ------INTRODUCTION:
#	Bu sınıf ana sınıfımızdır.Kendi içinde cümleleri tutmak için bir strin array ve birde kelimeleri 
# tutmak için bir MyWord tipinde bir kelime dizisini ve bunlara aitverileri private kısımda tutuyor.
# Bunlara ek olaarak bu sınıf,dosyadan veri okuma,dosyaya veri yazma,dosyadan okuduğu veri üzerinde işlemler
# yapma ve bazı operatorlerin overloadin lerini yapan fonksiyonlar içeriyor
*/
# ifndef HW7_H
# define HW7_H


# include <iostream>
# include <fstream>
# include <string>
# include "MyWord.h"

using std::ifstream;
using std::ofstream;

using std::istream;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::string;

//class MyWord;

namespace HW7Space
{

	class DocumentIndex
	{
	public:
		DocumentIndex();//constructor
		DocumentIndex(const char*filename,int theCapacity);//two parameter constructor
		DocumentIndex(DocumentIndex& other);//copy constructor
		~DocumentIndex();//destructor
		DocumentIndex& operator = (DocumentIndex& other);//Assignment operator overloading
		int * operator [] (string str1);//Parametre oarak bir kelime alacak ve geçtiği line dönderecek
		string operator [] (int lineNumber);//bir satır sayısı alacak ve o satırda geçen kelimelrin listesini dönderecek
		DocumentIndex operator + (DocumentIndex& other);//iki obje alıp birleştirecek ve yeni bir obje return edecek
		DocumentIndex operator += (DocumentIndex& other);// iki obje alıp birleştirecek ve yeni bir obje return edecek
		friend ostream& operator << (ostream& outStream,DocumentIndex& other);//
		friend istream& operator >> (istream& inpStream,DocumentIndex& other);//
		int findRowSize(const char*filename);//bir dosya adı alıp doyadaki satır sayısını bulacak
		int findMaxColumnSize(const char*filename);//dosyadaki en uzun satırın karakter sayısını dönderir
		void popBackWord(char*str1);//Kelime listesine kelime ekleyecek
		void readfile(const char *filename);//Dosyadan veri okuyup array atar
		int getUsed()const;//
		int getCapacity()const;//
		void setUsed(int theUsed);//
		void setCapacity(int theCapacity);//
		void readWordFromFile(const char*filename);//Dosyadan kelime okur
		int findWordSize(const char* filename);//metindeki tüm keliemlerin sayısını bulur
		void reSize(int size);//Kelimeleri tutan arrayin sayzını yeniden oluşturacak
		bool isThereWord(string str);//WordArray in içinde kelime arayacak
		void readIndex();//sentences arrayinden indexleri okuyacak
		void ignorePunctuation();//Keliemlerdeki noktalama işaretlerini,parantezleri vb.iaretleri kaldıracak
		void alphabeticalOrderWord();//Kelimeleri alfabetik sıralama
		void addWordAndNumbers(string str,int *lines,int size);//Kelime ve satır sayısını alacak ve kelimeyi ekleyecek
		int returnSizeForSearchWord(string str);//Aranan kelimenin geçtiği satırı satır sayısını dönderecek
		void printScreen();//Ekrana yazar
	private:
		string *sentences;
		int maxRowSize;
		
		MyWord*wordArray;
		int used;
		int capacity;

	};

}


#endif //HW7_H
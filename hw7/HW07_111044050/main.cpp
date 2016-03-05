/* main.cpp
# 
# AUTHOR : MEHMET MAZHAR SALIKCI
# NUMBER : 111044050
# HOMEWORK : 07
# FILE : main.cpp
# ------INTRODUCTION:
#  Bu program bir dökümanda geçen kelimeleri,geçtiği satır sayısına göre indexleyip,
#  daha sonra kelimeleri alfabetik sıraya göre dizer.
# ------Program Akışı:
#  İlk olarak dosyadan veriyi satır satır okuyup,DocummentIndex sınıfımızda oluşturduğumuz string
# array ine attık.Bu işlemi dosya sonuna kadar devam ettirip dosyadaki tüm cümleleri okuduk.
# Daha sonra string Array ine attığımız bu cümlelerde geçen kelimeleri,İşlemlerimizi kolaylaştırmak için
# olşturduğumuz MyWord sınıfımızdan elde ettiğimiz kelime array ine bu kelimeleri parselledik.Bu işlemi yaparken
# aynı kelimelerin tekrardan array e yazılmaması için daha önce cümleleri tuttuğumuz array den ve dosyadan yararlandık.
# Bu kelime okuma işlemini tüm verileri okuyuncaya kadar sürdürdük.
# Daha sonra kelimeleri noktalama işaretlerini ignore ettik.Bundan sonra da kelimeleri alfabetik sıraya koyduk
# Tüm bu işlemler sonucunda elimizde kelimeleri sıralanmış bir array oldu ve arrayi dosyaya yazdık.
*/
# include <iostream>
# include <string>
# include <fstream>
#include <sstream>
# include "hw7.h"
# include "MyWord.h"

using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;
using std::stringstream;
using namespace HW7Space;//My namespace

/*#########################################
#										  #
#			MAIN FUNCTION                 #
#                                         #
###########################################
*/

int main(int argc, char const *argv[])
{
	DocumentIndex object,object1;

	int arr;
	int section;

	cout << "Tesst1 : 1 " << endl;
	cout << "Tesst2 : 2 " << endl;
	cout << "Tesst3 : 3 " << endl;
	cout << "Tesst4 : 4 " << endl;
	cout << "Tesst5 : 5 " << endl;
	cout << "Tesst6 : 6 " << endl;
	cout << "Bir test seciniz: ";
	cin >> section;

	if(section == 1){
		object.readfile("inputfile1.txt");
		object.readWordFromFile("inputfile1.txt");
		object.readIndex();
		object.ignorePunctuation();
		object.alphabeticalOrderWord();
		cout << object;
	}
	if (section == 2)
	{	
		cout << "filename : inputfile2.txt <<" << endl;
		cin >> object;
		object.readWordFromFile("inputfile2.txt");
		object.readIndex();
		object.ignorePunctuation();
		object.alphabeticalOrderWord();
		cout << object;	
	}	
	if (section == 3)
	{	
		cout << "filename : inputfile.txt <<" << endl;
		cin >> object;
		object.readWordFromFile("inputfile.txt");
		object.readIndex();
		object.ignorePunctuation();
		object.alphabeticalOrderWord();	

		cout <<"Index operator overloading Test:" << endl;
		cout << "object[word],return lines :" << endl;
		int *size = object["lorem"];
		int a = object.returnSizeForSearchWord("lorem"); 
		for (int i = 0; i < a; ++i)
		{
			cout << i + 1 << ".index:  " <<  size[i] << endl;
		}	
	}	
	
	if (section == 4)
	{
		cout << "filename : inputfile1.txt <<" << endl;
		cin >> object;
		object.readWordFromFile("inputfile1.txt");
		object.readIndex();
		object.ignorePunctuation();
		object.alphabeticalOrderWord();	
		cout << endl <<"------------Index operator overloading Test:" << endl << endl;
		cout << "-----------object[line],return words :" << endl << endl;
		cout << "result :  " << endl << object[10]  << endl << endl;
	}
	if (section == 5)
	{
	 	object.readfile("test1.txt");
		object.readWordFromFile("test1.txt");
		object.readIndex();
		//cout << "Birinci objenin ilk durumu: " << endl << endl;
		cout << object;
		
		object1.readfile("test.txt");
		object1.readWordFromFile("test.txt");
		object1.readIndex();
		//cout << "İkinci objenin ilk durumu:" << endl << endl;
		cout << object1;
		
		object += object1;

		object.ignorePunctuation();
		object.alphabeticalOrderWord();
		//cout << "Object += Object1 testi: " << endl << endl;
		cout << object;
	}	
	if (section == 6)
	{
		cout << endl;
		cout << "Eleman ekleme testi : " << endl << endl;
		object.readfile("test1.txt");
		object.readWordFromFile("test1.txt");
		
		object.readIndex();
		object.ignorePunctuation();
		object.alphabeticalOrderWord();
		cout << "ILK DURUM: " << endl << endl;
		object.printScreen();
		int arr[] = {1,3,5};
		object.addWordAndNumbers("CSE241ObjectOriented",arr,3);
		cout << "SON DURUM : " << endl << endl;
		object.printScreen();
	}

	
	return 0;
}
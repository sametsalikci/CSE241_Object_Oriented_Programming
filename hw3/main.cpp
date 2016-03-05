/*
# NAME : MEHMET NAZHAR SALIKCI
# NUMBER : 111044050
# HOMEWORK : 03

----------INTODUCTION-----------------------------
  Bu program bir vektör uzayının calasını oluşturur,gereksinim duyduğu
  fonksiyon ve değişkenleri tanımlar,bu değişken ve fonksiyonlarla 
  vektörlerde yapılan temel işlemleri yapar
  --cross product (çapraz çarpım)
  --dot product (noktasal çarpım)
  --find magnitude (byüklük bulma)
  

*/
#include <iostream>
#include "Vect3D.h"
#include <cmath>
#include <cstdlib>

using namespace std;



int main(int argc, char const *argv[])
{
	double result;
	Vect3D v(4.0,5.0,6.0),v1(4.5,6.7,7.8),baseVect;//initalize with Constructor 


	//Constructor Initialize and  testing input function
	Vect3D vector1;
	vector1.input();

	//Testing result of DotProduct function
	cout << endl << "Result DotProduct1:" <<endl;
	result = vector1.dotProduct(v1);
	cout << result << endl;

	cout << endl << "Result DotProduct2:" <<endl;
	result = vector1.dotProduct(v);
	cout << result << endl;

	//Testing result of crossProduct function 
	cout << endl << "Result crossProduct1:" <<endl;
	baseVect = v1.crossProduct(v);
	baseVect.output();

	cout << endl << "Result crossProduct2:" <<endl;
	baseVect = vector1.crossProduct(v);
	baseVect.output();

	//Testing result of magnitude function
	cout << endl << "Result magnitude1 : " <<endl;
	result = vector1.magnitudeVect3D();
	cout << result << endl;

	cout << endl << "Result magnitude2 : " <<endl;
	result = v1.magnitudeVect3D();
	cout << result << endl;

	//Testing Call Bye Value
	cout << endl <<"Testing call bye value:" << endl;
	cout << "Class'ın önceki değerleri: " << endl << endl;
	v.output();
	cout << "Class'ın sonraki değerleri: " << endl << endl;
	testCallByValue(v);
	v.output();

	//Testing Call Bye Reference 
	cout << endl << "Testing call bye value:" << endl;
	cout << "Class'ın önceki değerleri: " << endl << endl;
	v.output();
	testCallByReference(v);
	cout << "Class'ın sonraki değerleri: " << endl << endl;
	v.output();

	return 0;
}


/*
# NAME : MEHMET NAZHAR SALIKCI
# NUMBER : 111044050
# HOMEWORK : 03
*/
#include <iostream>
#include "Vect3D.h"
#include <cmath>

using namespace std;

//FUNCTIONS IMPLEMENTATION

//Return  res = x1 * x2 + y1 * y2 + z1 + z2;
double Vect3D::dotProduct(const Vect3D& v1){

	double resX,resY,resZ;

	resX = v1.x * x;
	resY =  v1.y * y;
	resZ =  v1.z * z;
	return (sqrt(resX + resY + resZ));
}

//return magnitude of a vector etc. (x,y,z)
double Vect3D::magnitudeVect3D(){

	double resX,resY,resZ;

	resX = pow(x,2);
	resY = pow(y,2);
	resZ = pow(z,2);
	return (sqrt(resX + resY + resZ));
}
//return cross prdoduct
//return a *b = (a2 * b3-a3 * b2,a3 * b1 - a1 * b3,a1 * b2 - a2 * b1)
Vect3D Vect3D::crossProduct(const Vect3D & v){

	Vect3D vec;
	double newX,newY,newZ;

	newX = y * v.z - z * v.y;
	newY = z * v.x - x * v.z;
	newZ = x * v.y - y * v.x;
	vec.setX(newX);
	vec.setY(newY);
	vec.setZ(newZ);
	return (vec);
}
//Three parameter constructor
Vect3D::Vect3D(double cordX ,double cordY,double cordZ)
	:x(cordX),y(cordY),z(cordZ)
{/*Body intentionally empty*/ }
//Two parameter constructor
Vect3D::Vect3D(double cordX,double cordY)
	:x(cordX),y(cordY){
	z = 0;
}
//Get values from user for variables of a claass
void Vect3D::input(){

	cout << "Enter a value for X coordinate :  X = ";
	cin >> x;
	cout << "Enter a value for Y coordinate :  Y = ";
	cin >> y;
	cout << "Enter a value for Z coordinate :  Z = ";
	cin >> z;
}
//Print values of variables of a class
void Vect3D::output(){

	cout << "Values of X : " << x <<  endl << endl; 
	cout << "Value of Y : " << y <<  endl << endl; 
	cout << "Value of Z : " << z <<  endl << endl; 
}
/*testing call bye value*/
void testCallByValue(Vect3D v1){

	v1.setX(300);
	v1.setY(100);
	v1.setZ(500);
}
/*testing call bye reference*/
void testCallByReference(Vect3D &v1){

	v1.setX(300);
	v1.setY(100);
	v1.setZ(500);	
}
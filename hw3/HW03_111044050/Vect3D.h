/*
# NAME : MEHMET NAZHAR SALIKCI
# NUMBER : 111044050
# HOMEWORK : 03
*/
/*
* The vector class and this class componenets and
* these components are processes that are related to
*/
class Vect3D
{
public:
	Vect3D(double,double,double);//three parameter constructor
	Vect3D(double,double);//two parameter constructor
	Vect3D(double cordX):x(cordX),y(0),z(0){/*empty*/};//one parameter constructer
	Vect3D():x(0),y(0),z(0){/*empty*/};//Default constructor

	//setter functions
	void setX(double newX){x = newX;};
	void setY(double newY){y = newY;};
	void setZ(double newZ){z = newZ;};
	//getter functions
	double getX(){return x;};
	double getY(){return y;};
	double getZ(){return z;};

	double dotProduct(const Vect3D&);//return x.y.z
	Vect3D crossProduct(const Vect3D&);//return (x,y,z)
	double magnitudeVect3D();//return magnitude of a vector etc. (x,y,z)

	void input();
	void output();
	
private:
	double x;
	double y;
	double z;
};
//functions Testing cal bye vule and cal bye reference metod
void testCallByValue(Vect3D v1);
void testCallByReference(Vect3D &v1);
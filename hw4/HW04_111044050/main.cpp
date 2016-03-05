# include <iostream>
# include <vector>
#include <cstdio>
#include <algorithm>


using namespace std;

class Cell
{
public:
	Cell(int newX,int newY):x(newX),y(newY){/*empty*/}
	Cell():x(0),y(0){/*empty*/}
	int getX()const{return x;}//inline function
	int getY()const{return y;}//inline function
	void setX(int newX){x = newX;}//inline member function
	void setY(int newY){y = newY;}//inline member function
private:
	int x;//x  coordinate
	int y;//y coordinate
};
class GameOfLife
{
public:
	//GameOfLife(vector<Cell> v){}
	//GameOfLife();
	void combineLiveCell(GameOfLife & livCell);
	int returnHeight()const;//The class will have functions to return the current height of the board
	int returnWidth()const;//The class will have functions to return the current width of the board
	void output()const;//The class will have a function that displays the current board on the screen
	void playGame();//The class will have a function named play that plays the game for a single time step
	static int livingCellSize();//The class will have a static function that returns the number of living cells in all the games
	void writeFile(const char* filename);//dosyadan oyunun ilk durumunu okur
	void readFile(const char* filename);//oyunun son durumunu dosyaya yazar
	int findRow(char const* fileName);//Dosyadan okuduğu dizinin satır sayısını döndürür
	int findColumn(char const* fileName);//Dosyadan okuduğu dizinin sutun sayısını döndürür
	bool isLivingCell(int cordX,int cordY)const;//bir koordnate alır,orda canlı hücre varsa true yoksa false dönderir
	int getNumLiveNeighbour(int cordX,int cordY);//bir hücrenin canlı komşu sayısnı dönderirir
	int finIndex(int cordX,int cordY);//bir vectörde verdiğimiz kordinatları barındıran indexi döndürür
	void myTestFunc();//main function
private:
	vector<Cell> livingCells;
	static int livingCellCount;
};

int GameOfLife::livingCellCount = 0;
/*
####################################################################
#-------------------------------------------------------------------
#                     MAIN FUNCTION                            	   #
#-------------------------------------------------------------------
####################################################################
*/
int main(int argc, char const *argv[])
{
	GameOfLife tempObje;//fonksiyonu çağırmak için bir temp obje oluşturduk
	char choice;
	do {
		tempObje.myTestFunc();
		cout<<"Total living cells: "<<GameOfLife::livingCellSize() << endl;;
		cout<<"\nPLAY AGAIN? y/n: ";
		cin>>choice;
	}while(choice == 'y');
	
	return 0;
}

void GameOfLife::myTestFunc(){

	FILE*dosya;
	int section;
	GameOfLife game1,game2,game3,game4,game5;

	cout << "1.Game: 10 X 20 " << endl;
	cout << "2.Game: 15 X 15 " << endl;
	cout << "3.Game: 20 X 20 " << endl;
	cout << "4.Game: 30 X 50 " << endl;
	cout << "5.Game: 40 X 10 " << endl;
	cout << "6.combineLiveCell fonksiyonun testi: " << endl;
	cout << "Bir tanesini seçin : ";
	cin >> section;

	if(section == 1){	//game1 test
		if ((dosya=fopen("game1.txt","r")) != NULL )
		{
			cout << endl << "Oyunun ilk durumu>>" << endl;
			game1.readFile("game1.txt");
			game1.output();
			game1.playGame();
			game1.writeFile("endOfGame1.txt");
			cout << "GAME OVER >>>" << endl << endl;
		}
		{
			cout << "\nDosya adını yanlış girdiniz:" << endl;
			cout << "\nUSAGE: fileName.txt" << endl << endl;
		}
	}
	/*--------------------------------------------------*/
	if(section == 2){//game2 test	
		
		if ((dosya=fopen("game2.txt","r")) != NULL )
		{
			cout << endl << "Oyunun ilk durumu>>" << endl;
			game1.readFile("game2.txt");
			game1.output();
			game1.playGame();
			game1.writeFile("endOfGame2.txt");
			cout << "GAME OVER >>>" << endl << endl;
		}
		{
			cout << "\nDosya adını yanlış girdiniz:" << endl;
			cout << "\nUSAGE: fileName.txt" << endl << endl;
		}
	}
	/*--------------------------------------------------*/
	if(section == 3){//game3 test
		if ((dosya=fopen("game3.txt","r")) != NULL )
		{
			cout << endl << "Oyunun ilk durumu>>" << endl;
			game1.readFile("game3.txt");
			game1.output();
			game1.playGame();
			game1.writeFile("endOfGame3.txt");
			cout << "GAME OVER >>>" << endl << endl;
		}
		else{
			cout << "\nDosya adını yanlış girdiniz:" << endl;
			cout << "\nUSAGE: fileName.txt" << endl << endl;
		}
	}
	/*--------------------------------------------------*/
	if(section == 4){//game4 test
		if ((dosya=fopen("game4.txt","r")) != NULL )
		{
			cout << endl << "Oyunun ilk durumu>>" << endl;
			game1.readFile("game4.txt");
			game1.output();
			game1.playGame();
			game1.writeFile("endOfGame4.txt");
			cout << "GAME OVER >>>" << endl << endl;
		}
		else{
			cout << "\nDosya adını yanlış girdiniz:" << endl;
			cout << "\nUSAGE: fileName.txt" << endl << endl;
		}
	}
	/*--------------------------------------------------*/
	if(section == 5){//game5 test
		if ((dosya=fopen("game5.txt","r")) != NULL )
		{
			cout << endl << "Oyunun ilk durumu>>" << endl;
			game1.readFile("game5.txt");
			game1.output();
			game1.playGame();
			game1.writeFile("endOfGame5.txt");
			cout << "GAME OVER >>>" << endl << endl;
		}else{
			cout << "\nDosya adını yanlış girdiniz:" << endl;
			cout << "\nUSAGE: fileName.txt" << endl << endl;
		}
	}
	/*--------------------------------------------------*/
	if(section == 6){//iki objenin birleştirilmesini sağlayan fonksiyoun test edilemsi
		cout << "İki objenin birleştirilmesi < game1 ve gamet2 > " << endl;
		cout << "Game1 nın ilk durumu >> " << endl;
		game1.readFile("game1.txt");
		game1.output();
		cout << "game2 nun ilk durumu >> " << endl;
		game2.readFile("game2.txt");
		game2.output();
		cout << "İki objenin birleştrimiş şekli >> " << endl;
		game1.combineLiveCell(game2);
		game1.output();
	}
}
//bir vectörde verdiğimiz kordinatları barındıran indexi döndürür
//aranan eleman yoksa -1 dönderir
int GameOfLife::finIndex(int cordX,int cordY){

	for (int i = 0; i < livingCells.size(); ++i)
	{
		if (livingCells[i].getX() == cordX && livingCells[i].getY() == cordY)
		{
			return i;
		}
	}
	return -1;
}
void GameOfLife::playGame(){

	char character;
	int stepNumber;
	int sizeOfCell;
	GameOfLife tempObje;

	tempObje.livingCells = livingCells;
	cout << "Adım sayısını giriniz:";
	cin >> stepNumber;

	for (int N = 0; N < stepNumber; ++N)
	{
		cout <<"Devam etmek için herhangi bir karakter girin ve entere basın:" ;
		cin >>character;
		for (int i = 0; i < returnHeight(); ++i)
		{
			for (int j = 0; j < returnWidth(); ++j)
			{
				sizeOfCell = tempObje.getNumLiveNeighbour(i,j);
				if(isLivingCell(i,j))
				{
					if (sizeOfCell == 2 || sizeOfCell == 3){
						// Cell c(i,j);
						// livingCells.push_back(c);	
					}
					else{
						int index = finIndex(i,j);
						livingCells.erase(livingCells.begin() + index);//hücreyi öldür
					}	
				}
				if (!(isLivingCell(i,j)))
				{
					if(sizeOfCell == 3){
						Cell c(i,j);
						livingCells.push_back(c);
					}
				}
				if (isLivingCell(i,j))
				{
					if (sizeOfCell <=1 || sizeOfCell >= 4){//arr[i][j] = DEAD_CELL; öldür hücreyi
						int index = finIndex(i,j);
						livingCells.erase(livingCells.begin() + index);//hücreyi öldür
					}		
				}
			}
		}
		tempObje.livingCells = livingCells;
		output();
		cout << endl <<endl << endl;
		cout << "step N:" << N+1;
		cout << "\t\t\t\t\t\t\tpopulation:" << livingCells.size() << endl;
		
	}
	GameOfLife::livingCellCount += livingCells.size();
}
//bir hücrenin canlı komşu sayısnı dönderirir
int GameOfLife::getNumLiveNeighbour(int i,int j){

	int rowSize = returnHeight();
	int colSize = returnWidth();
	int count = 0;
	//corner A
	if (i == 0 && j == 0 )
	{	
		if (isLivingCell(i + 1,j + 1)){
			++count;
		}
		if (isLivingCell(i,j + 1)){
			++count;
		}
		if (isLivingCell(i + 1,j)){
			++count;
		}
		return count;	
	}		
	//corner  B
	if (i == 0 && j == colSize-1)
	{
		if (isLivingCell(i,j - 1)){
			++count;
		}
		if (isLivingCell(i + 1,j)){
			++count;
		}
		if (isLivingCell(i + 1,j - 1)){
			++count;
		}
		return count;
	}
	//corner  C
	if (i == rowSize-1 && j == 0)
	{
		if (isLivingCell(i - 1,j)){
			++count;
		}
		if (isLivingCell(i,j + 1)){
			++count;
		}
		if (isLivingCell(i - 1,j + 1)){
			++count;
		}
		return count;
	}
	//corner  D
	if (i == rowSize-1 && j == colSize-1)
	{
		if (isLivingCell(i,j - 1)){
			++count;
		}
		if (isLivingCell(i - 1,j - 1)){
			++count;
		}
		if (isLivingCell(i - 1,j)){
			++count;
		}
		return count;
	}		
	//üst kenar
	if (i == 0 && j != 0)
	{
		if (isLivingCell(i,j + 1)){
			++count;
		}
		if (isLivingCell(i ,j - 1)){
			++count;
		}
		if (isLivingCell(i + 1,j + 1)){
			++count;
		}
		if (isLivingCell(i + 1,j - 1)){
			++count;
		}
		if (isLivingCell(i + 1,j)){
			++count;
		}
		return count;
	}
	//alt kenar 
	if (i == rowSize-1 && j != 0)
	{
		if (isLivingCell(i,j + 1)){
			++count;
		}
		if (isLivingCell(i,j - 1)){
			++count;
		}
		if (isLivingCell(i - 1,j + 1)){
			++count;
		}
		if (isLivingCell(i - 1,j - 1)){
			++count;
		}
		if (isLivingCell(i - 1,j)){
			++count;
		}
		return count;
	}
	//sağ kenar 
	if (i != 0 && j == colSize-1)
	{
		if (isLivingCell(i - 1,j )){
			++count;
		}
		if (isLivingCell(i,j - 1)){
			++count;
		}
		if (isLivingCell(i - 1,j - 1)){
			++count;
		}
		if (isLivingCell(i + 1,j - 1)){
			++count;
		}
		if (isLivingCell(i + 1,j)){
			++count;
		}
		return count;
	}
	//sol kenar
	if (i != 0 && j == 0)
	{
		if (isLivingCell(i - 1,j)){
			++count;
		}
		if (isLivingCell(i - 1,j + 1)){
			++count;
		}
		if (isLivingCell(i ,j + 1)){
			++count;
		}
		if (isLivingCell(i + 1,j )){
			++count;
		}
		if (isLivingCell(i + 1,j + 1)){
			++count;
		}
		return count;
	}
	if (i != 0 || j != 0)
	{	

		if (isLivingCell(i - 1,j)){
			++count;
		}
		if (isLivingCell(i - 1,j + 1)){
			++count;
		}
		if (isLivingCell(i ,j + 1)){
			++count;
		}
		if (isLivingCell(i + 1,j )){
			++count;
		}
		if (isLivingCell(i + 1,j + 1)){
			++count;
		}
		if (isLivingCell(i - 1,j - 1)){
			++count;
		}
		if (isLivingCell(i ,j - 1)){
			++count;
		}
		if (isLivingCell(i + 1,j - 1)){
			++count;
		}
		return count;
	}
	return 0;
}
//bu fonksiyon bir class ojesi üzerinde çalışır ve başka bir class objesi alır
//bu iki class ın canlı hücrelerini birleştirecek
//parametre olarak verilen obje fonksiyonu çağıran objenin canlı 
//hücrelerine eklenecek
void GameOfLife::combineLiveCell(GameOfLife & livCell){

	for (int i = 0; i < livCell.livingCells.size(); ++i)
	{
		if ( !(isLivingCell(livCell.livingCells[i].getX(), livCell.livingCells[i].getY())) )
		{
			livingCells.push_back(livCell.livingCells[i]);
		}
	}
}
//bir vektörün içinden en büyük değerli x sayını dönderecek
//satır sayısı dönecek
int GameOfLife::returnHeight()const{

	int max = livingCells[0].getX();
	for (int i = 1; i < livingCells.size(); ++i)
	{
		if (livingCells[i].getX() > max)
		{
			max = livingCells[i].getX();
		}
	}
	return max + 1;//max değişkeninde index tutulduğundan size bulmak i.için 1 ekleriz
}
//bir vectörün içnden en büyük değerli y saysını dönderecek
//kolon sayısı dönecek
int GameOfLife::returnWidth()const{

	int max = livingCells[0].getY();
	for (int i = 1; i < livingCells.size(); ++i)
	{
		if (livingCells[i].getY() > max)
		{
			max = livingCells[i].getY();
		}
	}
	return max + 1;//max değişkeninde index tutulduğundan size bulmak i.için 1 ekleriz
}
//alınan yükseklik bilgisi ve genişlik bilgisiyle,bir yardımcı fonksiyonla
//bir bir cell vectrünün içindeki canlı ve ölü hücreleri ekrana basar
void GameOfLife::output()const{

	for (int i = 0; i < returnHeight(); ++i)
	{
		for (int j = 0; j < returnWidth(); ++j)
		{
			if (isLivingCell(i,j))
			{
				cout << "X";
			}
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}
//bir coordinate alacak ve bu kordinate bizim Cell vektörün içinde varsa true dönderecek
//dönderdiği değere göre true ise 'X',false ise ' ' basılacak ekrana
bool GameOfLife::isLivingCell(int cordX,int cordY)const{
		
	for(int i = 0; i < livingCells.size(); ++i){
		
		if(livingCells[i].getX() == cordX && livingCells[i].getY() == cordY){
			return true;
		}
	}
	return false;
}
//Dosyadan okuduğu dizinin satır sayısını döndürür
int GameOfLife::findRow(char const*fileName){

	int status;
	char cellChar;
	int rowCount = 1;
	FILE*inputFile = fopen(fileName,"r");

	status = fscanf(inputFile,"%c",&cellChar);
	while(status != EOF){
		
		if (cellChar=='\n')
		{
			++rowCount;
		}
		status = fscanf(inputFile,"%c",&cellChar);
	}
	fclose(inputFile);
	return rowCount;
}
//Dosyadan okudugğu board un sutun sayısını bulma
int GameOfLife::findColumn(char const*fileName){

	char cellChar;
	int colCount = 0;
	FILE*inputFile = fopen(fileName,"r");

	fscanf(inputFile,"%c",&cellChar);
	
	while(cellChar != '\n'){
		++colCount;
		fscanf(inputFile,"%c",&cellChar);
	}
	fclose(inputFile);
	return colCount;
}
//parametre olarak aldığı dosyada istendiği şekilde gerekli 'x'
//değerlerini okuyarak koordinatları ile vectöre atar
void GameOfLife::readFile(const char* filename){

	char temp;
	char cellChar;
	int sizeRow = findRow(filename);
	int sizeCol = findColumn(filename);
	FILE*inputFile = fopen(filename,"r");//dosyayı read modunda açma

	for (int i = 0; i < sizeRow; ++i)
	{
		for (int j = 0; j <sizeCol; ++j)
		{
			fscanf(inputFile,"%c",&cellChar);
			if (cellChar == 'X')
			{
				Cell cell(i,j);//Cell sınıfının constructor unu çağırdık
				livingCells.push_back(cell);//her defasında ekleme yapıyoruz
			}
		}
		fscanf(inputFile,"%c",&temp);// '\n' karakterini okuma 
	}
	fclose(inputFile);
}
//parametre olarak aldığı dosyada istendiği şekilde gerekli 'x'
//değerlerini kordinatları ile ekrana basar,diğer kısma boşluk basar
void GameOfLife::writeFile(const char* filename){

	FILE*inputFile = fopen(filename,"write");//dosyayı write modunda açma
	
	for (int i = 0; i < returnHeight(); ++i)
	{
		for (int j = 0; j < returnWidth(); ++j)
		{
			if (isLivingCell(i,j))
			{
				fprintf(inputFile,"%c",'X');
			}
			fprintf(inputFile,"%c",' ');
		}
		fprintf(inputFile,"\n");
	}
	fclose(inputFile);
}
//bu fonksiyon herhangi bir obje alır ve bu objenin canlı hücrelerini başka bir objeye atar

int GameOfLife::livingCellSize(){
	return livingCellCount;
}
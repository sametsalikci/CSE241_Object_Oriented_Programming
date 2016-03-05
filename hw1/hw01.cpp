#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#define ALIVE_CELL 'X'
#define DEATH_CELL ' '

using namespace std;

int findRow(char const*fileName);
int findColumn(char const*fileName);
char **createArray(char**gameArray,int rowSize,int colSize);
void printArray(char**array,int row,int column);
void readValuesFromFile(char const*fileName,char**array,int rowSize,int colSize);
void cleanArray(char**array,int rowSize,int colSize);
void writeValuesFile(char**array,int rowSize,int colSize);
int getNumLiveNeighbour(char**arr,int i,int j,int rowSize,int colSize);
void playGameOfLife(char**arr,int rowSize,int colSize,int numberOfstep);
void copyArray(char**arr1,char**arr2,int rowSize,int colSize);
int findAliveCell(char**arr,int rowSize,int colSize);
void freeArray(char**arr,int rowSize);

int main(int argc, char const *argv[])
{
	char **gameArray;
	int rowSize;
	int colSize;

	if (argc==3)
	{	
		rowSize =  findRow(argv[1]);
		colSize = findColumn(argv[1]);
		gameArray = createArray(gameArray,rowSize,colSize);	
		readValuesFromFile(argv[1],gameArray,rowSize,colSize);
		cout << endl << "Oyunun ilk durumu>>" << endl;
		printArray(gameArray,rowSize,colSize);
		playGameOfLife(gameArray,rowSize,colSize,atoi(argv[2]));
		writeValuesFile(gameArray,rowSize,colSize);
	}
	else
	{
		cout << "parametreleri kontrol ediniz" << endl;
		cout << "\tUSAGE:\n\t\t./myProg   fileName   stepNumber" << endl; 
	}
	//freeArray(gameArray,rowSize);
	return 0;
}
//Dosyadan okuma fonksiyonu	
void readValuesFromFile(char const*fileName,char**array,int rowSize,int colSize){

	char cellChar;
	int i = 0,j = 0;
	FILE * inpFile = fopen(fileName,"r");
	while(!feof(inpFile)){
		
		fscanf(inpFile,"%c",&cellChar);
		if(cellChar == '\n'){
			++i;
			j = 0;
			fscanf(inpFile,"%c",&cellChar);
		}
		array[i][j] = cellChar;
		++j;
	}
	fclose(inpFile);
}
//Satır bulma fonksiyonu
int findRow(char const*fileName){

	int status;
	char cellChar;
	int rowCount = 0;
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
//Sutun bulma fonksiyonu
int findColumn(char const*fileName){

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
//Dinamik array oluşturma fonksiyonu
char **createArray(char**gameArray,int rowSize,int colSize){

	int i;
	
	gameArray = (char**)malloc(rowSize*sizeof(char*));

	for(i = 0; i < colSize; ++i){
	 	
	 	gameArray[i] = (char*)malloc(sizeof(char));

	} return gameArray;

}
//Arrayı ekrana basma fonksiyonu
void printArray(char**array,int row,int column){
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			cout << array[i][j];
		}	
		cout << endl;
	}
}
//Dosyaya yazma fonksiyonu
void writeValuesFile(char**array,int rowSize,int colSize){

	FILE*outputFile = fopen("finalGameOfLife.txt","w");
	
	for (int i = 0; i < rowSize; ++i)
	{
		for (int j = 0; j < colSize; ++j)
		{
			fprintf(outputFile,"%c",array[i][j]);
		}
		fprintf(outputFile, "\n");
	}
}
//Oyun oynama fonksiyonu
void playGameOfLife(char**arr,int rowSize,int colSize,int numberOfstep){

	char character;
	int aliveCount;
	int sizeOfCell;
	char**tempArray;
	
	tempArray = createArray(tempArray,rowSize,colSize);
	copyArray(arr,tempArray,rowSize,colSize);
	for ( int N = 0; N < numberOfstep; ++N)
	{
		cout <<"Devam etmek için herhangi bir karakter girin ve entere basın:" ;
		cin >>character;
		for (int i = 0; i < rowSize; ++i)
		{
			for (int j = 0; j < colSize; ++j)
			{
				sizeOfCell = getNumLiveNeighbour(tempArray,i,j,rowSize,colSize);
				if(arr[i][j] == ALIVE_CELL)
				{
					if (sizeOfCell == 2 || sizeOfCell == 3){
						arr[i][j] = ALIVE_CELL;	
					}
					else{
						arr[i][j] = DEATH_CELL;	
					}
				}
				if (arr[i][j] == DEATH_CELL)
				{
					if(sizeOfCell == 3)
						arr[i][j] = ALIVE_CELL;
				}
				if (arr[i][j] == DEATH_CELL)
				{
					if(sizeOfCell <=2 || sizeOfCell >=4)
						arr[i][j] = DEATH_CELL;
				}
				if (arr[i][j] == ALIVE_CELL)
				{
					if (sizeOfCell <=1 || sizeOfCell >= 4)
						arr[i][j] = DEATH_CELL;
				}
			}
		}
		copyArray(arr,tempArray,rowSize,colSize);
		printArray(arr,rowSize,colSize);
		cout << endl <<endl << endl;
		aliveCount = findAliveCell(arr,rowSize,colSize);
		cout << "step N:" << N+1;
		cout << "\t\t\t\t\t\t\tpopulation:" << aliveCount << endl;
	}
	//free(tempArray,rowSize);
}
//Oyun kuralları
int getNumLiveNeighbour(char**arr,int i,int j,int rowSize,int colSize){
	
	int count = 0;
	//corner A
	if (i == 0 && j == 0 )
	{	
		if (arr[i+1][j+1] == ALIVE_CELL){
			++count;
		}
		if (arr[i][j+1] == ALIVE_CELL){
			++count;
		}
		if (arr[i+1][j] == ALIVE_CELL){
			++count;
		}
		return count;	
	}		
	//corner  B
	if (i == 0 && j == colSize-1)
	{
		if (arr[i][j-1] == ALIVE_CELL){
			++count;
		}
		if (arr[i+1][j] == ALIVE_CELL){
			++count;
		}
		if (arr[i+1][j-1] == ALIVE_CELL){
			++count;
		}
		return count;
	}
	//corner  C
	if (i == rowSize-1 && j == 0)
	{
		if (arr[i-1][j] == ALIVE_CELL){
			++count;
		}
		if (arr[i][j+1] == ALIVE_CELL){
			++count;
		}
		if (arr[i-1][j+1] == ALIVE_CELL){
			++count;
		}
		return count;
	}
	//corner  D
	if (i == rowSize-1 && j == colSize-1)
	{
		if (arr[i][j-1] == ALIVE_CELL){
			++count;
		}
		if (arr[i-1][j-1] == ALIVE_CELL){
			++count;
		}
		if (arr[i-1][j] == ALIVE_CELL){
			++count;
		}
		return count;
	}		
	//üst kenar
	if (i == 0 && j != 0)
	{
		if (arr[i][j+1] == ALIVE_CELL){
			++count;
		}
		if (arr[i][j-1] == ALIVE_CELL){
			++count;
		}
		if (arr[i+1][j+1] == ALIVE_CELL){
			++count;
		}
		if (arr[i+1][j-1] == ALIVE_CELL){
			++count;
		}
		if (arr[i+1][j] == ALIVE_CELL){
			++count;
		}
		return count;
	}
	//alt kenar 
	if (i == rowSize-1 && j != 0)
	{
		if (arr[i][j+1] == ALIVE_CELL){
			++count;
		}
		if (arr[i][j-1] == ALIVE_CELL){
			++count;
		}
		if (arr[i-1][j+1] == ALIVE_CELL){
			++count;
		}
		if (arr[i-1][j-1] == ALIVE_CELL){
			++count;
		}
		if (arr[i-1][j] == ALIVE_CELL){
			++count;
		}
		return count;
	}
	//sağ kenar 
	if (i != 0 && j == colSize-1)
	{
		if (arr[i-1][j] == ALIVE_CELL){
			++count;
		}
		if (arr[i][j-1] == ALIVE_CELL){
			++count;
		}
		if (arr[i-1][j-1] == ALIVE_CELL){
			++count;
		}
		if (arr[i+1][j-1] == ALIVE_CELL){
			++count;
		}
		if (arr[i+1][j] == ALIVE_CELL){
			++count;
		}
		return count;
	}
	//sol kenar
	if (i != 0 && j == 0)
	{
		if (arr[i-1][j] == ALIVE_CELL){
			++count;
		}
		if (arr[i-1][j+1] == ALIVE_CELL){
			++count;
		}
		if (arr[i][j+1] == ALIVE_CELL){
			++count;
		}
		if (arr[i+1][j] == ALIVE_CELL){
			++count;
		}
		if (arr[i+1][j+1] == ALIVE_CELL){
			++count;
		}
		return count;
	}
	if (i != 0 || j != 0)
	{	

		if (arr[i-1][j] == ALIVE_CELL){
			++count;
		}
		if (arr[i-1][j+1] == ALIVE_CELL){
			++count;
		}
		if (arr[i][j+1] == ALIVE_CELL){
			++count;
		}
		if (arr[i+1][j] == ALIVE_CELL){
			++count;
		}
		if (arr[i+1][j+1] == ALIVE_CELL){
			++count;
		}
		if (arr[i-1][j-1] == ALIVE_CELL){
			++count;
		}
		if (arr[i][j-1] == ALIVE_CELL){
			++count;
		}
		if (arr[i+1][j-1] == ALIVE_CELL){
			++count;
		}
		return count;
	}
	return 0;
}
//Arrayın kopyasını alan fonksiyon
void copyArray(char**arr1,char**arr2,int rowSize,int colSize){

	for (int i = 0; i < rowSize; ++i)
	{
		for (int j = 0; j < colSize; ++j)
		{
			arr2[i][j] = arr1[i][j];
		}
	}
}
//Canlı hücre sayısını hesapla
int findAliveCell(char**arr,int rowSize,int colSize){

	int count = 0;
	for (int i = 0; i < rowSize; ++i)
	{
		for (int j = 0; j < colSize; ++j)
		{
			if (arr[i][j] == ALIVE_CELL)
				++count;
		}
	}
	return count;
}
//Allocate edilen geri geri verme
void freeArray(char**arr,int rowSize){

	for (int i = 0; i < rowSize; ++i)
	{
			free(arr[i]);	
	}
	free(arr);
}
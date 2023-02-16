#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
int main(){
	FILE * pFile;
	pFile = fopen ("MuestreoCurvaXY.dat","r");
	double x1,y1,x2,y2;
	double longarco=0, integral=0;
	//Tomo el primer punto (x1,y1)
	//fscanf detecta el primer número, si lo vuelvo a ejecutar detecta el segundo (en la primera fila), luego cambia de fila y así...
	fscanf(pFile, "%lf", &x1);
	fscanf(pFile, "%lf", &y1);
	//lo hago hasta el k=59 ya que el último punto es el 60. Mi for compararía en esa iteración el punto 59 con el 60.
	for(int k=1;k<=59;k++){
		//Lo siguiente lee el archivo
		fscanf(pFile, "%lf", &x2);
		fscanf(pFile, "%lf", &y2);
		//Hago la diagonal entre el punto (x1,y1) y (x2,y2)
		longarco+=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		//si y1 e y2 tienen el mismo signo
		if(y1*y2>=0){
			if(y1>=0 & y2>=0){
				//Calculo el aŕea debajo de la diagonal dada por los puntos (x1,y1) y (x2,y2)
				//No le pongo valor absoluto a (y2-y1) para que si y1>y2 me reste el área del triángulo
				//Quizá requiera escribir en papel para ver esto
				integral+=abs(x2-x1)*abs(y1)+abs(x2-x1)*(y2-y1)/2;
			}
			else{
				//En caso de que y1 e y2 sean negativos se comporta un poco diferente
				//No le pongo valor absoluto a (y1-y2) para que si y2>y1 me reste el área del triángulo
				integral+=-(abs(x2-x1)*abs(y1)+abs(x2-x1)*(y1-y2)/2);

			}
		}
		//En el caso de que y1 e y2 tengan diferente signo defino un punto en el que y=0 y esté en la recta formada por (x1,y1) y (x2,y2)
		else{
			double c;
			c=-y1*(x2-x1)/(y2-y1)+x1;
			//Hago el área del triángulo entre (x1,y1), (x1,0) y (c,0) 
			//y el área del triángulo formada por (x2,y2),(x2,0) y (c,0)
			//Dejo y1 e y2 sin valor absoluto para que reste el área del triángulo en caso de que su valor y1 o y2 sea negativo.
			integral+=abs(x1-c)*y1/2+abs(x2-c)*y2/2;
		}
		//Redefino el (x1,y1) para que lo tome como el siguiente punto
		x1=x2;
		y1=y2;
	}
	fclose (pFile);
	cout << "Una aproximación de la longitud de arco de la función es "<< longarco << endl;
	cout << "Una aproximación del área de la función es "<< integral << endl;
}
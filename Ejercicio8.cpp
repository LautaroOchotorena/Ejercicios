#include <iostream>
#include <cmath>
#include <string>
//fstream necesario para escribir en el archivo
#include <fstream>
//Lo siguiente es para las funciones especiales, para compilar usar -lgsl -lgslcblas
#include <gsl/gsl_sf_bessel.h>
#include <gsl/gsl_sf_erf.h>
#include <gsl/gsl_sf_hermite.h>
using namespace std;
void fun_especiales(double a,double b,int N){
	//Pasar al ejecutar primero el intervalo que se quiere tratar con a<b y luego un N positivo.
	ofstream Outfile;
	//escribir en un archivo nuevo llamado "funciones_especiales.dat"
	Outfile.open ("funciones_especiales.dat",ios_base::out);
	Outfile.precision(9);
	double x,y,z,h;
	//Rango de x de [a,b] tomando N puntos.
	for (int k=0; k<=N-1; k++){
	x=a+(b-a)*k/(N-1);
	y=gsl_sf_bessel_Jn(0, x);
	z=gsl_sf_erf(x);
	h= gsl_sf_hermite_func(4, x);
	//Ahora escribo. La primera columna representa los x, la segunda la evalución en la función de bessel
	//La tercera columna la evaluación de erf y la cuarta la evaluación de hermite
	Outfile << x << " " << y << " " << z << " " << h << endl;
	}
	//Graficamos en grace todo junto. -nxy hace sets separados siempre tomando a x como la primera columna,
	//el y lo varía de columna al cambiar de set
	system("xmgrace -nxy funciones_especiales.dat");
	//Imprimí una foto de este script con a=-10, b=10 y N=10000, agregando las etiquetas correspondientes
	return;
}
int main(){
	//Ejecuto con a=-10, b=10 y N=10000
	fun_especiales(-10,10,10000);
	return 0;
}
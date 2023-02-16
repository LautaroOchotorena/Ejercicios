#include <iostream>
#include <fstream>
#include <gsl/gsl_interp.h>
#include <gsl/gsl_spline.h>
using namespace std;
int main(){
	//Seteamos los puntos por los que va a pasar la spline
	double X[5]={-4, -2, 0, 3, 5};
	double Y[5]={10, -6, 2, -1, 8};
	//Invocamos a las funciones de gsl para la interpolación
	gsl_interp_accel *acc=gsl_interp_accel_alloc();
	gsl_spline *spline=gsl_spline_alloc(gsl_interp_cspline, 5);
	gsl_spline_init(spline,X,Y,5);
	//El siguiente paso es para crear un archivo de texto para su posterior uso en xmgrace
	ofstream Outfile;
	Outfile.open("spline.dat",ios_base::out);
	Outfile.precision(9);
	double xi,yi;
	for (xi = X[0]; xi < X[4]; xi += 0.01){
        yi = gsl_spline_eval (spline, xi, acc);
        Outfile << xi << " " << yi << endl;
    }
    system("xmgrace spline.dat");
}
#include <iostream>
#include <cmath>
using namespace std;
double f(double x){
	return (exp(x)-x-2);
}
int main(){
	double a=0;
	double b=2;
	double tol_cuadrado=pow(10,-12);
	//yo quiero que si el valor absoluto es mayor a la tolerancia (10^-6) al evaluar en ambos
	//bordes siga haciendo el método, lo cual es lo mismo elevar al cuadrado y pedir que sea mayor
	//a la tolerancia al cuadrado, así ahorro escribir.
	while(f(a)*f(a)>tol_cuadrado && f(b)*f(b)>tol_cuadrado){
		//Me fijo con qué borde tiene diferente signo el punto medio evaluado y redefino el otro borde como el punto medio
		if(f(a)*f(a+(b-a)/2)<=0){
			b = a+(b-a)/2;
		}
		else{
			a = a+(b-a)/2;
		}
	}
	//Ahora veré, después de pasar por el ciclo while, si es el a o el b en donde se encontró el valor deseado
	if(f(a)*f(a)<=tol_cuadrado){
		cout << "Una raíz con un error de 10^-6 es " << a << endl;
	}
	else{
		cout << "Una raíz con un error de 10^-6 es " << b << endl;
	}
}
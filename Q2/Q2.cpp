#include <iostream> 
#include <bits/stdc++.h>

using namespace std;

/*

Q2 Radars A and B, distance a = 500 m apart, track plane C by recording angles α and β at onesecond intervals.
Three successive readings are:

		|9		|10		|11		
		|-------|-------|-------
A(deg)	|54.80	|54.06	|53.34
B(deg)	|65.59	|64.59	|63.62

Calculate the speed v of the plane and the climb angle γ at t = 10 s. The (x, y) coordinates of the plane are: 

x = a * (tan degB/ tan degB - tan degA)

y = a * (tan degA * tan degB / tan degB - tan degA)

*/


double xfunc(double a, double degA, double degB ){
	double x;
	cout << tanh(degB) << " " << tanh(degA) << " " << endl;
	x = a * (tanh(degB)/ (tanh(degB) - tanh(degA)));
	return x;
}

double yfunc(double a, double degA, double degB){
	double y;
	cout << tanh(degB) << " " << tanh(degA) << " " << endl;
	y = a * (	(tanh(degA) * tanh(degB))	/ ( 	(tanh(degB) - tanh(degA))	)	);
	return y;
}


int main(){

	double a, degA, degB;
	a = 500.00;

	// 9
	degA = 54.80;
	degB = 65.59;

	// 10
	degA = 54.06;
	degB = 64.59;

	// 11
	degA = 53.34;
	degB = 63.62;

	cout << xfunc(a, degA, degB) << endl;

	a = 500.00;
	degA = 54.80;
	degB = 65.59;

	cout << yfunc(a, degA, degB) << endl;


}
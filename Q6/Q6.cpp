#include <bits/stdc++.h>

using namespace std;

vector<double> xval;
vector<double> yval;

void dataDump() {
    ofstream myfile;

    myfile.open("graph.txt");

    for (int i = 0; i < xval.size(); i++) {
        myfile << xval[i] << " " << yval[i] << endl;
    }

    myfile.close();
}

double f(double x) {
    return 2510 * log(2800000 / (2800000 - 13300 * x)) - 9.81 * x - 335;
}

double secant() {
    double x0 = 50, x1 = 100, x2;
    double fx0 = f(x0), fx1 = f(x1);

    while (fabs(x1 - x0) >= 0.1) {
        x2  = (fx1 * x0 - fx0 * x1) / (fx1 - fx0);
        x0  = x1;
        fx0 = fx1;
        x1  = x2;
        fx1 = f(x1);
        xval.push_back(x1);
        yval.push_back(fx1);
    }
    return x2;
}

int main() {
    cout << secant();
    dataDump();

    return 0;
}

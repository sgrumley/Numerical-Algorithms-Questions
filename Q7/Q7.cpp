#include <bits/stdc++.h>
#define PI 3.14159265
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
    return tan(50 * PI / 180.0) * x - (9.81 / 1250 * cos(50 * PI / 180.0) * cos(50 * PI / 180.0)) * pow(x, 2) + 1;
}

double ysection(double m) {
    double a = 1;
    double b = m;
    double c;

    for (int n = 0; n < 80; n++) {
        c = (a + b) / 2;

        if (f(c) > f(c + 1)) {
            // a, c new intervals
            b = c;
        } else {
            // b, c new intervals
            a = c + 1;
        }

        if ((b - a) / pow(2, n + 1) <= 0.0001) {
            return c;
        }
    }
}

double bisection() {
    double a = 1;
    double b = 500;
    double c;

    for (int n = 0; n < 15; n++) {
        c = (a + b) / 2;

        if (f(c) * f(a) < 0) {
            // a, c new intervals
            b = c;
        } else {
            // b, c new intervals
            a = c;
        }

        if ((b - a) / pow(2, n + 1) <= 0.0001) {
            return ysection(c);
        }
    }
}

int main() {
    double res = bisection();

    cout << "at " << res << "m the max height of " << f(res) << " is reached" << endl;

    for (int i = 0; i < 400; i++) {
        xval.push_back(i);
        yval.push_back(f(i));
    }
    dataDump();

    return 0;
}

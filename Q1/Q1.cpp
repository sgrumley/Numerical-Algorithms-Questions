#include <bits/stdc++.h>

using namespace std;

vector<double> hval;
vector<double> errval;
vector<double> rounderrval;
vector<double> truncerrval;
vector<float>  floaterrval;

void dataDump() {
    ofstream myfile;

    myfile.open("graph.txt");

    for (int i = 0; i < hval.size(); i++) {
        myfile << hval[i] << " " << errval[i] << " " << rounderrval[i] << " " << truncerrval[i] << " " << floaterrval[i] << endl;
    }

    myfile.close();
}

float ff(float x) {
    return -0.1 * pow(x, 4) - 0.15 * pow(x, 3) - 0.5 * pow(x, 2) - 0.15 * x + 1.2;
}

float fdf(float x) {
    return -0.4 * pow(x, 3) - 0.45 * pow(x, 2) - x - 0.15;
}

double f(double x) {
    return -0.1 * pow(x, 4) - 0.15 * pow(x, 3) - 0.5 * pow(x, 2) - 0.15 * x + 1.2;
}

double df(double x) {
    return -0.4 * pow(x, 3) - 0.45 * pow(x, 2) - x - 0.15;
}

double thirddf(double x) {
    return -2.4 * x - 0.9;
}

double centDif(double x, double h) {
    return (f(x + h) - f(x - h)) / (2 * h);
}

float floatfunc() {
    float x, h, v, error;

    x = 0.5;
    h = 0.001;

    // Approximating difference
    cout << "Float\n";

    for (int i = 0; i < 10; i++) {
        v = (f(x + h) - f(x - h)) / (2 * h);

        error = fabs(df(x) - v) * 100 / df(x);
        floaterrval.push_back(fabs(error));
        cout << "h: " << h << " Value = " << v << ", Error = " << error << "%" << endl;
        h += 0.001;
    }
}

double truncerr(double h) {
    double m = thirddf(0.5);

    return fabs(pow(h, 2) * m / 6);
}

double rounderr(double x, double h) {
    double e1 = fabs(f(x + 1) - df(x + 1));
    double e2 = fabs(f(x - 1) - df(x + 1));

    return fabs((e1 - e2) / 2 * h);
}

int main() {
    // calculating error

    double x, h, v, error;

    x = 0.5;
    h = 0.001;

    // Approximating difference
    cout << "Double\n";

    for (int i = 0; i < 10; i++) {
        v = (f(x + h) - f(x - h)) / (2 * h);

        error = fabs(df(x) - v)  / df(x);
        double rerr = rounderr(x, h);
        double terr = truncerr(h);
        hval.push_back(h);
        errval.push_back(fabs(error));
        rounderrval.push_back(rerr);
        truncerrval.push_back(terr);
        cout << "h: " << h << " Value = " << v << ", Error of function = " << error << "% " << "Trunc error: " << terr << " Round error: " << rerr << endl;
        h += 0.001;
    }
    double hopt = cbrt(3 * 0.0000001 / thirddf(0.5));


    floatfunc();
    dataDump();
    cout << "optimal h is: " << fabs(hopt);

    return 0;
}

// Need to figure out the value of h

// find round off error and trunctation error
// use random h steps and put them back into h optimal

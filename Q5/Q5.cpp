
#include <bits/stdc++.h>

using namespace std;

// double func(double t) {}
vector<double> tval;
vector<double> eulval;
vector<double> rkval;

void dataDump() {
    ofstream myfile;

    myfile.open("graph.txt");

    for (int i = 0; i < tval.size(); i++) {
        myfile << tval[i] << " " << eulval[i] << " " << rkval[i] << endl;
    }

    myfile.close();
}

double errorFunction(double total, double current) {
    return (total * current / total) * 100;
}

double multiTrap(double a, double b,  int n, vector<double>& func) {
    double h      = (b - a) / n;
    double result = func[a] + func[b];

    for (int i = 1; i < n; i++) {
        result += 2 * func[a + i * h];
    }
    result *= (b - a) / (2 * n);

    return result;
}

double rhomberg(double a, double b, vector<double>& f) {
    int size             = 5;
    int n                = 1;
    double R[size][size] = {};


    // Use Trapazoidal rule to construct [i][1] values
    for (int i = 1; i < size; i++) {
        R[i][1] = multiTrap(a, b, n, f);
        n      *= 2;
    }

    // Iterate through the rest of the matric and compute using Romberg Formula
    for (int k = 2; k < size; k++) {
        for (int j = 1; j < size - k + 1; j++) {
            R[j][k] = (pow(4, (k - 1)) * R[j + 1][k - 1] - R[j][k - 1]) / (pow(4, (k - 1)) - 1);
        }
    }

    return R[1][size - 1];
}

double f(double v) {
    double g = 9.81, c = 0.225, m = 90;

    return g - c / m * pow(v, 2);
}

int euler(double t, double h, double v1, vector<double>& eul) {
    double v, s;

    for (; t <= 50.0; t += h) {
        s = f(v1);
        v = v1 + s * h;

        eul.push_back(v);

        if (fabs(v1 - v) < 0.0015) {
            break;
        }
        v1 = v;
    }
    return 0;
}

int rk4(double t, double h, double v1, vector<double>& rk) {
    double v, k1, k2, k3, k4;


    for (; t <= 50.0; t += h) {
        k1 = f(v1);
        k2 = f(v1 + k1 * h / 2);
        k3 = f(v1 + k2 * h / 2);
        k4 = f(v1 + k3 * h);
        v  = v1 + (k1 + 2 * k2 + 2 * k3 + k4) * h / 6;
        rk.push_back(v);

        if (fabs(v1 - v) < 0.0015) {
            break;
        }
        v1 = v;
    }

    return 0;
}

int main() {
    // double a = 0.0;
    // double b = 8.0;
    // double actual = 230.969;
    double t = 0.0, h = 0.01;


    double v1 =  f(0); // 1.0;

    vector<double> eul;
    vector<double> rk;

    euler(t, h, v1, eul);


    rk4(t, h, v1, rk);


    double a = 0.0, b = 1.0;
    double res1 = 0.0;

    while (res1 <= 1000) {
        res1 = rhomberg(a, b, eul);

        // cout << res1 << " ";
        b += 0.01;
    }
    cout << "Time of impact for Euler = " << b / 10  << " at distance = " << res1  << endl;

    double a1 = 0.0, b1 = 1.0;
    double res2 = 0.0;

    while (res2 <= 1000) {
        res2 = rhomberg(a1, b1, rk);

        b1 += 0.01;
    }
    cout << "Time of impact for RK = " << b1 / 10  << " at distance = " << res2 << endl;
    double tdump = 1.0;

    for (int i = 0; i <= eul.size(); i += 100) {
        tdump += 1;
        tval.push_back(tdump);
        rkval.push_back(rk[i]);
        eulval.push_back(eul[i]);
    }

    dataDump();


    return 0;
}

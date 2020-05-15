
#include <bits/stdc++.h>

using namespace std;

double func(double t) {
    double e = exp(1.0);
    double g = 9.81;
    double m = 80.0;
    double c = 10.0;

    return g * m / c * (1 - pow(e, -(c / m) * t));
}

double errorFunction(double total, double current) {
    return (total * current / total) * 100;
}

double multiTrap(double a, double b,  int n) {
    double h      = (b - a) / n;
    double result = func(a) + func(b);

    for (int i = 1; i < n; i++) {
        result += 2 * func(a + i * h);
    }
    result *= (b - a) / (2 * n);

    return result;
}

double rhomberg(double a, double b) {
    int size             = 5;
    int n                = 1;
    double R[size][size] = {};

    // Use Trapazoidal rule to construct [i][1] values
    for (int i = 1; i < size; i++) {
        R[i][1] = multiTrap(a, b, n);
        n      *= 2;
    }

    // Iterate through the rest of the matric and compute using Romberg Formula
    for (int k = 2; k < size; k++) {
        for (int j = 1; j < size - k + 1; j++) {
            R[j][k] = (pow(4, (k - 1)) * R[j + 1][k - 1] - R[j][k - 1]) / (pow(4, (k - 1)) - 1);
        }
    }

    // Print resulting grid
    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size - i; j++) {
            cout << R[i][j] << " ";
        }
        cout << endl;
    }
    return R[1][size - 1];
}

double f(double v) {
    double g = 9.81, c = 0.225, m = 90;

    return g - c / m * pow(v, 2);
}

int euler(double t, double h, double v1, vector<double>& eul) {
    cout << v1 << endl;
    double v, s;

    for (; t <= 1.0; t += h) {
        s = f(v1);
        v = v1 + s * h;
        cout << v << " ";
        v1 = v;
        eul.push_back(v);
    }
    cout << endl;
    return 0;
}

int rk4(double t, double h, double v1, vector<double>& rk) {
    double v, k1, k2, k3, k4;

    cout << y1 << " ";

    for (; t <= 1.0; t += h) {
        k1 = f(v1);
        k2 = f(v1 + k1 * h / 2);
        k3 = f(v1 + k2 * h / 2);
        k4 = f(v1 + k3 * h);
        v  = v1 + (k1 + 2 * k2 + 2 * k3 + k4) * h / 6;
        cout << v << " ";
        v1 = v;
        rk.push_back(v);
    }
    cout << endl;
    return 0;
}

int main() {
    // double a = 0.0;
    // double b = 8.0;
    // double actual = 230.969;
    double t = 0.0, h = 0.1;

    double v1 =  f(0); // 1.0;

    vector<double> eul;
    vector<double> rk;

    euler(t, h, v1, eul);


    rk4(t, h, v1, rk);

    double eulSum = 0, rkSum = 0;
    cout << "t" << setw(20) << "Euler Velocity" << setw(19) << "RK Velocity" << setw(10) << "Distance" << endl;
    cout << "-----------------------------------------------------------------\n";

    for (int i = 0; i < eul.size(); i++) {
        double t = (double)(i + 1) / (double)100;
        eulSum += eul[i];
        rkSum  += rk[i];

        cout << t << setw(13) << eul[i] << setw(15) << rk[i] << setw(10) <<  eulSum << " vs " << rkSum << endl;
    }

    double a = 0.0, b = 6.0;
    double res1 = rhomberg(a, b);


    return 0;
}

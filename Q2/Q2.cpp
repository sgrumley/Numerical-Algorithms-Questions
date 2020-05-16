#include <bits/stdc++.h>

using namespace std;

double tanDeg(double deg) {
    return tan(deg * M_PI / 180);
}

double xfunc(double a, double degA, double degB) {
    double x;

    x = tanDeg(degB) / (tanDeg(degB) - tanDeg(degA));
    return x * a;
}

double yfunc(double a, double degA, double degB) {
    double y;

    y = a * ((tanDeg(degA) * tanDeg(degB))       / ((tanDeg(degB) - tanDeg(degA))));
    return y;
}

double pythag(double a, double b) {
    return sqrt(pow(a, 2) + pow(b, 2));
}

double findAngle(double o, double a) {
    // need conversion?
    return atan(o / a) * 180 / M_PI;
}

double speed(double distance, double time) {
    return distance / time;
}

int main() {
    double a, degA9, degB9, degA10, degB10, degA11, degB11;
    double x1, y1, x2, y2;
    double xDif, yDif;
    double angle, s;
    double hyp;

    a = 500.00;

    // 9
    degA9 = 54.80;
    degB9 = 65.59;

    // 10
    degA10 = 54.06;
    degB10 = 64.59;

    // 11
    degA11 = 53.34;
    degB11 = 63.62;

    x1 = xfunc(a, degA10, degB10);
    y1 = yfunc(a, degA10, degB10);

    x2 = xfunc(a, degA11, degB11);
    y2 = yfunc(a, degA11, degB11);

    xDif = x2 - x1;
    yDif = y2 - y1;

    hyp = pythag(xDif, yDif);
    s   = speed(hyp, 1);
    cout << "Speed at 10 sec: " << s  << " m/s" << endl;

    angle = findAngle(yDif, xDif);
    cout << "Angle of inclination @ 10 sec: " << angle << " degrees" << endl;
}

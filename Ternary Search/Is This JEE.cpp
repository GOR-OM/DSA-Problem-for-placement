#include <bits/stdc++.h>
using namespace std;

const double PI = 3.1415926536;
const double EPS = 1e-6;

double func(double b, double c, double x) {
    return (x * x + b * x + c) / sin(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        double b, c;
        cin >> b >> c;
        double l = 0;
        double r = PI / 2;
        while (r - l > EPS) {
            double m1 = l + (r - l) / 3;
            double m2 = r - (r - l) / 3;
            
            if (func(b, c, m1) > func(b, c, m2)) {
                l = m1;
            } else {
                r = m2;
            }
        }
        cout << fixed << setprecision(10) << func(b, c, l) << endl;
    }

    return 0;
}

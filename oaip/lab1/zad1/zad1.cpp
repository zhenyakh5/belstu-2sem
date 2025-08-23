#include <iostream>
#include <cmath>
using namespace std;

double equation1(double x) {
    return exp(x) + x - 4;
}

double equation2(double x) {
    return pow(x, 2) - 4;
}

double bisectionMethod(double (*equation)(double), double a, double b, double epsilon) {
    double c;

    while ((b - a) >= epsilon) {
        c = (a + b) / 2;

        if (equation(c) == 0.0) {
            break;
        }
        else if (equation(c) * equation(a) < 0) {
            b = c;
        }
        else {
            a = c;
        }
    }

    return c;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double a, b, epsilon = 0.001;

    cout << "Введите левую границу a: ";
    cin >> a;

    cout << "Введите правую границу b: ";
    cin >> b;

    double root1 = bisectionMethod(equation1, a, b, epsilon);
    cout << "Корень уравнения 1: " << root1 << endl;

    double root2 = bisectionMethod(equation2, a, b, epsilon);
    cout << "Корень уравнения 2: " << root2 << endl;

    return 0;
}

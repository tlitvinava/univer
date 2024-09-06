#include <iostream>
#include <cmath>

int main(){ //кажись работает(неееееееееееееееееееееееееееееееееееееееееееееееееееееееееееет)
    int m=20, a=0;
    long double h, b,y,x;
    const double PI = 3.141592653589793;
    b = PI / 2;
    h = (b - a) / m;
    for (int i = 0; i<=m; i++) {
        x = a + i * h;
        y = sin(x) - cos(x);
        std::cout << y<<'\n';
    }

}

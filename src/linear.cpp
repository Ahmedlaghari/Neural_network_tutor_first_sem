#include<iostream>
#include "derivativeb.h"
#include "derivativew.h"
using namespace std;
void linear(int *x , int *y) {
    float w = 1.0;
    float b = 3.0;
    int j = 0;
    while (j != 500) {
        cout << derivativeb(x, y, w, b) << "\n";
        cout << derivativew(x, y, w, b) << "\n";
        w = w - (0.001f * derivativew(x, y, w, b));
        b = b - (0.1f * derivativeb(x, y, w, b));
        j++;
    }
    cout << w << "hehe upper w tha neechey b hoga\n" << b;
}

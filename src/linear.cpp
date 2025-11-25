#include<iostream>
#include "derivativeb.h"
#include "derivativew.h"
using namespace std;
void linear() {
    float w = 1.0;
    float b = 3.0;
    float x[] = { 15,16,17,18,19,20,21,22,23,24,25,
                 26,27,28,29,30,31,32,33,34,35,
                 36,37,38,39,40,41,42,43,44,45,
                 46,47,48,49,50,51,52,53,54,55,
                 56,57,58,59,60 };

    float y[] = { 23,24,25,26,27,29,30,31,32,33,35,
                 36,37,38,39,41,42,43,44,45,47,
                 48,49,50,51,53,54,55,56,57,59,
                 60,61,62,63,65,66,67,68,69,71,
                 72,73,74,75,77 };

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
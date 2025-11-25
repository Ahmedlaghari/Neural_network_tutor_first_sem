#include<iostream>
float derivativeb(float* x, float* y, float w, float b) {
    int c = 0;
    float total = 0.0f;
    float rtotal = 0.0f;

    while (c != 46) {
        float err = -((y[c]) - (w * x[c] + b));
        c++;
        total = total + err;
        rtotal = (1.0f / 46.0f) * total;
    }
    return rtotal;
}
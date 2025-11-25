#include<iostream>
float derivativew(float* x, float* y, float w, float b) {
    int c = 0;
    float total = 0.0f;
    float rtotal = 0.0f;

    while (c != 46) {
        float difference = -((y[c]) - (w * x[c] + b)) * x[c];
        c++;
        total = total + difference;
        rtotal = (1.0f / 46.0f) * total;
    }
    return rtotal;
}

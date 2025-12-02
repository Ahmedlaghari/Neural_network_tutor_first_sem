#include<iostream>
float derivativew(float* x, float* y, float w, float b) {
    float total = 0.0f;
    float rtotal = 0.0f;
    int len = x,size();
    for (int i = 0 ; i < len ; i++ {
        float difference = -((y[c]) - (w * x[c] + b)) * x[c];
        c++;
        total = total + difference;
        rtotal = (1.0f / 46.0f) * total;
    }
    return rtotal;
}

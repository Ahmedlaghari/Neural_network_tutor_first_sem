#include<iostream>
float derivativeb(float* x, float* y, float w, float b) {
    int c = 0;
    float total = 0.0f;
    float rtotal = 0.0f;
    int len = x,size();
    for (int i = 0 ; i < len ; i++ {
        float err = -((y[c]) - (w * x[c] + b));
        c++;
        total = total + err;
        rtotal = (1.0f / 46.0f) * total;
    }
    return rtotal;
}

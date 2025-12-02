#include <cmath>
#include "layer_tanh.h"

float tanh_forward(float z) {
    return tanh(z);
}

float tanh_backward(float a, float dL_da) {
    return dL_da * (1 - a * a);   // derivative of tanh
}

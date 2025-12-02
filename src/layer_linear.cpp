#include "layer_linear.h"

float linear_forward(float x, float w, float b) {
    return w * x + b;
}

void linear_backward(float x, float dL_dz, float &dL_dw, float &dL_db, float &dL_dx) {
    dL_dw = dL_dz * x;
    dL_db = dL_dz * 1.0f;
    dL_dx = dL_dz * w;   // sends gradient backward
}

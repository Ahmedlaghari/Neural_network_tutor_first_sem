#include <iostream>
#include <cmath>
#include "layer_linear.h"
#include "layer_tanh.h"
#include "loss_mse.h"

using namespace std;

int main() {
    float w1 = 0.5, b1 = 0.1;
    float w2 = 0.5, b2 = 0.1;

    float lr = 0.01;

    for (int step = 0; step < 5000; step++) {

        float x = (step % 100) * 0.1f;
        float y = sin(x);

        // ---- FORWARD ----
        float z1 = linear_forward(x, w1, b1);
        float a1 = tanh_forward(z1);
        float z2 = linear_forward(a1, w2, b2);
        float y_pred = z2;

        // ---- LOSS ----
        float dL_dy_pred = mse_backward(y, y_pred);

        // ---- BACKWARD LAYER 2 (linear) ----
        float dL_dw2, dL_db2, dL_da1;
        linear_backward(a1, dL_dy_pred, dL_dw2, dL_db2, dL_da1);

        // ---- BACKWARD LAYER 1 (tanh + linear) ----
        float dL_dz1 = tanh_backward(a1, dL_da1);
        float dL_dw1, dL_db1, dL_dx;
        linear_backward(x, dL_dz1, dL_dw1, dL_db1, dL_dx);

        // ---- UPDATE ----
        w2 -= lr * dL_dw2;
        b2 -= lr * dL_db2;

        w1 -= lr * dL_dw1;
        b1 -= lr * dL_db1;

        if (step % 500 == 0)
            cout << "step=" << step << " pred=" << y_pred << " real=" << y << endl;
    }

    cout << "Final weights:" << endl;
    cout << "w1=" << w1 << " b1=" << b1 << endl;
    cout << "w2=" << w2 << " b2=" << b2 << endl;
}

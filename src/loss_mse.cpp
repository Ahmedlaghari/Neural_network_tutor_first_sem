#include "loss_mse.h"

float mse_loss(float y, float y_pred) {
    float diff = y - y_pred;
    return diff * diff;
}

float mse_backward(float y, float y_pred) {
    return -2 * (y - y_pred);
}

// activation.h
#pragma once
#include <cmath>

enum ActivationType {
    LINEAR,
    SIGMOID,
    TANH,
    RELU
};

double activate(double x, ActivationType act);
double activate_derivative(double x, ActivationType act);


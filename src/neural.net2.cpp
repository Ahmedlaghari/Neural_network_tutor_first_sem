#include "neural_net.h"
#include <cstdlib>
#include <cmath>
using namespace std;

// constructor
NeuralNet::NeuralNet(int h, double learning_rate,
    ActivationType h_act,
    ActivationType o_act)
{
    hidden_size = h;
    lr = learning_rate;
    hidden_act = h_act;
    output_act = o_act;

    w1.resize(h);
    b1.resize(h);
    w2.resize(h);

    for (int i = 0; i < h; i++) {
        w1[i] = ((double)rand() / RAND_MAX - 0.5);
        b1[i] = 0.0;
        w2[i] = ((double)rand() / RAND_MAX - 0.5);
    }
    b2 = 0.0;
}

// forward pass
double NeuralNet::forward(double x) {
    vector<double> hidden(hidden_size);
    vector<double> hidden_input(hidden_size);

    for (int i = 0; i < hidden_size; i++) {
        hidden_input[i] = w1[i] * x + b1[i];
        hidden[i] = activate(hidden_input[i], hidden_act);
    }

    double out_input = b2;
    for (int i = 0; i < hidden_size; i++)
        out_input += w2[i] * hidden[i];

    return activate(out_input, output_act);
}

// single-sample training
void NeuralNet::train_sample(double x, double y) {
    vector<double> h_in(hidden_size), h_out(hidden_size);

    for (int i = 0; i < hidden_size; i++) {
        h_in[i] = w1[i] * x + b1[i];
        h_out[i] = activate(h_in[i], hidden_act);
    }

    double o_in = b2;
    for (int i = 0; i < hidden_size; i++)
        o_in += w2[i] * h_out[i];

    double y_pred = activate(o_in, output_act);

    // -------- BACKPROP --------

    // output delta
    double delta_out =
        (y_pred - y) * activate_derivative(o_in, output_act);

    // update w2, b2
    for (int i = 0; i < hidden_size; i++)
        w2[i] -= lr * delta_out * h_out[i];

    b2 -= lr * delta_out;

    // hidden layer
    for (int i = 0; i < hidden_size; i++) {
        double delta_h =
            delta_out * w2[i] * activate_derivative(h_in[i], hidden_act);

        w1[i] -= lr * delta_h * x;
        b1[i] -= lr * delta_h;
    }
}

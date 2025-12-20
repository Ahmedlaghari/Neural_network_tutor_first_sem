#include <fstream>
#include <cmath>
#include "neural_net.h"
#include "json.hpp"

using json = nlohmann::json;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void train_and_save(const std::string& filename, double learning_rate);
    
int main() {
    train_and_save("pred.json", 0.01);
    train_and_save("pred1.json", 0.05);
    system("python \"C:\\\\Users\\\\Hp\\\\source\\\\repos\\\\Neural_network_tutor_first_sem\\\\endsemplottest.py\"");

    return 0;
}

void train_and_save(const std::string& filename, double learning_rate) {
    NeuralNet net(10, learning_rate, SIGMOID, LINEAR);
    json root;
    root["frames"] = json::array();

    for (int epoch = 0; epoch <= 5000; epoch++) {
        // training
        for (double x = 0; x <= 2 * M_PI; x += 0.1)
            net.train_sample(x, sin(x));

        if (epoch % 50 == 0) {
            json frame = json::array();
            for (double x = 0; x <= 2 * M_PI; x += 0.05) {
                frame.push_back({
                    {"x", x},
                    {"y", net.forward(x)}
                    });
            }
            root["frames"].push_back(frame);
        }
    }

    std::ofstream out(filename);
    out << root.dump(2);  // pretty print
    out.close();
}


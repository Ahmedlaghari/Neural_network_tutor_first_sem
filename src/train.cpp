//#include <fstream>
//#include <string>
//#include <cmath>
//#include "neural_net.h"
//
//#ifndef M_PI
//#define M_PI 3.14159265358979323846
//#endif
//
//int main() {
//
//    NeuralNet net(
//        10,         // hidden neurons
//        0.01,       // learning rate
//        TANH,       // hidden activation
//        LINEAR      // output activation
//    );
//
//    for (int epoch = 0; epoch <= 10000; epoch++) {
//        for (double x = 0; x <= 2 * M_PI; x += 0.1) {
//            net.train_sample(x, sin(x));
//        }
//
//        if (epoch % 1000 == 0) {
//            std::ofstream file(
//                "pred_" + std::to_string(epoch) + ".csv");
//
//            for (double x = 0; x <= 2 * M_PI; x += 0.05) {
//                file << x << ","
//                    << net.forward(x) << "\n";
//            }
//            file.close();
//        }
//    }
//
//    return 0;
//}

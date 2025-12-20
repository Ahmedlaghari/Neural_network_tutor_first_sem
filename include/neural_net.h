// neural_net.h
#pragma once
#include <vector>
#include "activation.h"

using namespace std;
class NeuralNet
{
private:
	int hidden_size;
	double lr;
	ActivationType hidden_act;
	ActivationType output_act;
	vector<double> w1;
	vector<double> b1;
	vector<double> w2;
	double b2;

public:
	NeuralNet(int h, double learning_rate, ActivationType h_act, ActivationType o_act);
	double forward(double x);
	void train_sample(double, double);
};
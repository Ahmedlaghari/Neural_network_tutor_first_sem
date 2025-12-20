//// activation.cpp
//#include "activation.h"
//
//double activate(double x, ActivationType act) {
//    switch (act) {
//    case LINEAR:  return x;
//    case SIGMOID: return 1.0 / (1.0 + exp(-x));
//    case TANH:    return tanh(x);
//    case RELU:    return x > 0 ? x : 0;
//    }
//	return x; // default to linear
//}
//
//double activate_derivative(double x, ActivationType act) {
//    switch (act) {
//    case LINEAR: return 1.0;
//    case SIGMOID: {
//        double s = 1.0 / (1.0 + exp(-x));
//        return s * (1 - s);
//    }
//    case TANH: {
//        double t = tanh(x);
//        return 1 - t * t;
//    }
//    case RELU: return x > 0 ? 1 : 0;
//    }
//    return 1.0;
//}


#include "activation.h"

double activate(double x, ActivationType act) {
	switch (act) {
	case LINEAR:  return x;                      //linear activation
	case SIGMOID: return 1.0 / (1.0 + exp(-x)); //sigmoid activation
	case TANH:    return tanh(x);				//tanh activation
	case RELU:    return x > 0 ? x : 0;         //relu activation
	}
	return x; // default to linear
}

double activate_derivative(double x, ActivationType act) {
	switch (act) {
	case LINEAR: return 1.0;                     //derivative of linear activation
	case SIGMOID: {                             //derivative of sigmoid activation
		double s = 1.0 / (1.0 + exp(-x));
		return s * (1 - s);
	}
	case TANH: {                                //derivative of tanh activation
		double t = tanh(x);
		return 1 - t * t;
	}
	case RELU: return x > 0 ? 1 : 0;            //derivative of relu activation
	}
	return 1.0;
}
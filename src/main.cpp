#include<iostream>
#include"derivativeb.h"
#include"derivativew.h"
#include"linear.h"
int main() {
	const int N = 50;
    float start = 0.0;
    float end   = 2 * M_PI;
    float step  = (end - start) / (N - 1);

    cout << "float x[] = { ";
    for (int i = 0; i < N; i++) {
        cout << start + i * step;
        if (i != N - 1) cout << ", ";
    }
    cout << "float y[] = { ";
    for (int i = 0; i < N; i++) {
        cout << sin(start + i * step);
        if (i != N - 1) cout << ", ";
    }
	linear(x,y);
	return 0;
}

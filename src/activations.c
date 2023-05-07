#include <math.h>
#include <stdio.h>

// tanh already implemented in math.h

double relu(double input) { return fmax(0.1 * input, input); }

double sigmoid(double input) { return 1 / (1 + exp(-input)); }

double binary_step(double input) { return input < 0 ? 0 : 1; }

double linear(double input) { return input; }

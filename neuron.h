#include <stddef.h>

typedef struct {
  double *weights;
  double bias;
} Neuron;

Neuron *create_neuron(size_t input_size);
void free_neuron(Neuron *neuron);

double* generate_weights(size_t size);
double* get_weights(Neuron *neuron);
double get_bias(Neuron *neuron);

void print_weights(Neuron *neuron);
void print_bias(Neuron *neuron);

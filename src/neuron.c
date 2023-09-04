#include "neuron.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Neuron *create_neuron(size_t input_size) {
  Neuron *neuron = calloc(1, sizeof(Neuron));

  if (neuron == NULL)
    return NULL;

  neuron->weights_size = input_size;
  double *weights = generate_weights(input_size);

  if (weights == NULL) {
    return NULL;
  }

  neuron->weights = weights;
  neuron->bias = (double)rand() / RAND_MAX;

  return neuron;
}

void free_neuron(Neuron *neuron) {
  free(neuron->weights);
  free(neuron);
}

double *generate_weights(size_t size) {
  double *weights = calloc(size, sizeof(double));
  if (weights == NULL) {
    printf("Cannot allocate memory to weights.\n");
    return NULL;
  }

  for (size_t i = 0; i < size; i++) {
    double r = (double)rand() / RAND_MAX;
    weights[i] = r;
  }

  return weights;
}

double *get_weights(Neuron *neuron) { return neuron->weights; }

double get_bias(Neuron *neuron) { return neuron->bias; }

double forward(Neuron *neuron, double *inputs) {
  double sum = 0;
  for (size_t i = 0; i < neuron->weights_size; i++) {
    sum += inputs[i] * neuron->weights[i];
  }

  return sum + neuron->bias;
}

#include "neuron.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Neuron *create_neuron(size_t input_size) {
  Neuron *neuron = malloc(sizeof(Neuron));
  neuron->weights = generate_weights(input_size);
  neuron->bias = (double)rand() / RAND_MAX;

  return neuron;
}

void free_neuron(Neuron *neuron) {
  free(neuron->weights);
  free(neuron);
}

double *generate_weights(size_t size) {
  double *weights = malloc(sizeof(double) * size);
  if (weights == NULL) {
    printf("Cannot allocate memory to weights.\n");
    exit(EXIT_FAILURE);
  }

  for (size_t i = 0; i < size; i++) {
    double r = (double)rand() / RAND_MAX;
    weights[i] = r;
  }

  return weights;
}

double *get_weights(Neuron *neuron) { return neuron->weights; }

double get_bias(Neuron *neuron) { return neuron->bias; }

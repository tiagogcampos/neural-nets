#include "sequential.h"
#include "layer.h"
#include <stdio.h>
#include <stdlib.h>

Sequential *create_sequential_layers(Layer **layers, size_t number_of_layers) {
  Sequential *seq = calloc(1, sizeof(Sequential));
  if (seq == NULL) {
    printf("Cannot allocate memory to sequential struct\n");
    exit(EXIT_FAILURE);
  }
  seq->layers = layers;
  seq->number_of_layers = number_of_layers;

  return seq;
}

double **forward_sequential(Sequential *sequential, double *inputs) {
  double **results = calloc(sequential->number_of_layers, sizeof(double *));

  if (results == NULL) {
    printf("Cannot allocate memory to results\n");
    return NULL;
  }

  double *forward_result = inputs;

  for (size_t i = 0; i < sequential->number_of_layers; i++) {
    forward_result = forward_layer(sequential->layers[i], inputs);
    results[i] = forward_result;
  }

  return results;
}

void free_sequential(Sequential *sequential) {
  for (size_t i = 0; i < sequential->number_of_layers; i++) {
    remove_layer(sequential->layers[i]);
  }

  free(sequential);
}

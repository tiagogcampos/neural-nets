#include <stdlib.h>
#include "layer.h"
#include "sequential.h"

Sequential *create_sequential_layers(Layer **layers, size_t number_of_layers) {
  Sequential *seq = malloc(sizeof(Sequential));
  seq->layers = layers;
  seq->number_of_layers = number_of_layers;

  return seq;
}


double** forward_sequential(Sequential *sequential, double *inputs) {
  double **results = malloc(sizeof(double *) * sequential->number_of_layers);
  double *forward_result = inputs;

  for(size_t i = 0; i < sequential->number_of_layers; i++) {
    forward_result = forward_layer(sequential->layers[i], inputs);
    results[i] = forward_result;
  }

  return results;
}

void free_sequential(Sequential *sequential) {
  for(size_t i = 0; i < sequential->number_of_layers; i++) {
    remove_layer(sequential->layers[i]);
  }

  free(sequential);
}

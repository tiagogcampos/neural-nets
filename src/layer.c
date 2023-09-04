#include "layer.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Layer *create_layer(size_t input_shape, size_t output_shape) {
  Layer *layer = calloc(1, sizeof(Layer));

  if (layer == NULL) {
    fprintf(stderr, "ERROR: could not allocate layer due: %m\n");
    return NULL;
  }

  layer->neurons = calloc(input_shape, sizeof(Neuron *));

  if (layer->neurons == NULL) {
    fprintf(stderr, "ERROR: could not allocate neurons due: %m\n");
    return NULL;
  }

  layer->input_shape = input_shape;
  layer->output_shape = output_shape;

  for (size_t i = 0; i < input_shape; i++) {
    Neuron *neuron = create_neuron(input_shape);
    if (neuron == NULL) {
      return NULL;
    }
    layer->neurons[i] = neuron;
  }

  return layer;
}

double *forward_layer(Layer *layer, double *inputs) {
  double *forward_pass = calloc(layer->input_shape, sizeof(double));

  if (forward_pass == NULL) {
    fprintf(stderr,
            "ERROR: could not allocate memory to foward_layer due: %m\n");
    remove_layer(layer);
    exit(EXIT_FAILURE);
  }

  for (size_t i = 0; i < layer->input_shape; i++) {
    forward_pass[i] = forward(layer->neurons[i], inputs);
  }

  return forward_pass;
}

size_t get_input_shape(Layer *layer) { return layer->input_shape; }

size_t get_output_shape(Layer *layer) { return layer->output_shape; }

void remove_layer(Layer *layer) {
  for (int i = 0; i < layer->input_shape; i++) {
    free_neuron(layer->neurons[i]);
  }
  free(layer);
}

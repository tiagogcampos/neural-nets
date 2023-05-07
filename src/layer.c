#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "layer.h"

Layer *create_layer(size_t input_shape, size_t output_shape) {
  Layer *layer = malloc(sizeof(Layer));
  layer->neurons = malloc(sizeof(Neuron *) * input_shape);
  layer->input_shape = input_shape;
  layer->output_shape = output_shape;

  for (size_t i = 0; i < input_shape; i++) {
    Neuron *neuron = create_neuron(input_shape);
    layer->neurons[i] = neuron;
  }

  return layer;
}

double *forward_layer(Layer *layer, double *inputs) {
  double *forward_pass = malloc(sizeof(double) * layer->input_shape);
  for(size_t i = 0; i < layer->input_shape; i++) {
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

#include <stddef.h>

#ifndef STRUCT_LAYER_INCLUDED
#define STRUCT_LAYER_INCLUDED

#include "neuron.h"

typedef struct {
  size_t input_shape;  
  size_t output_shape;
  Neuron **neurons;
} Layer;


Layer* create_layer(size_t input_shape, size_t output_shape);


double *forward_layer(Layer *layer, double *inputs);

size_t get_input_shape(Layer *layer);
size_t get_output_shape(Layer *layer);

void remove_layer(Layer *layer);
void print_layer(Layer *layer);

#endif


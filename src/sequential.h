#ifndef STRUCT_SEQ_INCLUDED
#define STRUCT_SEQ_INCLUDED
#include "layer.h"

typedef struct {
  Layer **layers;
  size_t number_of_layers;
} Sequential;


Sequential *create_sequential_layers(Layer **layers, size_t number_of_layers);

double** forward_sequential(Sequential *sequential, double *inputs);

void free_sequential(Sequential *sequential);

#endif

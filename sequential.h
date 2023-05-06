#ifndef STRUCT_SEQ_INCLUDED
#define STRUCT_SEQ_INCLUDED
#include "layer.h"

typedef struct {
  Layer **layers;
} Sequential;


Sequential *create_sequential_layers(Layer **layers);

#endif

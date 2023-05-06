#include <stdlib.h>
#include "layer.h"
#include "sequential.h"

Sequential *create_sequential_layers(Layer **layers) {
  Sequential *seq = malloc(sizeof(Sequential));
  seq->layers = layers;

  return seq;
}

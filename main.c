#include <stdio.h>
#include <stdlib.h>

#include "layer.h"
#include "sequential.h"



void run_with_sequential_layers() {
  Layer *test_layer = create_layer(100, 50);
  Layer *next = create_layer(50, 10);

  size_t number_of_layers = 2;
  Layer **layers = malloc(sizeof(Layer *) * number_of_layers);
  layers[0] = test_layer; layers[1] = next;

  Sequential *seq = create_sequential_layers(layers);

  for (size_t i = 0; i < 2; i++) {
    printf("Layer at %zu\n", i);
    printf("input_shape: %zu\n", seq->layers[i]->input_shape);
    printf("output_shape: %zu\n", seq->layers[i]->output_shape);
    printf("\n");

    remove_layer(seq->layers[i]);
  }

  free(layers);
}

void test_neuron_weights_and_biases() {
  Layer *layer = create_layer(2, 1);

  for (size_t i = 0; i < 2; i++) {
    Neuron *neuron = layer->neurons[i];
    double *weights = get_weights(neuron);
    double bias = get_bias(neuron);
    printf("Weights: \n");
    for (size_t i = 0; i < 2; i++) {
      printf("%f ", weights[i]);
    }
    printf("Bias: %f\n", bias);
  }
}

void simple_layer() {
  Layer *layer = create_layer(100, 50);

  size_t i_shape = get_input_shape(layer);
  size_t o_shape = get_output_shape(layer);

  printf("Input Shape: %zu\n", i_shape);
  printf("Output Shape: %zu\n", o_shape);
  printf("Address of layer: %p\n", layer);

  remove_layer(layer);
}

int main() {
  test_neuron_weights_and_biases();
  return 0;
}

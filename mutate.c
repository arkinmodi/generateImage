#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "a4.h"

void mutate(Individual *individual, double rate) {
    int n = individual[0].image.width * individual[0].image.height;
    int num_pixels = (rate/100*n);
    int max_color = individual[0].image.max_color + 1;

    for(int i = num_pixels; i != 0 ; i--) {
        int r = rand() % max_color;
        int g = rand() % max_color;
        int b = rand() % max_color;
        int index = rand() % (n + 1);

        individual->image.data[index].r = r;
        individual->image.data[index].g = g;
        individual->image.data[index].b = b;
    }
}

void mutate_population(Individual *individual, int population_size, double rate) {
    int start = population_size/4;  // Mutate the last 3 quarters
    for(int i = start; i < population_size; i++)
        mutate(individual+i, rate);
}
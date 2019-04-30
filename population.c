#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "a4.h"

PIXEL *generate_random_image(int width, int height, int max_color) {
    PIXEL *data = malloc(width * height * sizeof(PIXEL));

    for(int i = 0; i < width * height; i++) {
        data[i].r = rand() % (max_color + 1);
        data[i].g = rand() % (max_color + 1);
        data[i].b = rand() % (max_color + 1);
    }
    return data;
}

Individual *generate_population(int population_size, int width, int height, int max_color) {
    Individual *data = malloc(population_size * sizeof(Individual));

    for(int i = 0; i < population_size; i++) {
        data[i].image.height = height;
        data[i].image.width = width;
        data[i].image.max_color = max_color;
        data[i].image.data = generate_random_image(width, height, max_color);
    }
    return data;
}
#include <stdio.h>
#include <stdlib.h>
#include "a4.h"

static int compare(const void *a, const void *b) {
    Individual *A = (Individual *)a;
    Individual *B = (Individual *)b;

    if (A->fitness > B->fitness) return 1;
    else if (A->fitness < B->fitness) return -1;
    else return 0;
}

PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate) {
    Individual *data = generate_population(population_size, image->width, image->height, image->max_color);
    comp_fitness_population(image->data, data, population_size);
    qsort(data, population_size, sizeof(Individual), compare);

    //char name[50];    // Used to write a file for each generation

    for(int i = 1; i <= num_generations; i++) {
        crossover(data, population_size);
        mutate_population(data, population_size, rate);
        comp_fitness_population(image->data, data, population_size);
        qsort(data, population_size, sizeof(Individual), compare);
        printf("GENERATION: %5d\t\tFITNESS: %f\n", i, data[0].fitness);
/*
        // Used to write a file for each generation
        snprintf(name, sizeof(name), "%05d.ppm", i);
        PPM_IMAGE *temp = malloc(sizeof(PPM_IMAGE));
        temp->height = data[0].image.height;
        temp->width = data[0].image.width;
        temp->max_color = data[0].image.max_color;
        temp->data = data[0].image.data;
        write_ppm(name, temp);
*/
    }

    // stores the most fit image so that data can be freed
    PPM_IMAGE *final = malloc(sizeof(PPM_IMAGE));
    final->height = data[0].image.height;
    final->width = data[0].image.width;
    final->max_color = data[0].image.max_color;
    final->data = data[0].image.data;

    // frees all images except the most fit image
    for(int i = 1; i < population_size; i++)
        free(data[i].image.data);
    free(data);
    return final;
}

void free_image(PPM_IMAGE *p) {
    free(p->data);
    free(p);
}
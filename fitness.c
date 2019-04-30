#include <stdio.h>
#include <math.h>
#include "a4.h"

// Orignial function (works with any image_size)
/*double comp_distance(const PIXEL *A, const PIXEL *B, int image_size) {
    double total = 0.0;
    for(int i = 0; i < image_size; i++) {
        double r = A[i].r - B[i].r;
        double g = A[i].g - B[i].g;
        double b = A[i].b - B[i].b;
        total += r*r + g*g + b*b;
    }
    double result = sqrt(total);
    return result;
}*/

// This is faster but image_size needs to be divisible by 8
double comp_distance(const PIXEL *A, const PIXEL *B, int image_size) {
    double total = 0.0;
    for(int i = image_size - 1; i > 0; i-=8) {
        double r1 = A[i].r - B[i].r;
        double g1 = A[i].g - B[i].g;
        double b1 = A[i].b - B[i].b;
        double r2 = A[i-1].r - B[i-1].r;
        double g2 = A[i-1].g - B[i-1].g;
        double b2 = A[i-1].b - B[i-1].b;
        double r3 = A[i-2].r - B[i-2].r;
        double g3 = A[i-2].g - B[i-2].g;
        double b3 = A[i-2].b - B[i-2].b;
        double r4 = A[i-3].r - B[i-3].r;
        double g4 = A[i-3].g - B[i-3].g;
        double b4 = A[i-3].b - B[i-3].b;
        double r5 = A[i-4].r - B[i-4].r;
        double g5 = A[i-4].g - B[i-4].g;
        double b5 = A[i-4].b - B[i-4].b;
        double r6 = A[i-5].r - B[i-5].r;
        double g6 = A[i-5].g - B[i-5].g;
        double b6 = A[i-5].b - B[i-5].b;
        double r7 = A[i-6].r - B[i-6].r;
        double g7 = A[i-6].g - B[i-6].g;
        double b7 = A[i-6].b - B[i-6].b;
        double r8 = A[i-7].r - B[i-7].r;
        double g8 = A[i-7].g - B[i-7].g;
        double b8 = A[i-7].b - B[i-7].b;
        total += r1*r1 + g1*g1 + b1*b1 +
        r2*r2 + g2*g2 + b2*b2 +
        r3*r3 + g3*g3 + b3*b3 +
        r4*r4 + g4*g4 + b4*b4 +
        r5*r5 + g5*g5 + b5*b5 +
        r6*r6 + g6*g6 + b6*b6 +
        r7*r7 + g7*g7 + b7*b7 +
        r8*r8 + g8*g8 + b8*b8;
    }
    double result = sqrt(total);
    return result;
}

void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size) {
    int image_size = individual[0].image.height * individual[0].image.width;
    for(int i = 0; i < population_size; i++)
        individual[i].fitness = comp_distance(image, individual[i].image.data, image_size);
}
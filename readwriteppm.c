#include <stdio.h>
#include <stdlib.h>
#include "a4.h"

PPM_IMAGE *read_ppm (const char *file_name) {
    PPM_IMAGE *image = malloc(sizeof(PPM_IMAGE));
    FILE *inFile = fopen(file_name, "r");

    char width[4], height[4], max_color[4], trash[3];
    
    // Reads file and assigns to vars
    // trash = "P3" which means this is a RGB color image in ASCII
    fscanf(inFile, "%s %s %s %s", trash, width, height, max_color); 
    
    image->height = atoi(height);
    image->width = atoi(width);
    image->max_color = atoi(max_color);

    PIXEL *data = malloc((image->height * image->width) * sizeof(PIXEL));
    for(int i = 0; i < image->height * image->width; i++) {
        int r, g, b;
        fscanf(inFile, "%d %d %d", &r, &g, &b);

        data[i].r = r;
        data[i].g = g;
        data[i].b = b;
    }
    image->data = data;
    fclose(inFile);
    return image;
}

void write_ppm (const char *file_name, const PPM_IMAGE *image) {
    FILE *outFile = fopen(file_name, "w");
    fprintf(outFile, "%s\n%d %d\n%d\n", "P3", image->width, image->height, image->max_color);
    for(int i = 0; i < (image->height * image->width); i++)
        fprintf(outFile, "%d %d %d ", image->data[i].r, image->data[i].g, image->data[i].b);
    fclose(outFile);
}
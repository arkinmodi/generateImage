# Genetic Image Generation
Assignment 4 for SFWRENG 2S03 - Principles of Programming

## Overview
The goal of this assignment is to compute an image, using a basic genetic algorithm approach, that is close to a given image.

## How It Works


## Visualizing The Image Evolution
A visualization of the evolution of `escher` and `mcmaster`. The images shown below are the original image and the generated image, respectively. Each frame in the videos represents each evolution the generated image took.

### Escher
[![Escher](https://github.com/arkinmodi/generateImage/blob/master/export/image/me.jpeg) ![Escher](https://github.com/arkinmodi/generateImage/blob/master/export/image/me2.jpeg)](https://youtu.be/xwlO-Sd1wuU)

YouTube Video: https://youtu.be/xwlO-Sd1wuU

### McMaster
[![McMaster](https://github.com/arkinmodi/generateImage/blob/master/export/image/mcmaster.jpeg) ![McMaster](https://github.com/arkinmodi/generateImage/blob/master/export/image/mcmaster2.jpeg)](https://youtu.be/xwlO-Sd1wuU)

YouTube Video: https://youtu.be/xwlO-Sd1wuU

## How To Run
The program requires 5 in-line arguments (in this order):
* input_file: The source file
* output_file: Name of the output file
* num_generations: Number of generations (iterations)
* population_size: The population size
* mutation_rate: The mutation rate

The makefile currently on supports two different cases, `make escher` (bird image) and `make mcmaster` (McMaster University logo). Also, `make clean` for clean-up.

### Note
`a4.h`, `crossover.c`, `main.c`, and `makefile` were provided by [Dr. Ned Nedialkov](http://www.cas.mcmaster.ca/~nedialk/).
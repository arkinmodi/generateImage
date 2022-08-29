# Genetic Image Generation
Assignment 4 for SFWRENG 2S03 - Principles of Programming

## Overview
The goal of this assignment is to compute an image, using a basic genetic algorithm approach, that is close to a given image.

## How It Works
The basic idea is that the program generates random images, where each pixel is a random color, and the image with the closest "fitness" will be the one outputted.

The way this program works is that it first generates a "population". This population is an array of images with each pixel being a random color. 

Next, the "fitness" of each image is calculated. Fitness is calculated by the following formulas:

&nbsp;&nbsp;&nbsp;&nbsp; Denote the input image by *A* and an arbitrary image by *B*. Let *n* be the number of pixels in each of these images.  
&nbsp;&nbsp;&nbsp;&nbsp; Denote a pixel *i* in *A* by *A(i)* and in *B* by *B(i)*. Let

$$d(i) = [A(i).r - B(i).r]^{2} + [A(i).g - B(i).g]^{2} + [A(i).b - B(i).b]^{2}$$

&nbsp;&nbsp;&nbsp;&nbsp; where *r*, *g*, *b* denote the values for red, green, and blue.

&nbsp;&nbsp;&nbsp;&nbsp; The distance between *A* and *B* is

$$f(A,B) = \sqrt{\sum_{i=1}^{n} d(i)}$$

The population is then sorted base on the fitness values in ascending order.

The program now begins the mutation process. The program uses a [genetic algorithm](https://en.wikipedia.org/wiki/Genetic_algorithm) to mutate the population (this allows the program to generate images that will converge to the inputted image). Then the last 75% of the population has random pixels (determined by the `mutation_rate`) replaced with new randomly generated pixels. The mutation process is then loop for a total of `num_generations` times.

After `num_generations` mutations, the image with the lowest fitness score is outputted to `output_file`.

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
* mutation_rate: The percentage of pixels to be mutated

The makefile currently on supports two different cases, `make escher` (bird image) and `make mcmaster` (McMaster University logo). Also, `make clean` for clean-up.

### Note
`a4.h`, `crossover.c`, `main.c`, and `makefile` were provided by [Dr. Ned Nedialkov](http://www.cas.mcmaster.ca/~nedialk/).

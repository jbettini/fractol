# Fractol

## Overview

Fractol is a project that visualizes fractals. This implementation includes three types of fractals: Burning Ship, Julia, and Mandelbrot. The project allows for interactive exploration and manipulation of these fractals.
Features

-   Visualizes three types of fractals: Burning Ship, Julia, and Mandelbrot.
-   Interactive controls for zooming and navigating the fractal space.
-   Customizable parameters for generating different views of the fractals.

## Prerequisites

-   A Unix-like operating system.
-   GCC (GNU Compiler Collection) installed.
-   Basic knowledge of C programming.

## Installation

-   git clone https://github.com/jbettini/fractol.git
-   cd fractol
-   make

## Usage

Run the compiled executable with the name of the fractal as an argument:
./fractol [fractal_name]

### Available fractal names:

-   mandelbrot
-   julia
-   burningship

### Example:
./fractol mandelbrot

## Project Structure

-   src/: Source files.
-   include/: Header files.
-   Makefile: Build configuration.
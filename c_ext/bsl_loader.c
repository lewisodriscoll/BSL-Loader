#include "bsl_loader.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

void loader_dealloc(Loader_params *params) {
    int i;

    // Free the memory allocated in loader_init
    for (i = 0; i < params->rasters; i++) {
        free(params->data[i]);
    }
    free(params->data);
}

void loader_init(Loader_params *params) {
    int i;

    // Allocate memory for a 2d array of size pixels*rasters
    params->data = malloc(sizeof(float *) * params->rasters);
    for (i = 0; i < params->rasters; i++) {
        params->data[i] = malloc(sizeof(float) * params->pixels);
    }
}

void load_frame(Loader_params *params) {
    // Struct for storing values read from file
    struct record {
        float x;
    };

    int frame;
    int raster;
    int pixel;
    int frame_pos;
    FILE *input_file;
    struct record my_record;

    input_file = fopen(params->filename, "rb");

    if (!input_file) {
        printf("Unable to open file: %s\n", params->filename);
        return;
    }

    // Index of byte where the requried frame starts
    frame_pos = params->rasters * params->pixels * params->frame;
    // Move the pointer to the start of the frame we're interested in
    fseek(input_file, frame_pos*sizeof(struct record), SEEK_SET);
    // Read the frame data into params->data
    for (raster = 0; raster < params->rasters; raster++) {
        for (pixel = 0; pixel < params->pixels; pixel++) {
            fread(&my_record, sizeof(struct record), 1, input_file);
            params->data[raster][pixel] = my_record.x;
        }
    }

    fclose(input_file);

    return;
}

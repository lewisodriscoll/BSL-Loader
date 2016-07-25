#include "bsl_loader.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

void loader_dealloc(Loader_params *params) {
    int i;

    for (i = 0; i < params->rasters; i++) {
        free(params->data[i]);
    }
    free(params->data);
}

void loader_init(Loader_params *params) {
    int i;

    params->data = malloc(sizeof(float *) * params->rasters);
    for (i = 0; i < params->rasters; i++) {
        params->data[i] = malloc(sizeof(float) * params->pixels);
    }
}

void load_frame(Loader_params *params) {
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

    frame_pos = params->rasters * params->pixels * params->frame;
    fseek(input_file, frame_pos*sizeof(struct record), SEEK_SET);
    for (raster = 0; raster < params->rasters; raster++) {
        for (pixel = 0; pixel < params->pixels; pixel++) {
            fread(&my_record, sizeof(struct record), 1, input_file);
            params->data[raster][pixel] = my_record.x;
        }
    }

    fclose(input_file);

    return;
}

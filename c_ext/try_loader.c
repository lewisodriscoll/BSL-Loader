#include "bsl_loader.h"
#include <string.h>

int main() {
    // Header file will be parsed in python.
    // Pixels, raters, frame and filename will be passed in from python code.
    Loader_params params;
    params.pixels = 1475;
    params.rasters = 1679;
    params.frame = 5;
    strcpy(params.filename, "../multi_data/B12001.629");

    // Allocates the params.data 2D array
    loader_init(&params);

    // Loads the data from params.frame into params.data
    load_frame(&params);

    printf("data[766][1358] = %f\n", params.data[766][1358]);

    // Frees the memory allocated in loader_init
    loader_dealloc(&params);

    return 1;
}

#include "bsl_loader.h"
#include <string.h>

int main() {
    Loader_params params;
    params.pixels = 1475;
    params.rasters = 1679;
    params.frame = 5;
    strcpy(params.filename, "../multi_data/B12001.629");

    loader_init(&params);

    load_frame(&params);

    printf("data[766][1358] = %f\n", params.data[766][1358]);

    loader_dealloc(&params);

    return 1;
}

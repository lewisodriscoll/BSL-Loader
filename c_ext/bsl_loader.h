#if !defined(bsl_loader)
#define bsl_loader

typedef struct Loader_params {
    // File to load
    char filename[50];
    // Frame to load
    int frame;
    // Number of pixels in the file
    int pixels;
    // Number of rasters in the file
    int rasters;
    // Data to be returned;
    float **data;
} Loader_params;

void loader_dealloc(Loader_params *params);
void loader_init(Loader_params *params);
void load_frame(Loader_params *params);

#endif

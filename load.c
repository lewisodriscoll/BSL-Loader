#include <stdio.h>

struct rec {
    float x;
};

const int n_frames = 41;
const long n_pixels = 1475;
const long n_rasters = 1679;

float frames[1475*1679*41];

int offset(int x, int y, int z) {
    return (z * n_pixels * n_rasters) + (y * n_pixels) + x;
}

int main() {
    // float frames[1679][1475][41];

    int frame;
    int raster;
    int pixel;
    FILE *my_file;
    struct rec my_record;
    char filename[50];
    FILE *save_file;

    my_file = fopen("multi_data/B12001.629", "rb");

    if (!my_file) {
        printf("Unable to open input file");
        return 1;
    }

    for (frame = 0; frame < n_frames; frame++) {
        sprintf(filename, "multi_data/export/frame%d.txt", frame);
        save_file = fopen(filename, "w");
        if (!save_file) {
            printf("Unable to open save file: %s", filename);
            return 1;
        }
        for (raster = 0; raster < n_rasters; raster++) {
            for (pixel = 0; pixel < n_pixels; pixel++) {
                fread(&my_record, sizeof(struct rec), 1, my_file);
                frames[offset(raster, pixel, frame)] = my_record.x;
                fprintf(save_file, "%.2e ", my_record.x);
            }
            fprintf(save_file, "\n");
        }
        printf("%s\n", filename);
        fclose(save_file);
    }

    fclose(my_file);

    return 0;
}

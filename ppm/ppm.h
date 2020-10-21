#if defined DEFINE_PPM

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define PPM_CHAR 'P'
#define PPM_ASCII '3'
#define PPM_BINARY '6'

typedef struct ppm_type_tag {
  int width;
  int height;
  uint8_t max_color_size;
  bool binary_format;
  char *data;
  FILE *fptr;
} ppm_type;

const uint8_t bytes_per_pixel = 3;
typedef uint8_t color_type[3];

bool write_ppm_file(char filename[], ppm_type *ppm) {
  if (ppm == NULL) {
    return false;
  }

  if (ppm->fptr) {
    fclose(fptr);
  }

  remove(ppm->filename);

  FILE *fptr = fopen(ppm->filename, "wb");

  if (ppm->binary_format) {
    fprintf(fptr, "P6\n");
    fprintf(fptr, "%i %i\n", ppm->width, ppm->height);
    fprintf(fptr, "%i\n", ppm->max_color_size);
    fwrite(ppm->data, 1, ppm->width * ppm->height * bytes_per_pixel, fptr);
  }
}

bool load_ppm_file(char filename[], ppm_type *ppm) {
  char file_marker[2] = {0};
  ppm->fptr = fopen(filename, "r");
  fscanf(ppm->fptr, "%c%c", file_marker[0], file_marker[1]);
  if (file_marker[0] == PPM_CHAR) {
    if (file_marker[1] == PPM_BINARY) {
      ppm->binary_format = true;
    } else if (file_marker[1] == PPM_ASCII) {
      ppm->binary_format = false;
    } else {
      ppm->fptr = NULL;
      return false;
    }
  }
}

void draw_pixel(int x, int y, color_type color, ppm_type *ppm) {
  int offset = (y * ppm->width + x) * bytes_per_pixel;
  memcpy(&ppm->data[offset], color, bytes_per_pixel);
}

#endif

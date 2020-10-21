#define DEFINE_PPM

#include "ppm.h"

static ppm_type ppm;

int main(int argc, char* argv[])
{
    load_ppm_file("test.ppm", &ppm);
}

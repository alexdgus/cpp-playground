#define DEFINE_PPM

#include "ppm.h"

static ppm_type ppm;

int main(int argc, char* argv[])
{
    open_ppm_file("test.ppm", &ppm);
}

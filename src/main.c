// CRPC Main
//
// Usage:
//  crpc [option] [path to input crpc file] [output directory]
//
// Options:
// -v, --verbose
//     Prints extra log statements, for debugging

#include "..\include\logging.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

const char usage[] = "\nUsage:\n\ncrpc [option] [path to input crpc file] [output directory]\n\nOptions:\n\n-v, --verbose\n\tPrints extra log statements, for debugging\n";

extern int verbose;

int main(int argc, char* argv[])
{
        if (argc != 3 && argc != 4)
        {
                fprintf(stderr, usage);
                return -1;
        }

        if (!strcmp(argv[1], "-v") || !strcmp(argv[1], "--verbose"))
                verbose = 1;

        int inputPathIndex = 1, outputDirIndex = 2;
        if (verbose)
        {
                inputPathIndex = 2;
                outputDirIndex = 3;
        }

        FILE *in = fopen(argv[inputPathIndex], "r");
        if (!in)
        {
                fprintf(stderr, "File error: can't open input file %s: %s\n",
                        argv[inputPathIndex], strerror(errno));
                return -1;
        }
        LOG("Input file: %s\n", argv[inputPathIndex]);

        struct stat s = { 0 };
        if (stat(argv[outputDirIndex], &s))
        {
                fprintf(stderr, "File error: can't open output directory %s: %s\n",
                        argv[outputDirIndex], strerror(errno));
                return -1;
        }
        LOG("Output directory: %s\n", argv[outputDirIndex]);

        return 0;
}

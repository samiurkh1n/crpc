#ifndef _LOGGING_H_
#define _LOGGING_H_

int verbose = 0;

#define LOG(fmt, ...)\
        do {\
                if (verbose) fprintf(stdout, fmt, __VA_ARGS__);\
        } while(0)

#endif  // _LOGGING_H_

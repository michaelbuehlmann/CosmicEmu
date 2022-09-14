#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "emu.h"

int main(int argc, char **argv) {

    // A main function to be used as an example.

    // Parameter order
    // '\omega_m'   '\omega_b'   '\sigma_8'   'h'   'n_s'   'w_0'   'w_a'   '\omega_{\nu}'   'z'

    double xstar[9]; // = {0.1335, 0.02258, 0.8, 0.71, 0.963, -1.0, 0.0, 0.0, .75};
    double ystar[351];
    int i, j;
    FILE *infile;
    FILE *outfile;
    char instring[256];
    char outname[256];
    char *token;
    int good = 1;
    int ctr = 0;
    char ctrc[100];

    // Read inputs from a file
    // File should be space delimited with 9 numbers on each line
    // '\omega_m'   '\omega_b'   '\sigma_8'   'h'   'n_s'   'w_0'   'w_a'   '\omega_{\nu}'   'z'
    if((infile = fopen("xstar.dat","r"))==NULL) {
        printf("Cannot find inputs.\n");
        exit(1);
    }

    // Read in the inputs and emulate the results.
    while(good == 1) {

        // Read each line
        if(fgets(instring, 256, infile) != NULL) {
            token = strtok(instring, " ");

            // Parse each line, which is space delimited
            for(i=0; i<9; i++) {
                xstar[i] = atof(token);
                token = strtok(NULL, " ");
            }

            // Get the answer.
            emu(xstar, ystar);

            // output file name
            strcpy(outname, "EMU");
            sprintf(ctrc, "%i", ctr);
            strcat(outname, ctrc);
            strcat(outname, ".txt");

            // Open the output file
            if ((outfile = fopen(outname,"w"))==NULL) {
                printf("cannot open %s \n",outname);
                exit(1);
            }
            for(i=0; i<nmode; i++) {
                fprintf(outfile, "%f %f \n", mode[i], ystar[i]);
            }
            fclose(outfile);

            ctr++;
        } else {
            good = 0;
        }
    }
    fclose(infile);

}

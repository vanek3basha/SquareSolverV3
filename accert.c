#include "TestHeader.h"
#include "SquareSolver.h" 
#include "accert.h"
#include "scantestdynamyc.h"


void accert(int bool_char )
    {
#ifndef NDEBUG
    if (bool_char != 0);
    else
        {
        printf("Asserted failed");
        exit(1);
        }
#endif
    }
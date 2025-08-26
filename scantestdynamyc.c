#include "TestHeader.h"
#include "SquareSolver.h"                                                                        //библиотечки
#include "accert.h"
#include "scantestdynamyc.h"
#include "My_realloc.h"
#include "is_zero.h"


size_t reader(double **ptr_data, size_t* length)
{
    size_t capacity = 10;
    
    *ptr_data = (double *)calloc(capacity, sizeof(double));
    if (!*ptr_data) 
        {
            perror("> error while allocating memory\n");
            return 1;
        }
    // else
    //     exit(1);
    
    FILE* ptr_file = fopen("Filer.txt", "r");

    if(ptr_file == NULL) 
        {
            perror("Filer.txt");
            return 1;
        }
    // else
    //     exit(1);
    
    char nan_proof[10];
    
    while(1)
        {
            if (*length == capacity)
                {
                    *ptr_data = append(ptr_data, length, &capacity);
                }

            if (fscanf(ptr_file, "%lg, ", &(*ptr_data)[*length]) == 1)
                {
                    //printf("[%d]> number: %g\n", length, ptr_data[length]);
                    (*length)++;
                    continue;
                }
            if (fscanf(ptr_file, "%s, ", nan_proof) == 1 && !strcmp(nan_proof, "NAN"))
                {
                    *ptr_data[*length] = NAN;
            //printf("[%d]> number: %g\n", length, ptr_data[length]);
                    (*length)++;
                continue;
                }
            else
                {
                    break;
                }
        }

    //printf("%lg ", ptr_data[i]);
 
    fclose(ptr_file);

    // for(int i = 0; i < *length; ++i)
        //printf("%lg ", (*ptr_data)[i]);
    //printf("%d ", *length);
    
    return *length;
}
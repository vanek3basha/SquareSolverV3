#include "TestHeader.h"
#include "SquareSolver.h"                                                                        //библиотечки
#include "accert.h"
#include "scantestdynamyc.h"

double* append(double **ptr_data, int* ptr_length, int* ptr_capacity)
{
    *ptr_capacity = *ptr_capacity * 2;
    double* ptr_list = (double *)calloc(*ptr_capacity, sizeof(double));
    if(ptr_list == NULL)
        return *ptr_data;
        
    for(int i = 0;i < *ptr_length; ++i)
        ptr_list[i] = (*ptr_data)[i];

        free(*ptr_data);
        *ptr_data = ptr_list;
        
    return *ptr_data;
}


int reader(double **ptr_data, int* length)
{
    int capacity = 10;
    
    *ptr_data = (double *)calloc(capacity, sizeof(double));
    if (!*ptr_data) {
        perror("> error while allocating memory\n");
        return 1;
    }
    
    FILE* ptr_file = fopen("Filer.txt", "r");
    if(ptr_file == NULL) {
        perror("Filer.txt");
        return 1;
    }
    
    char nan_proof[4];
    
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
    for(int i = 0; i < *length; ++i)
        //printf("%lg ", (*ptr_data)[i]);
    //printf("%d ", *length);
    return *length;
}
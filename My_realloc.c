#include "My_realloc.h"
#include <stdlib.h>
#include "scantestdynamyc.h"
#include "is_zero.h"

double* append(double **ptr_data, size_t* ptr_length, size_t* ptr_capacity)
{
    *ptr_capacity = *ptr_capacity * 2;
    double* ptr_list = (double *)calloc(*ptr_capacity, sizeof(double));
    
    if(ptr_list == NULL)
        {
            return *ptr_data;
        }
        
    for(size_t i = 0;i < *ptr_length; ++i)
        {
        ptr_list[i] = (*ptr_data)[i];
    }
    //*ptr_data = ptr_list;
    free(*ptr_data);
    return ptr_list;
    
}

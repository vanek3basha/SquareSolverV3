#include "TestHeader.h"
#include "SquareSolver.h" 
#include "accert.h"
#include "scantestdynamyc.h"



int admin_function()
    {
    
    printf(ANSI_COLOR_CYAN "Press T for starting test or press any key for used square solver\n");
    printf(ANSI_COLOR_MAGENTA "");
    char test = getchar();
    while(getchar() != '\n')
        continue;
    if (test == 'T') {
        double *data = NULL;
        int lenght1= 0;
        lenght1 = reader(&data, &lenght1);
        char test;
        // for(int i = 0; i < lenght1; ++i)
        //     printf("%lg ", data[i]);
        unit_test(data, lenght1);

        free(data);
        return 0;
    }

    return 1;
    }
/*********************************************************************************************************************************************************/
void unit_test(double* ptr_data, int length)
    {
    for(int i = 0 ; i < (length); ){
        struct test library_unit_test_massive = {{ptr_data[i], ptr_data[i+1], ptr_data[i+2], ptr_data[i+3], ptr_data[i+4]}, ptr_data[i+5], ptr_data[i+6], ptr_data[i+7]};
        i = i + 8;
        init_test(library_unit_test_massive);
    }
    getchar(); 
    }
/******************************************************************************************************************/
/*struct koeficients scan_struct_test_function(double scan_a, double scan_b, double scan_c, double scan_x1, double scan_x2)
    { 
    struct koeficients scan;
    scan.a = scan_a;
    scan.b = scan_b;
    scan.c = scan_c;
    scan.x1 = scan_x1;
    scan.x2 = scan_x2; 
    return scan;
    }*/
/******************************************************************************************************************/
void init_test(struct test library_unit_test)
    {
    
    int number_roots_test = square_solver_function(&library_unit_test.unit);
    if (number_roots_test == library_unit_test.num_test){
        if (library_unit_test.x1_test == library_unit_test.unit.x1 ) {
            if (library_unit_test.x2_test == library_unit_test.unit.x2){
                printf(ANSI_COLOR_GREEN "OK\n");
            }
            else if (isnan(library_unit_test.x2_test) && isnan(library_unit_test.unit.x2))
                printf(ANSI_COLOR_GREEN  "OK\n");
            else
                printf(ANSI_COLOR_RED "NO, FAILED, x2 not equal\n" );
        }
        else if (isnan(library_unit_test.x1_test) && isnan(library_unit_test.unit.x1)){
            if (library_unit_test.x2_test == library_unit_test.unit.x2){
                printf(ANSI_COLOR_GREEN "OK\n");
            }
            else if (isnan(library_unit_test.x2_test) && isnan(library_unit_test.unit.x2)){
                printf(ANSI_COLOR_GREEN  "OK\n");
            }
            else
                printf(ANSI_COLOR_RED "NO, FAILED, x2 not equal \n");
        }
        else
            printf(ANSI_COLOR_RED "NO, FAILED, x1 not equal \n");
        }  
    else
        printf(ANSI_COLOR_RED "NO, FAILED, number of roots not equal \n");
    }
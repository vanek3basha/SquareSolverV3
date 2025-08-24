#include "TestHeader.h"
#include "SquareSolver.h" 
#include "accert.h"
int admin_function()
    {
    char test;
    printf("Press T for starting test\n");
    test = getchar();
    if (test == 'T') {
        unit_test();
        return 0;
    }

    return 1;
    }
/*********************************************************************************************************************************************************/
void unit_test()
    {
    struct test library_unit_test_massive[5] = {
        {{1, 2, 1, NAN, NAN}, -1, NAN, 1},
        {{0, 0, 0, NAN, NAN}, NAN, NAN, -1}, 
        {{0, 0, 1, NAN, NAN}, NAN, NAN, 0}, 
        {{0, 2, 1, NAN, NAN}, 0.5, NAN, 1}, 
        {{1, 4, 3, NAN, NAN}, -1, -3, 2}};

    //init_test(1, 2, 1, 1,-1, NAN)
    int i = 0;
    while (i != 5)
        {
        init_test(library_unit_test_massive[i]);
        i+=1;   
        }
    getchar();
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
                printf("OK\n");
            }
            else if (isnan(library_unit_test.x2_test) == isnan(library_unit_test.unit.x2))
                printf("OK\n");
            else
                printf("NO, FAILED, x2 not equal\n" );
        }
        else if (isnan(library_unit_test.x1_test) == isnan(library_unit_test.unit.x1)){
            if (library_unit_test.x2_test == library_unit_test.unit.x2){
                printf("OK\n");
            }
            else if (isnan(library_unit_test.x2_test) == isnan(library_unit_test.unit.x2)){
                printf("OK\n");
            }
            else
                printf("NO, FAILED, x2 not equal \n");
        }
        else
            printf("NO, FAILED, x1 not equal \n");
        }  
    else
        printf("NO, FAILED, number of roots not equal \n");
    }
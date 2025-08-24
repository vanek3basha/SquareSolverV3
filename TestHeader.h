#ifndef TEST_HEADER_H_
#define TEST_HEADER_H_
#include "SquareSolver.h"




struct test
    {
    struct koeficients unit;
    double x1_test;
    double x2_test;
    int num_test;
    };
void unit_test();
int admin_function();
//struct koeficients scan_struct_test_function(double scan_a, double scan_b, double scan_c);
void init_test(struct test library_unit_test);
#endif
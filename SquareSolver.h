#ifndef SQUARE_SOLVER_H_
#define SQUARE_SOLVER_H_
#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
#include <string.h>
#define ONE_ROOT 1
#define TWO_ROOT 2
#define ZER0_ROOT 0
#define INFINITY_ROOT -1
struct koeficients
    {
    double a;
    double b;
    double c;
    double x1;
    double x2;
    };
void  starting_function(struct koeficients* library_start);
/*********************************************************************************************************************************************************/
//! \brief Solves quadratic equations of the form ax^2+bx+c=0
//! \details it receives a struct with coefficients a, b, c and  as input and returns the roots of the equation in the same struct
//! @param [in] a coefficient for x^2
//! @param [in] b coefficient for x
//! @param [in] c free coefficient
//! @param [out] x1 Pointer to the 1st root
//! @param [out] x2 Pointer to the 2nd root
//! @param [out] x Pointer to the only one root
/*********************************************************************************************************************************************************/
int square_solver_function(struct koeficients* library_square);                     // прототиты функций
double coefs_scan_and_fixer();
void printing_function(int number_of_koefs, struct koeficients library_printing);
double discriminant_function(struct koeficients library_Discriminant);
int line_solver_function(struct koeficients* library_line); 
double one_root_function(struct koeficients library_one_root);
double first_root_function(struct koeficients library_first_root, double D_first_root);
double second_root_function(struct koeficients library_second_root,double D_second_root);

#endif
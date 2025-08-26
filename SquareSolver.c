#include "TestHeader.h"
#include "SquareSolver.h"
#include "accert.h" 
#include "scantestdynamyc.h"
#include "is_zero.h"

void  starting_function(struct koeficients* library_start) 
    {
    printf(ANSI_COLOR_CYAN "Hello\n");
    printf("Enter koefs for ax^2+bx+c\n");
    printf("Enter koef a: ");
    printf(ANSI_COLOR_MAGENTA "");

    library_start->a = coefs_scan_and_fixer();

    printf(ANSI_COLOR_CYAN "\nEnter koef b: ");
    printf(ANSI_COLOR_MAGENTA "");

    library_start->b = coefs_scan_and_fixer();

    printf(ANSI_COLOR_CYAN "\nEnter koef c: ");
    printf(ANSI_COLOR_MAGENTA "");

    library_start->c = coefs_scan_and_fixer();

    printf(ANSI_COLOR_CYAN "");
    }
/*********************************************************************************************************************************************************/
double coefs_scan_and_fixer() 
    {
        double input =0;
        int ch = 0;
        while (scanf("%lf", &input) != 1)                                                      //проверяем значения введенные в scanf()
        {
            while ((ch = getchar()) != '\n')
                printf("%d", ch); 

            printf(ANSI_COLOR_CYAN "\nError, enter number: ");
            printf(ANSI_COLOR_MAGENTA "");
    }
    
    return input;
    }
/*********************************************************************************************************************************************************/
int square_solver_function( struct koeficients* library_square)    //вызываемая функция считающая корни
    {    
    double D = discriminant_function(*library_square);                                                                 
        //printf("%f", D);
    if (is_zero(library_square->a)) 
        {
            return line_solver_function(library_square);   
        }
    if (fabs(D) < 1e-6) 
        {
            library_square->x1 = one_root_function(*library_square) ;
            return ONE_ROOT;
        }
    if (D > 0) 
        {                                                                       //проверка дискриминанта на знак
            library_square->x1 = first_root_function(*library_square, D);
            library_square->x2 = second_root_function(*library_square, D);

            if  (library_square->x2 > library_square->x1)
            {
                library_square->x2 = first_root_function(*library_square, D);
                library_square->x1 = second_root_function(*library_square, D);
            }

            return TWO_ROOT;
        }
        
    if (D < 0) 
        {
            return ZER0_ROOT;
        }
    else
        exit(1);
    }

/*********************************************************************************************************************************************************/
double discriminant_function(struct koeficients library_Discriminant)
    {
        return (library_Discriminant.b * library_Discriminant.b - 4 * library_Discriminant.a * library_Discriminant.c);
    }
/*********************************************************************************************************************************************************/
int line_solver_function(struct koeficients *library_line)
    {
        if (is_zero(library_line->b))
            {
                if (is_zero(library_line->c))
                    {
                        return INFINITY_ROOT;
                    }
                return ZER0_ROOT;
            }

        library_line->x1 = - library_line->c / library_line->b;
        return ONE_ROOT;
    }
/*********************************************************************************************************************************************************/
double one_root_function(struct koeficients library_one_root)
    {
        return (- library_one_root.b / (2*library_one_root.a));
    }
/*********************************************************************************************************************************************************/
double first_root_function(struct koeficients library_first_root, double D_first_root)
    {
        return ( - library_first_root.b + pow(D_first_root, 0.5)) / (2 * library_first_root.a);
    }
/*********************************************************************************************************************************************************/
double second_root_function(struct koeficients library_second_root,double D_second_root)
    {
        return ( - library_second_root.b - pow(D_second_root, 0.5)) / (2 * library_second_root.a);
    }
/*********************************************************************************************************************************************************/
void printing_function(int number_of_koefs,struct koeficients library_printing)
    {
        switch(number_of_koefs)
            {
                case ZER0_ROOT:                                                                 //разный вывод для разного кол-ва корней
                    printf("No answers\n");
                    break;
                case ONE_ROOT: 
                    printf("Answer x=%lg\n", library_printing.x1);
                    break;
                case TWO_ROOT:
                    printf("Answers x1=%lg , x2=%lg\n", library_printing.x1, library_printing.x2);
                    break;
                case INFINITY_ROOT:
                    printf("The equation has an infinite number of roots\n");
                    break;
                default:
                    break;
            }
        printf("For break press #,for continue press any key \n");
        printf(ANSI_COLOR_MAGENTA "");    
    }
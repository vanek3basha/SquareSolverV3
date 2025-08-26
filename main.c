// SquareSolver(типо кввадратные уравнения решает)

/*********************************************************************************************************************************************************/
#include "TestHeader.h"
#include "SquareSolver.h"                                                                        //библиотечки
#include "accert.h"
#include "scantestdynamyc.h"
#include "is_zero.h"
/*********************************************************************************************************************************************************///
//getopts
int main() 
    {
        struct koeficients library_main ={};                                                       // коофиценты и конечные ответы
        int exit_for_circle = 'h';
        if (admin_function()==0)
            {
                return 0;
            }                                                                 //принимаем на ввод коэфы
        while (exit_for_circle != '#')
            {   
                starting_function(&library_main);
                int number_of_roots = square_solver_function(&library_main);
                printing_function(number_of_roots, library_main);
                getchar();
                exit_for_circle = getchar();

                while (exit_for_circle =='\n')
                    {
                        exit_for_circle = getchar();
                    }
                while(getchar() != '\n')
                    {
                        continue;
                    }  
            }

        printf(ANSI_COLOR_CYAN "End\n");

        printf("> end\n");
        return 0;
    }
/*********************************************************************************************************************************************************/
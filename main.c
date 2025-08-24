// SquareSolver(типо кввадратные уравнения решает)

/*********************************************************************************************************************************************************/
#include "TestHeader.h"
#include "SquareSolver.h"                                                                        //библиотечки
#include "accert.h"

/*********************************************************************************************************************************************************/

int main() 
    {
    struct koeficients library;                                                       // коофиценты и конечные ответы
    char pivko;
    if (admin_function()==0)
        return 0;
    pivko = 'h';                                                                 //принимаем на ввод коэфы
    while (pivko != '#')
        {   
        starting_function(&library);
        int number_of_roots = square_solver_function(&library);
        printing_function(number_of_roots, library);
        getchar();
        pivko = getchar();
        while(getchar() != '\n')
            continue;  
        }
    printf("End\n");
    return 0;
    }
/*********************************************************************************************************************************************************/



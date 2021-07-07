#include <stdio.h>
#include <stdlib.h>
#include "pais.h"
#include "parser.h"
#include "LinkedList.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param lista LinkedList*
 * \return int
 *
 */
int parser_paisFromText(FILE* pFile , LinkedList* lista)
{
    int error=0;
    char buffer[5][20];
    ePais* aux=NULL;

    if(pFile!=NULL && lista!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
        while(!feof(pFile))
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4])==5)
            {
                aux=pais_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
                if(aux!=NULL)
                {
                    if(!ll_add(lista,aux))
                    {
                        aux=NULL;
                        error=1;
                    }
                }
            }
        }
    }

    return error;
}

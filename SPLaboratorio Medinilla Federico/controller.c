#include <stdio.h>
#include <stdlib.h>
#include "pais.h"
#include "misFuncionesGet.h"
#include "parser.h"
#include "LinkedList.h"
#include "controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path ,LinkedList* lista)
{
    int error=1;
    char sobreescribe;
    FILE* f;

    if(path!=NULL && lista!=NULL)
    {
        f=fopen(path,"r");
        if(f!=NULL)
        {
            if(!ll_isEmpty(lista))
            {
                if(!getDosChar("\nEl programa ya tiene datos cargados. Desea sobreescribirlos?(S/N): ","\nERROR - Re-ingrese 's' o 'n'.",'n','s'))
                {
                    sobreescribe='n';
                }
                else
                {
                    sobreescribe='s';
                }
            }
            if(ll_isEmpty(lista) || sobreescribe=='s')
            {
                ll_clear(lista);
                parser_paisFromText(f,lista);
                error=0;
            }
        }
    }
    fclose(f);

    return error;
}



int controller_mostrarPais(ePais* pais)
{
    int error=1;
    int id;
    char nombre[20];
    int vac1;
    int vac2;
    int sinVac;

    if(pais!=NULL)
    {
        if(pais_getId(pais,&id)==0
        &&pais_getNombre(pais,nombre)==0
        &&pais_getVac1(pais,&vac1)==0
        &&pais_getVac2(pais,&vac2)==0
        &&pais_getSinVac(pais,&sinVac)==0)
        {
            printf("\n%3d %10s %2d %2d %2d\n",id,nombre,vac1,vac2,sinVac);
            error=0;
        }
    }

    return error;
}

int controller_listPaises(LinkedList* lista)
{
    int error=1;
    ePais* aux=NULL;
    int tam;

    if(lista!=NULL)
    {
        tam=ll_len(lista);
        printf("\n|ID|  |Nombre Pais|  |1Dosis|  |2Dosis|  |sinVacunar|\n");
        for(int i=0;i<tam;i++)
        {
            aux=(ePais*) ll_get(lista,i);
            controller_mostrarPais(aux);
            error=0;
        }
    }

    return error;
}
int pais_filter2dosis(void* pais)
{
	int error=0;

	ePais* pais1;

	if(pais!=NULL)
	{
		pais1= (ePais*) pais;
		if(pais1->vac2dosis>30)
		{
			error=1;
		}
	}
	return error;
}
int controller_filterPaises(LinkedList* lista)
{
    int error=-1;

    LinkedList* listaFiltrada=NULL;
	if(listaFiltrada!=NULL)
	{
		listaFiltrada=ll_filter(lista, pais_filter2dosis);
		controller_listPaises(listaFiltrada);
		error=0;
	}
	return error;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "misFuncionesGet.h"
#include "LinkedList.h"

int randomVac1(void* pais);
int randomVac2(void* pais);
int porcentajeSinVacunar(void* pais);

int main()
{
    srand(time(NULL));
    LinkedList* listaVacunas=NULL;
    int menuOpcion;
    char salir='n';
    char path[20];

    listaVacunas=ll_newLinkedList();
    if(listaVacunas!=NULL)
    {
        do
        {
            if(!getNumero(&menuOpcion,
                "1) CARGAR archivo.\n"
                "2) IMPRIMIR lista.\n"
                "3) ASIGNAR estadisticas.\n"
                "4) FILTRAR paises copados.\n"
                "5) FILTRAR paises en el horno.\n"
                "6) ORDENAR por nivel de vacunacion.\n"
                "7) IMPRIMIR paises mas castigados.\n"
                "8) SALIR.\n\n"
                "Ingrese una opcion: ",
                "\nERROR Ingrese una opcion valida(1-8).\n",1,8))
            {
                switch(menuOpcion)
                {
                case 1:
                    getPath("\n**Bienvenido a la carga de datos en modo texto**\nIngrese el nombre del archivo(data.csv): ",path);
                    if(!controller_loadFromText(path,listaVacunas))
                    {
                        printf("\n\nEl archivo a sido cargado con exito!\n\n");
                    }
                    else
                    {
                        printf("\nERROR al cargar el archivo.\n");
                    }
                    break;
                case 2:
                    if(!controller_listPaises(listaVacunas))
                    {
                        printf("\n\nLa lista se mostro con exito!\n\n");
                    }
                    else
                    {
                        printf("\nERROR al mostrar la lista.\n\n");
                    }
                    break;
                case 3:
                    listaVacunas=ll_map(listaVacunas,randomVac1);
                    listaVacunas=ll_map(listaVacunas,randomVac2);
                    listaVacunas=ll_map(listaVacunas,porcentajeSinVacunar);
                    break;
                case 4:
                    break;
                case 8:
                    if(!getDosChar("\nSalir?(S/N): ","\nERROR ingrese S o N.\n",'s','n'))
                    {
                        salir='s';
                    }
                    else
                    {
                        salir='n';
                    }
                    break;
                }
            }
        }while(salir!='s');
    }

    return 0;
}

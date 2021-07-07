#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "misFuncionesGet.h"
#include "LinkedList.h"
#include "pais.h"
#include "controller.h"

ePais* pais_new()
{
	ePais* aux;

	aux= (ePais*) malloc (sizeof(ePais));
	if(aux!=NULL)
	{
		aux->id=0;
		strcpy(aux->nombre, " ");
        aux->vac1dosis=0;
        aux->vac2dosis=0;
        aux->sinVacunar=0;
	}

	return aux;
}
ePais* pais_newParametros(char* idStr,char* nombreStr,char* vac1Str, char* vac2Str,char* sinVacStr)
{
	ePais* aux;
	aux=pais_new();

	if(aux!=NULL && idStr!=NULL && nombreStr!=NULL && vac1Str!=NULL && vac2Str!=NULL && sinVacStr!=NULL)
	{
		if(!(pais_setId(aux,atoi(idStr))==0
            &&pais_setNombre(aux,nombreStr)==0
            &&pais_setVac1(aux,atoi(vac1Str))==0
            &&pais_setVac2(aux,atoi(vac2Str))==0
            &&pais_setSinVac(aux,atoi(sinVacStr))==0))
		{
			free(aux);
			aux=NULL;
		}
	}

	return aux;
}
///
///SETTERS
int pais_setId(ePais* this,int id)
{
    int error=1;

    if(this!=NULL && id>=0)
    {
        this->id=id;
        error=0;
    }

    return error;
}
int pais_setNombre(ePais* this,char* nombre)
{
	int error=1;

	if(this!=NULL && strlen(nombre)<100 && strlen(nombre)>1 )
	{
		strcpy(this->nombre,nombre);
		error=0;
	}

	return error;
}

int pais_setVac1(ePais* this,int vac1)
{
	int error=1;

	if(this!=NULL && vac1>=0)
	{
		this->vac1dosis=vac1;
		error=0;
	}

	return error;
}

int pais_setVac2(ePais* this,int vac2)
{
	int error=1;

	if(this!=NULL && vac2>=0)
	{
		this->vac2dosis=vac2;
		error=0;
	}

	return error;
}
int pais_setSinVac(ePais* this,int sinVac)
{
	int error=1;

	if(this!=NULL && sinVac>=0)
	{
		this->sinVacunar=sinVac;
		error=0;
	}

	return error;
}
///
///GETTERS
int pais_getId(ePais* this,int* id)
{
	int error=1;

	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		error=0;
	}

	return error;
}

int pais_getNombre(ePais* this,char* nombre)
{
	int error=1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		error=0;
	}

	return error;
}

int pais_getVac1(ePais* this,int* vac1)
{
	int error=1;

	if(this!=NULL && vac1!=NULL)
	{
		*vac1=this->vac1dosis;
		error=0;
	}

	return error;
}

int pais_getVac2(ePais* this,int* vac2)
{
	int error=1;

	if(this!=NULL && vac2!=NULL)
	{
		*vac2=this->vac2dosis;
		error=0;
	}

	return error;
}
int pais_getSinVac(ePais* this,int* sinVac)
{
	int error=1;

	if(this!=NULL && sinVac!=NULL)
	{
		*sinVac=this->sinVacunar;
		error=0;
	}

	return error;
}
///
///
int numAleatorio(int a,int b)
{
    int resultado;

    resultado=rand()%(a-b+1)+b;

    return resultado;
}
int randomVac1(void* pais)
{
    int error=0;
    int resultado;
    int min=1;
    int max=60;

    ePais* pais1;
    if(pais!=NULL)
    {
        pais1=(ePais*)pais;
        resultado=numAleatorio(max,min);
        if(resultado>=min && resultado<=max)
        {
            pais1->vac1dosis=resultado;
            error=1;
        }
    }

    return error;
}
int randomVac2(void* pais)
{
    int error=0;
    int resultado;
    int min=1;
    int max=40;

    ePais* pais2;
    if(pais!=NULL)
    {
        pais2=(ePais*)pais;
        resultado=numAleatorio(max,min);
        if(resultado>=min && resultado<=max)
        {
            pais2->vac2dosis=resultado;
            error=1;
        }
    }

    return error;
}

int porcentajeSinVacunar(void* pais)
{
    int error=0;
    int vac1;
    int vac2;
    int resultado;

    ePais* pais1;
    if(pais!=NULL)
    {
        pais1=(ePais*)pais;
        vac1=pais1->vac1dosis;
        vac2=pais1->vac2dosis;
        resultado=100-(vac1+vac2);
        if(resultado>=0 && resultado<=100)
        {
            pais1->sinVacunar=resultado;
            error=1;
        }
    }

    return error;
}

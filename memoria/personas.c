#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personas.h"
#include "validaciones.h"

Personas* Per_new(void)
{
    return (Personas*) malloc(sizeof(Personas));
}

Personas* Per_newStr(char* id,
                     char* nombre[50],
                     char* apellido[50],
                     char* estado)
{
    Personas* retorno = NULL;
    Personas* pAuxPersonas;

    if( id != NULL && nombre != NULL &&
        apellido != NULL & estado != NULL)
    {
        pAuxPersonas = Per_new();
        if(pAuxPersonas != NULL)
        {
            if( !Per_setNombre(pAuxPersonas, nombre) &&
                !Per_setApellido(pAuxPersonas, apellido)
                !Per_setIdStr(pAuxPersonas, id) &&
                !Per_setEstadoStr(pAuxPersonas, estado))
            {
                retorno = pAuxPersonas;
            }
            else
            {
                Per_delete(pAuxPersonas);
            }
        }
    }
}

int Per_delete(Personas* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int Per_setId(Personas* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int Per_setIdStr(Personas* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL && !isValidNumber(id))
    {
        retorno = Per_setId(this, atoi(id));
    }
    return retorno;
}

int Per_getId(Personas* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}

int Per_getIdStr(Personas* this, char* resultado)
{
    int retorno = -1;
    int bufferInt;

    if(this != NULL && resultado != NULL)
    {
        Emp_getId(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt)
        retorno = 0;
    }
    return retorno;
}

int Per_setNombre(Personas* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre >= 0)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

int Per_getNombre(Personas* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(this->nombre,resultado);
        retorno = 0;
    }
    return retorno;
}

int Per_setApellido(Personas* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido >= 0)
    {
        strcpy(this->apellido, apellido);
        retorno = 0;
    }
    return retorno;
}

int Per_getApellido(Personas* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(this->apellido,resultado);
        retorno = 0;
    }
    return retorno;
}

int Per_setEstado(Personas* this, int estado)
{
    int retorno = -1;
    if(this != NULL && estado >= 0)
    {
        this->estado = estado;
        retorno = 0;
    }
    return retorno;
}

int Per_getEstado(Personas* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->estado;
        retorno = 0;
    }
    return retorno;
}

//int isValidName(char* stringRecibido)   //si fuera un numero podrìa necesitar parametros para validar max y min
//{
//    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
//    int i;
//    for(i=0;stringRecibido[i]!='\0';i++)
//    {
//        //printf("%d",i);
//        if(stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z')// o ((stringRecibido[i]<'A' || (stringRecibido[i]>'Z') && (stringRecibido[i]<'a' || stringRecibido[i]>'z'))
//        {
//            retorno=0;
//            break;
//        }
//    }
//    return retorno;
//}

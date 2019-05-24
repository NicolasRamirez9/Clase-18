#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int getString(char* msg,char* msgE,int minimo,int maximo,int reintentos,char* resultado)
{
    int ret = -1;
    char bufferStr[400];
    if(msg != NULL && msgE != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
    {
        do
        {
            printf("\n%s",msg);
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr) >= minimo && strlen(bufferStr)<maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                ret = 0;
                break;
            }
            else
            {
                printf("\n%s",msgE);
            }
            reintentos --;
        }
        while(reintentos>0);
    }
    return ret;
}

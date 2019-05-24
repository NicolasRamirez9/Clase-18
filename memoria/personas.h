#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    int estado;
}Personas;

Personas* Per_new(void);
Personas* Per_newStr(char* id,
                     char* nombre[50],
                     char* apellido[50],
                     char* estado);

int Per_delete(Personas* this);

int Per_setId(Personas* this, int id);
int Per_getId(Personas* this, int* resultado);
int Per_setNombre(Personas* this, char* nombre);
int Per_getNombre(Personas* this, char* resultado);
int Per_setApellido(Personas* this, char* apellido);
int Per_getApellido(Personas* this, char* resultado);
int isValidName(char* stringRecibido);
int Per_setEstado(Personas* this, int estado);
int Per_getEstado(Personas* this, int* resultado);


#endif // PERSONAS_H_INCLUDED

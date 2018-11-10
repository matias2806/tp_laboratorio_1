#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(int* idStr,char* nombreStr,int* horasTrabajadasStr, int* sueldo);
void employee_delete(Employee* lista);

int employee_setId(Employee* lista,int id);
int employee_getId(Employee* lista,int* id);

int employee_setNombre(Employee* lista,char* nombre);
int employee_getNombre(Employee* lista,char* nombre);

int employee_setHorasTrabajadas(Employee* lista,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* lista,int* horasTrabajadas);

int employee_setSueldo(Employee* lista,int sueldo);
int employee_getSueldo(Employee* lista,int* sueldo);



int employee_OrdenaEnteroID(void* elementoA, void* elementoB);
int employee_OrdenaEnteroHoras(void* elementoA, void* elementoB);
int employee_OrdenaEnteroSueldo(void* elementoA, void* elementoB);
int employee_OrdenaCadenaNombre(void* elementoA, void* elementoB);


#endif // employee_H_INCLUDED

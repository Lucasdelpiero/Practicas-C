#ifndef HEADER_18E0D4663C5B0A76
#define HEADER_18E0D4663C5B0A76

#define MAX_LONG_NOMBRE 50

typedef struct {
    char nombre[MAX_LONG_NOMBRE];
    char apellido[MAX_LONG_NOMBRE];
} persona;

persona NuevaPersona(char nombre[MAX_LONG_NOMBRE], char apellido[MAX_LONG_NOMBRE]);
void MostrarNombreCompleto(persona P);
#endif // header guard 


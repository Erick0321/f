#include <stdio.h>

#define ESTUDIANTES 5
#define ASIGNATURAS 3
#define NOTA_APROBATORIA 6.0

void ingresarCalificaciones(float notas[ESTUDIANTES][ASIGNATURAS]);

int main() {
    float notas[ESTUDIANTES][ASIGNATURAS];

    printf("Sistema de gestion de calificaciones\n");

    return 0;
}
void ingresarCalificaciones(float notas[ESTUDIANTES][ASIGNATURAS]) {
    int i, j;
    float nota;

    for (i = 0; i < ESTUDIANTES; i++) {
        for (j = 0; j < ASIGNATURAS; j++) {
            do {
                printf("Estudiante %d, Asignatura %d: ", i + 1, j + 1);
                scanf("%f", &nota);
            } while (nota < 0 || nota > 10);

            notas[i][j] = nota;
        }
    }
}
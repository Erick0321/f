#include <stdio.h>

#define ESTUDIANTES 5
#define ASIGNATURAS 3
#define NOTA_APROBATORIA 6.0

void ingresarCalificaciones(float notas[ESTUDIANTES][ASIGNATURAS]);

int main() {
    float notas[ESTUDIANTES][ASIGNATURAS];

    printf("Sistema de gestion de calificaciones\n");

    ingresarCalificaciones(notas);
    mostrarTabla(notas);

    return 0;
}
void ingresarCalificaciones(float notas[ESTUDIANTES][ASIGNATURAS]) {
    int i, j;
    float nota;

    for (i = 0; i < ESTUDIANTES; i++) {
        for (j = 0; j < ASIGNATURAS; j++) {
            do {
                scanf("%f", &nota);
            } while (nota < 0 || nota > 10);

            notas[i][j] = nota;
        }
    }
}

void mostrarTabla(float notas[ESTUDIANTES][ASIGNATURAS]) {
    int i, j;

    printf("TABLA DE CALIFICACIONES\n");

    for (i = 0; i < ESTUDIANTES; i++) {
        printf("Estudiante %d: ", i + 1);
        for (j = 0; j < ASIGNATURAS; j++) {
            printf("%.1f ", notas[i][j]);
        }
        printf("\n");
    }
}
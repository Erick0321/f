#include <stdio.h>

#define ESTUDIANTES 5
#define ASIGNATURAS 3
#define NOTA_APROBATORIA 6.0

void ingresarCalificaciones(float notas[ESTUDIANTES][ASIGNATURAS]);
void mostrarTabla(float notas[ESTUDIANTES][ASIGNATURAS]);
void calcularPromedioEstudiante(float notas[ESTUDIANTES][ASIGNATURAS]);
void calcularPromedioAsignatura(float notas[ESTUDIANTES][ASIGNATURAS]);
void calcularMaxMin(float notas[ESTUDIANTES][ASIGNATURAS]);
void calcularAprobados(float notas[ESTUDIANTES][ASIGNATURAS]);

int main() {
    float notas[ESTUDIANTES][ASIGNATURAS];

    printf("Sistema de gestion de calificaciones\n");

    ingresarCalificaciones(notas);
    mostrarTabla(notas);
    calcularPromedioEstudiante(notas);
    calcularPromedioAsignatura(notas);
    calcularMaxMin(notas);
    calcularAprobados(notas);

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

    for (i = 0; i < ESTUDIANTES; i++) {
        printf("Estudiante %d: ", i + 1);
        for (j = 0; j < ASIGNATURAS; j++) {
            printf("%.1f ", notas[i][j]);
        }
        printf("\n");
    }
}

void calcularPromedioEstudiante(float notas[ESTUDIANTES][ASIGNATURAS]) {
    int i, j;
    float suma, promedio;

    for (i = 0; i < ESTUDIANTES; i++) {
        suma = 0;
        for (j = 0; j < ASIGNATURAS; j++) {
            suma += notas[i][j];
        }
        promedio = suma / ASIGNATURAS;
        printf("Estudiante %d: %.2f\n", i + 1, promedio);
    }
}

void calcularPromedioAsignatura(float notas[ESTUDIANTES][ASIGNATURAS]) {
    int i, j;
    float suma, promedio;

    for (j = 0; j < ASIGNATURAS; j++) {
        suma = 0;
        for (i = 0; i < ESTUDIANTES; i++) {
            suma += notas[i][j];
        }
        promedio = suma / ESTUDIANTES;
        printf("Asignatura %d: %.2f\n", j + 1, promedio);
    }
}

void calcularMaxMin(float notas[ESTUDIANTES][ASIGNATURAS]) {
    int i, j;
    float maxEst, minEst, maxAsig, minAsig;

    for (i = 0; i < ESTUDIANTES; i++) {
        maxEst = minEst = notas[i][0];
        for (j = 1; j < ASIGNATURAS; j++) {
            if (notas[i][j] > maxEst) maxEst = notas[i][j];
            if (notas[i][j] < minEst) minEst = notas[i][j];
        }
        printf("Estudiante %d -> Max: %.1f Min: %.1f\n", i + 1, maxEst, minEst);
    }

    for (j = 0; j < ASIGNATURAS; j++) {
        maxAsig = minAsig = notas[0][j];
        for (i = 1; i < ESTUDIANTES; i++) {
            if (notas[i][j] > maxAsig) maxAsig = notas[i][j];
            if (notas[i][j] < minAsig) minAsig = notas[i][j];
        }
        printf("Asignatura %d -> Max: %.1f Min: %.1f\n", j + 1, maxAsig, minAsig);
    }
}

void calcularAprobados(float notas[ESTUDIANTES][ASIGNATURAS]) {
    int i, j, aprobados, reprobados;

    for (j = 0; j < ASIGNATURAS; j++) {
        aprobados = 0;
        reprobados = 0;

        for (i = 0; i < ESTUDIANTES; i++) {
            if (notas[i][j] >= NOTA_APROBATORIA)
                aprobados++;
            else
                reprobados++;
        }

        printf("Asignatura %d -> Aprobados: %d Reprobados: %d\n",
               j + 1, aprobados, reprobados);
    }
}
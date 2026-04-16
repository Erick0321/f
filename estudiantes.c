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
    printf("==============================================\n");
    printf("   SISTEMA DE GESTION DE CALIFICACIONES\n");
    printf("==============================================\n\n");
    
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
    printf("Ingrese las calificaciones (0 a 10):\n");
    printf("----------------------------------------------\n");

    for (i = 0; i < ESTUDIANTES; i++) {
        printf("\n  Estudiante %d:\n", i + 1);
        for (j = 0; j < ASIGNATURAS; j++) {
            do {
                printf("    Asignatura %d: ", j + 1);
                scanf("%f", &nota);
                if (nota < 0 || nota > 10) {
                    printf("    *** ERROR: La nota debe estar entre 0 y 10. Intente de nuevo.\n");
                }
            } while (nota < 0 || nota > 10);
            notas[i][j] = nota;
        }
    }
    printf("\n");
}

void mostrarTabla(float notas[ESTUDIANTES][ASIGNATURAS]) {
    int i, j;
    printf("==============================================\n");
    printf("         TABLA DE CALIFICACIONES\n");
    printf("==============================================\n");
    printf("%-15s", "");
    for (j = 0; j < ASIGNATURAS; j++) printf("  Asig.%d", j + 1);
    printf("\n----------------------------------------------\n");
    for (i = 0; i < ESTUDIANTES; i++) {
        printf("Estudiante %-4d", i + 1);
        for (j = 0; j < ASIGNATURAS; j++) printf("    %.1f ", notas[i][j]);
        printf("\n");
    }
    printf("\n");
}

void calcularPromedioEstudiante(float notas[ESTUDIANTES][ASIGNATURAS]) {
    int i, j;
    float suma, promedio;
    printf("==============================================\n");
    printf("       PROMEDIO POR ESTUDIANTE\n");
    printf("==============================================\n");
    for (i = 0; i < ESTUDIANTES; i++) {
        suma = 0;
        for (j = 0; j < ASIGNATURAS; j++) suma += notas[i][j];
        promedio = suma / ASIGNATURAS;
        printf("  Estudiante %d: %.2f\n", i + 1, promedio);
    }
    printf("\n");
}

void calcularPromedioAsignatura(float notas[ESTUDIANTES][ASIGNATURAS]) {
    int i, j;
    float suma, promedio;
    printf("==============================================\n");
    printf("       PROMEDIO POR ASIGNATURA\n");
    printf("==============================================\n");
    for (j = 0; j < ASIGNATURAS; j++) {
        suma = 0;
        for (i = 0; i < ESTUDIANTES; i++) suma += notas[i][j];
        promedio = suma / ESTUDIANTES;
        printf("  Asignatura %d: %.2f\n", j + 1, promedio);
    }
    printf("\n");
}

void calcularMaxMin(float notas[ESTUDIANTES][ASIGNATURAS]) {
    int i, j;
    float maxEst, minEst, maxAsig, minAsig;
    printf("==============================================\n");
    printf("     CALIFICACION MAXIMA Y MINIMA\n");
    printf("==============================================\n");

    printf("\n  Por estudiante:\n");
    for (i = 0; i < ESTUDIANTES; i++) {
        maxEst = minEst = notas[i][0];
        for (j = 1; j < ASIGNATURAS; j++) {
            if (notas[i][j] > maxEst) maxEst = notas[i][j];
            if (notas[i][j] < minEst) minEst = notas[i][j];
        }
        printf("    Estudiante %d -> Max: %.1f  Min: %.1f\n", i+1, maxEst, minEst);
    }

    printf("\n  Por asignatura:\n");
    for (j = 0; j < ASIGNATURAS; j++) {
        maxAsig = minAsig = notas[0][j];
        for (i = 1; i < ESTUDIANTES; i++) {
            if (notas[i][j] > maxAsig) maxAsig = notas[i][j];
            if (notas[i][j] < minAsig) minAsig = notas[i][j];
        }
        printf("    Asignatura %d -> Max: %.1f  Min: %.1f\n", j+1, maxAsig, minAsig);
    }
    printf("\n");
}

void calcularAprobados(float notas[ESTUDIANTES][ASIGNATURAS]) {
    int i, j, aprobados, reprobados;
    printf("==============================================\n");
    printf("    APROBADOS Y REPROBADOS POR ASIGNATURA\n");
    printf("==============================================\n");

    for (j = 0; j < ASIGNATURAS; j++) {
        aprobados = reprobados = 0;
        for (i = 0; i < ESTUDIANTES; i++) {
            if (notas[i][j] >= NOTA_APROBATORIA) aprobados++;
            else reprobados++;
        }
        printf("  Asignatura %d: %d aprobados, %d reprobados\n", j+1, aprobados, reprobados);
    }
    printf("\n");
}
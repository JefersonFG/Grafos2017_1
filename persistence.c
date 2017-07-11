#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persistence.h"

#define MAX_LINE_SIZE 50

void getGraphSize(char *fileName, int *graphSize) {
    FILE *pFile;
    char line[MAX_LINE_SIZE];
    char separator[2] = " ";
    char *token;

    pFile = fopen(fileName, "r");

    if (pFile == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    if (fgets(line, MAX_LINE_SIZE, pFile) == NULL) {
        printf("Error reading from file\n");
        exit(1);
    }

    fclose(pFile);

    token = strtok(line, separator);
    graphSize[0] = strtol(token, NULL, 10);
    token = strtok(NULL, separator);
    graphSize[1] = strtol(token, NULL, 10);
}

void readInputFile(char *fileName, int numEdges, struct Graph *graph) {
    FILE *pFile;
    char line[MAX_LINE_SIZE];
    char separator[2] = " ";
    char *token;
    int vertex1, vertex2;
    int i;

    pFile = fopen(fileName, "r");

    if (pFile == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    if (fgets(line, MAX_LINE_SIZE, pFile) == NULL) {
        printf("Error reading from file\n");
        exit(1);
    }

    for (i = 0; i < numEdges; i++) {
        if (fgets(line, MAX_LINE_SIZE, pFile) == NULL) {
            printf("Error reading from file\n");
            exit(1);
        }

        token = strtok(line, separator);
        vertex1 = strtol(token, NULL, 10);
        token = strtok(NULL, separator);
        vertex2 = strtol(token, NULL, 10);

        addEdge(graph, vertex1, vertex2);
    }

    fclose(pFile);
}

#include <stdio.h>
#include "persistence.h"
#include "graph_processing.h"

int main() {
    printf("Debug: main\n");
    getGraphSize("Teste");
    readInputFile("Teste", 0);
    numOfConnectedComponentsBfs(0, 0, 0);
    numOfConnectedComponentsDfs(0, 0, 0);
    distancesBfs(0, 0, 0);
    distancesDfs(0, 0, 0);
    return 0;
}
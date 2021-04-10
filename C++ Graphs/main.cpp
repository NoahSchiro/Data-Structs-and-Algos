#include "graph.cpp"    //Graph Class
#include <stdlib.h>     //Random Numbers
#include <time.h>       //Random Numbers

int main() {

    srand(time(NULL));

    node start(rand()%100,rand()%100);
    graph g(start);

    //Create a graph of 10 nodes in total
    for(int i = 0; i < 9; i++) {
        g.addNode(rand()%100,rand()%100);
    }

    //Creat 5 random connections
    for(int i = 0; i < 5; i++) {

        //Picks two random nodes out of all nodes in graph
        int searchSpace = g.allNodes.size();
        node temp1 = g.allNodes[ (rand() % searchSpace) ];
        node temp2 = g.allNodes[ (rand() % searchSpace) ];

        g.addConnection(temp1, temp2);
    }

    g.showNodes();

    g.showMatrix();

    return 0;
}
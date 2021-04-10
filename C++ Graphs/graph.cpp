#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

class node {
    public:
        //Assume the data in our graph 
        //is just the nodes location on 
        //a 2d plane (assume a space of
        //1000, 1000 pixels)
        int location[2];

        node(int x, int y) {
            location[0] = x;
            location[1] = y;
        }

    friend class graph;
};

class graph {
    public:

    std::vector<node> allNodes;
    std::vector<std::vector<bool>> adjMat;

    //Constructor
    graph(node start) {
        allNodes.push_back(start);

        std::vector<bool> temp = {false};
        adjMat.push_back(temp);
    }

    //Returns whether or not a node is in the graph
    bool inGraph(node input) {

        for(int i = 0; i < allNodes.size(); i++) {
            
            if(input.location[0] == allNodes[i].location[0] && input.location[1] == allNodes[i].location[1]){
                return true;
            }
        }

        return false;
    }

    void addNode(int inputX, int inputY) {

        //Create node with given values
        node input(inputX, inputY);
        //Add node to graph
        allNodes.push_back(input);

        //Expand each ROW of the matrix to include new node
        for(int i = 0; i < adjMat.size(); i++) {
            adjMat[i].push_back(false);
        }

        //Add an additional row to the 
        //matrix to include the new node
        std::vector<bool> temp;
        for(int i = 0; i <= adjMat.size(); i++) {
            temp.push_back(false);
        }

        adjMat.push_back(temp);
    }

    void deleteNode(node input);
    
    void addConnection(node one, node two) {

        //Determines if these nodes are even in the graph
        if(inGraph(one) && inGraph(two)) {

            //Find where they are in our allNodes vector
            int onePosition, twoPosition;
            for(int i = 0; i < allNodes.size(); i++) {
                if(one.location[0] == allNodes[i].location[0] && one.location[1] == allNodes[i].location[1]) {
                    onePosition = i;
                }

                if(two.location[0] == allNodes[i].location[0] && two.location[1] == allNodes[i].location[1]) {
                    twoPosition = i;
                }
            }

            adjMat[onePosition][twoPosition] = 1;
            adjMat[twoPosition][onePosition] = 1;
        }
        
    }

    void deleteConnection(node one, node two);

    void showNodes(){

        for(int i = 0; i < allNodes.size(); i++) {
            std::cout << "(" << allNodes[i].location[0] << ", " 
                             << allNodes[i].location[1] << ")\n";
        }
    }

    void showMatrix() {

        for(int i = 0; i < adjMat.size(); i++) {
            for(int j = 0; j < adjMat[i].size(); j++) {
                std::cout << adjMat[i][j] << "\t";
            }
            std::cout << "\n";
        }
    }
};

#endif
/**
 * 
 * @Date: 4-28-15
 * @Author: Jake Hayhurst
 */
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
/**
 * finds the index of the minimum distance value of the verticies not yet in the shortest path tree. 
 * Will check if the edge weight is negative to make sure that an autobahn is chosen over a normal road
 */
int minDistance(int distance[], bool shortestPath[],int numberOfNodes){
    int min = INT_MAX;
    int minIndex;
    for (int i = 0; i < numberOfNodes, i++){
        if (shortestPath[i] == false && distance[i] <= min && distance[i] > 0){
            min = distance[i];
            minIndex = i; 
        }
        if (shortestPath[i] == false && distance[i] <= min && distance[i] < 0){
            if (std::abs(distance) <=min){
                min = distance[i];
                minIndex = i;
            }
        }
    }
    return minIndex;
}

/**
 * This is the cipher to change the char values to the corrisponding integer values to be used in dijkstra's algorithim 
 */
int cipherCharToInt(char charMatrix[], char to){
    for (int i = 0; i< charMatrix.size(); i++){
        if (to == charMatrix[i]) return i;
    }
}

/**
 * This method prints the results of the dijkstra algorithim 
 */
void printResult(int start, int end, int distance, int autoBahnKM, char charMatrix[]){
    char charStart = charMatrix[start];
    char charEnd = charMatrix[end];
    std::cout << charStart << " " << charEnd << " " << distance << " " << autoBahnKM << std::endl;
}

/**
 * Uses dijkstra's algorithim to check for all the distances from a starting part and then has an array 
 * containing all the distances to the nodes.
 * Calls the printResults() method to print the result of the shortest path from the src to the end
 */
void dijkstra(int adjMatrix[][], int src, int end, bool autoBahnIndex[][], int numberOfNodes, char charMatrix[]){
    int distance[numberOfNodes];
    bool shortestPath[numberOfNodes];       
    for (int i = 0; i < numberOfNodes; i++){
        distance[i] = INT_MAX;
        shortestPath[i] = false;
    }
    //the distance from a node to itself will always be zero
    distance[src] = 0;
    
    for (int k= 0; count < numberOfNodes; k++){
        int mindex = minDistance(distance, shortestPath, numberOfNodes);
        //will mark the index as being used in the shortest path
        shortestPath[mindex] = true;

        for (int j = 0; j < numberOfNodes; j++){
            if (!shortestPath[j] && std::(adjMatrix[mindex][j]) && std::abs(distance[mindex]) != INT_MAX && std::abs(distance[mindex]) + std::abs(adjMatrix[mindex][j]) < std::abs(distance[j])){
                //makes sure that the distance that is added is not negative 
                distance[j] = std::abs(distance[mindex]) + std::abs(adjMatrix[mindex][j]); 
                if (autoBahnIndex[mindex][j]){
                    //Adds the traveled miles from the adjMatrix to the total autoBahn miles if their is an autoBahn path at that location
                    autoBahnKM += std::abs(adjMatrix[mindex][j]);
                }
            }
            
        }
    }
    printResult(start, end, distance[end], autoBahnKM, charMatrix); 
}




/**
 * Implements the adjMatrix to have negative edges to make checking for auto Bahn easier.
 * A cipher will be implemented that will make the use of dijkstra's algo using an array of ints rather than chars to make implementation easier.
 * 
 */
int main(){
    int numberOfNodes;
    std::cin >> numberOfNodes;
    char charMatrix[numberOfNodes];
    for (int i = 0, i < numberOfNodes; i++)
        std::cin <<charMatrix[i];

    //Imagine a cycpher that will take the char and convert it to the corrisponding value within the charMatrix
    //This will be used for taking in values within the dijktra algorithim
    
    int numberOfEdges;
    cin >> numberOfEdges;
    int adjMatrix[numberOfNodes][numberOfNodes];
    bool autoBahnIndex[numberOfNodes][numberOfNodes];
    
    //Inits the autoBahnIndex to be false 
    for (int k = 0; k < numberofNodes; k++)
        for (int l = 0; l < numberOfNodes; l++)
            autoBahnIndex[k][l] = false;

    for (int j = 0; j < numberOfEdges; j++){

        char charStart;
        char charEnd;
        int distance;
        int start;
        int end;
        char autoBahn;

        std::cin << charStart;
        std::cin << charEnd;
        std::cin << distance;
        std::cin << autoBahn;
        
        start = cipherCharToInt(charMatrix, charStart);
        end = cipherCharToInt(charMatrix, charEnd);
               
        if (autoBahn == a){
            //If the road is autobahn then the edge weight for the distance will be negative 
            adjMatrix[start][end] = distance *-1;
            adjMatrix[end][start] = distance *-1;
            autoBahnIndex[start][end] = true;
            autoBahnIndex[end][start] = true;
        }
        else{
            adjMatrix[start][end] = distance;
            adjMatrix[end][start] = distance;
        }
    }
    int numberOfShortestPaths;
    std::cin << numberOfShortestPaths;
    
    for (int m = 0; m < numberOfShortestPaths; m++){
        char charStart;
        char charEnd;
        int start;
        int end;
        
        std::cin << start;
        std::cin << end;
        
        start = cipherCharToInt(charMatrix, charStart);
        end = cipherCharToInt(charMatrix, charEnd);
                
        dijkstra(adjMatrix, start, end, autoBahnIndex, numberOfNodes, charMatrix);
    }      
}        



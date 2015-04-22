/** Each test case will begin with a line with two integers n ( 1 <= n <= 2,000) and m (1 <= m <= 50,000), Where n is the number of tasks, and m is the number of relationships between items 
 * On each of the next m lines will be two integers, d and u (1 <= u, d <= n, d != u) which indicate that collecting item or preforming action d allows access to item or action u.
 * The input will end with two 0's on their own line. 
 *
 *@Date: 4-20-15
 *@Author: Jake Hayhurst
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <list>

/**
 * Recursively calls the function to check if the node has been not visited.
 * If it has not been visited then sets visited in the bool stack to be true and the recStack to be true as well to check later in recursive calls.
 * then loops through each node to check for the next node using DFS. If the node loops onto itself i.e. you need 4 to unlock 4 then it would be cyclic. If the child node is not visited and the child node using the recursive call is able to make it back to the child then it will be cyclic.
 */
bool isCyclicRecursive(std::vector<int> *pMatrix, int V, bool visited[], bool *recStack){
    if (visited[V] == false){
        visited[V] = true;
        recstack[V] = true;
                
        for(std::vector<int>::const_iterator i = pMatrix[V].begin(); i != pMatrix[V].end(); ++i){
            if (*i == V) return true;
            if (!visited[*i] && isCyclicRecursive(*i, visited, recStack))
                return true;
            else if (recStack[*i])
                return true; 
        }
    }
    recStack [V] = false;
    return false;
}

/**
 * This method will check if the adjMatrix is cyclic or not
 * It inits the visited and recStack matrixes to false as they have not visited any node
 */
bool isCyclic(std::vector<int> *pMatrix, int V){  
    
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for (int i = 1; i < V; i ++){
        visited[i] = false;
        recStack[i] = false;
    }   
    for (int i = 1; i < V; i++)
        if (isCyclicRecursive(pMatrix,i, visited, recStack))
            return true;
    return false;   
}

/**
 * This method will check id the adjMatrix is linear or not.
 * If the node has more than one child then it would be non linear gameplay thus would not be linear.
 */
bool isLinear(std::vector<int> *pMatrix, int V){
    //TODO Implement Method
    
    //This loop checks if the matrix has multiple children connecting it 
    //if the loop has multiple children then the gameplay is non linear    
    for (int k = 1; k < V; k++)
        if (pMatrix[k].size() > 1) 
            return false;
    
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for (int i = 1; i < V; i ++){
        visited[i] = false;
        recStack[i] = false;
    }
          
}

/**
 * Main method for determining gameplay type
 */
int main(int argc,char*  argv[]){

    //This initalizes the variables for use
    int d = 0; //D allows access to item or action U
    int u = 0; //U is the item or action 
    int n = 0; //N is the number of items or tasks
    int m = 0; //M is the number of relations between items
    //Ends initilization of the variables
    
    int i = 1;
    while (atoi(argv[i]) != 0 || atoi(argv[i+1]) != 0){
        //This loop inits values N and M and then incriments 
        n = atoi(argv[i]);
        m = atoi(argv[i+1]);
        
        std::vector<int> *adjMatrix = new std::vector<int> [n+1];
        int k = i +2;
        for (int j = 0; j < m*2; j+=2){
            //This loop goes through the D and U variables and does something with them
            d = atoi(argv[k+j]);
            u = atoi(argv[k+1+j]);
            
            adjMatrix[d].push_back(u);        
                       
        }
        //printVector(adjMatrix, n+1);

        //This checks for what type of gameplay is possible
        if (isCyclic(adjMatrix, n+1)){ 
            std::cout << "Infeasable Game" << std::endl;
        }
        else if (isLinear(adjMatrix, n+1)){
            std::cout<< "Linear Gameplay" << std::endl;
        }
        else {
            std::cout << "Non-Linear Gameplay Possible" << std::endl;
        }
        
        //Incriments I to go to the next inputed value
        i += (atoi(argv[i+1])*2) + 2;
    }
    std::cout << "out of loop" << std::endl;
}


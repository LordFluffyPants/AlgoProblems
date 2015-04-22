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

void printVector(std::vector<int> *pMatrix, int V){
    for (int k = 1; k < V; k++){
    
        for(std::vector<int>::const_iterator i = pMatrix[k].begin(); i != pMatrix[k].end(); ++i){
        std::cout << *i << std::endl;
        }
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
        printVector(adjMatrix, n+1);
        i += (atoi(argv[i+1])*2) + 2;
    }
    std::cout << "out of loop" << std::endl;
}


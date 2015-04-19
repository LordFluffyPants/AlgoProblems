/* This might just be the most poorly written question i have ever read */

#include <iostream>
#include <string>
#include <stdlib.h>

int main(int argc,char*  argv[]){
    //This initalizes the variables for use
    int d = 0; //D allows access to item or action U
    int u = 0; //U is the item or action 
    int n = 0; //N is the number of items or tasks
    int m = 0; //M is the number of relations between items
    //Ends initilization of the variables
    //std::cout << argc << std::endl;
    int i = 1;
    while (atoi(argv[i]) != 0 || atoi(argv[i+1]) != 0){
        n = atoi(argv[i]);
        m = atoi(argv[i+1]);
        
        int k = i +2;
        for (int j = 0; j < m*2; j+=2){
            d = atoi(argv[k+j]);
            u = atoi(argv[k+1+j]);
            //std::cout << j << std::endl;
            std::cout << "D is " << d << std::endl;
            std::cout << "U is " << u << std::endl;
            
        }
        //std:: cout << i << std::endl; 
        i += (atoi(argv[i+1])*2) + 2; 
        //std::cout << i << std::endl;
        

    }
    std::cout << "out of loop" << std::endl;
}


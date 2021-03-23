/*
 * Title: hw2_2.cpp
 * Abstract: This program implements the Depth-First Search (DFS) 
             algorithm using a stack and a mark array.
 * Author: Justin Mello
 * ID: 2002
 * Date: 03/23/2021
*/
#include <iostream>
#include <vector>

using namespace std;

//Global counter
int counter = 0;

void depthRecursion(int index, vector<int> & countArray, vector<vector<int>> & graph) {
    
    int empty = 0;
    countArray[index] = ++counter;
    
    for(int i = 0; i < graph[index].size(); i++) {
        int result = graph[index][i];
        
        if(countArray[result] == empty)
            depthRecursion(result, countArray, graph);
        }
}

int main()
{
    
    //Inital variables
    int initial = 0;
    int vertices;
    int numOfEdges;
    int vertFrom;
    int vertTo;
    
    //Get vertices/edges, create graph.
    cin >> vertices;
    
    vector<vector<int>> graph (vertices);
    
    cin >> numOfEdges;
    
    
    //Populate with user provided values
    for(int i = 0; i < numOfEdges; i++) {
        cin >> vertFrom;
        cin >> vertTo;
        graph[vertFrom].push_back(vertTo);
    }
    
    //Search and Display
    vector <int> mark(graph.size(), initial);
    depthRecursion(initial, mark, graph);
    
    //Loop to display results
    for (int i = 0; i < graph.size(); i++){
		cout << "Mark[" << i << "]: " << mark[i] << endl;
	}
    
    
    return 0;
}


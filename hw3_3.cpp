#include <iostream>
#include <vector>


using namespace std;

//Global counter
int counter = 0;

void dfs(int index, vector<int> & countArray, vector<vector<int>> & graph) {
    
    countArray[index] = ++counter;
    
    for(int i = 0; i < graph[index].size(); i++) {
        int result = graph[index][i];
        
        if(countArray[result] == 0)
            dfs(result, countArray, graph);
        }
}

void dfs(vector<vector<int>> & graph) {
    
    int start = 0;
    vector <int> mark(graph.size(), start);
    
    dfs(start, mark, graph);
    
    for (int i = 0; i < graph.size(); i++){
		cout << "Mark[" << i << "]: " << mark[i] << endl;
	}
}


int main()
{
    
    //Inital variables
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
    dfs(graph);
    
    
    return 0;
}


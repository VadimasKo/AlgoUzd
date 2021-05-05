#include <iostream>
#include <vector>

class Graph{
    private:
        int size;
        std::vector<int> *adj;
        void DFS_helper(int node, bool visitedArray[]);
    public:
        Graph(int size);
        ~Graph();
        void addEdge(int node1, int node2);
        void DFS(int node);

};

Graph::Graph(int size){
    this->size = size;
    adj = new std::vector<int>[size];
}
Graph::~Graph(){
    delete[] adj;
}
void Graph::addEdge(int node1, int node2){
    adj[node1].push_back(node2);
}

void Graph::DFS(int node){
    bool visitedArray[size];
    for(int i=0; i<size; i++){
        visitedArray[i] = false;
    }

    DFS_helper(node,visitedArray);
}

void Graph::DFS_helper(int node, bool visitedArray[]){
    visitedArray[node] = true;

    for(auto i = adj[node].begin();i != adj[node].end(); i++){
        if(visitedArray[*i] == false){
            std::cout<<"traveling from node "<<node<<"to node"<<*i<<"\n";
            DFS_helper(*i,visitedArray);
        }
    }

}

int main(){
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);

    g.addEdge(1, 0);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    g.addEdge(2, 0);
    g.addEdge(2, 4);

    g.addEdge(3, 1);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    g.addEdge(4,1);
    g.addEdge(4, 2);
    g.addEdge(4, 3);
    g.addEdge(4, 5);

    g.addEdge(5, 3);
    g.addEdge(5, 4);

    g.DFS(4);
}
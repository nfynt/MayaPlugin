//Can be represented using either:
//> Adjacency matrix
//> Adjacency List

/**
 * Adjacency matrix space complexity: O(nxn), n-no of nodes/vertices
 * Pros: easier to implement; removing edge takes O(1) time; edge check op takes O(1)
 * Cons: more space; adding a vertex takes O(nxn);
 * 
 * Adjacency List, space complexity: O(|V| + |E|); Vertices and edges
 * Pros: saves space; adding a vertex is easier
 * Cons: Queries for finding edge is not efficient taken O(V)
 * */

#include <iostream>
#include <vector>

using namespace std;

void AddEdge(vector<int> graph[], int s, int e)
{
    graph[s].push_back(e);
}

void ShowGraph(vector<int> gr[], int vertices)
{
    for(int i=0;i<vertices;i++)
    {
        cout<<"["<<i<<"]";
        vector<int>::iterator it;
        for(it=gr[i].begin();it!=gr[i].end();it++)
        cout<<"->"<<*it;
        cout<<endl;
    }
}

int main()
{
    int V=5;
    cout<<"Enter no of vertices: ";
    cin>>V;
    vector<int> graph[V];
    cout<<"\nDefine graph edges entering start and end vertices in new lines\nEnter 0 0  to exit\n\n";
    int s,e;
    while(true)
    {
        cin>>s>>e;
        if(s==e || s==0) break;
        AddEdge(graph,s,e);
    }
    cout<<"\n\nGraph:\n";
    ShowGraph(graph,V);

    return 0;
}

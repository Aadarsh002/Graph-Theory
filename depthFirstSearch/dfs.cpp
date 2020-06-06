#include<iostream>
#define MAX 10

using namespace std;

void dfs(int graph[MAX][MAX],int source,int visited[MAX],int n)
{
	visited[source]=1;
	for(int i=0;i<n;i++)
	{
		if(graph[source][i] && !visited[i])
			dfs(graph,i,visited,n);
	}
}

int main()
{
	int graph[MAX][MAX],noOfV,visited[MAX],source,i,j;
	
	cout<<"Enter the number of vertices: ";
	cin>>noOfV;
	
	cout<<"Enter the adjacency matrix:"<<endl;
	for(i=0;i<noOfV;i++)
	{
		for(j=0;j<noOfV;j++)
		{
			cin>>graph[i][j];
		}
	}
	
	//mark all the vertices as unvisited
	for(i=0;i<noOfV;i++)
		visited[i]=0;
		
	cout<<"Enter the source vertex between 1 t0 "<<noOfV<<": ";
	cin>>source;
	
	//MAKE A dfs function A CALL
	dfs(graph,source,visited,noOfV);
	
	//disply the traversal of vertices
	for(i=0;i<noOfV;i++)
	{
		if(visited[i])
			cout<<"vertex "<<i+1<<" is visited"<<endl;
		else
			cout<<"vertex "<<i+1<<" is not visted"<<endl;
	}
	
	return 0;
}

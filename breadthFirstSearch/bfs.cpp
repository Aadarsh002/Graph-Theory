#include<iostream>
#include<queue>
#define MAX 10

using namespace std;

void bfs(int graph[MAX][MAX],int source,int visited[MAX],int n)
{
	queue <int> myQueue;
	
	int frontVertex;
	
	visited[source]=1;
	myQueue.push(source);
	while(!myQueue.empty())
	{
		frontVertex=myQueue.front();
		myQueue.pop();
		for(int i=0;i<n;i++)
		{
			if(graph[frontVertex][i] && !visited[i])
			{
				visited[i]=1;
				myQueue.push(i);
			}
		}
	}
}

int main()
{
	int noOfV,graph[MAX][MAX],source,visited[MAX],i,j;
	
	cout<<"Enter the number of vertices: ";
	cin>>noOfV;
	
	cout<<"Enter the adjacency matrix:"<<endl;
	for(i=0;i<noOfV;i++)
		for(j=0;j<noOfV;j++)
			cin>>graph[i][j];
			
	//mark all the vertices as unvisited
	for(i=0;i<noOfV;i++)
		visited[i]=0;
		
	cout<<"Enter the source vertex: ";
	cin>>source;
	
	bfs(graph,source,visited,noOfV);
	
	//dispaly reachable and not rechable vertices
	for(i=0;i<noOfV;i++)
	{
		if(visited[i])
			cout<<"vertex "<<i+1<<" is rechable"<<endl;
		else
			cout<<"vertex "<<i+1<<" is not rechable"<<endl;
	}
	
	return 0;
}

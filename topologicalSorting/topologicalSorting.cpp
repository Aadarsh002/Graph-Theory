#include<iostream>
#define MAX 10

using namespace std;

void jobVectorFxn(int jobVector[MAX],int n)
{
	cout<<"Topological Ordering are:"<<endl;
	for(int i=0;i<n;i++)
		cout<<jobVector[i]+1<<"	";
	cout<<endl;
}

void topologicalSorting(int graph[MAX][MAX],int n)
{
	int indegree[MAX],stack[MAX],top=-1,i,j,jobVector[MAX];
	int k=0;//for jobVector
	
	//calculate the indegree of vertices
	for(i=0;i<n;i++)
	{
		indegree[i]=0;
		for(j=0;j<n;j++)
		{
			if(graph[j][i])
				indegree[i]++;
		}
	}
	
	while(true)
	{
		for(i=0;i<n;i++)
		{
			if(indegree[i]==0)
			{
				top++;
				stack[top]=i;
				indegree[i]=-1;
			}
		}
		if(top==-1)//ckeck for stack empty
			break;
		
		jobVector[k]=stack[top--];
		
		for(i=0;i<n;i++)
		{
			if(graph[jobVector[k]][i])
				indegree[i]--;
		}
		k++;
	}
	//displaying jobVector
	jobVectorFxn(jobVector,k);
}

int main()
{
	int graph[MAX][MAX],noOfV,i,j;
	
	cout<<"Enter the number of vertices: ";
	cin>>noOfV;
	
	cout<<"Enter the adjacency matrix:"<<endl;
	for(i=0;i<noOfV;i++)
		for(j=0;j<noOfV;j++)
			cin>>graph[i][j];
			
	topologicalSorting(graph,noOfV);
	return 0;
}

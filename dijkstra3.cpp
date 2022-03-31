#include<bits/stdc++.h>
using namespace std ;

int cost[9][9] ={
        { 0, 4, 99, 99, 99, 99, 99, 8, 99 },
        { 4, 0, 8, 99, 99, 99, 99, 11, 99 },
        { 99, 8, 0, 7, 99, 4, 99, 99, 2 },
    	{ 99, 99, 7, 0, 9, 14, 99, 99, 99 },
        { 99, 99, 99, 9, 0, 10, 99, 99, 99 },
    	{ 99, 99, 4, 14, 10, 0, 2, 99, 99 },
    	{ 99, 99, 99, 99, 99, 2, 0, 1, 6 },
        { 8, 11, 99, 99, 99, 99, 1, 0, 7 },
    	{ 99, 99, 2, 99, 99, 99, 6, 7, 0 } 
	};
int n = 9  ; 

int getMin(int dist[] , bool visited[]){
    int key = 0 ; 
    int min = INT_MAX ; 
    for(int i=0;i <= n ; i++){
        if(!visited[i] && dist[i]<min){
            min = dist[i] ; 
            key = i ; 
        }
    }
    return key ; 
}

void display(int dist[] , int par[],int final ){
   for(int i =0 ;i <= n ;i++){
   	if(i==final)
	   {
       /*int temp = par[i] ; 
       cout<<i << " <- " ;
       while(temp!=-1)
       {
           cout<< temp << " <- " ;
           temp = par[temp] ; 
       }*/
       cout<<endl; 
       cout<<"::::Distance = " << dist[i] ; 
       cout<<endl;
	}
   } 
}
void path(int dist[] , int par[],int final ){
	for(int i =0 ;i <= n ;i++){
   	if(i==final)
	   {
       int temp = par[i] ; 
       cout<<i << " <- " ;
       while(temp!=-1)
       {
           cout<< temp << " <- " ;
           temp = par[temp] ; 
       }
}
}
}

void dijkstra(int src, int final ){
    int par[100] , dist[100] ; 
    bool visited[100] ={0} ; 
    fill(dist , dist+n  , INT_MAX ) ; 

    dist[src] =0 ; 
    par[src] =-1 ;
    
    for(int g = 0  ;g<n-1 ; g++){
        int u = getMin( dist ,  visited )  ; 
        visited[u] = true ;
        //cout<< " min = " << u <<endl; 
        for(int v =0 ; v<= n ;v++){
            if(!visited[v] && (dist[u]+cost[u][v]) <  dist[v] && cost[u][v]!=99)
            {
                par[v] = u ; 
                dist[v] = dist[u] + cost[u][v] ; 
            }
        }
    }
    
    display(dist , par, final) ; 
    path(dist , par,final );
}



int main(void) {
    int src ;
	int final;
    cout<<"\nEnter source : " ;  cin>>src ;
    cout<<"\nEnter final : " ;  cin>>final ;
    dijkstra(src, final) ; 
}

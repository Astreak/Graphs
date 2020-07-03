#include<bits/stdc++.h>
// Graph Problems
using namespace std;

class Graph{
    public:
    int V;
    Graph(int V){
        this->V=V;
    }
    unordered_map<int,vector<int>> adj;
    void bfs(int s);
    void dfsutils(int v,unordered_map<int,bool>& visited,map<int,int>& time,vector<int>& A);
    int dfs_code();
    int  dfs(int s);
    void add_edge(int a,int b);
    bool cycleutils(int v,unordered_map<int,bool>& visited,int parent);
    bool cycle(int s);
    int code(int s);
    unordered_map<int,int> nodes_at_level(int s,int k);
    bool has_path(int s,int d);
    bool Path(int s,int d,unordered_map<int,bool>& visited);
    int count_cc();
    void CC(int v,unordered_map<int,bool>& visited);
     

};

void Graph::CC(int v,unordered_map<int,bool>& visited){
    visited[v]=true;
    for(auto i=adj[v].begin();i!=adj[v].end();++i){
        if(!visited[*i])
            CC(v,visited);
    }

}



typedef class T{

    int data;
    T* next;
    T* prev;
    void insert(int data);
    void del(int data);
    void inorder();
    void postorder();
    bool check_bst(T* root);
}T;
//change directed and undirected graph here
void Graph::add_edge(int a,int b){
    adj[a].push_back(b);

    

}

void Graph::bfs(int s){
    unordered_map<int,bool> visited(false);
    visited[s]=true;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int s=Q.front();
        cout<<s<<"  ";
        Q.pop();
        for(auto i=adj[s].begin();i!=adj[s].end();i++){
            if(!visited[*i]){
                visited[*i]=true;
                Q.push(*i);
            
           }
           
        
       }
    
   }
}

unordered_map<int,int> Graph::nodes_at_level(int s,int k){
    unordered_map<int,bool> visited(false);
    visited[s]=true;
    queue<int> Q;
    Q.push(s);
    unordered_map<int,int> Level;
    vector<int> T;
    int c=0;
    Level[s]=0;
    while(!Q.empty()){
        int s=Q.front();
        Q.pop();
        
       for(auto i=adj[s].begin();i!=adj[s].end();i++){
            if(!visited[*i]){
                visited[*i]=true;
                Q.push(*i);
                Level[*i]=Level[s]+1;
          }
     }
        
        
        
    }
     return Level;
    

}






void Graph::dfsutils(int v,unordered_map<int,bool>&visited,map<int,int>&time,vector<int>&A){
    visited[v]=true;
    cout<<v<<"\n";
    int t=0;
    for(auto i=adj[v].begin();i!=adj[v].end();i++){
        if(!visited[*i]){
            dfsutils(*i,visited,time,A);
              
         }
         ++t;
        A.push_back(*i);
            
     }
      time[v]=t;
      
}


int  Graph::dfs_code(){
    
    map<int,int> time;
    for(int s=0;s<V;s++){
    for(auto i=adj[s].begin();i!=adj[s].end();i++){
          unordered_map<int,bool> visited(false);
          vector<int> temp;
          dfsutils(*i,visited,time,temp);
          if(temp.size()==V)
            return *i;
          
       }
    }
    return -100;

}

bool Graph::Path(int s,int d,unordered_map<int,bool>& visited){
    visited[s]=true;
    for(auto i=adj[s].begin();i!=adj[s].end();i++){
        if(!visited[*i]){
            if(Path(*i,d,visited))
                return true;
            else if(*i==d)
                return true;
        
        }
    
    }
    return false;

}


bool Graph::has_path(int s,int d){
    unordered_map<int,bool> visited;
    return Path(s,d,visited);


}

int Graph::dfs(int s){
    unordered_map<int,bool> visited(false);
    map<int,int>time;
    vector<int> T;
    dfsutils(s,visited,time,T);
    

}


bool check_all_visited(unordered_map<int,bool> visited,int V){
    int c=0;
    for(auto x:visited){
        if(x.second==false)
            return false;
        c++;
    }
    if(c==V)
        return true;
    else
        return false;

}


    
    
       






bool Graph::cycleutils(int v,unordered_map<int,bool>&visited,int parent){
    visited[v]=true;
    for(auto i=adj[v].begin();i!=adj[v].end();i++){
         if(!visited[*i]){
            if(cycleutils(*i,visited,v))
                return true;
         }
         else if(*i!=parent)
            return true;
    
      }
      
      return false;


}

bool Graph::cycle(int s){
    unordered_map<int,bool> visited(false);
    return cycleutils(s,visited,-1);


}

bool movable(int M[][5],bool visited[][5],int row,int col){
    return (((row<5)&&(row>=0)) && ((col<5)&&(col>=0)) &&(M[row][col] && !visited[row][col]));

}

void DFS(int M[][5],bool visited[][5],int row,int col){

    int rowM[]={-1,-1,-1,0,0,1,1,1};
    int colM[]={-1,0,1,-1,1,-1,0,1};
    visited[row][col]=true;
    for(int i=0;i<8;i++){
        if(movable(M,visited,row+rowM[i],col+colM[i]))
            DFS(M,visited,row+rowM[i],col+colM[i]);
       }

}

int count(int M[][5]){
    bool visited[5][5];
    int c=0;
    memset(visited,false,sizeof(visited));
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(M[i][j]==1 && !visited[i][j]){
                DFS(M,visited,i,j);
                ++c;
            
            }
        
             
        }
        
      }
      
   return c;
   
   
 }
    
int binary_search(int a[],int low,int high,int x){
    int mid=low+(high-low)/2;
    if(low<=high){
    if(a[mid]==x)
        return mid+1;
    else if(a[mid]>x)
        return binary_search(a,0,mid-1,x);
    else
        return binary_search(a,mid+1,high,x);
    }
    

}
    
    
    
int code(int a[],int n){
    int m=INT_MAX;

    for(int i=0;i<n;i++){
        m=min(m,a[i]-a[i-1]);
    }
    return m;
} 
    
int smallest_factor(int n){
    int c=0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
        if(i>3 && i%2!=0){
            c=i;
            return c;       
            }
        }
    }
    
    return -1;


}





    
    
            





int main(){
    Graph G(12);
    G.add_edge(1,2);
    G.add_edge(12,34);
    G.add_edge(3,12);
    G.add_edge(6,7);
    G.add_edge(2,3);
    G.add_edge(34,6);
    G.add_edge(7,3);
    cout<<"NO of connected components";
    int y=G.count_cc();
    cout<<y<<"\n";   
    
}
    
   
    
    
    
 


#include <iostream>
#include <vector>
using namespace std;
class edge{
public:
    edge(int a=0, int b=0, int w=0){ va=a; vb=b; weight=w; }
    bool operator<(edge& e) { return (weight<e.weight) ; }
    void operator=(edge& e) { va=e.va; vb=e.vb; weight=e.weight; }
    int va;
    int vb;
    int weight;
};

int main(void){

    int T,n,m,W;
    int i,j,k,to,New,minimum;
    int a,b,w;
    vector<edge>::iterator it;
    vector<edge> *V;
    int *N;
    edge t;

    cin>>T;
    while(T--){
        //input
        cin>>n>>m;
        V = new vector<edge>[n+1];//for edge 0:waste
        N = new int[n+1]; //tree to vertex 0:waste
        for(i=1;i<=n;i++) N[i]=-1; //-1 for infinity -2 for no
        W=0;
        for(i=0;i<m;i++){
            cin>>a>>b>>w;
            t.va = a;
            t.vb = b;
            t.weight = w;
            V[a].push_back(t);
            t.va = b;
            t.vb = a;
            V[b].push_back(t);
        }
        //choose for no cycle
        New=1;
        for(i=1;i<n;i++){
            N[New] = -2;
            for(it=V[New].begin();it!=V[New].end();++it) {
                to = (*it).vb;
                if( N[to]==-2 ) continue;
                if( N[to]==-1 || N[to]>(*it).weight ) N[to] = (*it).weight;
            }
            minimum = -1;
            for(j=1;j<=n;j++) if(N[j]>=0) if( minimum<0 || minimum > N[j] ){ minimum = N[j]; k=j; }
            W += minimum;
            New = k;
        }
        //output
        cout<<W<<endl;
        //clean
        delete [] V;
        delete [] N;
    }
    return 0;
}


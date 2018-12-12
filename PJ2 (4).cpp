#include<iostream>
#include<fstream>
#include<cstdlib>
#include<queue>
#include<vector>
#include<string>
#include <iomanip>
using namespace std;
queue <int> Q;
vector <int> Path;
int count = 0,wow_x,wow_y;
int DIREC[4][2] = {-1,0,0,1,1,0,0,-1};//givenext D,L,U,R  , to go U,R,D,L
int m,n,B,cur_B;
void check(int x,int y,int indir,int outdir,int start_x,int start_y,bool**visited,int**dist,int**dist2){
    //cout<<x<<"+"<<y<<endl;
     if(indir==outdir+2||indir+2==outdir) if(x!=start_x||y!=start_y)  dist[x][y] = -1;
     if((x!=start_x||y!=start_y)&&(dist[x-DIREC[indir][0]][y-DIREC[indir][1]]==-1/*||visited[x-DIREC[indir][0]][y-DIREC[indir][1]]==1*/)
     &&(dist[x+DIREC[outdir][0]][y+DIREC[outdir][1]]==-1)/*||visited[x+DIREC[outdir][0]][y-DIREC[outdir][1]]==1*/
        &&(dist[x-DIREC[outdir][0]][y-DIREC[outdir][1]]==-1))
     {dist[x][y] = -1;}
     return;
}
void checkb(int x,int y,int indir,int outdir,int start_x,int start_y,bool**visited,int**dist,int**dist2){
    if(indir==outdir+2||indir+2==outdir) if(x!=start_x||y!=start_y) dist[x][y] = -1;
    if((x!=start_x||y!=start_y)&&(dist[x-DIREC[indir][0]][y-DIREC[indir][1]]==-1)
       &&(dist[x+DIREC[outdir][0]][y+DIREC[outdir][1]]==-1))
     {dist[x][y] = -1;}
     return;
}
void walk(int cur_x,int cur_y,int dir,int start_x,int start_y,bool**visited,int**dist,int**dist2);
void gohome(int cur_x,int cur_y,int dir,int start_x,int start_y,bool**visited,int**dist,int**dist2){  //indir
    if(count==0) {return;}
    /*for(int i=0;i<=m+1;i++) {
        for(int j=0 ; j<=n+1 ; j++)
            {   cout<< setw(3) << visited[i][j]<<' ';}
                cout<<endl;}*/
    //if(dist[cur_x][cur_y]==-1)  return;
    wow_x = cur_x; wow_y = cur_y;
    cur_B = cur_B-1;
    if(visited[cur_x][cur_y]==false) {
            if(cur_x!=start_x||cur_y!=start_y){visited[cur_x][cur_y] = true; count--;}
        }
    if(Path.empty()) {
        Path.push_back(cur_x-1);
        Path.push_back(cur_y-1);
    }
    else{
        if(*(Path.end()-2)==cur_x-1 && *(Path.end()-1)==cur_y-1) {}
        else{
                Path.push_back(cur_x-1);
                Path.push_back(cur_y-1);
        }
    }
    cout<<"home"<<cur_x<<","<<cur_y<<",d:"<<dist[cur_x][cur_y]<<",dir:"<<dir<<",count:"<<count<<endl;
    if(cur_x==start_x&&cur_y==start_y) {walk(cur_x,cur_y,(dir+2)%4,start_x,start_y,visited,dist,dist2); return;}
    else{
        if(count==0) return;
        if(count!=0&&dist2[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]]>dist2[cur_x][cur_y]-1
           &&dist[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]]!=-1
           &&!visited[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]])
            {
                walk(cur_x+DIREC[(dir+1)%4][0],cur_y+DIREC[(dir+1)%4][1],(dir+3)%4,start_x,start_y,visited,dist,dist2);
                check(cur_x,cur_y,dir,(dir+3)%4,start_x,start_y,visited,dist,dist2);
                return;
            }
        else if(count!=0&&dist2[cur_x+DIREC[(dir+2)%4][0]][cur_y+DIREC[(dir+2)%4][1]]>dist2[cur_x][cur_y]-1
                &&dist[cur_x+DIREC[(dir+2)%4][0]][cur_y+DIREC[(dir+2)%4][1]]!=-1
                &&!visited[cur_x+DIREC[(dir+2)%4][0]][cur_y+DIREC[(dir+2)%4][1]])
            {
                walk(cur_x+DIREC[(dir+2)%4][0],cur_y+DIREC[(dir+2)%4][1],(dir+0)%4,start_x,start_y,visited,dist,dist2);
                check(cur_x,cur_y,dir,(dir+0)%4,start_x,start_y,visited,dist,dist2);
                return;
            }
        else if(count!=0&&dist2[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]]>dist2[cur_x][cur_y]-1
                &&dist[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]]!=-1
                &&!visited[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]])
            {
                walk(cur_x+DIREC[(dir+3)%4][0],cur_y+DIREC[(dir+3)%4][1],(dir+1)%4,start_x,start_y,visited,dist,dist2);
                check(cur_x,cur_y,dir,(dir+1)%4,start_x,start_y,visited,dist,dist2);
                return;
            }
        else{


        if(count!=0&&dist2[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]]==dist2[cur_x][cur_y]-1
           &&dist[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]]!=-1
           &&!visited[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]])
            {
                gohome(cur_x+DIREC[(dir+1)%4][0],cur_y+DIREC[(dir+1)%4][1],(dir+3)%4,start_x,start_y,visited,dist,dist2);
                checkb(cur_x,cur_y,dir,(dir+3)%4,start_x,start_y,visited,dist,dist2);
                return;
            }
        else if(count!=0&&dist2[cur_x+DIREC[(dir+2)%4][0]][cur_y+DIREC[(dir+2)%4][1]]==dist2[cur_x][cur_y]-1
                &&dist[cur_x+DIREC[(dir+2)%4][0]][cur_y+DIREC[(dir+2)%4][1]]!=-1
                &&!visited[cur_x+DIREC[(dir+2)%4][0]][cur_y+DIREC[(dir+2)%4][1]])
            {
                gohome(cur_x+DIREC[(dir+2)%4][0],cur_y+DIREC[(dir+2)%4][1],(dir+0)%4,start_x,start_y,visited,dist,dist2);
                checkb(cur_x,cur_y,dir,(dir+0)%4,start_x,start_y,visited,dist,dist2);
                return;
            }
        else if(count!=0&&dist2[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]]==dist2[cur_x][cur_y]-1
                &&dist[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]]!=-1
                &&!visited[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]])
            {
                gohome(cur_x+DIREC[(dir+3)%4][0],cur_y+DIREC[(dir+3)%4][1],(dir+1)%4,start_x,start_y,visited,dist,dist2);
                checkb(cur_x,cur_y,dir,(dir+1)%4,start_x,start_y,visited,dist,dist2);
                return;
            }
        else {
            if(count!=0&&dist2[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]]==dist2[cur_x][cur_y]-1
                    &&!visited[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]])
                {
                    gohome(cur_x+DIREC[(dir+1)%4][0],cur_y+DIREC[(dir+1)%4][1],(dir+3)%4,start_x,start_y,visited,dist,dist2);
                    checkb(cur_x,cur_y,dir,(dir+3)%4,start_x,start_y,visited,dist,dist2);
                    return;
                }
            else if(count!=0&&dist2[cur_x+DIREC[(dir+2)%4][0]][cur_y+DIREC[(dir+2)%4][1]]==dist2[cur_x][cur_y]-1
                    &&!visited[cur_x+DIREC[(dir+2)%4][0]][cur_y+DIREC[(dir+2)%4][1]])
                {
                    gohome(cur_x+DIREC[(dir+2)%4][0],cur_y+DIREC[(dir+2)%4][1],(dir+0)%4,start_x,start_y,visited,dist,dist2);
                    checkb(cur_x,cur_y,dir,(dir+0)%4,start_x,start_y,visited,dist,dist2);
                    return;
                }
            else if(count!=0&&dist2[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]]==dist2[cur_x][cur_y]-1&&!visited[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]])
                {
                    gohome(cur_x+DIREC[(dir+3)%4][0],cur_y+DIREC[(dir+3)%4][1],(dir+1)%4,start_x,start_y,visited,dist,dist2);
                    checkb(cur_x,cur_y,dir,(dir+1)%4,start_x,start_y,visited,dist,dist2);
                    return;
                }

            else{
                if(count!=0&&dist2[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]]==dist2[cur_x][cur_y]-1)
                    {
                        gohome(cur_x+DIREC[(dir+1)%4][0],cur_y+DIREC[(dir+1)%4][1],(dir+3)%4,start_x,start_y,visited,dist,dist2);
                        checkb(cur_x,cur_y,dir,(dir+3)%4,start_x,start_y,visited,dist,dist2);
                        return;
                }
                else if(count!=0&&dist2[cur_x+DIREC[(dir+2)%4][0]][cur_y+DIREC[(dir+2)%4][1]]==dist2[cur_x][cur_y]-1)
                    {
                        gohome(cur_x+DIREC[(dir+2)%4][0],cur_y+DIREC[(dir+2)%4][1],(dir+0)%4,start_x,start_y,visited,dist,dist2);
                        checkb(cur_x,cur_y,dir,(dir+0)%4,start_x,start_y,visited,dist,dist2);
                        return;
                }
                else if(count!=0&&dist2[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]]==dist2[cur_x][cur_y]-1)
                    {
                        gohome(cur_x+DIREC[(dir+3)%4][0],cur_y+DIREC[(dir+3)%4][1],(dir+1)%4,start_x,start_y,visited,dist,dist2);
                        checkb(cur_x,cur_y,dir,(dir+1)%4,start_x,start_y,visited,dist,dist2);
                        return;
                    }
                }
              }
        }
    }
    if(count==0) return;
}
void walk(int cur_x,int cur_y,int dir,int start_x,int start_y,bool**visited,int**dist,int**dist2){  //in_dir
    if(count==0) return;
    if(dist[cur_x][cur_y]==-1)  return;
    cur_B=cur_B-1;
   /*for(int i=0;i<=m+1;i++) {
        for(int j=0 ; j<=n+1 ; j++)
            {   cout<< setw(3) << dist[i][j]<<' ';}
                cout<<endl;}*/
    wow_x = cur_x; wow_y = cur_y;
    if(visited[cur_x][cur_y]==false) {
        if(cur_x!=start_x||cur_y!=start_y){visited[cur_x][cur_y] = true; count--;}
    }
    cout<<cur_x<<","<<cur_y<<",d:"<<dist[cur_x][cur_y]<<",dir"<<dir<<",count:"<<count<<endl;
    if(Path.empty()) {
        Path.push_back(cur_x-1);
        Path.push_back(cur_y-1);
    }
    else{
        if(*(Path.end()-2)==cur_x-1 && *(Path.end()-1)==cur_y-1) {}
        else{
                Path.push_back(cur_x-1);
                Path.push_back(cur_y-1);
        }
    }

    if(cur_x==start_x&&cur_y==start_y) {
            cur_B = B;
            if(count!=0&&dir == 0)      {walk(cur_x+DIREC[0][0],cur_y+DIREC[0][1],2,start_x,start_y,visited,dist,dist2);return;}
            //from up , give down(go to up)
            else if(count!=0&&dir == 1) {walk(cur_x+DIREC[1][0],cur_y+DIREC[1][1],3,start_x,start_y,visited,dist,dist2);return;}
            //from right , give next left (go to right)
            else if(count!=0&&dir == 2) {walk(cur_x+DIREC[2][0],cur_y+DIREC[2][1],0,start_x,start_y,visited,dist,dist2);return;}
            else if(count!=0&&dir == 3) {walk(cur_x+DIREC[3][0],cur_y+DIREC[3][1],1,start_x,start_y,visited,dist,dist2);return;}
    }
    else{
        if(
        ((dist[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]]==-1/*||visited[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]]==1*/)&&
        (dist[cur_x+DIREC[(dir+2)%4][0]][cur_y+DIREC[(dir+2)%4][1]]==-1/*||visited[cur_x+DIREC[(dir+2)%4][0]][cur_y+DIREC[(dir+2)%4][1]]==1*/)&&
        (dist[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]]==-1/*||visited[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]]==1*/))
        ||(cur_B<=dist[cur_x+1][cur_y])&&(cur_B<=dist[cur_x-1][cur_y])&&(cur_B<=dist[cur_x][cur_y+1])&&(cur_B<=dist[cur_x][cur_y-1])
            )   gohome(cur_x,cur_y,(dir+2)%4,start_x,start_y,visited,dist,dist2);

        if(count!=0&&dist[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]]==dist[cur_x][cur_y]+1
                &&(!visited[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]])&&cur_B-1>=dist2[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]])
                    {
                        check(cur_x,cur_y,dir,(dir+3)%4,start_x,start_y,visited,dist,dist2);
                        walk(cur_x+DIREC[(dir+1)%4][0],cur_y+DIREC[(dir+1)%4][1],(dir+3)%4,start_x,start_y,visited,dist,dist2);
                        return;
              }
        else if(count!=0&&dist[cur_x+DIREC[(dir+2)%4][0]][cur_y+DIREC[(dir+2)%4][1]]==dist[cur_x][cur_y]+1
                &&(!visited[cur_x+DIREC[(dir+2)%4][0]][cur_y+DIREC[(dir+2)%4][1]])&&cur_B-1>=dist2[cur_x+DIREC[(dir+2)%4][0]][cur_y+DIREC[(dir+2)%4][1]])
                    {
                        check(cur_x,cur_y,dir,(dir+0)%4,start_x,start_y,visited,dist,dist2);
                        walk(cur_x+DIREC[(dir+2)%4][0],cur_y+DIREC[(dir+2)%4][1],(dir+0)%4,start_x,start_y,visited,dist,dist2);
                        return;
                  }
        else if(count!=0&&dist[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]]==dist[cur_x][cur_y]+1
                &&(!visited[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]])&&cur_B-1>=dist2[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]])
                    {
                        check(cur_x,cur_y,dir,(dir+1)%4,start_x,start_y,visited,dist,dist2);
                        walk(cur_x+DIREC[(dir+3)%4][0],cur_y+DIREC[(dir+3)%4][1],(dir+1)%4,start_x,start_y,visited,dist,dist2);
                        return;
                  }
        else{
            if(count!=0&&dist[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]]!=-1
                &&(!visited[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]])&&cur_B-1>=dist2[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]])
                    {
                        check(cur_x,cur_y,dir,(dir+3)%4,start_x,start_y,visited,dist,dist2);
                        walk(cur_x+DIREC[(dir+1)%4][0],cur_y+DIREC[(dir+1)%4][1],(dir+3)%4,start_x,start_y,visited,dist,dist2);
                        return;
                   }
            else if(count!=0&&dist[cur_x+DIREC[(dir+2)%4][0]][cur_y+DIREC[(dir+2)%4][1]]!=-1
                &&(!visited[cur_x+DIREC[(dir+2)%4][0]][cur_y+DIREC[(dir+2)%4][1]])&&cur_B-1>=dist2[cur_x+DIREC[(dir+2)%4][0]][cur_y+DIREC[(dir+2)%4][1]])
                    {
                        check(cur_x,cur_y,dir,(dir+0)%4,start_x,start_y,visited,dist,dist2);
                        walk(cur_x+DIREC[(dir+2)%4][0],cur_y+DIREC[(dir+2)%4][1],(dir+0)%4,start_x,start_y,visited,dist,dist2);
                        return;
                 }
            else if(count!=0&&dist[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]]!=-1
                &&(!visited[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]])&&cur_B-1>=dist2[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]])
                    {
                        check(cur_x,cur_y,dir,(dir+1)%4,start_x,start_y,visited,dist,dist2);
                        walk(cur_x+DIREC[(dir+3)%4][0],cur_y+DIREC[(dir+3)%4][1],(dir+1)%4,start_x,start_y,visited,dist,dist2);
                        return;
                 }
            else {
                if(count!=0&&dist2[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]]!=-1&&cur_B-1>=dist2[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]])
                    {
                        check(cur_x,cur_y,dir,(dir+3)%4,start_x,start_y,visited,dist,dist2);
                        walk(cur_x+DIREC[(dir+1)%4][0],cur_y+DIREC[(dir+1)%4][1],(dir+3)%4,start_x,start_y,visited,dist,dist2);
                        return;
                 }
                else if(count!=0&&dist2[cur_x+DIREC[(dir+2)%4][0]][cur_y+DIREC[(dir+2)%4][1]]!=-1&&cur_B-1>=dist2[cur_x+DIREC[(dir+2)%4][0]][cur_y+DIREC[(dir+2)%4][1]])
                    {
                        check(cur_x,cur_y,dir,(dir+0)%4,start_x,start_y,visited,dist,dist2);
                        walk(cur_x+DIREC[(dir+2)%4][0],cur_y+DIREC[(dir+2)%4][1],(dir+0)%4,start_x,start_y,visited,dist,dist2);
                        return;
                   }
                else if(count!=0&&dist2[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]]!=-1&&cur_B-1>=dist2[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]])
                    {
                        check(cur_x,cur_y,dir,(dir+1)%4,start_x,start_y,visited,dist,dist2);
                        walk(cur_x+DIREC[(dir+3)%4][0],cur_y+DIREC[(dir+3)%4][1],(dir+1)%4,start_x,start_y,visited,dist,dist2);
                        return;
                   }
                }
            }
    }
    if(count==0) {return;}
}
void BFS(int x,int y,bool**visited,int **dist,char**M){
    if(M[x+1][y]=='0'&&!visited[x+1][y]) {dist[x+1][y] = dist[x][y]+1; visited[x+1][y] = 1;Q.push(x+1);Q.push(y);}
    if(M[x-1][y]=='0'&&!visited[x-1][y]) {dist[x-1][y] = dist[x][y]+1; visited[x-1][y] = 1;Q.push(x-1);Q.push(y);}
    if(M[x][y+1]=='0'&&!visited[x][y+1]) {dist[x][y+1] = dist[x][y]+1; visited[x][y+1] = 1;Q.push(x);Q.push(y+1);}
    if(M[x][y-1]=='0'&&!visited[x][y-1]) {dist[x][y-1] = dist[x][y]+1; visited[x][y-1] = 1;Q.push(x);Q.push(y-1);}
}
int main(){
    fstream testcase;
    int x , y ,start_x,start_y;
    int cur_x,cur_y;


    cin>>m;
    cin>>n;
    cin>>B;
    char tmp;
    char** M = new char*[m+2];
    bool** visited = new bool*[m+2];
    int** dist = new int*[m+2];
    int** dist2 = new int*[m+2];
    for (int i = 0; i <= m+1; i++){
        M[i] = new char[n+2];
        visited[i] = new bool[n+2];
        dist[i] = new int[n+2];
        dist2[i] = new int[n+2];
    }
    for(int i=0;i<=m+1;i++){
        for(int j=0 ; j<=n+1 ; j++){
            dist[i][j] = -1;
            visited[i][j] = false;
            if(i==0||i==m+1||j==0||j==n+1) M[i][j] = '1';
            else{
                cin>>tmp;
                M[i][j] = tmp;
                if(M[i][j]=='R') {
                    x = i;
                    start_x = i;
                    y = j;
                    start_y = j;
                }
                if(M[i][j]=='0') count++;
            }
        }
    }

    Q.push(x);
    Q.push(y);
    visited[x][y] = true;
    dist[x][y] = 0;
    while(!Q.empty()){
        x = Q.front();
        Q.pop();
        y = Q.front();
        Q.pop();
        BFS(x,y,visited,dist,M);
    }

    for(int i=0;i<=m+1;i++)  for(int j=0 ; j<=n+1 ; j++)  {
        dist2[i][j] = dist[i][j];
        if(M[i][j]=='0'||'R') visited[i][j] = false;
        else visited[i][j] = true;
        }
    cur_x = start_x;
    cur_y = start_y;
    cur_B = B;
    if(count!=0){
            walk(cur_x-1,cur_y,0,start_x,start_y,visited,dist,dist2);
        if(count!=0){
            walk(cur_x,cur_y+1,1,start_x,start_y,visited,dist,dist2);}
        if(count!=0)
            walk(cur_x+1,cur_y,2,start_x,start_y,visited,dist,dist2);
        if(count!=0)
            walk(cur_x,cur_y-1,3,start_x,start_y,visited,dist,dist2);

        while(dist2[wow_x][wow_y]!=0){

            if(Path.empty()) {
                Path.push_back(wow_x-1);
                Path.push_back(wow_y-1);
            }
            else{
                if(*(Path.end()-2)==wow_x-1 && *(Path.end()-1)==wow_y-1) {}
                else{
                        Path.push_back(wow_x-1);
                        Path.push_back(wow_y-1);
                }
            }
            if(dist2[wow_x-1][wow_y]==dist2[wow_x][wow_y]-1) {wow_x=wow_x-1; wow_y=wow_y;}
            else if(dist2[wow_x+1][wow_y]==dist2[wow_x][wow_y]-1) {wow_x=wow_x+1; wow_y=wow_y;}
            else if(dist2[wow_x][wow_y+1]==dist2[wow_x][wow_y]-1) {wow_x=wow_x; wow_y=wow_y+1;}
            else if(dist2[wow_x][wow_y-1]==dist2[wow_x][wow_y]-1) {wow_x=wow_x; wow_y=wow_y-1;}
        }
        Path.push_back(start_x-1);
        Path.push_back(start_y-1);
        }
    for(int i=0;i<=m+1;i++) {
        for(int j=0 ; j<=n+1 ; j++)
            {cout<< visited[i][j]<<' ';}
            cout<<endl;}
    for (int i = 0; i <=n+1; i++){
        delete [] M[i];
        delete [] dist[i];
        delete [] visited[i];
        delete [] dist2[i];
    }
        delete [] M;
        delete [] dist;
        delete [] visited;
        delete [] dist2;

    return 0;
}


#include<iostream>
#include<fstream>
#include<cstdlib>
#include<queue>
#include<utility>
#include<vector>
#include<string>
using namespace std;
queue <int> Q;
vector <int> Path;
int count = 0,wow_x,wow_y;
int DIREC[4][2] = {-1,0,0,1,1,0,0,-1};//givenext D,L,U,R
int B,cur_B;
void walk(int cur_x,int cur_y,int dir,int start_x,int start_y,bool**visited,int**dist);
void gohome(int cur_x,int cur_y,int dir,int start_x,int start_y,bool**visited,int**dist){
    if(count==0) {return;}
    wow_x = cur_x; wow_y = cur_y;
    cur_B = cur_B-1;
    if(visited[cur_x][cur_y]==false) {
            if(cur_x!=start_x||cur_y!=start_y){visited[cur_x][cur_y] = true; count--;}
        }
    //if(Path.back()-1!=cur_x&&Path.back()!=cur_y) {
                Path.emplace_back(cur_x-1);
                Path.emplace_back(cur_y-1);
     //   }
    //cout<<"home"<<cur_x<<","<<cur_y<<",d:"<<dist[cur_x][cur_y]<<",dir:"<<dir<<",count:"<<count<<endl;
    if((dist[cur_x-DIREC[dir%4][0]][cur_y-DIREC[dir%4][1]]==-1||visited[cur_x-DIREC[dir%4][0]][cur_y-DIREC[dir%4][1]]==1)&&
       (dist[cur_x-DIREC[(dir+1)%4][0]][cur_y-DIREC[(dir+1)%4][1]]==-1||visited[cur_x-DIREC[(dir+1)%4][0]][cur_y-DIREC[(dir+1)%4][1]]==1)&&
       (dist[cur_x-DIREC[(dir+3)%4][0]][cur_y-DIREC[(dir+3)%4][1]]==-1)||visited[cur_x-DIREC[(dir+3)%4][0]][cur_y-DIREC[(dir+3)%4][1]]==1)
       {dist[cur_x][cur_y] = -1;}
    if(cur_x==start_x&&cur_y==start_y) {walk(cur_x,cur_y,(dir+2)%4,start_x,start_y,visited,dist); return;}
    else{
        if(count==0) return;
        if(count!=0&&dist[cur_x-DIREC[dir%4][0]][cur_y-DIREC[dir%4][1]]==dist[cur_x][cur_y]-1&&!visited[cur_x-DIREC[dir%4][0]][cur_y-DIREC[dir%4][1]])
            {gohome(cur_x-DIREC[dir%4][0],cur_y-DIREC[dir%4][1],dir%4,start_x,start_y,visited,dist);}
        else if(count!=0&&dist[cur_x-DIREC[(dir+1)%4][0]][cur_y-DIREC[(dir+1)%4][1]]==dist[cur_x][cur_y]-1&&!visited[cur_x-DIREC[(dir+1)%4][0]][cur_y-DIREC[(dir+1)%4][1]])
            {gohome(cur_x-DIREC[(dir+1)%4][0],cur_y-DIREC[(dir+1)%4][1],(dir+1)%4,start_x,start_y,visited,dist);}
        else if(count!=0&&dist[cur_x-DIREC[(dir+3)%4][0]][cur_y-DIREC[(dir+3)%4][1]]==dist[cur_x][cur_y]-1&&!visited[cur_x-DIREC[(dir+3)%4][0]][cur_y-DIREC[(dir+3)%4][1]])
            {gohome(cur_x-DIREC[(dir+3)%4][0],cur_y-DIREC[(dir+3)%4][1],(dir+3)%4,start_x,start_y,visited,dist);}
        else if(count!=0&&dist[cur_x-DIREC[(dir+2)%4][0]][cur_y-DIREC[(dir+2)%4][1]]==dist[cur_x][cur_y]-1&&!visited[cur_x-DIREC[(dir+2)%4][0]][cur_y-DIREC[(dir+2)%4][1]])
            {gohome(cur_x-DIREC[(dir+2)%4][0],cur_y-DIREC[(dir+2)%4][1],(dir+2)%4,start_x,start_y,visited,dist);}
        else {
            if(count!=0&&dist[cur_x-DIREC[dir%4][0]][cur_y-DIREC[dir%4][1]]==dist[cur_x][cur_y]-1)
                {gohome(cur_x-DIREC[dir%4][0],cur_y-DIREC[dir%4][1],dir%4,start_x,start_y,visited,dist);}
            else if(count!=0&&dist[cur_x-DIREC[(dir+1)%4][0]][cur_y-DIREC[(dir+1)%4][1]]==dist[cur_x][cur_y]-1)
                {gohome(cur_x-DIREC[(dir+1)%4][0],cur_y-DIREC[(dir+1)%4][1],(dir+1)%4,start_x,start_y,visited,dist);}
            else if(count!=0&&dist[cur_x-DIREC[(dir+3)%4][0]][cur_y-DIREC[(dir+3)%4][1]]==dist[cur_x][cur_y]-1)
                {gohome(cur_x-DIREC[(dir+3)%4][0],cur_y-DIREC[(dir+3)%4][1],(dir+3)%4,start_x,start_y,visited,dist);}
            else if(count!=0&&dist[cur_x-DIREC[(dir+2)%4][0]][cur_y-DIREC[(dir+2)%4][1]]==dist[cur_x][cur_y]-1)
                {gohome(cur_x-DIREC[(dir+2)%4][0],cur_y-DIREC[(dir+2)%4][1],(dir+2)%4,start_x,start_y,visited,dist);}
            else {return;}
        }
    }
    if(count==0) {return; }
}
void walk(int cur_x,int cur_y,int dir,int start_x,int start_y,bool**visited,int**dist){  //in_dir
    if(count==0) {return;}
    wow_x = cur_x; wow_y = cur_y;
    cur_B=cur_B-1;
    bool no = true;
    if(dist[cur_x][cur_y]==-1)  return;
    if(visited[cur_x][cur_y]==false) {
            if(cur_x!=start_x||cur_y!=start_y){visited[cur_x][cur_y] = true; count--;}
            }
    //cout<<cur_x<<","<<cur_y<<",d:"<<dist[cur_x][cur_y]<<",dir"<<dir<<",count:"<<count<<endl;
    //if(Path.back()-1!=cur_x&&Path.back()!=cur_y) {
                Path.emplace_back(cur_x-1);
                Path.emplace_back(cur_y-1);
    //    }
    if((dist[cur_x+DIREC[dir%4][0]][cur_y+DIREC[dir%4][1]]==-1||visited[cur_x+DIREC[dir%4][0]][cur_y+DIREC[dir%4][1]]==1)&&
       (dist[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]]==-1||visited[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]]==1)&&
       (dist[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]]==-1)||visited[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]]==1)
       {dist[cur_x][cur_y] = -1;cout<<"L";}
    if(cur_x==start_x&&cur_y==start_y) {
            cur_B = B;
            if(count!=0&&dir == 0)      {walk(cur_x+DIREC[2][0],cur_y+DIREC[2][1],2,start_x,start_y,visited,dist);no = false;}
            //from up , give down(go to up)
            else if(count!=0&&dir == 1) {walk(cur_x+DIREC[3][0],cur_y+DIREC[3][1],3,start_x,start_y,visited,dist);no = false;}
            //from right , give next left (go to right)
            else if(count!=0&&dir == 2) {walk(cur_x+DIREC[0][0],cur_y+DIREC[0][1],0,start_x,start_y,visited,dist);no = false;}
            else if(count!=0&&dir == 3) {walk(cur_x+DIREC[1][0],cur_y+DIREC[1][1],1,start_x,start_y,visited,dist);no = false;}
    }
    else{
            if(count!=0&&dist[cur_x+DIREC[dir%4][0]][cur_y+DIREC[dir%4][1]]==dist[cur_x][cur_y]+1
                &&(!visited[cur_x+DIREC[dir%4][0]][cur_y+DIREC[dir%4][1]])&&cur_B-1>=dist[cur_x+DIREC[dir%4][0]][cur_y+DIREC[dir%4][1]])
                    {walk(cur_x+DIREC[dir%4][0],cur_y+DIREC[dir%4][1],dir%4,start_x,start_y,visited,dist); no = false;}
            if(count!=0&&dist[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]]==dist[cur_x][cur_y]+1
                &&(!visited[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]])&&cur_B-1>=dist[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]])
                    {walk(cur_x+DIREC[(dir+1)%4][0],cur_y+DIREC[(dir+1)%4][1],(dir+1)%4,start_x,start_y,visited,dist);no = false;}
            if(count!=0&&dist[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]]==dist[cur_x][cur_y]+1
                &&(!visited[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]])&&cur_B-1>=dist[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]])
                    {walk(cur_x+DIREC[(dir+3)%4][0],cur_y+DIREC[(dir+3)%4][1],(dir+3)%4,start_x,start_y,visited,dist);no = false;}
    if(no){
            if(count!=0&&dist[cur_x+DIREC[dir%4][0]][cur_y+DIREC[dir%4][1]]!=-1
                &&(!visited[cur_x+DIREC[dir%4][0]][cur_y+DIREC[dir%4][1]])&&cur_B-1>=dist[cur_x+DIREC[dir%4][0]][cur_y+DIREC[dir%4][1]])
                    {walk(cur_x+DIREC[dir%4][0],cur_y+DIREC[dir%4][1],dir%4,start_x,start_y,visited,dist);}
            else if(count!=0&&dist[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]]!=-1
                &&(!visited[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]])&&cur_B-1>=dist[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]])
                    {walk(cur_x+DIREC[(dir+1)%4][0],cur_y+DIREC[(dir+1)%4][1],(dir+1)%4,start_x,start_y,visited,dist);}
            else if(count!=0&&dist[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]]!=-1
                &&(!visited[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]])&&cur_B-1>=dist[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]])
                    {walk(cur_x+DIREC[(dir+3)%4][0],cur_y+DIREC[(dir+3)%4][1],(dir+3)%4,start_x,start_y,visited,dist);}
                else {
                    if(count!=0&&dist[cur_x+DIREC[dir%4][0]][cur_y+DIREC[dir%4][1]]!=-1&&cur_B-1>=dist[cur_x+DIREC[dir%4][0]][cur_y+DIREC[dir%4][1]])
                    {walk(cur_x+DIREC[dir%4][0],cur_y+DIREC[dir%4][1],dir%4,start_x,start_y,visited,dist);}
                    else if(count!=0&&dist[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]]!=-1&&cur_B-1>=dist[cur_x+DIREC[(dir+1)%4][0]][cur_y+DIREC[(dir+1)%4][1]])
                    {walk(cur_x+DIREC[(dir+1)%4][0],cur_y+DIREC[(dir+1)%4][1],(dir+1)%4,start_x,start_y,visited,dist);}
                    else if(count!=0&&dist[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]]!=-1&&cur_B-1>=dist[cur_x+DIREC[(dir+3)%4][0]][cur_y+DIREC[(dir+3)%4][1]])
                    {walk(cur_x+DIREC[(dir+3)%4][0],cur_y+DIREC[(dir+3)%4][1],(dir+3)%4,start_x,start_y,visited,dist);}
                    else gohome(cur_x,cur_y,dir,start_x,start_y,visited,dist);
                }
            }
            if(
               ((dist[cur_x+1][cur_y]==-1||visited[cur_x+1][cur_y]==1)&&
               (dist[cur_x-1][cur_y]==-1||visited[cur_x-1][cur_y]==1)&&
               (dist[cur_x][cur_y+1]==-1||visited[cur_x][cur_y+1]==1)&&
               (dist[cur_x][cur_y-1]==-1||visited[cur_x][cur_y-1]==1))
               ||(cur_B<=dist[cur_x+1][cur_y])&&(cur_B<=dist[cur_x-1][cur_y])&&(cur_B<=dist[cur_x][cur_y+1])&&(cur_B<=dist[cur_x][cur_y-1])
               )
                gohome(cur_x,cur_y,dir,start_x,start_y,visited,dist);
    }
    if(count==0) {return; }
}
void BFS(int x,int y,bool**visited,int **dist,char**M){
    if(M[x+1][y]=='0'&&!visited[x+1][y]) {dist[x+1][y] = dist[x][y]+1; visited[x+1][y] = 1;Q.push(x+1);Q.push(y);}
    if(M[x-1][y]=='0'&&!visited[x-1][y]) {dist[x-1][y] = dist[x][y]+1; visited[x-1][y] = 1;Q.push(x-1);Q.push(y);}
    if(M[x][y+1]=='0'&&!visited[x][y+1]) {dist[x][y+1] = dist[x][y]+1; visited[x][y+1] = 1;Q.push(x);Q.push(y+1);}
    if(M[x][y-1]=='0'&&!visited[x][y-1]) {dist[x][y-1] = dist[x][y]+1; visited[x][y-1] = 1;Q.push(x);Q.push(y-1);}
}
int main(int argc,char *argv[]){
    fstream testcase;
    int m,n;
    int x , y ,start_x,start_y;
    int cur_x,cur_y;

    string a,b,path1,path2;
    a = "/floor.data";
    b = "/final.path";
    if(argc!=2){
        cout<<"fail";
    }
    path1 = argv[1] + a;
    path2 = argv[1] + b;
    cout<<path1;
    testcase.open(path1,ios::in);
    if(!testcase) {
            cout<<"fail"<<endl;
            return 0;
    }
    testcase>>m;
    testcase>>n;
    testcase>>B;
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
                testcase>>tmp;
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
    testcase.close();

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
/*
    for(int i=0;i<=m+1;i++){
        for(int j=0 ; j<=n+1 ; j++){
            cout<<dist[i][j]<<' ';
        }
        cout<<endl;
    }
*/
    for(int i=0;i<=m+1;i++)  for(int j=0 ; j<=n+1 ; j++)  {visited[i][j] = false; dist2[i][j] = dist[i][j];}
    cur_x = start_x;
    cur_y = start_y;
    visited[start_x][start_y] = true;
    if(count!=0)
        walk(cur_x,cur_y,0,start_x,start_y,visited,dist);
    if(count!=0)
        walk(cur_x,cur_y,1,start_x,start_y,visited,dist);
    if(count!=0)
        walk(cur_x,cur_y,2,start_x,start_y,visited,dist);
    if(count!=0)
        walk(cur_x,cur_y,3,start_x,start_y,visited,dist);

    while(dist2[wow_x][wow_y]!=0){
        Path.emplace_back(wow_x-1);
        Path.emplace_back(wow_y-1);
        if(dist2[wow_x-1][wow_y]==dist2[wow_x][wow_y]-1) {wow_x=wow_x-1; wow_y=wow_y;}
        else if(dist2[wow_x+1][wow_y]==dist2[wow_x][wow_y]-1) {wow_x=wow_x+1; wow_y=wow_y;}
        else if(dist2[wow_x][wow_y+1]==dist2[wow_x][wow_y]-1) {wow_x=wow_x; wow_y=wow_y+1;}
        else if(dist2[wow_x][wow_y-1]==dist2[wow_x][wow_y]-1) {wow_x=wow_x; wow_y=wow_y-1;}
    }
    Path.emplace_back(start_x-1);
    Path.emplace_back(start_y-1);

    cout<<(Path.size())/2<<endl;
    for(auto i=Path.begin();i<Path.end();i=i+2){
        cout<<*i<<' ';
        cout<<*(i+1)<<endl;
    }

    testcase.open(path2,ios::out);
    if(testcase.fail()) cout<<"fail2";
    else{
        testcase<<(Path.size())/2<<endl;
        for(auto i=Path.begin();i<Path.end();i=i+2){
            testcase<<*i<<' ';
            testcase<<*(i+1)<<endl;
        }
    }
    testcase.close();

    for (int i = 0; i <=n+1; i++){
        delete [] M[i];
    }
         delete [] M;

    return 0;
}


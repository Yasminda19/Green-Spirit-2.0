#include <stdio.h>
char maze[100][100];
int find_path(int x,int y,int z){
    if(x>=z-1 || x<=0 || y>=z-1 || y<=0) return 0;
    if(maze[x][y]=='Y') return 1;
    if(maze[x][y]=='#') return 0;
    if(maze[x][y]=='0') return 0;
    if(maze[x][y]=='Z') return 0;
    maze[x][y]='0';
    if(find_path(x-1,y,z)== 1) return 1;
    if(find_path(x,y-1,z)== 1) return 1;
    if(find_path(x+1,y,z)== 1) return 1;
    if(find_path(x,y+1,z)== 1) return 1;
    maze[x][y]='Z';
    return 0;
}
int main(){
    int start[2];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",&maze[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(maze[i][j]=='X'){
                start[1]=i;
                start[2]=j;
            }
        }
    }
    find_path(start[1],start[2],n);
    maze[start[1]][start[2]]='S';
    for(int i=0;i<n;i++){
        printf("%s\n",maze[i]);
    }
}

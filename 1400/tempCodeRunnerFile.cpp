if(maze[x + i][1 - y]){
                if(maze[x][y] % 2 && maze[x + i][1 - y] % 2) cnt ++;
                else cnt --;
            }
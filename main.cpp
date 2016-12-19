#include <iostream>
#include <fstream>

char tranningData[] = "./tranning.txt";
int status[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,1,2,0,0,0},{0,0,0,2,1,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
void getAccessibleWhite(int Whites[8][8]);
void getAccessibleBlack(int Blacks[8][8]);
void doWhite(int directionX,int directionY);
void doBlack(int directionX,int directionY);
int isEnd();
int main(){
    srand(time(NULL));
    std::ofstream fout(tranningData);
    while(!isEnd()){
        int directionX,directionY;
        int Whites[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
        getAccessibleWhite(Whites);
        int noNext = 1;
        for(int i=0 ;i < 8 ;i++){
            for (int j=0 ;j < 8 ;j++){
                if(Whites[i][j] == 1){
                    noNext = 0;
                }
            }
        }
        if (!noNext) {
            do{
                directionX = rand() % 8 + 0;
                directionY = rand() % 8 + 0;
            }while(Whites[directionX][directionY] != 1);
            doWhite(directionX,directionY);
            fout<<"next is "<<directionX<<","<<directionY<<std::endl;
            for(int i=0 ;i < 8 ;i++){
                for (int j=0 ;j < 8 ;j++){
                    fout<<status[i][j]<<" ";
                }
                fout<<std::endl;
            }
            fout<<std::endl;
        }
        if(!isEnd()){
            int Blacks[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
            getAccessibleBlack(Blacks);
            int noNext = 1;
            for(int i=0 ;i < 8 ;i++){
                for (int j=0 ;j < 8 ;j++){
                    if(Blacks[i][j] == 1){
                        noNext = 0;
                    }
                }
            }
            if (noNext) {
                break;
            }
            do{
                directionX = rand() % 8 + 0;
                directionY = rand() % 8 + 0;
            }while(Blacks[directionX][directionY] != 1);
            doBlack(directionX,directionY);
            fout<<"next is "<<directionX<<","<<directionY<<std::endl;
        }
        for(int i=0 ;i < 8 ;i++){
            for (int j=0 ;j < 8 ;j++){
                fout<<status[i][j]<<" ";
            }
            fout<<std::endl;
        }
        fout<<std::endl;
    }
    int sumWhite = 0,sumBlack = 0;
    for(int i=0 ;i < 8 ;i++){
        for (int j=0 ;j < 8 ;j++){
            if(status[i][j] == 1){
                sumWhite++;
            }else if(status[i][j] == 2){
                sumBlack++;
            }
        }
    }
    if(sumWhite > sumBlack){
        fout<<"white is "<<sumWhite<<" black is "<<sumBlack<<" white win"<<std::endl;
    }else if(sumWhite < sumBlack){
        fout<<"white is "<<sumWhite<<" black is "<<sumBlack<<" Black win"<<std::endl;
    }else{
        fout<<"white is "<<sumWhite<<" black is "<<sumBlack<<" Draw"<<std::endl;
    }
    return 0;
}
void getAccessibleWhite(int Whites[8][8]){
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0; j < 8 ; j++){
            if(status[i][j] == 0){
                int k,v;
                for(k = i - 2; k >= 0 ; k--){
                    if(status[k][j] == 1 && status[i - 1][j] == 2){
                        Whites[i][j] = 1;
                        break;
                    }
                }
                for(k = i + 2; k <= 7 ; k++){
                    if(status[k][j] == 1 && status[i + 1][j] == 2){
                        Whites[i][j] = 1;
                        break;
                    }
                }
                for(v = j - 2; v >= 0; v--){
                    if(status[i][v] == 1 && status[i][j - 1] == 2){
                        Whites[i][j] = 1;
                        break;
                    }
                }
                for(v = j + 2; v <= 7; v++){
                    if(status[i][v] == 1 && status[i][j + 1] == 2){
                        Whites[i][j] = 1;
                        break;
                    }
                }
                k = i - 2;
                v = j - 2;
                while(k >= 0 && v >= 0){
                    if(status[k][v] == 1 && status[i - 1][j - 1] == 2){
                        Whites[i][j] = 1;
                        break;
                    }
                    k--;
                    v--;
                }
                k = i + 2;
                v = j - 2;
                while(k <= 7 && v >= 0){
                    if(status[k][v] == 1 && status[i + 1][j - 1] == 2){
                        Whites[i][j] = 1;
                        break;
                    }
                    k++;
                    v--;
                }
                k = i - 2;
                v = j + 2;
                while(k >= 0 && v <= 7){
                    if(status[k][v] == 1 && status[i - 1][j + 1] == 2){
                        Whites[i][j] = 1;
                        break;
                    }
                    k--;
                    v++;
                }
                k = i + 2;
                v = j + 2;
                while(k <= 7 && v <= 7){
                    if(status[k][v] == 1 && status[i + 1][j + 1] == 2){
                        Whites[i][j] = 1;
                        break;
                    }
                    k++;
                    v++;
                }
            }
        }
    }
}
void getAccessibleBlack(int Blacks[8][8]){
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0; j < 8 ; j++){
            if(status[i][j] == 0){
                int k,v;
                for(k = i - 2; k >= 0 ; k--){
                    if(status[k][j] == 2 && status[i - 1][j] == 1){
                        Blacks[i][j] = 1;
                        break;
                    }
                }
                for(k = i + 2; k <= 7 ; k++){
                    if(status[k][j] == 2 && status[i + 1][j] == 1){
                        Blacks[i][j] = 1;
                        break;
                    }
                }
                for(v = j - 2; v >= 0; v--){
                    if(status[i][v] == 2 && status[i][j - 1] == 1){
                        Blacks[i][j] = 1;
                        break;
                    }
                }
                for(v = j + 2; v <= 7; v++){
                    if(status[i][v] == 2 && status[i][j + 1] == 1){
                        Blacks[i][j] = 1;
                        break;
                    }
                }
                k = i - 2;
                v = j - 2;
                while(k >= 0 && v >= 0){
                    if(status[k][v] == 2 && status[i - 1][j - 1] == 1){
                        Blacks[i][j] = 1;
                        break;
                    }
                    k--;
                    v--;
                }
                k = i + 2;
                v = j - 2;
                while(k <= 7 && v >= 0){
                    if(status[k][v] == 2 && status[i + 1][j - 1] == 1){
                        Blacks[i][j] = 1;
                        break;
                    }
                    k++;
                    v--;
                }
                k = i - 2;
                v = j + 2;
                while(k >= 0 && v <= 7){
                    if(status[k][v] == 2 && status[i - 1][j + 1] == 1){
                        Blacks[i][j] = 1;
                        break;
                    }
                    k--;
                    v++;
                }
                k = i + 2;
                v = j + 2;
                while(k <= 7 && v <= 7){
                    if(status[k][v] == 2 && status[i + 1][j + 1] == 1){
                        Blacks[i][j] = 1;
                        break;
                    }
                    k++;
                    v++;
                }
            }
        }
    }
}
void doWhite(int directionX,int directionY){
    int k,v;
    status[directionX][directionY] = 1;
    for(k = directionX - 2; k >= 0 ; k--){
        if(status[k][directionY] == 1 && status[directionX - 1][directionY] == 2){
            for(int x = directionX - 1 ; x >= k + 1; x--){
                status[x][directionY] = 1;
            }
            break;
        }
    }
    for(k = directionX + 2; k <= 7 ; k++){
        if(status[k][directionY] == 1 && status[directionX + 1][directionY] == 2){
            for(int x = directionX + 1 ; x <= k - 1 ; x++){
                status[x][directionY] = 1;
            }
            break;
        }
    }
    for(v = directionY - 2; v >= 0; v--){
        if(status[directionX][v] == 1 && status[directionX][directionY - 1] == 2){
            for(int x = directionY - 1 ; x >= v + 1; x--){
                status[directionX][x] = 1;
            }
            break;
        }
    }
    for(v = directionY + 2; v <= 7; v++){
        if(status[directionX][v] == 1 && status[directionX][directionY + 1] == 2){
            for(int x = directionY + 1 ; x <= v - 1; x++){
                status[directionX][x] = 1;
            }
            break;
        }
    }
    k = directionX - 2;
    v = directionY - 2;
    while(k >= 0 && v >= 0){
        if(status[k][v] == 1 && status[directionX - 1][directionY - 1] == 2){
            int x,y;
            x = directionX - 1;
            y = directionY - 1;
            while(x >= k + 1 && y >= v + 1){
                status[x][y] = 1;
                x--;
                y--;
            }
        }
        k--;
        v--;
    }
    k = directionX + 2;
    v = directionY - 2;
    while(k <= 7 && v >= 0){
        if(status[k][v] == 1  && status[directionX + 1][directionY - 1] == 2){
            int x,y;
            x = directionX + 1;
            y = directionY - 1;
            while(x <= k - 1 && y >= v + 1){
                status[x][y] = 1;
                x++;
                y--;
            }
        }

        k++;
        v--;
    }
    k = directionX - 2;
    v = directionY + 2;
    while(k >= 0 && v <= 7){
        if(status[k][v] == 1  && status[directionX - 1][directionY + 1] == 2){
            int x,y;
            x = directionX - 1;
            y = directionY + 1;
            while(x >= k + 1 && y <= v - 1){
                status[x][y] = 1;
                x--;
                y++;
            }
        }
        k--;
        v++;
    }
    k = directionX + 2;
    v = directionY + 2;
    while(k <= 7 && v <= 7){
        if(status[k][v] == 1  && status[directionX + 1][directionY + 1] == 2){
            int x,y;
            x = directionX + 1;
            y = directionY + 1;
            while(x <= k - 1 && y <= v - 1){
                status[x][y] = 1;
                x++;
                y++;
            }
        }
        k++;
        v++;
    }

}
void doBlack(int directionX,int directionY){
    int k,v;
    status[directionX][directionY] = 2;
    for(k = directionX - 2; k >= 0 ; k--){
        if(status[k][directionY] == 2 && status[directionX - 1][directionY] == 1){
            for(int x = directionX - 1 ; x >= k + 1 ; x--){
                status[x][directionY] = 2;
            }
            break;
        }
    }
    for(k = directionX + 2; k <= 7 ; k++){
        if(status[k][directionY] == 2 && status[directionX + 1][directionY] == 1){
            for(int x = directionX + 1 ; x <= k - 1; x++){
                status[x][directionY] = 2;
            }
            break;
        }
    }
    for(v = directionY - 2; v >= 0; v--){
        if(status[directionX][v] == 2 && status[directionX][directionY - 1] == 1){
            for(int x = directionY - 1 ; x >= v + 1; x--){
                status[directionX][x] = 2;
            }
            break;
        }
    }
    for(v = directionY + 2; v <= 7; v++){
        if(status[directionX][v] == 2 && status[directionX][directionY + 1] == 1){
            for(int x = directionY + 1 ; x <= v - 1; x++){
                status[directionX][x] = 2;
            }
            break;
        }
    }
    k = directionX - 2;
    v = directionY - 2;
    while(k >= 0 && v >= 0){
        if(status[k][v] == 2 && status[directionX - 1][directionY - 1] == 1){
            int x,y;
            x = directionX - 1;
            y = directionY - 1;
            while(x >= k + 1 && y >= v + 1){
                status[x][y] = 2;
                x--;
                y--;
            }
        }
        k--;
        v--;
    }
    k = directionX + 2;
    v = directionY - 2;
    while(k <= 7 && v >= 0){
        if(status[k][v] == 2  && status[directionX + 1][directionY - 1] == 1){
            int x,y;
            x = directionX + 1;
            y = directionY - 1;
            while(x <= k - 1 && y >= v + 1){
                status[x][y] = 2;
                x++;
                y--;
            }
        }

        k++;
        v--;
    }
    k = directionX - 2;
    v = directionY + 2;
    while(k >= 0 && v <= 7){
        if(status[k][v] == 2  && status[directionX - 1][directionY + 1] == 1){
            int x,y;
            x = directionX - 1;
            y = directionY + 1;
            while(x >= k + 1 && y <= v - 1){
                status[x][y] = 2;
                x--;
                y++;
            }
        }
        k--;
        v++;
    }
    k = directionX + 2;
    v = directionY + 2;
    while(k <= 7 && v <= 7){
        if(status[k][v] == 2  && status[directionX + 1][directionY + 1] == 1){
            int x,y;
            x = directionX + 1;
            y = directionY + 1;
            while(x <= k - 1 && y <= v - 1){
                status[x][y] = 2;
                x++;
                y++;
            }
        }
        k++;
        v++;
    }
}
int isEnd(){
    for(int i=0 ; i < 8 ; i++){
        for(int j=0 ; j < 8 ; i++){
            if(status[i][j] == 0){
                return 0;
            }
        }
    }
    return 1;
}
#include <iostream>
#include <fstream>
#include <sstream>

typedef struct leaf{
    int index;
    void *last;
    int status[8][8];
} node;

char tranningData[] = "./tranning.txt";
int status[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,1,2,0,0,0},{0,0,0,2,1,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
void getAccessibleWhite(int stat[8][8],int Whites[8][8]);
void getAccessibleBlack(int stat[8][8],int Blacks[8][8]);
void doWhiteToStatus(int directionX,int directionY,int stat[8][8]);
void doBlackToStatus(int directionX,int directionY,int stat[8][8]);
void arrayToArray(int origin[8][8],int data[8][8]);
int doBlackIntelligence();
int doWhiteIntelligence();
int isEnd();
int main(){
    std::ofstream fout(tranningData);
    srand(time(NULL));
    int i,j;
    int winWhite = 0,winBlack = 0;
    for(int tranning = 1;tranning <= 1;tranning ++){
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                status[i][j] = 0;
            }
        }
        status[3][3] = 1;
        status[3][4] = 2;
        status[4][3] = 2;
        status[4][4] = 1;
        while (!isEnd()) {
            int directionX, directionY;
            int Whites[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0}};
            getAccessibleWhite(status,Whites);
            int noNext = 1;
            for (i = 0; i < 8; i++) {
                for (j = 0; j < 8; j++) {
                    if (Whites[i][j] == 1) {
                        noNext = 0;
                    }
                }
            }
            if (!noNext) {
                /*do {
                 directionX = rand() % 6 + 0;
                 directionY = rand() % 6 + 0;
                 } while (Whites[directionX][directionY] != 1);
                 doWhiteToStatus(directionX, directionY,status);
                 //fout << "nw" << directionX << "," << directionY << std::endl;
                 std::cout<< "nw" << directionX<<directionY << " "<<std::endl;;*/
                doWhiteIntelligence();
                std::cout<<"  ";
                for (i = 0; i < 8; i++) {
                    std::cout<<"\033[1;32m"<<i<<"\033[0m ";
                }
                std::cout<<std::endl;
                for (i = 0; i < 8; i++) {
                    std::cout<<"\033[1;32m"<<i<<"\033[0m ";
                    for (j = 0; j < 8; j++) {
                        //fout << status[i][j];
                        if(status[i][j] == 1){
                            std::cout<<"○ ";
                        }else if(status[i][j] == 2){
                            std::cout<<"● ";
                        }else {
                            std::cout << "□ ";
                        }
                    }
                    std::cout << std::endl;
                }
                //fout << std::endl;
                std::cout<<std::endl;
            }
            if (!isEnd()) {
                int Blacks[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0}};
                getAccessibleBlack(status,Blacks);
                int noNext = 1;
                for (i = 0; i < 8; i++) {
                    for (j = 0; j < 8; j++) {
                        if (Blacks[i][j] == 1) {
                            noNext = 0;
                        }
                    }
                }
                if (noNext) {
                    break;
                }
                do{
                    std::cout<<"input where you want to input like 2 1" << std::endl;
                    scanf("%d %d",&directionX,&directionY);
                }while(Blacks[directionX][directionY]!=1);
                /*do {
                 directionX = rand() % 6 + 0;
                 directionY = rand() % 6 + 0;
                 } while (Blacks[directionX][directionY] != 1);*/
                doBlackToStatus(directionX, directionY,status);
                std::cout << "nb" << directionX << directionY << std::endl;
                //oss << "nb" << directionX <<directionY << " ";
                //doBlackIntelligence();
                std::cout<<"  ";
                for (i = 0; i < 8; i++) {
                    std::cout<<"\033[1;32m"<<i<<"\033[0m ";
                }
                std::cout<<std::endl;
                for (i = 0; i < 8; i++) {
                    std::cout<<"\033[1;32m"<<i<<"\033[0m ";
                    for (j = 0; j < 8; j++) {
                        //fout << status[i][j];
                        if(status[i][j] == 1){
                            std::cout<<"○ ";
                        }else if(status[i][j] == 2){
                            std::cout<<"● ";
                        }else {
                            std::cout << "□ ";
                        }
                    }
                    std::cout << std::endl;
                }
                //fout << std::endl;
                std::cout<<std::endl;
            }
        }
        int sumWhite = 0, sumBlack = 0;
        for (i = 0; i < 8; i++) {
            for (j = 0; j <8; j++) {
                if (status[i][j] == 1) {
                    sumWhite++;
                } else if (status[i][j] == 2) {
                    sumBlack++;
                }
            }
        }
        if (sumWhite > sumBlack) {
            std::cout << "w" << sumWhite << "b" << sumBlack << "w" << std::endl;
            winWhite++;
            //oss << "w" << " ";
        } else if (sumWhite < sumBlack) {
            std::cout << "w" << sumWhite << "b" << sumBlack << "l" << std::endl;
            winBlack++;
            //oss << "l" << " ";
        } else {
            std::cout << "w" << sumWhite << "b" << sumBlack << "d" << std::endl;
            //oss << "d" << " ";
        }
    }
    std::cout << "w " << winWhite << " b " << winBlack << std::endl;
    return 0;
}
int doWhiteIntelligence(){
    printf("thinking!!!");
    int directionX,directionY,i,j,depth,first = 1;
    int nowStatus[8][8];
    for (int k = 0; k < 8; ++k) {
        for (int l = 0; l < 8; ++l) {
            nowStatus[k][l] = status[k][l];
        }
    }
    int Whites[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};
    getAccessibleWhite(nowStatus,Whites);
    int noNext = 1;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (Whites[i][j] == 1) {
                noNext = 0;
                first++;
            }
        }
    }
    if (noNext) {
        return -1;
    }
    node* nodes = new node[10000000];
    arrayToArray(nodes[0].status,nowStatus);
    nodes[0].index = 0;
    int lastLocat = 0,locat = 0;
    int doWhat = 0;
    int firstX[65];
    int firstY[65];
    int win[65];
    int total[65];
    double right[65];
    int randIndex[65];
    for(i = 0;i < 65 ; i++){
        firstX[i] = -1;
        firstY[i] = -1;
        win[i] = 0;
        total[i] = -1;
        right[i] = 0.0;
        randIndex[i] = 0;
    }
    for(depth = 0 ; depth< 5 ; depth++){
        int nodeNum = 0;
        int noNext = 1;
        for(int i = lastLocat ; i <= locat ; ++i){
            int tempStatus[8][8];
            if(doWhat == 1){
                int Blacks[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0}};
                getAccessibleBlack(nodes[i].status,Blacks);
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if (Blacks[k][l] == 1) {
                            noNext = 0;
                        }
                    }
                }
                if (noNext) {
                    break;
                }
                for (int k = 0; k < 8; ++k) {
                    for (int l = 0; l < 8; ++l) {
                        if (Blacks[k][l] == 1) {
                            arrayToArray(tempStatus, nodes[i].status);
                            doBlackToStatus(k, l, tempStatus);
                            nodeNum++;
                            arrayToArray(nodes[nodeNum + locat].status, tempStatus);
                            nodes[nodeNum + locat].last = &nodes[i];
                            nodes[nodeNum + locat].index = nodeNum + locat;
                            if(depth == 0){
                                firstX[nodeNum + locat] = k;
                                firstY[nodeNum + locat] = l;
                            }
                        }
                    }
                }
            }else{
                int Whites[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0}};
                getAccessibleWhite(nodes[i].status,Whites);
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if (Whites[k][l] == 1) {
                            noNext = 0;
                        }
                    }
                }
                if (noNext) {
                    break;
                }
                for (int k = 0; k < 8; ++k) {
                    for (int l = 0; l < 8; ++l) {
                        if (Whites[k][l] == 1) {
                            arrayToArray(tempStatus, nodes[i].status);
                            doWhiteToStatus(k, l, tempStatus);
                            nodeNum++;
                            arrayToArray(nodes[nodeNum + locat].status, tempStatus);
                            nodes[nodeNum + locat].last = &nodes[i];
                            nodes[nodeNum + locat].index = nodeNum + locat;
                            if(depth == 0){
                                firstX[nodeNum + locat] = k;
                                firstY[nodeNum + locat] = l;
                            }
                        }
                    }
                }
            }
        }
        if(nodeNum != 0){
            lastLocat = locat + 1;
        }
        locat += nodeNum;
        if(doWhat == 1){
            doWhat = 0;
        }else{
            doWhat = 1;
        }
        if(noNext){
            break;
        }
    }
    for(i = lastLocat ; i <= locat ; i++){
        int isWin = 0;
        node tempnode;
        tempnode = nodes[i];
        int sumWhite = 0, sumBlack = 0;
        for (int k = 0; k < 8; k++) {
            for (int l = 0; l < 8; l++) {
                if (nodes[i].status[k][l] == 1) {
                    sumWhite++;
                } else if (nodes[i].status[k][l] == 2) {
                    sumBlack++;
                }
            }
        }
        if (sumWhite > sumBlack) {
            isWin = 1;
        }
        while(tempnode.index >= first){
            tempnode = *(node*)(tempnode.last);
        }
        if(total[tempnode.index] == -1){
            total[tempnode.index]+=1;
        }
        total[tempnode.index] += 1;
        if(isWin){
            win[tempnode.index] += 1;
        }
    }
    double maxWin = 0.0;
    int maxIndex = 1;
    for( i = 1 ; i<=64 ; i++){
        double dis = 0.0;
        if(firstX[i] == -1){
            continue;
        }
        if(firstX[i] > 4 && firstY[i] > 4){
            dis = (double)(firstX[i] - 7 + firstY[i] - 7) / 100.0;
        }else if(firstX[i] < 3 && firstY[i] > 4){
            dis = (double)(firstX[i] - 0 + firstY[i] - 7) / 100.0;
        }else if(firstX[i] > 4 && firstY[i] < 3){
            dis = (double)(firstX[i] - 7 + firstY[i] - 0) / 100.0;
        }else if(firstX[i] < 3 && firstY[i] < 3) {
            dis = (double) (firstX[i] - 0 + firstY[i] - 0) / 100.0;
        }
        //corner
        if(firstX[i] == 0 && firstY[i] == 0){
            dis = 1;
        }else if(firstX[i] == 0 && firstY[i] == 7){
            dis = 1;
        }else if(firstX[i] == 7 && firstY[i] == 0){
            dis = 1;
        }else if(firstX[i] == 7 && firstY[i] == 7){
            dis = 1;
        }
        //near corner
        if(firstX[i] == 0 && firstY[i] == 1){
            dis = -0.5;
        }else if(firstX[i] == 1 && firstY[i] == 0){
            dis = -0.5;
        }else if(firstX[i] == 1 && firstY[i] == 1){
            dis = -0.5;
        }else if(firstX[i] == 0 && firstY[i] == 6){
            dis = -0.5;
        }else if(firstX[i] == 1 && firstY[i] == 6){
            dis = -0.5;
        }else if(firstX[i] == 1 && firstY[i] == 7){
            dis = -0.5;
        }else if(firstX[i] == 6 && firstY[i] == 0){
            dis = -0.5;
        }else if(firstX[i] == 6 && firstY[i] == 1){
            dis = -0.5;
        }else if(firstX[i] == 7 && firstY[i] == 1){
            dis = -0.5;
        }else if(firstX[i] == 7 && firstY[i] == 6){
            dis = -0.5;
        }else if(firstX[i] == 6 && firstY[i] == 6){
            dis = -0.5;
        }else if(firstX[i] == 6 && firstY[i] == 7){
            dis = -0.5;
        }
        right[i] = (double)win[i]/(double)total[i] + dis;
        if(right[i] > maxWin && total[i] != -1){
            maxWin = right[i];
            maxIndex = i;
        }
    }
    int radi = 0;
    for (i = 1; i<= 64; i++) {
        if(right[i] == maxWin && total[i] != -1){
            randIndex[radi++] = i;
        }
    }
    int randNum;
    do{
        randNum = rand() % radi + 0;
        directionX = firstX[randIndex[randNum]];
        directionY = firstY[randIndex[randNum]];
    }while(Whites[directionX][directionY] != 1);
    doWhiteToStatus(directionX,directionY,status);
    std::cout << "nw" << directionX << directionY <<std::endl;;
    return 0;
}
int doBlackIntelligence(){
    printf("thinking!!!");
    int directionX,directionY,i,j,depth,first = 1;
    int nowStatus[8][8];
    for (int k = 0; k < 8; ++k) {
        for (int l = 0; l < 8; ++l) {
            nowStatus[k][l] = status[k][l];
        }
    }
    int Blacks[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};
    getAccessibleBlack(nowStatus,Blacks);
    int noNext = 1;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (Blacks[i][j] == 1) {
                noNext = 0;
                first++;
            }
        }
    }
    if (noNext) {
        return -1;
    }
    node* nodes = new node[1000000];
    arrayToArray(nodes[0].status,nowStatus);
    nodes[0].index = 0;
    int lastLocat = 0,locat = 0;
    int doWhat = 1;
    int firstX[65];
    int firstY[65];
    int win[65];
    int total[65];
    for(i = 0;i < 65 ; i++){
        firstX[i] = 0;
        firstY[i] = 0;
        win[i] = 0;
        total[i] = -1;
    }
    for(depth = 0 ; depth< 7 ; depth++){
        int nodeNum = 0;
        int noNext = 1;
        for(int i = lastLocat ; i <= locat ; ++i){
            int tempStatus[8][8];
            if(doWhat == 1){
                int Blacks[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0}};
                getAccessibleBlack(nodes[i].status,Blacks);
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if (Blacks[k][l] == 1) {
                            noNext = 0;
                        }
                    }
                }
                if (noNext) {
                    break;
                }
                for (int k = 0; k < 8; ++k) {
                    for (int l = 0; l < 8; ++l) {
                        if (Blacks[k][l] == 1) {
                            arrayToArray(tempStatus, nodes[i].status);
                            doBlackToStatus(k, l, tempStatus);
                            nodeNum++;
                            arrayToArray(nodes[nodeNum + locat].status, tempStatus);
                            nodes[nodeNum + locat].last = &nodes[i];
                            nodes[nodeNum + locat].index = nodeNum + locat;
                            if(depth == 0){
                                firstX[nodeNum + locat] = k;
                                firstY[nodeNum + locat] = l;
                            }
                        }
                    }
                }
            }else{
                int Whites[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0}};
                getAccessibleWhite(nodes[i].status,Whites);
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if (Whites[k][l] == 1) {
                            noNext = 0;
                        }
                    }
                }
                if (noNext) {
                    break;
                }
                for (int k = 0; k < 8; ++k) {
                    for (int l = 0; l < 8; ++l) {
                        if (Whites[k][l] == 1) {
                            arrayToArray(tempStatus, nodes[i].status);
                            doWhiteToStatus(k, l, tempStatus);
                            nodeNum++;
                            arrayToArray(nodes[nodeNum + locat].status, tempStatus);
                            nodes[nodeNum + locat].last = &nodes[i];
                            nodes[nodeNum + locat].index = nodeNum + locat;
                            if(depth == 0){
                                firstX[nodeNum + locat] = k;
                                firstY[nodeNum + locat] = l;
                            }
                        }
                    }
                }
            }
        }
        if(nodeNum != 0){
            lastLocat = locat + 1;
        }
        locat += nodeNum;
        if(doWhat == 1){
            doWhat = 0;
        }else{
            doWhat = 1;
        }
        if(noNext){
            break;
        }
    }
    for(i = lastLocat ; i <= locat ; i++){
        int isWin = 0;
        node tempnode;
        tempnode = nodes[i];
        int sumWhite = 0, sumBlack = 0;
        for (int k = 0; k < 8; k++) {
            for (int l = 0; l < 8; l++) {
                if (nodes[i].status[k][l] == 1) {
                    sumWhite++;
                } else if (nodes[i].status[k][l] == 2) {
                    sumBlack++;
                }
            }
        }
        if (sumWhite < sumBlack) {
            isWin = 1;
        }
        while(tempnode.index >= first){
            tempnode = *(node*)(tempnode.last);
        }
        if(total[tempnode.index] == -1){
            total[tempnode.index]+=1;
        }
        total[tempnode.index] += 1;
        if(isWin){
            win[tempnode.index] += 1;
        }
    }
    double maxWin = 0.0;
    int maxIndex = 1;
    for( i = 1 ; i<=64 ; i++){
        double dis = 0.0;
        if(firstX[i] > 4 && firstY[i] > 4){
            dis = (double)(firstX[i] - 7 + firstY[i] - 7) / 10.0;
        }else if(firstX[i] < 3 && firstY[i] > 4){
            dis = (double)(firstX[i] - 0 + firstY[i] - 7) / 10.0;
        }else if(firstX[i] > 4 && firstY[i] < 3){
            dis = (double)(firstX[i] - 7 + firstY[i] - 0) / 10.0;
        }else if(firstX[i] < 3 && firstY[i] < 3) {
            dis = (double) (firstX[i] - 0 + firstY[i] - 0) / 10.0;
        }
        //corner
        if(firstX[i] == 0 && firstY[i] == 0){
            dis = 1;
        }else if(firstX[i] == 0 && firstY[i] == 7){
            dis = 1;
        }else if(firstX[i] == 7 && firstY[i] == 0){
            dis = 1;
        }else if(firstX[i] == 7 && firstY[i] == 7){
            dis = 1;
        }
        //near corner
        if(firstX[i] == 0 && firstY[i] == 1){
            dis = -0.5;
        }else if(firstX[i] == 1 && firstY[i] == 0){
            dis = -0.5;
        }else if(firstX[i] == 1 && firstY[i] == 1){
            dis = -0.5;
        }else if(firstX[i] == 0 && firstY[i] == 6){
            dis = -0.5;
        }else if(firstX[i] == 1 && firstY[i] == 6){
            dis = -0.5;
        }else if(firstX[i] == 1 && firstY[i] == 7){
            dis = -0.5;
        }else if(firstX[i] == 6 && firstY[i] == 0){
            dis = -0.5;
        }else if(firstX[i] == 6 && firstY[i] == 1){
            dis = -0.5;
        }else if(firstX[i] == 7 && firstY[i] == 1){
            dis = -0.5;
        }else if(firstX[i] == 7 && firstY[i] == 6){
            dis = -0.5;
        }else if(firstX[i] == 6 && firstY[i] == 6){
            dis = -0.5;
        }else if(firstX[i] == 6 && firstY[i] == 7){
            dis = -0.5;
        }
        if((double)win[i]/(double)total[i] + dis > maxWin && total[i] != -1){
            maxWin = (double)win[i]/(double)total[i];
            maxIndex = i;
        }
    }
    int randIndex[65];
    int radi = 0;
    for (i = 1; i<= 64; i++) {
        double dis = 0.0;
        if(firstX[randIndex[i]] > 4 && firstY[randIndex[i]] > 4){
            dis = (double)(firstX[randIndex[i]] - 7 + firstY[randIndex[i]] - 7) / 10.0;
        }else if(firstX[randIndex[i]] < 3 && firstY[randIndex[i]] > 4){
            dis = (double)(firstX[randIndex[i]] - 0 + firstY[randIndex[i]] - 7) / 10.0;
        }else if(firstX[randIndex[i]] > 4 && firstY[randIndex[i]] < 3){
            dis = (double)(firstX[randIndex[i]] - 7 + firstY[randIndex[i]] - 0) / 10.0;
        }else if(firstX[randIndex[i]] < 3 && firstY[randIndex[i]] < 3) {
            dis = (double) (firstX[randIndex[i]] - 0 + firstY[randIndex[i]] - 0) / 10.0;
        }
        //corner
        if(firstX[randIndex[i]] == 0 && firstY[randIndex[i]] == 0){
            dis = 1;
        }else if(firstX[randIndex[i]] == 0 && firstY[randIndex[i]] == 7){
            dis = 1;
        }else if(firstX[randIndex[i]] == 7 && firstY[randIndex[i]] == 0){
            dis = 1;
        }else if(firstX[randIndex[i]] == 7 && firstY[randIndex[i]] == 7){
            dis = 1;
        }
        //near corner
        if(firstX[randIndex[i]] == 0 && firstY[randIndex[i]] == 1){
            dis = -0.5;
        }else if(firstX[randIndex[i]] == 1 && firstY[randIndex[i]] == 0){
            dis = -0.5;
        }else if(firstX[randIndex[i]] == 1 && firstY[randIndex[i]] == 1){
            dis = -0.5;
        }else if(firstX[randIndex[i]] == 0 && firstY[randIndex[i]] == 6){
            dis = -0.5;
        }else if(firstX[randIndex[i]] == 1 && firstY[randIndex[i]] == 6){
            dis = -0.5;
        }else if(firstX[randIndex[i]] == 1 && firstY[randIndex[i]] == 7){
            dis = -0.5;
        }else if(firstX[randIndex[i]] == 6 && firstY[randIndex[i]] == 0){
            dis = -0.5;
        }else if(firstX[randIndex[i]] == 6 && firstY[randIndex[i]] == 1){
            dis = -0.5;
        }else if(firstX[randIndex[i]] == 7 && firstY[randIndex[i]] == 1){
            dis = -0.5;
        }else if(firstX[randIndex[i]] == 7 && firstY[randIndex[i]] == 6){
            dis = -0.5;
        }else if(firstX[randIndex[i]] == 6 && firstY[randIndex[i]] == 6){
            dis = -0.5;
        }else if(firstX[randIndex[i]] == 6 && firstY[randIndex[i]] == 7){
            dis = -0.5;
        }
        if((double)win[randIndex[i]]/(double)total[randIndex[i]] + dis == maxWin && total[i] != -1){
            randIndex[radi++] = i;
        }
    }
    int randNum = rand() % radi + 0;;
    directionX = firstX[randIndex[randNum]];
    directionY = firstY[randIndex[randNum]];
    doBlackToStatus(directionX,directionY,status);
    std::cout << "nb" << directionX << directionY <<std::endl;;
    return 0;
}
void getAccessibleWhite(int stat[8][8],int Whites[8][8]){
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0; j < 8 ; j++){
            if(stat[i][j] == 0){
                int k,v;
                for(k = i - 2; k >= 0 ; k--){
                    if(stat[k][j] == 1 && stat[i - 1][j] == 2){
                        Whites[i][j] = 1;
                        break;
                    }
                }
                for(k = i + 2; k <= 7 ; k++){
                    if(stat[k][j] == 1 && stat[i + 1][j] == 2){
                        Whites[i][j] = 1;
                        break;
                    }
                }
                for(v = j - 2; v >= 0; v--){
                    if(stat[i][v] == 1 && stat[i][j - 1] == 2){
                        Whites[i][j] = 1;
                        break;
                    }
                }
                for(v = j + 2; v <= 7; v++){
                    if(stat[i][v] == 1 && stat[i][j + 1] == 2){
                        Whites[i][j] = 1;
                        break;
                    }
                }
                k = i - 2;
                v = j - 2;
                while(k >= 0 && v >= 0){
                    if(stat[k][v] == 1 && stat[i - 1][j - 1] == 2){
                        Whites[i][j] = 1;
                        break;
                    }
                    k--;
                    v--;
                }
                k = i + 2;
                v = j - 2;
                while(k <= 7 && v >= 0){
                    if(stat[k][v] == 1 && stat[i + 1][j - 1] == 2){
                        Whites[i][j] = 1;
                        break;
                    }
                    k++;
                    v--;
                }
                k = i - 2;
                v = j + 2;
                while(k >= 0 && v <= 7){
                    if(stat[k][v] == 1 && stat[i - 1][j + 1] == 2){
                        Whites[i][j] = 1;
                        break;
                    }
                    k--;
                    v++;
                }
                k = i + 2;
                v = j + 2;
                while(k <= 7 && v <= 7){
                    if(stat[k][v] == 1 && stat[i + 1][j + 1] == 2){
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
void getAccessibleBlack(int stat[8][8],int Blacks[8][8]){
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0; j < 8 ; j++){
            if(stat[i][j] == 0){
                int k,v;
                for(k = i - 2; k >= 0 ; k--){
                    if(stat[k][j] == 2 && stat[i - 1][j] == 1){
                        Blacks[i][j] = 1;
                        break;
                    }
                }
                for(k = i + 2; k <= 7 ; k++){
                    if(stat[k][j] == 2 && stat[i + 1][j] == 1){
                        Blacks[i][j] = 1;
                        break;
                    }
                }
                for(v = j - 2; v >= 0; v--){
                    if(stat[i][v] == 2 && stat[i][j - 1] == 1){
                        Blacks[i][j] = 1;
                        break;
                    }
                }
                for(v = j + 2; v <= 7; v++){
                    if(stat[i][v] == 2 && stat[i][j + 1] == 1){
                        Blacks[i][j] = 1;
                        break;
                    }
                }
                k = i - 2;
                v = j - 2;
                while(k >= 0 && v >= 0){
                    if(stat[k][v] == 2 && stat[i - 1][j - 1] == 1){
                        Blacks[i][j] = 1;
                        break;
                    }
                    k--;
                    v--;
                }
                k = i + 2;
                v = j - 2;
                while(k <= 7 && v >= 0){
                    if(stat[k][v] == 2 && stat[i + 1][j - 1] == 1){
                        Blacks[i][j] = 1;
                        break;
                    }
                    k++;
                    v--;
                }
                k = i - 2;
                v = j + 2;
                while(k >= 0 && v <= 7){
                    if(stat[k][v] == 2 && stat[i - 1][j + 1] == 1){
                        Blacks[i][j] = 1;
                        break;
                    }
                    k--;
                    v++;
                }
                k = i + 2;
                v = j + 2;
                while(k <= 7 && v <= 7){
                    if(stat[k][v] == 2 && stat[i + 1][j + 1] == 1){
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
void doWhiteToStatus(int directionX,int directionY,int stat[8][8]){
    int k,v;
    stat[directionX][directionY] = 1;
    for(k = directionX - 2; k >= 0 ; k--){
        if(stat[k][directionY] == 1 && stat[directionX - 1][directionY] == 2){
            for(int x = directionX - 1 ; x >= k + 1; x--){
                stat[x][directionY] = 1;
            }
            break;
        }
    }
    for(k = directionX + 2; k <= 7 ; k++){
        if(stat[k][directionY] == 1 && stat[directionX + 1][directionY] == 2){
            for(int x = directionX + 1 ; x <= k - 1 ; x++){
                stat[x][directionY] = 1;
            }
            break;
        }
    }
    for(v = directionY - 2; v >= 0; v--){
        if(stat[directionX][v] == 1 && stat[directionX][directionY - 1] == 2){
            for(int x = directionY - 1 ; x >= v + 1; x--){
                stat[directionX][x] = 1;
            }
            break;
        }
    }
    for(v = directionY + 2; v <= 7; v++){
        if(stat[directionX][v] == 1 && stat[directionX][directionY + 1] == 2){
            for(int x = directionY + 1 ; x <= v - 1; x++){
                stat[directionX][x] = 1;
            }
            break;
        }
    }
    k = directionX - 2;
    v = directionY - 2;
    while(k >= 0 && v >= 0){
        if(stat[k][v] == 1 && stat[directionX - 1][directionY - 1] == 2){
            int x,y;
            x = directionX - 1;
            y = directionY - 1;
            while(x >= k + 1 && y >= v + 1){
                stat[x][y] = 1;
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
        if(stat[k][v] == 1  && stat[directionX + 1][directionY - 1] == 2){
            int x,y;
            x = directionX + 1;
            y = directionY - 1;
            while(x <= k - 1 && y >= v + 1){
                stat[x][y] = 1;
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
        if(stat[k][v] == 1  && stat[directionX - 1][directionY + 1] == 2){
            int x,y;
            x = directionX - 1;
            y = directionY + 1;
            while(x >= k + 1 && y <= v - 1){
                stat[x][y] = 1;
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
        if(stat[k][v] == 1  && stat[directionX + 1][directionY + 1] == 2){
            int x,y;
            x = directionX + 1;
            y = directionY + 1;
            while(x <= k - 1 && y <= v - 1){
                stat[x][y] = 1;
                x++;
                y++;
            }
        }
        k++;
        v++;
    }

}
void doBlackToStatus(int directionX,int directionY,int stat[8][8]){
    int k,v;
    stat[directionX][directionY] = 2;
    for(k = directionX - 2; k >= 0 ; k--){
        if(stat[k][directionY] == 2 && stat[directionX - 1][directionY] == 1){
            for(int x = directionX - 1 ; x >= k + 1 ; x--){
                stat[x][directionY] = 2;
            }
            break;
        }
    }
    for(k = directionX + 2; k <= 7 ; k++){
        if(stat[k][directionY] == 2 && stat[directionX + 1][directionY] == 1){
            for(int x = directionX + 1 ; x <= k - 1; x++){
                stat[x][directionY] = 2;
            }
            break;
        }
    }
    for(v = directionY - 2; v >= 0; v--){
        if(stat[directionX][v] == 2 && stat[directionX][directionY - 1] == 1){
            for(int x = directionY - 1 ; x >= v + 1; x--){
                stat[directionX][x] = 2;
            }
            break;
        }
    }
    for(v = directionY + 2; v <= 7; v++){
        if(stat[directionX][v] == 2 && stat[directionX][directionY + 1] == 1){
            for(int x = directionY + 1 ; x <= v - 1; x++){
                stat[directionX][x] = 2;
            }
            break;
        }
    }
    k = directionX - 2;
    v = directionY - 2;
    while(k >= 0 && v >= 0){
        if(stat[k][v] == 2 && stat[directionX - 1][directionY - 1] == 1){
            int x,y;
            x = directionX - 1;
            y = directionY - 1;
            while(x >= k + 1 && y >= v + 1){
                stat[x][y] = 2;
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
        if(stat[k][v] == 2  && stat[directionX + 1][directionY - 1] == 1){
            int x,y;
            x = directionX + 1;
            y = directionY - 1;
            while(x <= k - 1 && y >= v + 1){
                stat[x][y] = 2;
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
        if(stat[k][v] == 2  && stat[directionX - 1][directionY + 1] == 1){
            int x,y;
            x = directionX - 1;
            y = directionY + 1;
            while(x >= k + 1 && y <= v - 1){
                stat[x][y] = 2;
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
        if(stat[k][v] == 2  && stat[directionX + 1][directionY + 1] == 1){
            int x,y;
            x = directionX + 1;
            y = directionY + 1;
            while(x <= k - 1 && y <= v - 1){
                stat[x][y] = 2;
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
        for(int j=0 ; j < 8 ; j++){
            if(status[i][j] == 0){
                //printf("%d",status[i][j]);
                return 0;
            }
        }
    }
    return 1;
}
void arrayToArray(int origin[8][8],int data[8][8]){
    for(int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j) {
            origin[i][j] = data[i][j];
        }
    }
}
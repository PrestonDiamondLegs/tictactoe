#include <stdio.h>
int PatternFormationFinder(int gridAR[3][3],int *row,int *coloum);
int find_winner(int gridAR[3][3]);
void intilize_array(int gridAR[3][3]);
void user_move(int gridAR[3][3]);
int computer_move();
int row;
int coloum;
int print_grid(int gridAR[3][3]) {
    for (int i=0;i<3;i++)  {
	printf("\n	----------\n");
	printf("	|");
        for(int j=0;j<3;j++) {
	    printf(" %d|",gridAR[i][j]);
	}
    }
    printf("\n	----------\n");

}
int main() {
    int gridAR[3][3];
    int winner;
    intilize_array(gridAR);
    int user_turn=1;// user move is 1
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if (user_turn==1) { // user move true
                printf("user\n");
	            user_move(gridAR);
                find_winner(gridAR);
                winner=find_winner(gridAR);
                switch (winner) {
                    case 0:
                    printf("no winner");
                    break;
                    case 1:
                    printf("user won");
                    break;
                    case 2:
                    printf("computer won");
                    break;
                }
                user_turn=0; // user move 0
                print_grid(gridAR);
            }
            else {
                printf("computer");
                printf("user\n");
	            int result=computer_move(gridAR);
                find_winner(gridAR);
                                winner=find_winner(gridAR);
                    switch (winner) {
                        case 0:
                        printf("no winner");
                        break;
                        case 1:
                        printf("user won");
                        break;
                        case 2:
                        printf("computer won");
                     break;
                 }
                print_grid(gridAR);
                user_turn=1;
            }
    }
        }
    return 1;
}



void user_move(int gridAR[3][3]) {
    int coloum,row;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
	        printf("enter row\n");
	        scanf("%d",&row);
	        printf("enter coloum\n");
	        scanf("%d",&coloum);
	        gridAR[row][coloum]=1;
	        i=3;
	        break;
        }
    }
}

int computer_move(int gridAR[3][3]) {
    int row;
    int coloum;
    if (PatternFormationFinder(gridAR,&row,&coloum) == 1) {
            printf("2");
//        gridAR[row][coloum]=2;
    }
    else {
        for(int i=0;i<3;i++) {
	        for(int j=0;j<3;j++) {
 	            if (gridAR[i][j]==0) {
                    gridAR[i][j]=2;
//                  printf("%d,%d\n",i,j);
                    printf("2\n");
                    i=3;
                    break;
                }
            }
        }
    }
}
void intilize_array(int gridAR[3][3]) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            gridAR[i][j]=0;
    }
        }
}
int find_winner(int gridAR[3][3]) {
    int value=0;
    int patternfound=0;
    // Find pattern in the rows
    for (int i=0;i<3;i++) {
        value=gridAR[i][0];
        patternfound=1;
        for (int j=1;j<3;j++) {
            if (value==0 ||  value != gridAR[i][j]) {
                patternfound=0;
                break;
            }
            value = gridAR[i][j];
        }
        if (patternfound==1) {
            printf("pattern found in row %d",i);
            return value; 

        }
    }
    value=0;
    patternfound=0;
    for (int i=0;i<3;i++) {
        value=gridAR[0][i];
        patternfound=1;
        for (int j=1;j<3;j++) {
            if (value==0 ||  value != gridAR[j][i]) {
                patternfound=0;
                break;
            }
            value = gridAR[j][i];
        }
        if (patternfound==1) {
            printf("pattern found in column %d", i);
            return value; 

        }
    }
    value=0;
    patternfound=0;
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if(i==j) {
                value=gridAR[i][j];
                patternfound=1;
                if (value==0 || value!= gridAR[i][j]) {
                    patternfound=0;
                    break;
                }
            }
        }
    }
    if (patternfound==1) {
        printf("patternfound ");
        return value; 

    }
    value=0;
    patternfound=0;
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if(i+j==3) {
                value=gridAR[i][j];
                patternfound=1;
                if (value==0 || value!= gridAR[i][j]) {
                    patternfound=0;
                    break;
                }
            }
        }
    }
    if (patternfound==1) {
        printf("patternfound ");
        return value;

    }
    return 0;
}


int PatternFormationFinder(int gridAR[3][3],int *row,int *coloum) {
    int twoCount=0;
    int zeroCount=0;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            switch(gridAR[i][j]) {
                case 0:
                *row=i;
                *coloum=j;
                zeroCount++;
                break;
                case 1:
                //nothing
                break;
                case 2:
                twoCount++;
                break;
            }
        }
    }
    if(zeroCount==1 & twoCount==0) {
        return 1;
    }
//    return 0;
    twoCount=0;
    zeroCount=0;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            switch(gridAR[j][i]) {
                case 0:
                *row=i;
                *coloum=j;
                zeroCount++;
                break;
                case 1:
                //nothing
                break;
                case 2:
                twoCount++;
                break;
            }
        }
    }
    if(zeroCount==1 & twoCount==0) {
        return 1;
    }
    return 0;
}

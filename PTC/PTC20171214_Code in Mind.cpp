#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

int main(){
    int sets, tests, n, i, j, k, ans2;
    char str[200], *text, ss[5];

    scanf("%d \n", &sets);

    while(sets--){
        int board[5][32] = {0};

        for(i=0;i<5;i++){
            fgets(str, 180, stdin);
            text = strtok(str, " \n");
            while(text != NULL){
                board[i][atoi(text)-1] = 1;
                text = strtok(NULL, " \n");
            }
        }

        scanf("%d", &tests);
        while(tests--){
            vector<int> ans(32,1);
            vector<int> isboard(5,0);
            scanf("%d", &n);
            for(j=0;j<n;j++){
                scanf("%s", ss);
                isboard[((int)ss[0] - 65)] = 1;
            }

            for(j=0;j<5;j++){
                for(k=0;k<32;k++){
                    if(ans[k]==1 && board[j][k] != isboard[j])
                        ans[k] = 0;
                }
            }
            ans2 = accumulate(ans.begin(), ans.end(), 0);
            if(ans2 > 1)
                printf("I don't know!\n");
            else if(ans2 == 0)
                printf("Impossible!\n");
            else{
                for(j=0;j<32;j++)
                    if(ans[j] == 1)
                        printf("%d\n", j+1);
            }
        }
        scanf("\n");
    }
    return 0;
}

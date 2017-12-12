#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <ctime>

#define QueensAmount        50
#define RUN_TIMES           30
#define MaxGenerations      50

using namespace std;

struct Node{
    Node(const int cost,const int row,const int value)
            :cost(cost), row(row), value(value) {}

    int cost, row, value;
};

void Generate_Location(vector<int> &, int &);
const int get_cost(const vector<int> &);
const int hill_climb(vector<int> &);

int main(){
    int i, counter(1), cost;
    vector<int> board(QueensAmount), result;

    srand(time(NULL));

    for(counter;counter<=RUN_TIMES;counter++){

        Generate_Location(board, cost);

        /* Start hill climbing*/
        for(i=0;cost!=0 && i<MaxGenerations;i++){
            cost = hill_climb(board);
            //cout << "Running times = " << i << "\tAttacks = " << cost << endl;
        }
        cout << "Run times = " << counter << "\tAttacks = " << cost << endl;
        result.push_back(cost);
    }

    cout << "\n========= HC RESULT =========\n";
    cout << "Attacks:\t";
    for(i=0;i<result.size();i++)
        cout << result[i] << " ";
    cout << "\nAverage attacks:\t" << (float)accumulate(result.begin(), result.end(), 0)/result.size();

    return 0;
}

void Generate_Location(vector<int> &board, int &cost){
    int i;

    for(i=0;i<QueensAmount;i++)
        board[i] = rand()%QueensAmount;

    cost = get_cost(board);
}

const int get_cost(const vector<int> &board){
    int i, j, cost(0);

    for(i=0;i<QueensAmount-1;i++)
        for(j=i+1;j<QueensAmount;j++)
            if(board[i] == board[j])
                cost++;
            else if(abs(board[i] - board[j]) == (j - i))
                cost++;
    return cost;
}

const int hill_climb(vector<int> &board){
    int row, value, cost(get_cost(board)), minCost(10000), tmpCost;
    vector<int> tmp_board;
    vector<struct Node>bestNeighbors;

    /* Check neighbors' cost*/
    for(row=0;row<QueensAmount;row++)
        for(value=0;value<QueensAmount;value++)
            if(board[row] == value)
                continue;
            else{
                tmp_board = board;
                tmp_board[row] = value;
                tmpCost = get_cost(tmp_board);
                if(tmpCost < minCost){
                    minCost = tmpCost;
                    bestNeighbors.clear();
                }
                if(tmpCost == minCost){
                    bestNeighbors.push_back(*(new struct Node(tmpCost,row,value)));
                }
            }

    /* Pick a random best neighbor, move to lower cost*/
    int randNum(rand()%bestNeighbors.size());
    board[bestNeighbors[randNum].row] = bestNeighbors[randNum].value;

    return bestNeighbors[randNum].cost;
}

#include <iostream>
#include <vector>
#include <algorithm>            //Use sort()
#include <numeric>              //Use accumulate()
#include <cstdlib>
#include <ctime>

#define QueensAmount            50
#define RUN_TIMES               30
#define MaxGenerations          50
#define PopulationSize          5000
#define CrossoverTimes          (int)PopulationSize/5
#define TournamentSelectionSize (int)20
#define MutationRate            (float)0.8

using namespace std;

struct populate{
    populate()
            :cost(cost), board(QueensAmount,0) {}

    populate(const int cost,const vector<int> &board)
            :cost(cost) {this->board = board;}

    int cost;
    vector<int> board;
};

const bool operator <(const populate& , const populate& );

const int get_cost(const vector<int> &);
void Generate_Population(vector<struct populate> &);
const int Tournament_Selection(const vector<struct populate> &);
void Crossover(vector<struct populate> &, const int, const int);
void group(vector<int> &, const int, const int);
void Mutation(vector<struct populate> &);
void Survivor(vector<struct populate> &);

int main(){
    int i, j, counter(1), cost, x, y;
    vector<struct populate> population(PopulationSize);
    vector<int> result;

    srand(time(NULL));

    for(counter;counter<=RUN_TIMES;counter++){
        Generate_Population(population);

        sort(population.begin(), population.end());

        cost = population[0].cost;

        /* Start genetic algorithm */
        for(i=0;cost!=0 && i<MaxGenerations;i++){
            for(j=0;j<CrossoverTimes;j++){
                x = Tournament_Selection(population);
                y = Tournament_Selection(population);
                while(y == x)
                    y = Tournament_Selection(population);
                Crossover(population, x, y);
            }
            Mutation(population);
            Survivor(population);
            cost = population[0].cost;
            //cout << "Running times = " << i << "\tAttacks = " << cost << endl;
        }
        cout << "Run times = " << counter << "\tAttacks = " << cost << endl;
        result.push_back(cost);
    }

    cout << "\n========= GA RESULT =========\n";
    cout << "Attacks:\t";
    for(i=0;i<result.size();i++)
        cout << result[i] << " ";
    cout << "\nAverage attacks:\t" << (float)accumulate(result.begin(), result.end(), 0)/result.size();

    return 0;
}

const bool operator <(const populate& n1, const populate& n2){
    return n1.cost < n2.cost;
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

void Generate_Population(vector<struct populate> &population){
    int i, j, tmp, randNum;

    /* Use Knuth Shuffle to generate not repeat random numbers */
    for(i=0;i<PopulationSize;i++){
        for(j=0;j<QueensAmount;j++)
            population[i].board[j] = j;
        for(j=QueensAmount-1;j>0;j--){
            randNum = rand()%j;
            tmp = population[i].board[j];
            population[i].board[j] = population[i].board[randNum];
            population[i].board[randNum] = tmp;
        }
        population[i].cost = get_cost(population[i].board);
    }
}

const int Tournament_Selection(const vector<struct populate> &population){
    int i, randNum, result(rand()%PopulationSize);

    for(i=1;i<TournamentSelectionSize;i++){
        randNum = rand()%PopulationSize;
        if(population[randNum].cost < population[result].cost)
            result = randNum;
    }
    return result;
}


void Crossover(vector<struct populate> &population, const int x, const int y){
    vector<int> p(QueensAmount);     //Disjoint Sets Forest
    int point1(rand()%(QueensAmount-2)+1), point2(rand()%(QueensAmount-2)+1), tmp, i;
    struct populate child1, child2;

    for(i=0;i<QueensAmount;i++) p[i] = i;
    while(point2 == point1) point2 = rand()%(QueensAmount-2)+1;
    if(point2 < point1){tmp = point2; point2 = point1; point1 = tmp;}

    /* Partially Mapped Crossover (PMX) */
    for(i=point1;i<=point2;i++)
        group(p, population[x].board[i], population[y].board[i]);

    child1.board.assign(population[x].board.begin(), population[x].board.begin()+point1);
    child2.board.assign(population[y].board.begin(), population[y].board.begin()+point1);

    child1.board.insert(child1.board.end(), population[x].board.begin()+point2+1, population[x].board.end());
    child2.board.insert(child2.board.end(), population[y].board.begin()+point2+1, population[y].board.end());

    for(i=0;i<child1.board.size();i++){
        child1.board[i] = p[child1.board[i]];
        child2.board[i] = p[child2.board[i]];
    }

    child1.board.insert(child1.board.begin()+point1, population[y].board.begin()+point1, population[y].board.begin()+point2+1);
    child2.board.insert(child2.board.begin()+point1, population[x].board.begin()+point1, population[x].board.begin()+point2+1);

    child1.cost = get_cost(child1.board);
    child2.cost = get_cost(child2.board);

    population.push_back(child1);
    population.push_back(child2);
}

void group(vector<int> &p, const int x, const int y){
    if(p[x] != x){
        p[p[x]] = p[x];
        group(p, p[x], y);
        p[x] = x;
    }
    else if(p[y] != y){
        p[p[y]] = p[y];
        group(p, x, p[y]);
        p[y] = y;
    }
    else{
        p[x] = y;
        p[y] = x;
    }
}

void Mutation(vector<struct populate> &population){
    int i, rand1, rand2, tmp;

    /* Swap Mutation */
    for(i=PopulationSize;i<population.size();i++)
        if((float)(rand()%1000)/1000 <= MutationRate){
            rand1 = rand()%QueensAmount;
            rand2 = rand()%QueensAmount;
            tmp = population[i].board[rand1];
            population[i].board[rand1] = population[i].board[rand2];
            population[i].board[rand2] = tmp;
        }
}

void Survivor(vector<struct populate> &population){
    sort(population.begin(), population.end());
    //population.erase(population.begin()+PopulationSize, population.end());
    population.erase(population.end()-2*CrossoverTimes, population.end());
}

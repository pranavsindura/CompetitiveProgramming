#include <bits/stdc++.h>
using namespace std;

const int M = 100000;
const int FEATURE = 10000;

class GA
{
    vector<bitset<M>> population;
    int mutation_rate, LEN;
    const int SZ = 100;
    const int ITERS = 10000;
public:
    GA(): mutation_rate(0) {}
    GA(int LEN, int mutation_rate): LEN(LEN), mutation_rate(mutation_rate) {}
    void init()
    {
        srand(time(NULL));
        population.clear();
        for(int i = 0; i < SZ; i++)
        {
            bitset<M> B;
            for(int j = 0; j < LEN; j++)
                B[j] = rand() % 2;
            population.push_back(B);
        }
    }
    void set(int LEN, int mutation_rate)
    {
        this->LEN = LEN;
        this->mutation_rate = mutation_rate;
        init();
    }
    ll fitness(bitset<M> &B)
    {
        bitset<FEATURE> best;
        for(int i = 0; i < LEN; i++)
            if(B[i])
                best |= rep[i];
        return best;
    }
    void order()
    {
        sort(population.begin(), population.end(), [&](string x, string y)
        {
            return fitness(x) > fitness(y);
        });
    }
    void selection()
    {
        order();
        vector<string> new_population;

        const int GOOD = 40;
        const int BAD = 10;

        for(int i = 0; i < GOOD; i++)
            new_population.push_back(population[i]);
        for(int i = SZ - 1; i >= SZ - BAD; i--)
            new_population.push_back(population[i]);

        population = new_population;
    }
    void crossover()
    {
        while((int)population.size() < SZ)
        {
            random_shuffle(population.begin(), population.end());
            string P = population[0];
            string Q = population[1];
            string child;
            // Perform crossover
            for(int i = 0; i < LEN; i++)
                child += (rand() % 2 ? P[i] : Q[i]);
            population.push_back(child);
        }
    }
    void mutation()
    {
        vector<string> new_population;
        for(int i = 0; i < SZ; i++)
        {
            string mutant;
            for(int j = 0; j < LEN; j++)
            {
                if(rand() % 100 < mutation_rate)
                    mutant += char(97 + rand() % 26);
                else
                    mutant += population[i][j];
            }
            new_population.push_back(mutant);
        }

        population = new_population;
    }
    string solve()
    {
        init();
        int gen = 0;
        while(gen < ITERS)
        {
            order();

            cout << "Generation " << gen << ": " << population[0] << endl;

            if(fitness(population[0]) == fitness(target)) break;

            selection();
            crossover();
            mutation();

            gen++;
        }
        return population[0];
    }
};

int main()
{
    GA test;
    string make;
    int mutation_rate;
    cin >> make >> mutation_rate;
    test.set(make, mutation_rate);
    string sol = test.solve();
    cout << "Found: " << sol << endl;
    return 0;
}
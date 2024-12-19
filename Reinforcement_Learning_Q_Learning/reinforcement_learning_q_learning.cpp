#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 5; // Grid size
const double alpha = 0.1; // Learning rate
const double gamma = 0.9; // Discount factor
const double epsilon = 0.1; // Exploration rate

void qLearning(vector<vector<double>>& Q) {
    srand(time(0));
    for (int episode = 0; episode < 1000; ++episode) {
        int state = rand() % N;
        while (state != N - 1) {
            int action = (rand() % 2) ? (state + 1) : max(0, state - 1);

            int reward = (action == N - 1) ? 100 : -1;

            Q[state][action] += alpha * (reward + gamma * Q[action][action] - Q[state][action]);

            state = action;
        }
    }
}

int main() {
    vector<vector<double>> Q(N, vector<double>(N, 0.0));
    qLearning(Q);

    cout << "Learned Q-Values:\n";
    for (const auto& row : Q) {
        for (double q : row) {
            cout << q << " ";
        }
        cout << endl;
    }
    return 0;
}


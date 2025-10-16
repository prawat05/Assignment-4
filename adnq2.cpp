#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int findMinIndex(queue<int>& q, int sortedIndex) {
    int min_index = -1;
    int min_val = INT_MAX;
    int n = q.size();
    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();
        if (curr <= min_val && i <= sortedIndex) {
            min_index = i;
            min_val = curr;
        }
        q.push(curr);
    }
    return min_index;
}

void insertMinToRear(queue<int>& q, int min_index) {
    int n = q.size();
    int min_val;
    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();
        if (i == min_index)
            min_val = curr;
        else
            q.push(curr);
    }
    q.push(min_val);
}

void sortQueue(queue<int>& q) {
    int n = q.size();
    for (int i = 1; i <= n; i++) {
        int min_index = findMinIndex(q, n - i);
        insertMinToRear(q, min_index);
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
    for (int s : students)
        q.push(s);

    int i = 0, unable = 0;
    while (!q.empty() && unable < q.size()) {
        if (q.front() == sandwiches[i]) {
            q.pop();
            i++;
            unable = 0;
        } else {
            int temp = q.front();
            q.pop();
            q.push(temp);
            unable++;
        }
    }
    return q.size();
}

int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};
    cout << countStudents(students, sandwiches);
    return 0;
}

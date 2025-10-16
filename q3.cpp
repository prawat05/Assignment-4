#include <iostream>
#include <queue>
using namespace std;

int main() 
{
    queue<int> q1;
    q1.push(4);
    q1.push(7);
    q1.push(11);
    q1.push(20);
    q1.push(5);
    q1.push(9);

    cout << "Original queue: ";
    queue<int> temp = q1; 
    while (!temp.empty()) 
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    int size = q1.size();
    if (size % 2 == 0) 
    {
        int n = size / 2;
        queue<int> x, y;

        for (int i = 0; i < n; i++)   // first half into x, second half remains in q1
        {
            x.push(q1.front());
            q1.pop();
        }

        cout << "Interleaved queue: ";      // Now q1 has the second half, x has the first half
        while (!x.empty() && !q1.empty())
        {
            cout << x.front() << " ";
            x.pop();
            cout << q1.front() << " ";
            q1.pop();
        }
        cout << endl;
    } 
    else 
    {
        cout << "Queue has odd number of elements — interleaving not possible evenly." << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#define MAX 5
using namespace std;
class circQueue
{
public:
    int arr[MAX];
    int f=-1,r=-1;
    
    bool isEmpty()
    {
        if(f==-1) return true;
        else return false;
    }
    bool isFull()
    {
        if(f==(r+1)%MAX) return true; 
        else return false;
    }
    void enqueue(int val)
    {
    if(isFull())  cout<<"CIRCULAR QUEUE FULL";
    else
    {
      if(f==-1) f=r=0;
      else r=(r+1)%MAX;
      arr[r]=val;   
    }
    }
    void dequeue()
    {
       if(isEmpty()) cout<<"QUEUE UNDERFLOW\n";
       else 
       {
          int removed = arr[f];
          cout<<"Element removed is :- "<<removed<<endl;
          if (f==r) f = r = -1;
          else f = (f + 1) % MAX;
       }
    }
    void peek()
    {
    if(isEmpty())  cout<<"Queue is empty\n";
    else  cout<<arr[f]<<endl;
    }
    void display()
    {
      if(isEmpty())  cout<<"Queue is empty\n";
      else 
      {
        int i = f;
        while(true)
        {
            cout<<arr[i]<<" ";
            if(i == r) break;
            i = (i+1) % MAX;
        }
        cout<<endl;
      }
    }
};


int main()
{
  circQueue q;
  int choice, val;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << (q.isEmpty() ? "Queue is Empty\n" : "Queue is NOT Empty\n");
                break;
            case 6:
                cout << (q.isFull() ? "Queue is Full\n" : "Queue is NOT Full\n");
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
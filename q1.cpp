#include <iostream>
#include <vector>
#define MAX 5
using namespace std;
class Queue
{
   public:
   int arr[MAX];
   int f=-1,r=-1; // front and rear pointers on queue

    bool isEmpty() //check if queue is empty
    {
       if(f==-1) return true; //since front ==-1(null) it is empty
       else return false;
    }
    bool isFull()  //check if queue is full
    {
       if(r==MAX-1) return true; //since rear = max-1 means rear at last element queue is full
       else return false;
    }
    void enqueue(int val)
    {
    if(isFull())  cout<<"QUEUE OVERFLOW\n";
    else
    {
      if(f==-1) //queue was empty case 
      {
        f++; //f=0
        r++; //r=0
      }
      arr[r]=val; //arr[0] = val !! first element enter 
      r++;   //only rear pointer will move
    }
    }
    void dequeue()
    {
    if(isEmpty())  
    {
        cout<<"QUEUE UNDERFLOW\n";
    }
    else
    {
      int removed = arr[f]; //fifo so first element is to be removed
      f++;
      cout<<"Element removed :- "<<removed<<endl;;
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
      cout<<"The queue is :- \n";
      for(int i=f;i<r;i++)
      {
        cout<<arr[i]<<" ";
      }
      cout<<endl;
    }
    }
};


int main() 
{
    Queue q;
    int choice, val;

    do {
        cout << "\n    Queue Menu    \n";
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
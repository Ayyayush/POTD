#include <bits/stdc++.h>
using namespace std;

class Queue
{
  int f, r, currsize;
  int capacity;
  int *ptr;

public:
  Queue(int size)
  {
    ptr = new int(size);
    capacity = size;
    currsize = 0;
    front = 0;
    rear = -1;
  }

  void push(int val)
  {
    if (isFull)
    {
      cout << "Queue is Full" << endl;
      return;
    }
    rear = (rear + 1) % size;
    ptr[rear] = val;
    currsize++;
  }

  void pop()
  {
    if (isEmpty())
    {
      cout << "Queue Underflow" << endl;
      return;
    }
    front = (front + 1) % size;
    currsize--;

    if (currsize == 0) // Case: Queue is now empty, reset front & rear
    {
      f = 0;
      r = -1;
    }
  }


  int getFront()
  {
    return ptr[front];
  }

  int getBack()
  {
    return ptr[rear];
  }

  boolean isEmpty(){
      return currsize==0;
  }

  boolean isFull()
  {
    return currsize==capacity;
  }


};

int main()
{
  
}
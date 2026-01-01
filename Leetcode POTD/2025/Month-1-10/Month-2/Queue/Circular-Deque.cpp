class MyCircularDeque {
public:
 int *ptr;
    int front, rear, capacity;

    MyCircularDeque(int k) {
      capacity = k;
        front = -1;
        rear = -1;
        ptr = new int[k];  
    }
    
    bool insertFront(int value) {
          if (isFull())                        // Queue full hone ka check
        {
          
            return false ;
        }

        if (isEmpty())                       // Pehla element insert karne ka case
        {
            front = rear = 0;
        }
        else if (front == 0)                 // Wrap around case
        {
            front = capacity - 1;
        }
        else
        {
            front--;                         // Normal front insertion
        }

        ptr[front] = value;
        return true;
    
    }
    
    bool insertLast(int value) {
         if (isFull())                        // Queue full hone ka check
        {
            return false ;
            
        }

        if (isEmpty())                       // Pehla element insert karne ka case
        {
            front = rear = 0;
        }
        else if (rear == capacity - 1)       // Wrap around case
        {
            rear =(rear+1)%capacity;
        }
        else
        {
            rear++;                          // Normal rear insertion
        }

        ptr[rear] = value;
        return true;
   
    }
    
    bool deleteFront() {
       if (isEmpty())
        {
           return false ;
           
        }

        if (front == rear)                   // Queue empty hone ka case
        {
            front = rear = -1;
        }
        else if (front == capacity - 1)      // Wrap around case
        {
            front = 0;
        }
        else
        {
            front++;                         // Normal pop front
            return true;
        }  
    }
    
    
    bool deleteLast() {
         if (isEmpty())
        {
           return false ;
        }

        if (front == rear)                   // Queue empty hone ka case
        {
            front = rear = -1;
        }
        else if (rear == 0)                  // Wrap around case
        {
            rear = capacity - 1;
        }
        else
        {
            rear--;                          // Normal pop back
            returnv true;
        }
    }
    
    int getFront() {
         if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return ptr[front];
  
    }
    
    int getRear() {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return ptr[rear];
   
    }
    
    bool isEmpty() {
          return front == -1;
    }
    
    bool isFull() {
         return (rear + 1) % capacity == front;   // Circular full condition
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
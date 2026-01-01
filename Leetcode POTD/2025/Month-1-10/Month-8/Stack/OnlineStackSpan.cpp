/**
 * *Online Stack Span
 * particular index pe usse < kitne value h nikalna h 
 * eg ::= 100,80,60,70,60,75,85
 *  ans == 1,1,1,2,1,4,6
 * 
 * *BRUTE FORCE
 * baar baar har index pe aake left jayenge 
 * nestled loop lagega
 * 
 * 
 * *BETTER APPROACH 
 * Stack use karenge  
 * 
 * 
 */



 #include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st;                         // stack stores {price, span}

    StockSpanner() {
        // Constructor - nothing to initialize explicitly
    }

    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;                  // accumulate span
            st.pop();                                 // remove smaller/equal price
        }
        st.push({price, span});                       // push current price and span
        return span;
    }
};

void better() 
{
    // 📌 Time Complexity: O(1) amortized per operation
    // 📌 Space Complexity: O(N) for the stack

    StockSpanner* obj = new StockSpanner();

    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    for(int price : prices) {
        cout << obj->next(price) << " ";
    }

    // Output should be: 1 1 1 2 1 4 6
}

int main()
{
    better();
    return 0;
}



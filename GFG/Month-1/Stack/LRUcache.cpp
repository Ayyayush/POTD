#include <bits/stdc++.h>
using namespace std;


// Function to simulate an LRU Cache
void simulateLRUCache() {
    int capacity;                 // Cache ki capacity define kar rahe hain
    cin >> capacity;              // Capacity input karenge user se
    vector<pair<int, int>> cache; // Vector banaya key-value pairs ko store karne ke liye

    string command;
    cin.ignore();  // Extra newline ignore karne ke liye

    while (getline(cin, command)) { // Jab tak input milta rahega
        if (command == "get") { // Agar command "get" hai
            int key;
            cin >> key;
            cin.ignore(); // Extra newline ignore karne ke liye

            int result = -1;
            for (int i = 0; i < cache.size(); i++) {
                if (cache[i].first == key) {
                    result = cache[i].second;
                    pair<int, int> temp = cache[i];
                    cache.erase(cache.begin() + i);
                    cache.push_back(temp);
                    break;
                }
            }
            cout << result << endl;
        } 
        
        else if (command == "put") { // Agar command "put" hai
            int key, value;
            cin >> key >> value;
            cin.ignore(); // Extra newline ignore karne ke liye

            bool found = false;
            for (int i = 0; i < cache.size(); i++) {
                if (cache[i].first == key) {
                    cache.erase(cache.begin() + i);
                    cache.push_back({key, value});
                    found = true;
                    break;
                }
            }
            if (!found) {
                if (cache.size() == capacity) {
                    cache.erase(cache.begin()); // Least Recently Used (LRU) element hatao
                }
                cache.push_back({key, value});
            }
        }
    }
}


void optimal()
{
    int capacity;                 // Cache ki capacity define kar rahe hain                 
    cin >> capacity;              // User se capacity input lenge                      
    list<int> dll;                // Doubly linked list jo keys ko store karegi LRU order me  
    unordered_map<int, pair<list<int>::iterator, int>> cache; // Map jo key ko list node aur value ke saath store karega  

    string command; // Command lenge, "get" ya "put"  
    while (cin >> command)   // Jab tak input milta rahega tab tak loop chalega  
    {
        if (command == "get")   // Agar "get" command mili toh key ka value return karna hai  
        {
            int key;
            cin >> key;   // User se key input lenge  

            if (cache.find(key) == cache.end())   // Agar key cache me nahi mili toh -1 return karenge  
            {
                cout << -1 << endl;
            }
            else   // Agar key mil gayi toh usko most recently used bana dena hai  
            {
                dll.erase(cache[key].first);   // Pehle usko purani position se hataenge  
                dll.push_front(key);           // Phir usko front pe daal denge  
                cache[key].first = dll.begin(); // Map me bhi update karenge  
                cout << cache[key].second << endl; // Value return karenge  
            }
        }
        else if (command == "put")   // Agar "put" command mili toh naya key-value pair insert karna hai  
        {
            int key, value;
            cin >> key >> value;   // User se key aur value input lenge  

            if (cache.find(key) != cache.end())   // Agar key pehle se exist karti hai toh usko delete kar dena hai  
            {
                dll.erase(cache[key].first);
            }
            else if (dll.size() == capacity)   // Agar cache full hai toh LRU element delete kar dena hai  
            {
                cache.erase(dll.back());  // Last wale element ko erase karenge  
                dll.pop_back();   // List se bhi remove karenge  
            }

            dll.push_front(key);  // Nayi key ko sabse aage add karenge  
            cache[key] = {dll.begin(), value}; // Map me bhi update karenge  
        }
    }
}




// Main function to execute the LRU Cache simulation
int main()
{
    simulateLRUCache(); // LRU Cache simulation function ko call karte hain
    return 0;           // Program successful end hota hai
}

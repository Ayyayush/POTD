#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int s;
    cin >> s;

    int mindiff = INT_MAX, diff = 0;
    vector<int> arr(s);

    for (int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    for (int i = 0; i < arr.size() - 1; i++)
    {
        diff = abs(arr[i] - arr[i + 1]);
        mindiff = min(diff, mindiff);
    }



    vector<pair<int, int>> result;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] - arr[i + 1] == mindiff)
        {
            result.push_back(make_pair(arr[i + 1], arr[i]));     // Yahan reverse karke push kar diya
        }
    }

    for (auto x : result)
    {
        cout << x.first << " " << x.second << endl;
    }
}

int main()
{
    brute();
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

int getNth(Node* head, int n) {
    while (--n && head) head = head->next;
    return head ? head->data : -1;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    cout << getNth(head, 2);  // Output: 2
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

void print(Node* head) {
    while (head) cout << head->data << " ", head = head->next;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    head->next = second;
    second->prev = head;
    print(head);  // Output: 1 2
    return 0;
}

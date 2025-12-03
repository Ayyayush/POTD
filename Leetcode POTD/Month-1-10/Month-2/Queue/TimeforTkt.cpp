#include <bits/stdc++.h>  
using namespace std;



// Function to calculate time for the person at position 'k' to finish buying tickets
void brute()
{
    int s, k, t = 0;
    cin >> s >> k;  // Input number of people and the position of the person 'k'
    
    vector<int> tickets(s);  // Vector to store the number of tickets each person wants
    queue<int> q;  // Queue to simulate the line of people

    // Input the ticket counts and push indices into the queue
    for (int i = 0; i < s; i++)
    {
        cin >> tickets[i];  // Input tickets for person at index i
        q.push(i);  // Store person index in the queue
    }

    // Process the queue
    while (!q.empty())
    {
        int i = q.front();  // Get the person at the front of the queue
        q.pop();  // Remove the person from the queue

        // If this person is at position k and has no tickets left, we are done
        if (i == k && tickets[i] == 0)
        {
            break;  // Exit the loop if person at position 'k' is done
        }

        // If the person has tickets left, they go back to the end of the queue
        if (tickets[i] > 0)
        {
            tickets[i]--;  // They buy one ticket
            q.push(i);  // They go back to the end of the queue
        }
        
        t++;  // Each iteration is 1 second, increment the time
    }

    cout << t << endl;  // Output the total time taken for person k to finish
}




// Function to calculate time using a different approach (without queue)
void better()
{
    int n, k;
    cin >> n >> k;  // Input the number of people and the position of person 'k'
    
    vector<int> tickets(n);  // Vector to store tickets for each person
    for (int i = 0; i < n; i++)
        cin >> tickets[i];  // Input ticket counts for all people

    int time = 0;  // Variable to track the total time

    // Calculate time taken for all people to buy tickets
    for (int i = 0; i < n; i++)
    {
        // If person i is in front of or at position k, they will take up to tickets[k] time
        if (i <= k)
            time += min(tickets[k], tickets[i]);  // Min of current person's tickets and person 'k's tickets
        else
            time += min(tickets[k] - 1, tickets[i]);  // After person 'k' is done, subtract 1 for other people
    }

    cout << time << endl;  // Output the total time taken
}

int main()
{
    brute();  // Call the brute function to process the queue and calculate time
    return 0;
}

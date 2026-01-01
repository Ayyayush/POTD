/**
 * ! Simple Bank System
 * 
 * Bank ke saare operations ko automate karna hai.      				// Problem ka main aim
 * Har account ke paas ek initial balance hota hai.     				// Balance ek array mein diya gaya hai
 * Hume kuch operations perform karne hain jaise:
 * - deposit karna
 * - withdraw karna
 * - transfer karna
 * 
 * Example:
 * Input:
 * n = 3
 * balance = [100, 200, 300]
 * 
 * Operation 1: deposit(2, 100)      // 2nd account mein 100 add karo
 * Operation 2: withdraw(1, 50)      // 1st account se 50 nikaalo
 * Operation 3: transfer(2, 3, 150)  // 2nd account se 150 3rd mein bhejo
 * 
 * Output:
 * balance = [50, 150, 450]
 * 
 * Agar koi account invalid hua (like 0 ya > n), ya balance kam hua toh operation fail karega.
 */


 #include <bits/stdc++.h>
using namespace std;

class Bank {
public:
    vector<long long> balance;     				// har account ka balance store karne ke liye vector
    int n;    									// total number of accounts

    // Constructor: Bank system initialize karne ke liye
    Bank(vector<long long>& balance) {
        n = balance.size();     					// total accounts ki count store ki
        this->balance = balance;    				// balance vector ko class variable mein assign kiya
    }

    // Function to transfer money between two accounts
    bool transfer(int account1, int account2, long long money) {
        // agar koi account invalid ho ya sender ke paas paisa kam ho toh false
        if (account1 > n || account2 > n || balance[account1 - 1] < money)
            return false;

        balance[account1 - 1] -= money;      		// sender se paisa nikaala
        balance[account2 - 1] += money;      		// receiver ko paisa diya
        return true;      							// transfer successful
    }

    // Function to deposit money into an account
    bool deposit(int account, long long money) {
        if (account > n)      						// agar account invalid hua
            return false;

        balance[account - 1] += money;      		// given paisa add kar diya
        return true;      							// deposit successful
    }

    // Function to withdraw money from an account
    bool withdraw(int account, long long money) {
        // agar account invalid hua ya paisa kam hua
        if (account > n || balance[account - 1] < money)
            return false;

        balance[account - 1] -= money;      		// paisa nikaal diya
        return true;      							// withdraw successful
    }
};

/**
 * Example:
 * 
 * Bank object ko initialize karne ke liye:
 * vector<long long> bal = {100, 200, 300};
 * Bank* obj = new Bank(bal);
 * 
 * bool t1 = obj->transfer(1, 2, 50);     // 1st se 2nd account ko 50 bhejo
 * bool d1 = obj->deposit(3, 100);       // 3rd account mein 100 add karo
 * bool w1 = obj->withdraw(2, 30);       // 2nd account se 30 nikaalo
 * 
 * Final balances: [50, 170, 400]
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> netCash;

void minimizeCashFlow() {
    string maxCreditor = max_element(begin(netCash), end(netCash), [](auto& a, auto&b) { return a.second < b.second; }) -> first;
    string maxDebtor = min_element(begin(netCash), end(netCash), [](auto& a, auto&b) { return a.second < b.second; }) -> first;

    if(!netCash[maxCreditor] && !netCash[maxDebtor]) return;

    int minAmount = min(netCash[maxCreditor], -netCash[maxDebtor]);
    netCash[maxCreditor] -= minAmount;
    netCash[maxDebtor] += minAmount;

    cout << maxDebtor << " pays " << minAmount << " to " << maxCreditor << endl;
    minimizeCashFlow();
}

int main() {
    string sender;
    string receiver;
    char choice;
    unsigned int amount;
    
    cout << "Entry Format: <Sender> <Receiver> <Amount>" << endl;
    while(true) {
        cout << "a: add entry" << endl;
        cout << "c: compute statement" << endl;
        cout << "q: quit" << endl;
        
        cin >> choice;
        switch(choice) {
            case 'a':
                cin >> sender >> receiver >> amount;
                netCash[sender] -= amount;
                netCash[receiver] += amount;
                break;
            case 'c':
                minimizeCashFlow();
            default:
                return 0;
        }
    }
    return 0;
}
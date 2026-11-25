#include <iostream>
#include <vector>
using namespace std;

// Function to take disk scheduling inputs
void inputHandler(vector<int>& requests, int& head,
                  int& diskSize, int& direction) {

    int n;

    cout << "\n===== Disk Scheduling Input =====\n";

    // Take disk size
    cout << "Enter disk size: ";
    cin >> diskSize;

    // Take initial head position
    cout << "Enter initial head position: ";
    cin >> head;

    // Take number of requests
    cout << "Enter number of disk requests: ";
    cin >> n;

    requests.clear();

    // Take request queue
    cout << "Enter disk request sequence:\n";

    for (int i = 0; i < n; i++) {
        int request;
        cout << "Request " << i + 1 << ": ";
        cin >> request;
        requests.push_back(request);
    }

    // Take direction
    cout << "\nSelect direction:\n";
    cout << "1. Left\n";
    cout << "2. Right\n";
    cout << "Enter choice: ";
    cin >> direction;
}

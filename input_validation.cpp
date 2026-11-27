#include <iostream>
#include <vector>
using namespace std;

// Validate disk size
bool validateDiskSize(int diskSize) {
    if (diskSize <= 0) {
        cout << "Error: Disk size must be positive!\n";
        return false;
    }

    return true;
}

// Validate initial head position
bool validateHead(int head, int diskSize) {
    if (head < 0 || head >= diskSize) {
        cout << "Error: Invalid head position!\n";
        return false;
    }

    return true;
}

// Validate number of requests
bool validateRequestCount(int n) {
    if (n < 0) {
        cout << "Error: Number of requests cannot be negative!\n";
        return false;
    }

    return true;
}

// Validate request queue
bool validateRequests(vector<int> requests, int diskSize) {
    if (requests.empty()) {
        cout << "Error: Request queue is empty!\n";
        return false;
    }

    for (int request : requests) {
        if (request < 0 || request >= diskSize) {
            cout << "Error: Invalid disk request position!\n";
            return false;
        }
    }

    return true;
}

// Validate direction
bool validateDirection(int direction) {
    if (direction != 1 && direction != 2) {
        cout << "Error: Choose 1 for Left or 2 for Right!\n";
        return false;
    }

    return true;
}

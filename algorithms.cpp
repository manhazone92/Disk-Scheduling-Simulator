
#include "algorithms.hpp"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

// Calculate total head movement
long long calculateMovement(const vector<int>& path) {
    long long total = 0;

    for (size_t i = 1; i < path.size(); i++) {
        total += abs(path[i] - path[i - 1]);
    }

    return total;
}

// Calculate estimated seek time
double calculateSeekTime(
    const vector<int>& path,
    double a,
    double b
) {
    double total = 0.0;

    for (size_t i = 1; i < path.size(); i++) {
        double distance = abs(path[i] - path[i - 1]);

        if (distance > 0) {
            total += a + b * sqrt(distance);
        }
    }

    return total;
}

// Add a serviced request
void addService(Result& result, int track) {
    result.path.push_back(track);
    result.order.push_back(track);
}

// Complete result calculations
void finishResult(Result& result, const Scenario& s) {

    result.movement = calculateMovement(result.path);

    if (!result.order.empty()) {
        result.average =
            (double)result.movement / result.order.size();
    }

    result.seekMs =
        calculateSeekTime(result.path, s.a, s.b);
}

// Separate requests into left and right sides
void splitRequests(
    const Scenario& s,
    Result& r,
    vector<int>& left,
    vector<int>& right
) {
    r.path.push_back(s.head);

    for (int track : s.requests) {

        if (track < s.head) {
            left.push_back(track);
        }
        else if (track > s.head) {
            right.push_back(track);
        }
        else {
            addService(r, track);
        }
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
}

// 1. FCFS
Result fcfs(const Scenario& s) {

    Result r;
    r.name = "FCFS";
    r.path.push_back(s.head);

    for (int track : s.requests) {
        addService(r, track);
    }

    finishResult(r, s);

    return r;
}

// 2. SSTF
Result sstf(const Scenario& s) {

    Result r;
    r.name = "SSTF";
    r.path.push_back(s.head);

    vector<int> pending = s.requests;
    int current = s.head;

    while (!pending.empty()) {

        size_t best = 0;
        int minDistance = abs(pending[0] - current);

        for (size_t i = 1; i < pending.size(); i++) {

            int distance = abs(pending[i] - current);

            if (distance < minDistance ||
                (distance == minDistance &&
                 pending[i] < pending[best])) {

                best = i;
                minDistance = distance;
            }
        }

        current = pending[best];

        addService(r, current);

        pending.erase(pending.begin() + best);
    }

    finishResult(r, s);

    return r;
}

// 3. SCAN
Result scan(const Scenario& s) {

    Result r;
    r.name = "SCAN";

    vector<int> left, right;

    splitRequests(s, r, left, right);

    if (s.direction == 'R') {

        for (int track : right) {
            addService(r, track);
        }

        // Move to the right physical boundary
        if (r.path.back() != s.diskSize - 1) {
            r.path.push_back(s.diskSize - 1);
        }

        // Reverse direction
        for (auto it = left.rbegin();
             it != left.rend(); ++it) {

            addService(r, *it);
        }

    } else {

        for (auto it = left.rbegin();
             it != left.rend(); ++it) {

            addService(r, *it);
        }

        // Move to the left physical boundary
        if (r.path.back() != 0) {
            r.path.push_back(0);
        }

        for (int track : right) {
            addService(r, track);
        }
    }

    finishResult(r, s);

    return r;
}

// 4. C-SCAN
Result cscan(const Scenario& s) {

    Result r;
    r.name = "C-SCAN";

    vector<int> left, right;

    splitRequests(s, r, left, right);

    if (s.direction == 'R') {

        for (int track : right) {
            addService(r, track);
        }

        if (r.path.back() != s.diskSize - 1) {
            r.path.push_back(s.diskSize - 1);
        }

        // Circular jump to track zero
        if (r.path.back() != 0) {
            r.path.push_back(0);
        }

        for (int track : left) {
            addService(r, track);
        }

    } else {

        for (auto it = left.rbegin();
             it != left.rend(); ++it) {

            addService(r, *it);
        }

        if (r.path.back() != 0) {
            r.path.push_back(0);
        }

        // Circular jump to the last track
        if (r.path.back() != s.diskSize - 1) {
            r.path.push_back(s.diskSize - 1);
        }

        for (auto it = right.rbegin();
             it != right.rend(); ++it) {

            addService(r, *it);
        }
    }

    finishResult(r, s);

    return r;
}

// 5. LOOK
Result look(const Scenario& s) {

    Result r;
    r.name = "LOOK";

    vector<int> left, right;

    splitRequests(s, r, left, right);

    if (s.direction == 'R') {

        for (int track : right) {
            addService(r, track);
        }

        // Reverse at the last pending request
        for (auto it = left.rbegin();
             it != left.rend(); ++it) {

            addService(r, *it);
        }

    } else {

        for (auto it = left.rbegin();
             it != left.rend(); ++it) {

            addService(r, *it);
        }

        for (int track : right) {
            addService(r, track);
        }
    }

    finishResult(r, s);

    return r;
}

// 6. C-LOOK
Result clook(const Scenario& s) {

    Result r;
    r.name = "C-LOOK";

    vector<int> left, right;

    splitRequests(s, r, left, right);

    if (s.direction == 'R') {

        for (int track : right) {
            addService(r, track);
        }

        // Jump to the lowest pending request
        if (!left.empty() && !right.empty()) {

            r.path.push_back(left.front());
            r.order.push_back(left.front());

            for (size_t i = 1; i < left.size(); i++) {
                addService(r, left[i]);
            }

        } else {

            for (int track : left) {
                addService(r, track);
            }
        }

    } else {

        for (auto it = left.rbegin();
             it != left.rend(); ++it) {

            addService(r, *it);
        }

        // Jump to the highest pending request
        if (!right.empty() && !left.empty()) {

            r.path.push_back(right.back());
            r.order.push_back(right.back());

            for (int i = (int)right.size() - 2;
                 i >= 0; i--) {

                addService(r, right[i]);
            }

        } else {

            for (auto it = right.rbegin();
                 it != right.rend(); ++it) {

                addService(r, *it);
            }
        }
    }

    finishResult(r, s);

    return r;
}


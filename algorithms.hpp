
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <string>
#include <vector>

struct Scenario {
    int diskSize = 200;
    int head = 50;
    char direction = 'R';

    std::vector<int> requests;

    double a = 2.0;
    double b = 0.5;
};

struct Result {
    std::string name;

    std::vector<int> path;
    std::vector<int> order;

    long long movement = 0;

    double average = 0.0;
    double seekMs = 0.0;
};

long long calculateMovement(
    const std::vector<int>& path
);

double calculateSeekTime(
    const std::vector<int>& path,
    double a,
    double b
);

Result fcfs(const Scenario& s);
Result sstf(const Scenario& s);
Result scan(const Scenario& s);
Result cscan(const Scenario& s);
Result look(const Scenario& s);
Result clook(const Scenario& s);

#endif


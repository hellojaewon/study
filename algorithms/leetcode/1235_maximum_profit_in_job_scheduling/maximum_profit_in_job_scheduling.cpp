#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;
struct Job {
    int startTime;
    int endTime;
    int profit;
    bool operator < (const Job & rhs) {
        return startTime < rhs.startTime;
    }
};

bool operator < (const Job & lhs, const Job & rhs) {
    return lhs.startTime < rhs.startTime;
}

int nextJob (const vector<Job> & jobs, int job) {
    int endTime = jobs[job].endTime;
    for (int i = job + 1; i < jobs.size(); i++) {
        if (endTime <= jobs[i].startTime)
            return i;
    }
    return jobs.size();
}

int dp (vector<Job> & jobs, int job, vector<int> & memo) {
    if (job >= jobs.size())
        return 0;

    if (memo[job] == -1)
        memo[job] = max(jobs[job].profit + dp(jobs, nextJob(jobs, job), memo), dp(jobs, job + 1, memo));
    return memo[job];
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    vector<Job> jobs;
    for (int i = 0; i < startTime.size(); i++)
        jobs.push_back(Job{startTime[i], endTime[i], profit[i]});

    std::sort(jobs.begin(), jobs.end());

    vector<int> memo(jobs.size(), -1);
    return dp(jobs, 0, memo);
}

void test1 () {
    std::vector<int> startTime{1,2,3,3};
    std::vector<int> endTime{3,4,5,6};
    std::vector<int> profit{50,10,40,70};
    assert(jobScheduling(startTime, endTime, profit) == 120);
}

void test2 () {
    std::vector<int> startTime{1,2,3,4,6};
    std::vector<int> endTime{3,5,10,6,9};
    std::vector<int> profit{20,20,100,70,60};
    assert(jobScheduling(startTime, endTime, profit) == 150);
}

int main () {
    test1();
    test2();

    return 0;
}

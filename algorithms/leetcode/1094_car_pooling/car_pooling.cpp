#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {
    sort(trips.begin(), trips.end(), [](const vector<int> & l, const vector<int> & r) { return l[1] < r[1]; });

    map<int,int> q;
    for (int i = 0; i < trips.size(); i++) {
        while (!q.empty()) {
            auto t = q.begin();
            if (t->first > trips[i][1])
                break;
            capacity += t->second;
            q.erase(t);
        }
        if (capacity < trips[i][0])
            return false;
        capacity -= trips[i][0];
        q[trips[i][2]] += trips[i][0];
    }

    return true;
}

void test1 () {
    vector<vector<int>> trips;
    trips.push_back(vector<int>{2,1,5});
    trips.push_back(vector<int>{3,3,7});
    assert(carPooling(trips, 4) == false);
}

void test2 () {
    vector<vector<int>> trips;
    trips.push_back(vector<int>{2,1,5});
    trips.push_back(vector<int>{3,3,7});
    assert(carPooling(trips, 5) == true);
}

void test3 () {
    vector<vector<int>> trips;
    trips.push_back(vector<int>{10,5,7});
    trips.push_back(vector<int>{10,3,4});
    trips.push_back(vector<int>{7,1,8});
    trips.push_back(vector<int>{6,3,4});
    assert(carPooling(trips, 24) == true);
}

int main () {
    test1();
    test2();
    test3();

    return 0;
}


#include <vector>
#include <list>
#include <utility>
using namespace std;

class MyHashMap {
    static const int BUCKETS = 1009;
    vector<list<pair<int, int>>> buckets;

    // Normalize negative keys to a valid bucket index.
    int hash(int key) const {
        int index = key % BUCKETS;
        return (index < 0) ? index + BUCKETS : index;
    }

public:
    MyHashMap() : buckets(BUCKETS) {}

    void put(int key, int value) {
        auto &bucket = buckets[hash(key)];

        for (auto &p : bucket) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }

        // Insert into the selected bucket, not outer vector.
        bucket.push_back({key, value});
    }

    int get(int key) {
        for (auto &p : buckets[hash(key)]) {
            if (p.first == key) {
                return p.second;
            }
        }

        // Key does not exist.
        return -1;
    }

    void remove(int key) {
        auto &bucket = buckets[hash(key)];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};

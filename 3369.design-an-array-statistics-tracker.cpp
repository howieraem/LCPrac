#include <bits/stdc++.h>

// S: O(n)
class StatisticsTracker {
    std::queue<int> nums;

    // For O(1) getMean()
    long long sum;

    // For O(1) getMode()
    int max_freq;
    std::unordered_map<int, int> num2freq;
    std::unordered_map<int, std::set<int>> freq2nums;

    // For O(1) getMedian()
    // Because we may need to remove arbitrary numbers from heaps, 
    // use std::multiset rather than std::priority_queue.
    std::multiset<int> max_heap;   // left half, heap top is max
    std::multiset<int> min_heap;   // right half, heap top is min

    // ensure len(min_heap) <= len(max_heap) <= len(min_heap) + 1,
    // so that median can be calculated in O(1)
    void balance_heaps() {
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.insert(*max_heap.rbegin());
            max_heap.erase(std::prev(max_heap.end()));
        } else if (min_heap.size() > max_heap.size()) {
            max_heap.insert(*min_heap.begin());
            min_heap.erase(min_heap.begin());
        }
    }

public:
    StatisticsTracker() : sum(0), max_freq(0) {}
    
    // T: O(log(n))
    void addNumber(int number) {
        nums.push(number);
        sum += number;
        
        int prev_freq = num2freq[number]++;
        if (prev_freq > 0) {
            freq2nums[prev_freq].erase(number);
            // optional: erase empty set from freq2nums
        }
        freq2nums[prev_freq + 1].insert(number);
        max_freq = std::max(max_freq, prev_freq + 1);
        
        if (max_heap.empty() || number <= *max_heap.rbegin()) {
            max_heap.insert(number);
        } else {
            min_heap.insert(number);
        }
        balance_heaps();
    }

    // T: O(log(n))
    void removeFirstAddedNumber() {
        int number = nums.front();
        nums.pop();
        sum -= number;

        int prev_freq = num2freq[number]--;
        freq2nums[prev_freq].erase(number);
        // optional: erase empty set from freq2nums
        if (prev_freq > 1) {
            freq2nums[prev_freq - 1].insert(number);
        }

        max_freq -= (prev_freq == max_freq && freq2nums[prev_freq].empty());
    
        auto it = max_heap.find(number);
        if (it != max_heap.end()) {
            max_heap.erase(it);
        } else {
            min_heap.erase(min_heap.find(number));
        }
        balance_heaps();
    }
    
    // T: O(1)
    int getMean() {
        // return floor() according to the requirements
        return sum / nums.size();
    }
    
    // T: O(1)
    int getMedian() {
        if (max_heap.size() == min_heap.size()) {
            // return the larger median according to the requirements
            return *min_heap.begin();
        } else {
            return *max_heap.rbegin();
        }
    }
    
    // T: O(1)
    int getMode() {
        return *freq2nums[max_freq].begin();
    }
};

/**
 * Your StatisticsTracker object will be instantiated and called as such:
 * StatisticsTracker* obj = new StatisticsTracker();
 * obj->addNumber(number);
 * obj->removeFirstAddedNumber();
 * int param_3 = obj->getMean();
 * int param_4 = obj->getMedian();
 * int param_5 = obj->getMode();
 */
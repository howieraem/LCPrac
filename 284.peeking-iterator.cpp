/*
 * @lc app=leetcode id=284 lang=cpp
 *
 * [284] Peeking Iterator
 */

#include <bits/stdc++.h>

using std::vector;

class Iterator {
	struct Data;
	Data* data;

public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);

	// Returns the next element in the iteration.
	int next();

	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

// @lc code=start
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

// T: O(1)
// S: O(1)
class PeekingIterator : public Iterator {
	std::optional<int> cache_next = {};

public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    if (Iterator::hasNext()) {
			cache_next = Iterator::next();
		}
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return cache_next.value();
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int next_val = cache_next.value();
		if (Iterator::hasNext()) {
			cache_next = Iterator::next();
		} else {
			cache_next = {};
		}
		return next_val;
	}
	
	bool hasNext() const {
	    return cache_next.has_value();
	}
};
// @lc code=end


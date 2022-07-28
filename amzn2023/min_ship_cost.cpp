/**
 * A fully loaded truck carries k parcels. It is most efficient
 * for a truck to be fully loaded. There are a number of parcels
 * already on the truck as listed in parcels[]. There are parcels 
 * with a unique id that ranges from 1 through infinity. The 
 * parcel id is also the cost to ship that parcel.
 * 
 * Given the parcel IDs which are already added in the shipment, 
 * find the minimum possible cost of shipping the items added to 
 * complete the load.
 * 
 * Example: parcels = [2, 3, 6, 10, 11], k = 9
 * 
 * Parcel ids range from 1 to inf. After reviewing the current manifest,
 * the remaining parcels to choose from are [1, 4, 5, 7, 8, 9, 12, 13, ...].
 * There are 5 parcels already on the truck, and it can carry 9 parcels 
 * when fully loaded. Choose 4 more packages to include: [1, 4, 5, 7], which
 * will give the minimal cost 17.
 */
#include <bits/stdc++.h>

// T: O(k - n)
// S: O(n)
int min_ship_cost(const std::vector<int>& parcels, int k) {
    std::unordered_set<int> s(parcels.begin(), parcels.end());
    int cur = 1, ans = 0;
    while (s.size() < k) {
        if (s.find(cur) == s.end()) {
            ans += cur;
            s.insert(cur);
        }
        ++cur;
    }
    return ans;
}

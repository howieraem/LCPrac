/*
 * @lc app=leetcode id=1236 lang=cpp
 *
 * [1236] Web Crawler
 */

#include <bits/stdc++.h>

using std::string;

class HtmlParser {
public:
    vector<string> getUrls(string url);
};

// @lc code=start
/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    // Graph BFS
    // T: O(V + E), V := the number of URLs, E := the number of links
    // S: O(V)
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        const string hostname = startUrl.substr(0, startUrl.find('/', 7));
        std::queue<string> q;
        std::unordered_set<string> vis;
        q.push(startUrl);
        vis.insert(startUrl);

        while (q.size()) {
            string cur_url = q.front(); q.pop();
            for (const auto& url : htmlParser.getUrls(cur_url)) {
                if (url.rfind(hostname, 0) != string::npos && vis.find(url) == vis.end()) {
                    q.push(url);
                    vis.insert(url);
                }
            }
        }

        std::vector<string> res;
        res.reserve(vis.size());
        std::copy(vis.begin(), vis.end(), std::back_inserter(res));
        return res;
    }
};
// @lc code=end


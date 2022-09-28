/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
// Tweet linked list + User object + Priority queue wrt timestamp
class Twitter {
    struct Tweet {
        int id, t;
        Tweet* next;

        Tweet(int _id, int _t, Tweet* _next) : id(_id), t(_t), next(_next) {}
    };

    class TweetComparator {
    public:
        bool operator() (Tweet* a, Tweet* b) {
            // Tweets must be ordered from most recent to least recent,
            // i.e. from large t to small t
            return a->t < b->t;
        }
    };

    struct User {
        int id;
        std::unordered_set<int> following;
        Tweet* head;

        User(int _id) : id(_id), head(nullptr) {
            following.insert(_id);  // IMPORTANT: user can see own tweets
        }

        void follow(int uid) {
            following.insert(uid);
        }

        void unfollow(int uid) {
            following.erase(uid);
        }

        void post(int tweet_id, int t) {
            head = new Tweet(tweet_id, t, head);
        }
    };

    static const int N_TWEETS_IN_FEED = 10;
    int time = 0;

    // Possible improvement: use std::unordered_set<User*> instead,
    // with custom hash and equal functions
    // https://stackoverflow.com/questions/50888127
    // https://stackoverflow.com/questions/31628251
    std::unordered_map<int, User*> users;

public:
    /**
     * @brief Composes a new tweet with ID tweetId by the user userId. 
     * Each call to this function will be made with a unique tweetId.
     * 
     * @param userId 
     * @param tweetId 
     */
    void postTweet(int userId, int tweetId) {
        auto it = users.find(userId);
        User* u;
        if (it == users.end()) {
            u = new User(userId);
            users[userId] = u;
        } else {
            u = it->second;
        }
        u->post(tweetId, time++);
    }

    /**
     * @brief Retrieves the 10 most recent tweet IDs in the user's news feed. 
     * Each item in the news feed must be posted by users who the user followed or by the user themself. 
     * Tweets must be ordered from most recent to least recent.
     * 
     * @param userId 
     * @return vector<int> 
     */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto it = users.find(userId);
        if (it == users.end()) {
            return res;
        }

        std::priority_queue<Tweet*, vector<Tweet*>, TweetComparator> max_heap;
        for (const int& u : it->second->following) {
            if (users[u]->head != nullptr) {
                max_heap.push(users[u]->head);
            }
        }

        res.reserve(N_TWEETS_IN_FEED);
        while (max_heap.size()) {
            Tweet* tweet = max_heap.top(); max_heap.pop();
            res.push_back(tweet->id);
            if (res.size() == N_TWEETS_IN_FEED) break;
            if (tweet->next != nullptr) {
                max_heap.push(tweet->next);
            }
        }

        return res;
    }
    
    /**
     * @brief The user with ID followerId started following the user with ID followeeId.
     * 
     * @param followerId 
     * @param followeeId 
     */
    void follow(int followerId, int followeeId) {
        User* follower;
        auto it = users.find(followerId);
        if (it == users.end()) {
            follower = new User(followerId);
            users[followerId] = follower;
        } else {
            follower = it->second;
        }

        if (users.find(followeeId) == users.end()) {
            users[followeeId] = new User(followeeId);
        }

        follower->follow(followeeId);
    }
    
    /**
     * @brief The user with ID followerId started unfollowing the user with ID followeeId.
     * 
     * @param followerId 
     * @param followeeId 
     */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            auto it = users.find(followerId);
            if (it != users.end()) {
                it->second->unfollow(followeeId);
            }
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end


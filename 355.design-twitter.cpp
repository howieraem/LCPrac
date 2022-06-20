/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Twitter {
    struct Tweet {
        int id, t;
        Tweet* next;

        Tweet(int _id, int _t) : id(_id), t(_t), next(nullptr) {}
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
            following.insert(_id);
        }

        void follow(int uid) {
            following.insert(uid);
        }

        void unfollow(int uid) {
            following.erase(uid);
        }

        void post(int tweet_id, int t) {
            Tweet* tweet = new Tweet(tweet_id, t);
            tweet->next = head;
            head = tweet;
        }
    };

    static const int N_TWEETS_IN_FEED = 10;
    int time = 0;
    std::unordered_map<int, User*> users;

public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        User* u;
        if (users.find(userId) == users.end()) {
            u = new User(userId);
            users[userId] = u;
        } else {
            u = users[userId];
        }
        u->post(tweetId, time++);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        if (users.find(userId) == users.end()) {
            return res;
        }

        std::priority_queue<Tweet*, vector<Tweet*>, TweetComparator> pq;
        for (const int& u : users[userId]->following) {
            Tweet* tweet = users[u]->head;
            if (tweet != nullptr) {
                pq.push(tweet);
            }
        }

        int n = 0;
        while (pq.size() && n++ < N_TWEETS_IN_FEED) {
            Tweet* tweet = pq.top(); pq.pop();
            res.push_back(tweet->id);
            if (tweet->next != nullptr) {
                pq.push(tweet->next);
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        User* follower;

        if (users.find(followerId) == users.end()) {
            follower = new User(followerId);
            users[followerId] = follower;
        } else {
            follower = users[followerId];
        }

        if (users.find(followeeId) == users.end()) {
            users[followeeId] = new User(followeeId);
        }

        follower->follow(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (users.find(followerId) != users.end() && followerId != followeeId) {
            users[followerId]->unfollow(followeeId);
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


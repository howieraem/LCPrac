#
# @lc app=leetcode.cn id=355 lang=python3
#
# [355] 设计推特
#
import heapq
from collections import defaultdict

# @lc code=start
class Tweet:
    # replicates a list node with time stamp for sorting

    def __init__(self, i, time):
        self.id = i
        self.t = time
        self.next: Tweet = None

    def __lt__(self, other):
        return self.t > other.t


class Twitter:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.user_tweets = defaultdict(lambda: None)    # returns None if key not exists
        self.user_follows = defaultdict(set)
        self.t = 0  # time stamp


    def postTweet(self, userId: int, tweetId: int) -> None:
        """
        Compose a new tweet.
        """
        self.t += 1
        tweet = Tweet(tweetId, self.t)
        # insert the new tweet to the head
        tweet.next = self.user_tweets[userId]
        self.user_tweets[userId] = tweet
        

    def getNewsFeed(self, userId: int) -> List[int]:
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        """
        tweets = []
        heap = []
        
        tweet = self.user_tweets[userId]
        if tweet:
            heap.append(tweet)
        for user in self.user_follows[userId]:
            tweet = self.user_tweets[user]
            if tweet:
                heap.append(tweet)
        heapq.heapify(heap)     # rearrange according to time stamp

        while heap and len(tweets) < 10:
            head = heapq.heappop(heap)
            tweets.append(head.id)
            if head.next:
                heapq.heappush(heap, head.next)
        
        return tweets
        

    def follow(self, followerId: int, followeeId: int) -> None:
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        """
        if followerId != followeeId:
            self.user_follows[followerId].add(followeeId)
        

    def unfollow(self, followerId: int, followeeId: int) -> None:
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        """
        if followerId != followeeId:
            self.user_follows[followerId].discard(followeeId)   # discard doesn't raise error if key not exists
        


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
# @lc code=end


class Twitter {
public:
    Twitter() {
        
    }

    void postTweet(int userId, int tweetId) {

        tweets.push_back({tweetId, userId});
    }

    vector<int> getNewsFeed(int userId) {

        vector<int> feeds;
        for (int i = (int)tweets.size() - 1; i >= 0 && feeds.size() < 10; --i) {
            int followeeId = tweets[i].second;
            if (userId == followeeId
                || (followees.count(userId) && followees[userId].count(followeeId))) {
                feeds.push_back(tweets[i].first);
            }
        }
        return feeds;
    }

    void follow(int followerId, int followeeId) {

        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {

        followees[followerId].erase(followeeId);
    }

private:
    vector<pair<int, int>> tweets;
    unordered_map<int, unordered_set<int>> followees;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

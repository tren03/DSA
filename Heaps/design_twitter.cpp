// The Twitter class implements a mini-Twitter system using a global timestamp, an unordered_map for user relationships, and another unordered_map for storing tweets with timestamps. Users can post tweets, which are recorded with the current timestamp, and follow/unfollow other users, updating their relationship mappings accordingly. The getNewsFeed method retrieves the 10 most recent tweets from a user and their followees by leveraging a max-heap (priority queue) to efficiently sort and extract the latest tweets. This design ensures efficient operations for posting, following, unfollowing, and retrieving news feeds.#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Twitter {
public:
    int time = 0;
    unordered_map<int, unordered_set<int>> rel;
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        rel[userId].insert(userId);
        tweets[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> feed;
        for (auto i : rel[userId]) {
            for (auto t : tweets[i]) {
                feed.push(t);
            }
        }
        
        vector<int> newsFeed;
        int count = 0;
        while (!feed.empty() && count < 10) {
            newsFeed.push_back(feed.top().second);
            feed.pop();
            count++;
        }
        return newsFeed;
    }

    void follow(int followerId, int followeeId) {
        rel[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            rel[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId, tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId, followeeId);
 * obj->unfollow(followerId, followeeId);
 */

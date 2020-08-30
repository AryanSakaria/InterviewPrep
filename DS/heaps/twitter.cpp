#include<bits/stdc++.h>

using namespace std;
struct Tweet
{
	int tweet_id;
	int tweet_time;
};

struct CompareHeight { 
    bool operator()(Tweet const& p1, Tweet const& p2) 
    { 
        // return "true" if "p1" is ordered  
        // before "p2", for example: 
        return p1.tweet_time < p2.tweet_time; 
    } 
}; 

class Twitter {
public:
    /** Initialize your data structure here. */
    int time;
    // we have a priority queue of tweets posted by the user
    unordered_map<int, vector<Tweet> > tweets;
    //a hash map of all users the user follows 
    unordered_map<int, vector<int> > follows;

    Twitter() 
    {
        //each tweet has time, id and user
        //each user has news_feed_tweets, people following, people followed
        //list of tweets
        //list of users -> unordered map to get instantly who follow who 
        //time variable
        time = 0;
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) 
    {
    	Tweet temp_tweet;
    	temp_tweet.tweet_id = tweetId; 
    	temp_tweet.tweet_time = time;
    	time++;

    	tweets[userId].push_back(temp_tweet);
    	// cout << "User " << userId << " with num tweets: " << tweets[userId].size() << "posted tweet " << tweetId << endl;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) 
    {
        priority_queue<Tweet, vector<Tweet>,  CompareHeight > p_q;

        for (int i = 0; i < tweets[userId].size(); ++i)
        {
        	p_q.push(tweets[userId][i]);
        	// cout << "Tweet ID pushed in stack" << tweets[userId][i].tweet_id << endl;
        	/* code */
        }

        for(int i = 0; i < follows[userId].size(); ++i)
        {
        	for(int j = 0; j < tweets[follows[userId][i]].size(); ++j)
        	{
        		p_q.push(tweets[follows[userId][i]][j]);
        		// cout << "Tweet ID pushed in stack" << tweets[follows[userId][i]][j].tweet_id << endl;
        	}
        }
        // cout << "top" << p_q.top().tweet_time << endl;
        int i = 0;
        vector<int> feed;
        // cout << "Printing feed" << endl;
        while(!p_q.empty() && i < 10)
        {
        	i++;
        	feed.push_back(p_q.top().tweet_id);
        	// cout << p_q.top().tweet_id << " ";
        	p_q.pop();
        }
        // for(int j = 0; j < feed.size(); j++)
        // {
        // 	cout << feed[j] << " " << endl;
        // }
        return feed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) 
    {
    	if(followerId == followeeId)
    	{
    		return;
    	}

        
        
        
    	if(binary_search(follows[followerId].begin(), follows[followerId].end(), followeeId))
    	{
    		return;
    	}
        
        follows[followerId].push_back(followeeId);
        // cout << "successfully followed" << endl;
        sort(follows[followerId].begin(), follows[followerId].end());
        // cout << endl;
        // cout << "User follows the following" << endl;
        // for(int i=0; i < follows[followerId].size(); i++ )
        // {
        // 	cout << follows[followerId][i] << " " ;
        // }
        // cout << endl;
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) 
    {
	
        
        if(follows.find(followerId)==follows.end())
        {
        	//not found
        	return;
        }
        
    	if(binary_search(follows[followerId].begin(), follows[followerId].end(), followeeId))
    	{
    		follows[followerId].erase(lower_bound(follows[followerId].begin(), follows[followerId].end(), followeeId));
            // cout << "successfully unfollowed" << endl;

    	}
    	// cout << endl;
        // cout << "User follows the following" << endl;
        for(int i=0; i < follows[followerId].size(); i++ )
        {
        	// cout << follows[followerId][i] << " " ;
        }
        // cout << endl;
        
    }
};





int main()
{
	Twitter* obj = new Twitter();
    obj->postTweet(1,3);
    obj->postTweet(1,4);
    obj->postTweet(2,35);
    obj->postTweet(2,37);


    obj->postTweet(3,5);
    obj->postTweet(17,29);
    obj->postTweet(17,30);
    obj->postTweet(1,31);

    obj->getNewsFeed(1);
    obj->getNewsFeed(2);
    obj->getNewsFeed(17);
    obj->getNewsFeed(3);




    obj->follow(1,3);
    obj->unfollow(1,3);
    obj->getNewsFeed(1);
    
    // obj->follow(1,2);
    // obj->follow(1,17);

    // obj->unfollow(1,3);

	return 0;
}
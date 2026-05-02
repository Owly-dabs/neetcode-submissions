import heapq

class Twitter:

    def __init__(self):
        self.time = 0 
        self.user_tweets = {}
        self.user_followers = {}
        self.follower_feeds = {}

    def createUser(self, userId: int) -> None:
        self.user_tweets[userId] = []
        self.user_followers[userId] = []
        self.follower_feeds[userId] = []

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.time += 1

        # create userId if doesnt exist
        if userId not in self.user_tweets:
            self.createUser(userId)

        # add to user_tweets
        self.user_tweets[userId].append((-self.time,tweetId))

        heapq.heappush(self.follower_feeds[userId], (-self.time,tweetId))

        # updates all follower_feeds (heaps)
        for followerId in self.user_followers[userId]:
            heapq.heappush(self.follower_feeds[followerId], (-self.time, tweetId))

    def getNewsFeed(self, userId: int) -> List[int]:
        res = []
        copy = self.follower_feeds[userId][:]
        for _ in range(10):
            if len(copy) == 0:
                return res
            res.append(heapq.heappop(copy)[1])
        return res


    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId == followeeId: return
        if followerId not in self.user_tweets:
            self.createUser(followerId)
        if followeeId not in self.user_tweets:
            self.createUser(followeeId)
        if followerId in self.user_followers[followeeId]:
            return

        self.user_followers[followeeId].append(followerId)
        new_tweets = self.user_tweets[followeeId]
        self.follower_feeds[followerId].extend(new_tweets)
        heapq.heapify(self.follower_feeds[followerId])


    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followerId == followeeId: return
        if followerId not in self.user_followers[followeeId]:
            return
            
        self.user_followers[followeeId].remove(followerId)
        remove_tweets = self.user_tweets[followeeId]
        for t in remove_tweets:
            self.follower_feeds[followerId].remove(t)
        heapq.heapify(self.follower_feeds[followerId])

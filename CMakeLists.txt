cmake_minimum_required(VERSION 3.18)
project(tweet_sentiment_analysis)

# Create the executable for sorting
add_executable(test_DSString src/test_DSString.cpp)
add_executable(tweet_sentiment_analysis src/main.cpp src/DSString.cpp src/DSString.h src/Tweets.cpp src/Tweets.h src/Word.cpp src/Word.h src/Functions.cpp src/Functions.h)


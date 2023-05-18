#include "Functions.h"
vector<DSString>positiveTweets;
vector<DSString>negativeTweets;
void readTrainFile(char fileToOpen[]) {
    //open file
    ifstream file(fileToOpen);
    char line[361], tweet[281];
    char sentiment[2];
    //extract just the tweets from file
    if (file.is_open()) {
        // remove header row
        file.getline(line, 361, '\n');

        int i = 0;
        while (file && i < 20000) {
            // read till first comma
            file.getline(sentiment, 361, ',');

            for (int i = 0; i < 4; i++)
                // parse till u get to last comma
                file.getline(tweet, 361, ',');

            // then read in the tweet after the last comma
            file.getline(tweet, 361, '\n');
            addTweet(tweet, sentiment);
            i++;
        }
        file.close();
    }
}
void addTweet(DSString tweet, DSString sentiment) {
    // add tweets to positive or negative list based on sentiment
    if (strcmp(sentiment.c_str(), "4") == 0)
        positiveTweets.push_back(tweet);

    else if (strcmp(sentiment.c_str(), "0") == 0)
        negativeTweets.push_back(tweet);
}

vector<DSString> nonsentimentalWords;
// list of non-sentimental words to take out of tweets that are neither positive or negative
//vector of non-sentimental words to take out of tweets that are neither positive or negative
vector<DSString> createVector(){
    nonsentimentalWords.push_back("a");
    nonsentimentalWords.push_back("about");
    nonsentimentalWords.push_back("above");
    nonsentimentalWords.push_back("after");
    nonsentimentalWords.push_back("again");
    nonsentimentalWords.push_back("against");
    nonsentimentalWords.push_back("all");
    nonsentimentalWords.push_back("am");
    nonsentimentalWords.push_back("an");
    nonsentimentalWords.push_back("and");
    nonsentimentalWords.push_back("any");
    nonsentimentalWords.push_back("are");
    nonsentimentalWords.push_back("aren't");
    nonsentimentalWords.push_back("as");
    nonsentimentalWords.push_back("at");
    nonsentimentalWords.push_back("be");
    nonsentimentalWords.push_back("because");
    nonsentimentalWords.push_back("been");
    nonsentimentalWords.push_back("before");
    nonsentimentalWords.push_back("being");
    nonsentimentalWords.push_back("below");
    nonsentimentalWords.push_back("between");
    nonsentimentalWords.push_back("both");
    nonsentimentalWords.push_back("but");
    nonsentimentalWords.push_back("by");
    nonsentimentalWords.push_back("can");
    nonsentimentalWords.push_back("can't");
    nonsentimentalWords.push_back("cannot");
    nonsentimentalWords.push_back("could");
    nonsentimentalWords.push_back("couldn't");
    nonsentimentalWords.push_back("did");
    nonsentimentalWords.push_back("didn't");
    nonsentimentalWords.push_back("do");
    nonsentimentalWords.push_back("does");
    nonsentimentalWords.push_back("doesn't");
    nonsentimentalWords.push_back("doing");
    nonsentimentalWords.push_back("don't");
    nonsentimentalWords.push_back("down");
    nonsentimentalWords.push_back("during");
    nonsentimentalWords.push_back("each");
    nonsentimentalWords.push_back("except");
    nonsentimentalWords.push_back("few");
    nonsentimentalWords.push_back("for");
    nonsentimentalWords.push_back("from");
    nonsentimentalWords.push_back("further");
    nonsentimentalWords.push_back("get");
    nonsentimentalWords.push_back("had");
    nonsentimentalWords.push_back("hadn't");
    nonsentimentalWords.push_back("has");
    nonsentimentalWords.push_back("hasn't");
    nonsentimentalWords.push_back("have");
    nonsentimentalWords.push_back("haven't");
    nonsentimentalWords.push_back("having");
    nonsentimentalWords.push_back("he");
    nonsentimentalWords.push_back("he'd");
    nonsentimentalWords.push_back("he'll");
    nonsentimentalWords.push_back("he's");
    nonsentimentalWords.push_back("her");
    nonsentimentalWords.push_back("here");
    nonsentimentalWords.push_back("here's");
    nonsentimentalWords.push_back("hers");
    nonsentimentalWords.push_back("herself");
    nonsentimentalWords.push_back("him");
    nonsentimentalWords.push_back("himself");
    nonsentimentalWords.push_back("his");
    nonsentimentalWords.push_back("how");
    nonsentimentalWords.push_back("how's");
    nonsentimentalWords.push_back("I");
    nonsentimentalWords.push_back("i");
    nonsentimentalWords.push_back("i'd");
    nonsentimentalWords.push_back("i'll");
    nonsentimentalWords.push_back("i'm");
    nonsentimentalWords.push_back("i've");
    nonsentimentalWords.push_back("idk");
    nonsentimentalWords.push_back("if");
    nonsentimentalWords.push_back("in");
    nonsentimentalWords.push_back("into");
    nonsentimentalWords.push_back("is");
    nonsentimentalWords.push_back("isn't");
    nonsentimentalWords.push_back("it");
    nonsentimentalWords.push_back("it's");
    nonsentimentalWords.push_back("its");
    nonsentimentalWords.push_back("itself");
    nonsentimentalWords.push_back("just");
    nonsentimentalWords.push_back("me");
    nonsentimentalWords.push_back("more");
    nonsentimentalWords.push_back("most");
    nonsentimentalWords.push_back("mustn't");
    nonsentimentalWords.push_back("my");
    nonsentimentalWords.push_back("myself");
    nonsentimentalWords.push_back("no");
    nonsentimentalWords.push_back("nor");
    nonsentimentalWords.push_back("not");
    nonsentimentalWords.push_back("of");
    nonsentimentalWords.push_back("off");
    nonsentimentalWords.push_back("on");
    nonsentimentalWords.push_back("once");
    nonsentimentalWords.push_back("only");
    nonsentimentalWords.push_back("or");
    nonsentimentalWords.push_back("other");
    nonsentimentalWords.push_back("ought");
    nonsentimentalWords.push_back("our");
    nonsentimentalWords.push_back("ours");
    nonsentimentalWords.push_back("ourselves");
    nonsentimentalWords.push_back("out");
    nonsentimentalWords.push_back("over");
    nonsentimentalWords.push_back("own");
    nonsentimentalWords.push_back("same");
    nonsentimentalWords.push_back("she");
    nonsentimentalWords.push_back("she'd");
    nonsentimentalWords.push_back("she'll");
    nonsentimentalWords.push_back("she's");
    nonsentimentalWords.push_back("should");
    nonsentimentalWords.push_back("shouldn't");
    nonsentimentalWords.push_back("so");
    nonsentimentalWords.push_back("some");
    nonsentimentalWords.push_back("such");
    nonsentimentalWords.push_back("than");
    nonsentimentalWords.push_back("that");
    nonsentimentalWords.push_back("that's");
    nonsentimentalWords.push_back("the");
    nonsentimentalWords.push_back("their");
    nonsentimentalWords.push_back("theirs");
    nonsentimentalWords.push_back("them");
    nonsentimentalWords.push_back("themselves");
    nonsentimentalWords.push_back("then");
    nonsentimentalWords.push_back("there");
    nonsentimentalWords.push_back("there's");
    nonsentimentalWords.push_back("these");
    nonsentimentalWords.push_back("they");
    nonsentimentalWords.push_back("they'd");
    nonsentimentalWords.push_back("they'll");
    nonsentimentalWords.push_back("they're");
    nonsentimentalWords.push_back("they've");
    nonsentimentalWords.push_back("this");
    nonsentimentalWords.push_back("those");
    nonsentimentalWords.push_back("through");
    nonsentimentalWords.push_back("to");
    nonsentimentalWords.push_back("too");
    nonsentimentalWords.push_back("under");
    nonsentimentalWords.push_back("until");
    nonsentimentalWords.push_back("up");
    nonsentimentalWords.push_back("very");
    nonsentimentalWords.push_back("was");
    nonsentimentalWords.push_back("wasn't");
    nonsentimentalWords.push_back("we");
    nonsentimentalWords.push_back("we'd");
    nonsentimentalWords.push_back("we'll");
    nonsentimentalWords.push_back("we're");
    nonsentimentalWords.push_back("we've");
    nonsentimentalWords.push_back("were");
    nonsentimentalWords.push_back("weren't");
    nonsentimentalWords.push_back("what");
    nonsentimentalWords.push_back("what's");
    nonsentimentalWords.push_back("when");
    nonsentimentalWords.push_back("when's");
    nonsentimentalWords.push_back("where");
    nonsentimentalWords.push_back("where's");
    nonsentimentalWords.push_back("which");
    nonsentimentalWords.push_back("while");
    nonsentimentalWords.push_back("who");
    nonsentimentalWords.push_back("who's");
    nonsentimentalWords.push_back("whom");
    nonsentimentalWords.push_back("why");
    nonsentimentalWords.push_back("why's");
    nonsentimentalWords.push_back("with");
    nonsentimentalWords.push_back("won't");
    nonsentimentalWords.push_back("would");
    nonsentimentalWords.push_back("wouldn't");
    nonsentimentalWords.push_back("you");
    nonsentimentalWords.push_back("you'd");
    nonsentimentalWords.push_back("you'll");
    nonsentimentalWords.push_back("you're");
    nonsentimentalWords.push_back("you've");
    nonsentimentalWords.push_back("your");
    nonsentimentalWords.push_back("yours");
    nonsentimentalWords.push_back("yourself");
    nonsentimentalWords.push_back("yourselves");
    nonsentimentalWords.push_back("now");
    nonsentimentalWords.push_back("then");
    };
vector<Word>positiveWords;
vector<Word>negativeWords;
void addWords(vector<DSString>& tweetsList, vector<Word>& wordsList) {
    // pointer to point to each individual word in tweet
    char* point;

    // loop through tweets
    for (int i = 0; unsigned(i) < tweetsList.size(); i++) {

        // pointer points to first word in tweet
        point = strtok(tweetsList[i].c_str(), " ");
        // loop through tweet
        while (point != NULL) {
            DSString word = point;
            // remove punctuation from word
            chopUpWord(&word);

            // check if word is in non-sentimental list or a user tag
            bool isValidWord = validWord(word);
            if (!isValidWord) {
                point = strtok(NULL, " ");
                continue;

            }

            if ((point != NULL) && (point[0] != '\0')) {
                // see if word exists in corresponding word list
                vector<Word>::iterator it = find(wordsList.begin(), wordsList.end(), Word(point));

                // if it does exist, increase quantity
                if (it != wordsList.end())
                    it->quantity++;
                    // if it doesn't exist, add to list
                else {
                    Word temp(point);
                    wordsList.push_back(temp);
                }
            }
            // advance to next word
            point = strtok(NULL, " ");

        }
    }
}
void chopUpWord(DSString* word) {
    // function to chop up word by calling another function to remove certain characters that are irrelevant
    removeChar(word, ',');
    removeChar(word, '.');
    removeChar(word, '!');
    removeChar(word, '"');
    removeChar(word, '?');
    removeChar(word, '(');
    removeChar(word, ')');
}
bool validWord(DSString word) {
    // check if word has @ sign
    if (strchr(word.c_str(), '@'))
        return false;
        // check if word is in nonsentimental list
    else if (find(nonsentimentalWords.begin(), nonsentimentalWords.end(), word) != nonsentimentalWords.end())
        return false;
    else
        return true;
}
void removeChar(DSString* word, char c) {
    // check if word is empty
    if (word == NULL)
        return;
    // create pointer that points to start of word
    char* result = word->c_str();
    char* wordPtr = word->c_str();

    // loop through every character in word
    while (*wordPtr) {
        // store letter in pointer value only if it is not the letter we're trying to remove
        if (*wordPtr != c) {
            *result = *wordPtr;
            result++;
        }
        // advance to next letter
        wordPtr++;
    }
    // add null character to end
    *result = '\0';
}
// this vector stores the results of my sentiment classifier given a set of tweets
vector<Tweets>tweetSentimentResults;
void readTestFile(char testFile[]) {
    //open file
    int sentiment = 0;

    ifstream file(testFile);
    char line[361], tweet[281], id[20];
    if (file.is_open()) {
        //remove header row in csv file
        file.getline(line, 361, '\n');

        int i = 0;
        // loop till end of file
        while (file && i < 10000) {
            // get id
            file.getline(id, 20, ',');

            // parse line to get just the tweet
            for (int i = 0; i < 3; i++)
                file.getline(tweet, 361, ',');
            file.getline(tweet, 361, '\n');

            // calls function to predict sentiment then add it to the list of results
            sentiment = predictTweet(tweet);
            Tweets temp(id, sentiment);
            tweetSentimentResults.push_back(temp);
            i++;
        }
        file.close();
    }
}
int predictTweet(char tweet[]) {
    char* point;

    // pointer points to first word in tweets
    point = strtok(tweet, " ");
    int sentimentScore = 0;
    // check every word and increase occurrence
    while (point != NULL) {
        // check if word is valid
        bool isValidWord = validWord(point);
        if (!isValidWord) {
            point = strtok(NULL, " ");
            continue;
        }
        // remove irrelevant characters from word
        DSString word = point;
        chopUpWord(&word);

        wordExists(sentimentScore, word);
        // advance to next word
        point = strtok(NULL, " ");
    }

    // check total sentiment of tweet
    if (sentimentScore >= 0)
        return 4;
    else
        return 0;
}
void wordExists(int& sentimentScore, DSString& word) {
    int positiveOcc = 0, negativeOcc = 0;
    // checks if the word exists
    vector<Word>::iterator it = find(positiveWords.begin(), positiveWords.end(), Word(word.c_str()));
    if (it != positiveWords.end())
        // if it does exist, find the number of occurrences of that word in the training phase
        positiveOcc += it->quantity;
    // repeat process for negativeWords
    it = find(negativeWords.begin(), negativeWords.end(), Word(word.c_str()));
    if (it != negativeWords.end())
        negativeOcc += it->quantity;
    // now compare the total number of occurrences of the positive words from the training phase to negative words
    if (positiveOcc >= negativeOcc)
        sentimentScore++;
    else
        sentimentScore--;
}

vector<Tweets>tweetActualSentimentResults;
void getActualSentiment(char sentimentFile[]) {
    //open file
    ifstream file(sentimentFile);
    char line[361], id[20], sentiment[5];

    if (file.is_open()) {
        //remove header line
        file.getline(line, 361, '\n');
        int i = 0;

        while (file && i < 10000) {
            // reading file to first comma to get sentiment
            file.getline(sentiment, 20, ',');
            file.getline(id, 20, '\n');
            int sentimentInt = 0;
            // stores sentiment as an integer
            if (sentiment[0] == '4')
                sentimentInt = 4;
            else if (sentiment[0] == '0')
                sentimentInt = 0;
            // adds tweets to the actual sentiments of the tweets list
            Tweets temp(id, sentimentInt);
            tweetActualSentimentResults.push_back(temp);
            i++;
        }
        file.close();
    }
}

void printResults(char outputFile[]) {
    vector<DSString>idsWrong;
    ofstream output(outputFile);
    int amountRight = 0;

    if (output.is_open()) {
        // loop through Tweets list
        for (int i = 0; i < tweetSentimentResults.size(); i++)
            // check if sentiments match
            if (tweetSentimentResults[i].Sentiment == tweetActualSentimentResults[i].Sentiment)
                ++amountRight;
            else
                // if sentiments dont match, add tweets id to idsWrong vector
                idsWrong.push_back(tweetSentimentResults[i].Id);

        float percentRight = (float)amountRight / tweetActualSentimentResults.size();

        // output percent right
        output << "% Correct: "<< setprecision(3)<<percentRight << endl;

        // output wrong id's
        output<<"\nIncorrectly Classified Tweet IDs:"<<endl;
        for (int i = 0; i < idsWrong.size(); i++)
            output << idsWrong[i] << endl;
        output.close();
    }

}

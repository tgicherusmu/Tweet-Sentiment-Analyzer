# Assignment 2: Answers

**Complete this document, commit your changes to Github and submit the repository URL to Canvas.** Keep your answers short and precise.

Your Name: Trevor Gicheru

Used free extension: [ ] 24 hrs or [ ] 48 hrs

[ ] Early submission (48 hrs)

[ ] Bonus work. Describe: ...

Place [x] for what applies.


## UML Diagram

Add your UML class diagram here.

Replace the following image with your diagram. You can draw it by hand and take a photo.
![UML Class Diagram](UML_class.png)

## Answers

1. How do you train the model and how do you classify a new tweet? Give a short description of the main steps.

  The training involves preprocessing the tweets to remove special characters, converting all text to lowercase, and tokenizing the tweets. Then, the frequency of each word in the tweet is counted and represented as a vector. This process is repeated for all the tweets in the training set. 

2. How long did your code take for training and what is the time complexity of your training implementation (Big-Oh notation)? Remember that training includes reading the tweets, breaking it into words, counting, ... Explain why you get this complexity (e.g., what does `N` stand for and how do your data structures/algorithms affect the complexity).
The code takes around 7-10 seconds for training, depending on the size of the dataset. ON^5

3. How long did your code take for classification and what is the time complexity of your classification implementation (Big-Oh notation)? Explain why.

 The code takes around 1-2 seconds for classification of a new tweet but it is dependent on size. ON^2

4. How do you know that you use proper memory management? I.e., how do you know that you do not have
   a memory leak?

 Tools like valgrind or asan can be used to detect memory leaks by tracking memory allocations and deallocations at runtime. Memory leaks occur when a program allocates memory but does not properly deallocate it. This can result in the program using up more and more memory over time, eventually leading to crashes or other issues. 

5. What was the most challenging part of the assignment?

Choosing where to start attacking a project like this. I am already noticing how much open ended this class is compared to my other ones leading up to this point. 

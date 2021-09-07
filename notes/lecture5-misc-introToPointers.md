# Lecture 5 - Some Misc. Topics and Intro to Pointers
## Miscellaneous Topics
The following are some micellaneous topics that will be helpful in your Project 1. 
### More on `stringstream`

### Generating Random Numbers and Chars
We can generate a random number by using the `rand()` and `srand()` functions. 

The following will generate a number between 0 and 9. 
```
int randNum = rand() % 10;
```

However, the issue with this is that the same random numbers will be generated over and over. That is because the seed (https://en.wikipedia.org/wiki/Random_seed) is always set to 1. We will want to change that to get truly random numbers each time. A good way to ensure that you are always getting a fresh set of random numbers is to set the seed to a relative time using the `time()` function (https://www.cplusplus.com/reference/ctime/time/). In this case, the value returned generally represents the number of seconds since 00:00 hours, Jan 1, 1970 UTC (i.e., the current unix timestamp). The seed is set as follows:
```
srand(time(NULL)); 
```

Now how do we change that to a char? 

Remember that a `char` in C++ has an ASCII decimal value: 
![image](https://user-images.githubusercontent.com/3376451/132389795-4d12e60e-e646-413d-a7a3-53cd6f554639.png)

So, for example the character '0' has the decimal equivalent of 48 and '9' has the decimal equivalent of 57. Therefore, if we wanted to generate a character from '0' to '9' then we just need to generate a number between 48 and 57:
```
int num = rand() % 10 + 48; // will generate a number between 48 and 57
char c = num; // c will now be a character between '0' and '9' 
```

## Introduction to Pointers

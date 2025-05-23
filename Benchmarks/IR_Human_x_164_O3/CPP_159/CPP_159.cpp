/*
You"re a hungry rabbit, and you already have eaten a certain number of carrots,
but now you need to eat more carrots to complete the day's meals.
you should return a vector of { total number of eaten carrots after your meals,
                                the number of carrots left after your meals }
if there are not enough remaining carrots, you will eat all remaining carrots, but will still be hungry.

Example:
* eat(5, 6, 10) -> {11, 4}
* eat(4, 8, 9) -> {12, 1}
* eat(1, 10, 10) -> {11, 0}
* eat(2, 11, 5) -> {7, 0}

Variables:
@number : integer
    the number of carrots that you have eaten.
@need : integer
    the number of carrots that you need to eat.
@remaining : integer
    the number of remaining carrots thet exist in stock

Constrain:
* 0 <= number <= 1000
* 0 <= need <= 1000
* 0 <= remaining <= 1000

Have fun :)
*/
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> eat(int number,int need,int remaining){

    if (need>remaining) return {number+remaining, 0};
    return {number+need,remaining-need};
}

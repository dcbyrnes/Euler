/*
    Created by: Daniel Byrnes
    Date: 10/4/2015

    Purpose: Sort numbers in the form b^e, b and e are integers between 
             1 and 10^9. Print the kth smallest integer in the list. 

    Usage: Upon execution the program will ask the use to input an integer x
           between 1 and 10^5. Then the program will generate x base-exponent pairs
           and report the kth smallest number in the list, where k is a randomly 
           generated number between 1 and x. 
*/

#include "exponential.h"

// comparator function used by qsort
int compare(const void* a, const void* b) {
    bexp* x = (bexp*)a;
    bexp* y = (bexp*)b;
     
    if(x->lnTransform < y->lnTransform) return -1;
    if(x->lnTransform > y->lnTransform) return 1;
    return 0;
}

int main() {
    /* init variables */
    int arr_length = 0, idx = 0;
    printf("Please enter an integer between 1 and 100,000: ");
    std::cin >> arr_length; 
    bexp numList[arr_length]; // array of length specified by user

    for (int i = 0; i < arr_length; i++) {
        numList[i].base = 1 + rand() % (UPPERBOUND - 1); // generate random base between 1 and 10^9
        numList[i].exp =  1 + rand() % (UPPERBOUND - 1); // generate random exponent between 1 and 10^9
        numList[i].lnTransform = numList[i].exp * log(numList[i].base); // log base e -> ln()
        printf("%d %d \n", numList[i].base, numList[i].exp);
    } 
    printf("\n");

    idx = rand() % arr_length + 1; // generate random index to query 
    qsort(numList, arr_length, sizeof(bexp), compare); // sort list of large numbers

    for (int i = 0; i < arr_length; i++) { // print sorted list
        printf("%d %d \n", numList[i].base, numList[i].exp);
    }
    printf("\n");

    // report kth smallest index (where k = idx)
    printf("The Kth smallest number in this list (where K = %d) is: %d^(%d) \n", idx, numList[idx-1].base, numList[idx-1].exp);

    return 0;
}

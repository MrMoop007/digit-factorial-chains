#include <stdio.h>
#include <stdbool.h>

bool checkDuplicates(int *arr, int n) {
    int i;
    int j;
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j])
                return true;
        }
    }
    return false;
}

int factorial(int n){
    int i;
    int total = 1;
    for(i = 0; i < n; i++){
        total *= n-i;
    }
    return total;
}

int sum_of_factorials(int n){
    int sum = 0;
    int i;
    while(n){
        sum += factorial(n%10);
        n /= 10;
    }
    return sum;
}

bool factorial_chain(int num){
    int terms[60];
    terms[0] = num;
    int in_array = 0;
    int i;
    int j = 0;
    for(i = 1; i < 60; i++){
        terms[i] = sum_of_factorials(terms[i-1]);
    }
    int n;
    n = sizeof(terms) / sizeof(terms[0]);
    if(checkDuplicates(terms, n)){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    int i;
    int total = 0;
    for(i = 0; i < 1000000; i++){
        if (factorial_chain(i)){total += factorial_chain(i);}
    }
    printf("There are %d factorial digit chains with a starting number below 1000000 that contain exactly 60 terms", total);
    return 0;
}
#include <stdio.h>

int main(void){
    // declare all of our needed variables at the beginning of the program
    // i: our looping variable to keep track of which test case we are on during our for loop later on
    // test_cases: the number of test cases to process
    // input: the number given as input for each test case
    int i, test_cases, input;

    // now, scan in the number of test cases and assign it to our previously declared variable
    scanf("%d", &test_cases);

    // have a for loop do a number of iterations equal to the given value for test_cases
    for(i = 0; i < test_cases; i++){
        // for each test case, take in a number and assign it to input
        scanf("%d", &input);

        // we can print out the first part of th output here because is it the same no matter what the input is
        printf("Shape #%d: ", i + 1);

        // now, we need to check if it is a shape Johnny likes; that is, if it has a number of sides 4 or less
        if(input <= 4){
            // if Johnny likes the shape, print out the appropriate response
            printf("Johnny's favorite!\n");
        }else{
            // if Johnny does not like the shape, print out the other response
            printf("Johnny will not be pleased with this one.\n");
        }
    }

    // and then, of course, we need to end the program.
    return 0;
}

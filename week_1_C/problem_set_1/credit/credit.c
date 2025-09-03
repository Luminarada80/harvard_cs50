#include <stdio.h>
#include <cs50.h>

long reverse_digit(long num)
{
    long rev_num = 0;
    while (num > 0)
    {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}

int numPlaces (long n) {
    if (n < 0) return numPlaces ((n == INT_MIN) ? INT_MAX: -n);
    if (n < 10) return 1;
    return 1 + numPlaces (n / 10);
}

int check_luhn_validity(long credit_card_num)
{
    long rev_credit_card_num = reverse_digit(credit_card_num);
    int len_credit_card_num = numPlaces(credit_card_num);

    // printf("Credit Card Num: %ld \n", credit_card_num);
    // printf("Number Reversed: %ld \n", rev_credit_card_num);

    // Reverse the credit card number and get each second number
    // starting with the second to last number
    int num_arr[len_credit_card_num];
    long num = credit_card_num;
    long rev_num = 0;
    int counter = 0;
    num /= 10;
    // printf("Every Other Number: ");
    while (num > 0)
    {
        rev_num = rev_num * 10 + num % 10;
        num_arr[counter] = rev_num % 10;
        // printf("%d ", num_arr[counter]);
        num /= 100; // Skip every other number
        counter++;

    }
    // printf("\n");

    // Multiply each digit by 2
    // printf("Every Other Number * 2: ");
    int doubled_num_arr[counter];
    for (int i = 0; i < counter; ++i){
        doubled_num_arr[i] = num_arr[i] * 2;
        // printf("%d ", doubled_num_arr[i]);
    }
    // printf("\n");


    // Add each number's digits to a sum
    int sum = 0;

    // printf("Add the digits: ");
    for (int i = 0; i < counter; ++i) {

        // Find the number of digits for the current number
        int num_digits = numPlaces(doubled_num_arr[i]);

        // If the number has more than 1 digit, loop through each digit of the number and add it to the sum
        // i.e. 12 -> 1 + 2
        if (num_digits > 1){

            int digit = doubled_num_arr[i];

            for (int x = 0; x < num_digits; x++) {
                int last_digit = digit % 10;
                // printf("%d ", last_digit);
                digit = digit / 10;
                sum += last_digit;
            }
        } else {
            // printf("%d ", doubled_num_arr[i]);
            sum += doubled_num_arr[i];
        }

    }
    // printf("= %d", sum);
    // printf("\n");

    // Add the sum to the digits that weren't multiplied by 2
    // Reverse the credit card number and get each second number
    // starting with the last number
    num = credit_card_num;
    rev_num = 0;
    counter = 0;

    // Start with the previous sum
    int final_sum = sum;

    // Reverse the number and get every second number
    // printf("Add digits that were not multiplied by 2, starting from the end: \n");
    // printf("%d ", sum);
    while (num > 0)
    {
        rev_num = rev_num * 10 + num % 10;
        final_sum += rev_num % 10;
        // printf("%ld ", rev_num % 10);
        num /= 100; // Skip every other number


        counter++;

    }
    // printf("\n");
    // printf("Final Sum = %d", final_sum);
    // printf("\n");

    // Return correct if total % 10 == 0
    int correct = 0;
    if (final_sum % 10 == 0){
        correct = 1;
    }

    return correct;
}


int main(void)
{
    long credit_card_num = get_long("Number: ");

    int correct = check_luhn_validity(credit_card_num);

    // Removes the last digit of the number until there are only 2 remaining
    long firstTwoNumbers = credit_card_num;
    while (firstTwoNumbers >= 100)
    {
        firstTwoNumbers = firstTwoNumbers / 10;
    }

    // If the number passes the luhn validity test, check if it has the company identifiers
    if (correct == 1)
    {
        // Get the length of the credit card number
        int len_credit_card_num = numPlaces(credit_card_num);
        // printf("Length = %d\n", len_credit_card_num);

        // Check if the first two number and the length are correct for the company
        if ((firstTwoNumbers == 34 || firstTwoNumbers == 37) && len_credit_card_num == 15)
        {
            printf("AMEX\n");
        }
        else if (firstTwoNumbers >= 51 && firstTwoNumbers <= 55 && len_credit_card_num == 16)
        {
            printf("MASTERCARD\n");
        }
        else if ((firstTwoNumbers >= 40 && firstTwoNumbers <= 49) && (len_credit_card_num == 13 || len_credit_card_num == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

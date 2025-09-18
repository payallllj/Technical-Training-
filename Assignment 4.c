#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// --- Program Based Task ---

// Problem 1: Write a program to print "Hello World!" using Python.
// This is a C program, so we'll do it in C.
void problem1() {
    printf("--- Problem 1: Print 'Hello World!' in C ---\n");
    printf("Hello World!\n\n");
}

// Problem 2: Use the printf() function to display multiple values on the same line.
void problem2() {
    int a = 10;
    float b = 20.5;
    char c = 'A';
    printf("--- Problem 2: Display Multiple Values ---\n");
    printf("The values are: %d, %.2f, %c\n\n", a, b, c);
}

// Problem 3: Write a program to display the result of addition, subtraction, multiplication, division, modulus, exponentiation.
// Note: C does not have a built-in exponentiation operator like **. We'll use the pow() function from math.h.
void problem3() {
    int x = 15, y = 4;
    printf("--- Problem 3: Arithmetic Operations ---\n");
    printf("x = 15, y = 4\n");
    printf("Addition: %d\n", x + y);
    printf("Subtraction: %d\n", x - y);
    printf("Multiplication: %d\n", x * y);
    printf("Division: %d\n", x / y);
    printf("Modulus: %d\n", x % y);
    // pow() returns a double, so we cast to int for display.
    printf("Exponentiation (15^4): %.0f\n\n", pow(x, y));
}

// --- Conditional Statements ---

// Problem 4: Write a program to check if a number is odd or even.
void problem4() {
    int num;
    printf("--- Problem 4: Odd or Even Check ---\n");
    printf("Enter an integer: ");
    scanf("%d", &num);
    if (num % 2 == 0) {
        printf("%d is an even number.\n\n", num);
    } else {
        printf("%d is an odd number.\n\n", num);
    }
}

// Problem 5: Use if-elif-else to categorize a number as positive, negative, or zero.
// Note: C uses 'if-else if-else'.
void problem5() {
    int num;
    printf("--- Problem 5: Positive, Negative, or Zero ---\n");
    printf("Enter an integer: ");
    scanf("%d", &num);
    if (num > 0) {
        printf("%d is a positive number.\n\n", num);
    } else if (num < 0) {
        printf("%d is a negative number.\n\n", num);
    } else {
        printf("The number is zero.\n\n");
    }
}

// --- Loops ---

// Problem 6: Print numbers from 1 to N using a for loop.
void problem6() {
    int n;
    printf("--- Problem 6: For Loop (1 to N) ---\n");
    printf("Enter a number N: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n\n");
}

// Problem 7: Print square of numbers from 0 to N-1.
void problem7() {
    int n;
    printf("--- Problem 7: Square of Numbers (0 to N-1) ---\n");
    printf("Enter a number N: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Square of %d is %d\n", i, i * i);
    }
    printf("\n");
}

// Problem 8: Use a while loop to find the sum of a number.
// NOTE: Assuming "sum of a number" means sum of its digits.
void problem8() {
    int num, original_num, sum = 0;
    printf("--- Problem 8: Sum of Digits using While Loop ---\n");
    printf("Enter a number: ");
    scanf("%d", &num);
    original_num = num;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    printf("The sum of digits of %d is %d\n\n", original_num, sum);
}

// --- Functions ---

// Problem 9: Write a function to return the factorial of a number.
long long factorial(int n) {
    if (n < 0) return -1; // Error case for negative numbers
    if (n == 0) return 1;
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

void problem9() {
    int num;
    printf("--- Problem 9: Factorial Function ---\n");
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);
    long long fact = factorial(num);
    if (fact == -1) {
        printf("Factorial is not defined for negative numbers.\n\n");
    } else {
        printf("Factorial of %d is %lld\n\n", num, fact);
    }
}

// Problem 10: Write a function to check if a number is prime.
int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void problem10() {
    int num;
    printf("--- Problem 10: Prime Number Check Function ---\n");
    printf("Enter a number: ");
    scanf("%d", &num);
    if (is_prime(num)) {
        printf("%d is a prime number.\n\n", num);
    } else {
        printf("%d is not a prime number.\n\n", num);
    }
}

// Problem 11: Write a function to return the Fibonacci sequence up to N terms.
void fibonacci_sequence(int n) {
    long long t1 = 0, t2 = 1, nextTerm;
    printf("--- Problem 11: Fibonacci Sequence ---\n");
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Please enter a positive integer.\n\n");
        return;
    }
    
    printf("Fibonacci Series: ");
    for (int i = 1; i <= n; ++i) {
        printf("%lld, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n\n");
}

// --- Data Structures (Lists, Tuples, Dictionaries, Sets) ---
// Note: C does not have built-in List, Tuple, Dictionary, or Set types like Python. We will simulate these using arrays and structs.

// Problem 12: Use list comprehensions to generate a list of squares of even numbers.
// We'll use a standard C array loop.
void problem12() {
    int arr[50];
    int count = 0;
    printf("--- Problem 12: Squares of Even Numbers (Simulated List Comp) ---\n");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            arr[count++] = i * i;
        }
    }
    printf("Squares of even numbers from 1 to 10: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

// Problem 13: Create a tuple with different data types.
// We'll use a struct to simulate a tuple.
void problem13() {
    struct MyTuple {
        int i;
        float f;
        char c;
    };
    struct MyTuple t = {10, 3.14, 'G'};
    printf("--- Problem 13: Simulated Tuple with a Struct ---\n");
    printf("Integer: %d, Float: %.2f, Character: %c\n\n", t.i, t.f, t.c);
}

// Problem 14: Use list comprehensions to generate a list of squares of up to N numbers.
void problem14() {
    int n;
    printf("--- Problem 14: Squares up to N (Simulated List Comp) ---\n");
    printf("Enter a number N: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * (i + 1);
    }
    printf("Squares up to %d: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    free(arr);
}

// Problem 15: Create a dictionary with names and ages and retrieve the age of a specific person.
// We'll simulate this using parallel arrays or a struct array.
#define MAX_PEOPLE 5
struct PersonDict {
    char name[20];
    int age;
};

void problem15() {
    struct PersonDict people[MAX_PEOPLE] = {
        {"Alice", 30}, {"Bob", 25}, {"Charlie", 35}, {"David", 40}, {"Eve", 28}
    };
    char search_name[20];
    int found = 0;
    
    printf("--- Problem 15: Simulated Dictionary ---\n");
    printf("Enter a name to find their age: ");
    scanf("%s", search_name);
    
    for (int i = 0; i < MAX_PEOPLE; i++) {
        if (strcmp(people[i].name, search_name) == 0) {
            printf("%s's age is %d.\n\n", search_name, people[i].age);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Name not found in the list.\n\n");
    }
}

// Problem 16: Use a set to remove duplicates from a list.
// We'll use a simple array and a boolean check to simulate a set's behavior.
void problem16() {
    int list[] = {1, 2, 3, 2, 4, 1, 5, 3};
    int unique_list[8];
    int unique_count = 0;
    int is_duplicate;
    
    printf("--- Problem 16: Remove Duplicates (Simulated Set) ---\n");
    printf("Original list: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
    
    for (int i = 0; i < 8; i++) {
        is_duplicate = 0;
        for (int j = 0; j < unique_count; j++) {
            if (list[i] == unique_list[j]) {
                is_duplicate = 1;
                break;
            }
        }
        if (!is_duplicate) {
            unique_list[unique_count++] = list[i];
        }
    }
    
    printf("List without duplicates: ");
    for (int i = 0; i < unique_count; i++) {
        printf("%d ", unique_list[i]);
    }
    printf("\n\n");
}

// Problem 17: Use a dictionary to count word frequencies and perform dictionary operations.
// We'll simulate this with a struct array.
void problem17() {
    struct WordFreq {
        char word[50];
        int count;
    } freq_list[50];
    
    char sentence[] = "hello world hello C programming";
    char *token;
    int word_count = 0;
    int found;
    
    printf("--- Problem 17: Simulated Word Frequency Dictionary ---\n");
    printf("Sentence: \"%s\"\n", sentence);
    
    token = strtok(sentence, " ");
    while (token != NULL) {
        found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(freq_list[i].word, token) == 0) {
                freq_list[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(freq_list[word_count].word, token);
            freq_list[word_count].count = 1;
            word_count++;
        }
        token = strtok(NULL, " ");
    }
    
    printf("Word frequencies:\n");
    for (int i = 0; i < word_count; i++) {
        printf("'%s': %d\n", freq_list[i].word, freq_list[i].count);
    }
    printf("\n");
}

// --- Strings ---

// Problem 18: Write a program to count vowels in a string.
void problem18() {
    char str[100];
    int vowels = 0;
    printf("--- Problem 18: Count Vowels in a String ---\n");
    printf("Enter a string: ");
    scanf(" %[^\n]s", str);
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowels++;
        }
    }
    printf("Number of vowels: %d\n\n", vowels);
}

// Problem 19: Write a program to reverse a string.
void problem19() {
    char str[100];
    printf("--- Problem 19: Reverse a String ---\n");
    printf("Enter a string: ");
    scanf(" %[^\n]s", str);
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    printf("Reversed string: %s\n\n", str);
}

// Problem 20: Check if a string is a palindrome.
void problem20() {
    char str[100];
    printf("--- Problem 20: Palindrome Check ---\n");
    printf("Enter a string: ");
    scanf(" %[^\n]s", str);
    int len = strlen(str);
    int is_palindrome = 1;
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - 1 - i])) {
            is_palindrome = 0;
            break;
        }
    }
    if (is_palindrome) {
        printf("The string is a palindrome.\n\n");
    } else {
        printf("The string is not a palindrome.\n\n");
    }
}

// --- Main Function for Menu ---
int main() {
    int choice;
    do {
        printf("Select a problem to run (1-20, 0 to exit):\n");
        printf("1. Print 'Hello World!'\n");
        printf("2. Display Multiple Values\n");
        printf("3. Arithmetic Operations\n");
        printf("4. Odd or Even Check\n");
        printf("5. Positive, Negative, or Zero\n");
        printf("6. For Loop (1 to N)\n");
        printf("7. Squares of Numbers\n");
        printf("8. Sum of Digits\n");
        printf("9. Factorial Function\n");
        printf("10. Prime Number Check\n");
        printf("11. Fibonacci Sequence\n");
        printf("12. Squares of Even Numbers\n");
        printf("13. Simulated Tuple\n");
        printf("14. Squares up to N\n");
        printf("15. Simulated Dictionary\n");
        printf("16. Remove Duplicates\n");
        printf("17. Word Frequencies\n");
        printf("18. Count Vowels\n");
        printf("19. Reverse a String\n");
        printf("20. Palindrome Check\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Clear input buffer to prevent issues with string input in later problems
        while (getchar() != '\n');

        switch (choice) {
            case 1: problem1(); break;
            case 2: problem2(); break;
            case 3: problem3(); break;
            case 4: problem4(); break;
            case 5: problem5(); break;
            case 6: problem6(); break;
            case 7: problem7(); break;
            case 8: problem8(); break;
            case 9: problem9(); break;
            case 10: problem10(); break;
            case 11: problem11(); break;
            case 12: problem12(); break;
            case 13: problem13(); break;
            case 14: problem14(); break;
            case 15: problem15(); break;
            case 16: problem16(); break;
            case 17: problem17(); break;
            case 18: problem18(); break;
            case 19: problem19(); break;
            case 20: problem20(); break;
            case 0: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

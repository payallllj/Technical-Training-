#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

// --- Helper Functions ---

// Structure to hold data and its original index for stability checks (Tasks 7 & 8)
typedef struct {
    int value;
    int original_index;
    char name[10]; // For Task 7/8 demonstration: e.g., 'S1', 'S2', 'S3'
} Element;

// Function to print an array of integers
void print_array(const char *title, const int *arr, int n) {
    printf("%s: [", title);
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : ", ");
    }
    printf("]\n");
}

// Function to print an array of Element structs
void print_element_array(const char *title, const Element *arr, int n) {
    printf("%s: [", title);
    for (int i = 0; i < n; i++) {
        printf("(%d,%s)%s", arr[i].value, arr[i].name, (i == n - 1) ? "" : ", ");
    }
    printf("]\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// --- TASK 1: Linear Search with Count ---

/**
 * Task 1: Linear Search with Count
 * Finds all positions of a number in an array and counts the number of times it was found.
 */
int linear_search_count(const int arr[], int n, int key, int positions[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            positions[count++] = i;
        }
    }
    return count;
}

void task_1_linear_search_demo() {
    printf("\n--- Task 1: Linear Search with Count ---\n");
    int arr[] = {10, 2, 5, 10, 8, 10, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    int positions[n];
    
    print_array("Array", arr, n);
    int count = linear_search_count(arr, n, key, positions);

    printf("Key %d found %d times at positions: ", key, count);
    for (int i = 0; i < count; i++) {
        printf("%d%s", positions[i], (i == count - 1) ? "" : ", ");
    }
    printf("\n");
}

// --- TASK 2: Binary Search (Iterative) ---

/**
 * Task 2: Binary Search (Iterative)
 * Searches for a key in a sorted array and counts comparisons.
 */
int binary_search_iterative(const int arr[], int n, int key, int *comparisons) {
    int low = 0;
    int high = n - 1;
    *comparisons = 0;

    while (low <= high) {
        (*comparisons)++; // Comparison for the while loop condition
        int mid = low + (high - low) / 2;
        
        (*comparisons)++; // Comparison for arr[mid] == key
        if (arr[mid] == key) {
            return mid; // Found
        } else if (arr[mid] < key) {
            (*comparisons)++; // Comparison for arr[mid] < key
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Not found
}

void task_2_binary_search_demo() {
    printf("\n--- Task 2: Binary Search (Iterative) ---\n");
    int arr[] = {2, 5, 8, 10, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 15;
    int comparisons;

    print_array("Sorted Array", arr, n);
    int index = binary_search_iterative(arr, n, key, &comparisons);

    if (index != -1) {
        printf("Key %d found at index %d.\n", key, index);
    } else {
        printf("Key %d not found.\n", key);
    }
    printf("Total comparisons: %d\n", comparisons);
}

// --- TASK 3: Jump Search vs Linear Search ---

/**
 * Task 3: Jump Search Implementation
 * Searches for a key in a sorted array by jumping blocks.
 */
int jump_search(const int arr[], int n, int key, int *comparisons) {
    int step = sqrt(n);
    int prev = 0;
    *comparisons = 0;

    while (arr[fmin(step, n) - 1] < key) {
        (*comparisons)++;
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    // Linear search in the block
    while (arr[prev] < key) {
        (*comparisons)++;
        prev++;
        if (prev == fmin(step, n))
            return -1;
    }

    (*comparisons)++;
    if (arr[prev] == key)
        return prev;

    return -1;
}

void task_3_jump_search_demo() {
    printf("\n--- Task 3: Jump Search vs Linear Search ---\n");
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 55;
    int comparisons_jump, comparisons_linear = 0;

    print_array("Sorted Array", arr, n);

    // Jump Search
    int index_jump = jump_search(arr, n, key, &comparisons_jump);
    printf("Jump Search: Key %d found at index %d. Comparisons: %d\n", key, index_jump, comparisons_jump);

    // Linear Search (Reusing Task 1 logic for comparison)
    int positions[n]; // dummy array
    for(int i=0; i<n; i++) {
        comparisons_linear++;
        if(arr[i] == key) break;
    }
    printf("Linear Search: Key %d found (index not tracked here). Comparisons: %d\n", key, comparisons_linear);
    printf("Conclusion: Jump Search (Comp: %d) is typically faster than Linear Search (Comp: %d) for large, sorted arrays.\n", comparisons_jump, comparisons_linear);
}

// --- TASK 4: Interpolation Search vs Binary Search ---

/**
 * Task 4: Interpolation Search Implementation
 * Searches for a key in a uniformly sorted array.
 */
int interpolation_search(const int arr[], int n, int key, int *comparisons) {
    int low = 0;
    int high = n - 1;
    *comparisons = 0;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        (*comparisons)++; // Comparison for while loop condition

        // Position calculation
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]));

        (*comparisons)++; // Comparison for arr[pos] == key
        if (arr[pos] == key) {
            return pos;
        } else if (arr[pos] < key) {
            (*comparisons)++; // Comparison for arr[pos] < key
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}

void task_4_interpolation_search_demo() {
    printf("\n--- Task 4: Interpolation Search vs Binary Search ---\n");
    // Array with uniform distribution for best Interpolation performance
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 90;
    int comparisons_inter, comparisons_bin;

    print_array("Uniformly Sorted Array", arr, n);

    // Interpolation Search
    int index_inter = interpolation_search(arr, n, key, &comparisons_inter);
    printf("Interpolation Search: Key %d found at index %d. Comparisons: %d\n", key, index_inter, comparisons_inter);

    // Binary Search
    int index_bin = binary_search_iterative(arr, n, key, &comparisons_bin);
    printf("Binary Search: Key %d found at index %d. Comparisons: %d\n", key, index_bin, comparisons_bin);
    printf("Conclusion: For uniformly distributed data, Interpolation Search (Comp: %d) is typically faster than Binary Search (Comp: %d).\n", comparisons_inter, comparisons_bin);
}

// --- TASK 5: Exponential Search ---

/**
 * Task 5: Exponential Search Implementation
 * Finds the range where the key might be present, then uses binary search.
 */
int binary_search_exp(const int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int exponential_search(const int arr[], int n, int key) {
    if (n == 0) return -1;
    if (arr[0] == key) return 0;

    int i = 1;
    while (i < n && arr[i] <= key) {
        i = i * 2;
    }

    // Call binary search for the found range
    // Range is from i/2 to min(i, n-1)
    return binary_search_exp(arr, i / 2, fmin(i, n - 1), key);
}

void task_5_exponential_search_demo() {
    printf("\n--- Task 5: Exponential Search ---\n");
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 14;

    print_array("Sorted Array", arr, n);
    int index = exponential_search(arr, n, key);

    if (index != -1) {
        printf("Key %d found at index %d.\n", key, index);
    } else {
        printf("Key %d not found.\n", key);
    }
}

// --- TASK 6: Bubble Sort (Iterative) with Optimization and Passes Count ---

/**
 * Task 6: Bubble Sort (Iterative) with Optimization
 * Sorts an array and counts passes/iterations. Optimized to stop early.
 */
void bubble_sort_iterative(int arr[], int n, int *passes) {
    *passes = 0;
    for (int i = 0; i < n - 1; i++) {
        (*passes)++; // Count of passes
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }
        // Optimization: If no two elements were swapped in inner loop, array is sorted.
        if (swapped == 0) {
            break;
        }
    }
}

void task_6_bubble_sort_demo() {
    printf("\n--- Task 6: Bubble Sort (Iterative) with Optimization ---\n");
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int passes;

    print_array("Original Array", arr, n);
    bubble_sort_iterative(arr, n, &passes);
    print_array("Sorted Array", arr, n);
    printf("Total passes/iterations: %d\n", passes);
}

// --- TASK 7: Selection Sort Stability Check ---

// Helper function to swap Element structs
void swap_elements(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Task 7: Selection Sort Implementation (using Element struct for stability check)
 * Selection sort is generally UNSTABLE.
 */
void selection_sort_stability(Element arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].value < arr[min_idx].value) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the current element
        swap_elements(&arr[min_idx], &arr[i]);
    }
}

void task_7_selection_sort_demo() {
    printf("\n--- Task 7: Selection Sort Stability Check ---\n");
    // Example for instability: Two elements with same value (10_S1, 10_S2). 
    // If original order (10_S1, 10_S2) changes to (10_S2, 10_S1), it's unstable.
    Element arr[] = {
        {10, 0, "S1"}, 
        {5, 1, "S3"}, 
        {10, 2, "S2"}, 
        {2, 3, "S4"}
    };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    print_element_array("Original Array (Value,ID)", arr, n);
    selection_sort_stability(arr, n);
    print_element_array("Sorted Array (Value,ID)", arr, n);

    printf("Analysis: In the sorted array, the order of elements with equal values (e.g., 10_S1 and 10_S2) may change.\n");
    printf("Selection sort is generally considered UNSTABLE because it swaps non-adjacent elements.\n");
}

// --- TASK 8: Insertion Sort Stability Check ---

/**
 * Task 8: Insertion Sort Implementation (using Element struct for stability check)
 * Insertion sort is generally STABLE.
 */
void insertion_sort_stability(Element arr[], int n) {
    for (int i = 1; i < n; i++) {
        Element key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than 'key', 
        // to one position ahead of their current position.
        // NOTE: We use arr[j].value > key.value, NOT >=. This ensures stability.
        while (j >= 0 && arr[j].value > key.value) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void task_8_insertion_sort_demo() {
    printf("\n--- Task 8: Insertion Sort Stability Check ---\n");
    // Example for stability: Two elements with same value (10_S1, 10_S2). 
    // Original order (10_S1, 10_S2) should be preserved after sorting.
    Element arr[] = {
        {10, 0, "S1"}, 
        {5, 1, "S3"}, 
        {10, 2, "S2"}, 
        {2, 3, "S4"}
    };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    print_element_array("Original Array (Value,ID)", arr, n);
    insertion_sort_stability(arr, n);
    print_element_array("Sorted Array (Value,ID)", arr, n);

    printf("Analysis: The sorted array maintains the original relative order of equal elements (10_S1 before 10_S2).\n");
    printf("Insertion sort is STABLE.\n");
}

// --- TASK 9: Merge Sort (Divide and Conquer) ---

void merge_task9(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[] and R[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort_task9(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Print message for divide and conquer principle
        printf("Divide: Subarray [%d] to [%d] is split into [%d] to [%d] and [%d] to [%d]\n", l, r, l, m, m + 1, r);

        merge_sort_task9(arr, l, m);
        merge_sort_task9(arr, m + 1, r);

        merge_task9(arr, l, m, r);
        printf("Conquer: Merged subarray [%d] to [%d]. Current state: ", l, r);
        for(int i=l; i<=r; i++) printf("%d ", arr[i]);
        printf("\n");
    }
}

void task_9_merge_sort_demo() {
    printf("\n--- Task 9: Merge Sort (Divide and Conquer) ---\n");
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    print_array("Original Array", arr, n);
    merge_sort_task9(arr, 0, n - 1);
    print_array("Final Sorted Array", arr, n);
}

// --- TASK 10: Quick Sort (Divide and Conquer) ---

int partition_task10(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot as the last element
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort_task10(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_task10(arr, low, high);
        
        // Print message for divide and conquer principle
        printf("Divide: Pivot %d placed at index %d. Array partitioned into: ", arr[pi], pi);
        for(int i=low; i<=high; i++) printf("%d ", arr[i]);
        printf("\n");

        quick_sort_task10(arr, low, pi - 1);
        quick_sort_task10(arr, pi + 1, high);
        
        if (low == 0 && high == (sizeof(arr)/sizeof(arr[0]))-1) { // Simple way to approximate final step
            printf("Conquer: All subarrays merged (implicit in recursive calls).\n");
        }
    }
}

void task_10_quick_sort_demo() {
    printf("\n--- Task 10: Quick Sort (Divide and Conquer) ---\n");
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    print_array("Original Array", arr, n);
    quick_sort_task10(arr, 0, n - 1);
    print_array("Final Sorted Array", arr, n);
}

// --- TASK 11: Fixed-Size Stack - Function Call Simulation ---

#define MAX_STACK_SIZE 5
int call_stack[MAX_STACK_SIZE];
int stack_top = -1;

void push_frame(int return_address) {
    if (stack_top >= MAX_STACK_SIZE - 1) {
        printf("STACK OVERFLOW: Cannot push return address %d. Stack size exceeded.\n", return_address);
        return;
    }
    call_stack[++stack_top] = return_address;
    printf("Push: Function called. Pushed return address %d. Top: %d\n", return_address, stack_top);
}

int pop_frame() {
    if (stack_top < 0) {
        printf("STACK UNDERFLOW: No more function frames to pop.\n");
        return -1; // Sentinel value
    }
    int return_address = call_stack[stack_top--];
    printf("Pop: Function returned. Popped return address %d. Top: %d\n", return_address, stack_top);
    return return_address;
}

// Simulated functions
void funcC(int ra) { push_frame(ra); printf("Inside funcC\n"); pop_frame(); }
void funcB(int ra) { push_frame(ra); printf("Inside funcB\n"); funcC(300); pop_frame(); }
void funcA(int ra) { push_frame(ra); printf("Inside funcA\n"); funcB(200); pop_frame(); }

void task_11_fixed_stack_simulation() {
    printf("\n--- Task 11: Fixed-Size Stack - Function Call Simulation ---\n");
    printf("Simulating function calls (return addresses are 100, 200, 300, etc.)\n");
    funcA(100);
}

// --- TASK 12: Dynamic Stack - Browser History Tracker (Linked List) ---

typedef struct HistoryNode {
    char url[100];
    struct HistoryNode *next;
} HistoryNode;

HistoryNode *history_top = NULL;

void push_url(const char *url) {
    HistoryNode *new_node = (HistoryNode *)malloc(sizeof(HistoryNode));
    if (!new_node) {
        printf("Memory allocation failed for new node.\n");
        return;
    }
    strcpy(new_node->url, url);
    new_node->next = history_top;
    history_top = new_node;
    printf("BROWSER: Visited '%s'.\n", url);
}

void pop_url() {
    if (!history_top) {
        printf("BROWSER: History is empty. Cannot go 'Back'.\n");
        return;
    }
    HistoryNode *temp = history_top;
    history_top = history_top->next;
    printf("BROWSER: Going 'Back' from '%s' to '%s'.\n", temp->url, history_top ? history_top->url : "Start Page");
    free(temp);
}

void peek_current_url() {
    if (history_top) {
        printf("BROWSER: Current Page: '%s'.\n", history_top->url);
    } else {
        printf("BROWSER: Currently on Start Page (History Empty).\n");
    }
}

void task_12_dynamic_stack_browser() {
    printf("\n--- Task 12: Dynamic Stack - Browser History Tracker (Linked List) ---\n");
    push_url("google.com");
    push_url("search.com/query");
    push_url("coer.university");
    peek_current_url();
    pop_url();
    peek_current_url();
    pop_url();
    pop_url();
    pop_url(); // Should result in underflow message

    // Clean up remaining nodes (optional but good practice)
    while (history_top) {
        HistoryNode *temp = history_top;
        history_top = history_top->next;
        free(temp);
    }
}

// --- TASK 13: Circular Buffer Stack (Memory-Efficient) ---

#define CIRCULAR_MAX_SIZE 5
int circular_buffer[CIRCULAR_MAX_SIZE];
int circular_top = -1;
int circular_count = 0; // Tracks actual number of elements

void circular_push(int item) {
    if (circular_count < CIRCULAR_MAX_SIZE) {
        circular_top = (circular_top + 1) % CIRCULAR_MAX_SIZE;
        circular_buffer[circular_top] = item;
        circular_count++;
        printf("CIRCULAR STACK: Pushed %d. Count: %d\n", item, circular_count);
    } else {
        // Overwrite the oldest item (FIFO behavior for stack implementation)
        // For a true stack, this is stack overflow, but if we treat it as
        // a memory-efficient circular buffer that reuses space:
        circular_top = (circular_top + 1) % CIRCULAR_MAX_SIZE;
        circular_buffer[circular_top] = item;
        printf("CIRCULAR STACK (OVERWRITE): Pushed %d. Buffer is full and oldest item was overwritten. Count: %d\n", item, circular_count);
    }
}

int circular_pop() {
    if (circular_count == 0) {
        printf("CIRCULAR STACK: UNDERFLOW. \n");
        return -1;
    }
    int item = circular_buffer[circular_top];
    circular_top = (circular_top - 1 + CIRCULAR_MAX_SIZE) % CIRCULAR_MAX_SIZE;
    circular_count--;
    return item;
}

void task_13_circular_stack_memory_efficient() {
    printf("\n--- Task 13: Circular Buffer Stack (Memor

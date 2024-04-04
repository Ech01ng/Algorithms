#include <stdio.h>
#include <stdlib.h>

//Struct definitions
struct LineCode {
    int numeric;
};

struct BatchCode {
    int numeric;
};

struct BatchDateTime {
    int dayOfMonth;
    int hourOfDay;
    int minuteOfHour;
};

struct ProductId {
    int numeric;
};

struct Issue {
    int code;
    char description[100];
};

struct Resolution {
    int code;
    char description[100];
};

struct ReportingEmployee {
    int id;
};

//Struct to hold all the data for a product line
typedef struct product_line {
    struct LineCode lineCode;
    struct BatchCode batchCode;
    struct BatchDateTime batchDateTime;
    struct ProductId productId;
    struct Issue issue;
    struct Resolution resolution;
    struct ReportingEmployee reportingEmployee;
} product_line;

//Function prototypes
void insert_test_data(struct product_line line_array[]);
void merge_sort(struct product_line line_array[], int left, int right);
void merge(struct product_line line_array[], int left, int middle, int right);
void report_on_productID(product_line* line_array, int lines, int log_size);
int compare_lines(product_line* line1, product_line* line2);
void print_all(product_line line_array[], int left, int right);
void search_issue_code(product_line* line_array);
void list_issue_codes(product_line* line_array);
void count_issues_for_all_products(product_line* line_array, int array_size);

int main() {
    //Array of product_line structs
    struct product_line line_array[44];

    //Insert test data into the array
    insert_test_data(line_array);

    //Sort the array using merge sort
    printf("\n---TASK 1) Report based on product ID---\n");
    report_on_productID(line_array, 1, 11);
    
    //Sort the array using merge sort
    printf("\n---TASK 2) Issues Report---\n");
    print_all(line_array, 0, 43);

    //Search for a specific issue code in the array
    printf("\n---TASK 3) Search for Issue Code---\n\n");
    search_issue_code(line_array);

    //List all the issue codes, the product ID related and their descriptions
    printf("\n---TASK 4) List Issue Codes---\n");
    list_issue_codes(line_array);
    count_issues_for_all_products(line_array, 44);

    return 0;
}

// ---------- Task 1 Start ----------

/*
Function to print the merged array
Big O Notation: O(n log n)
The merge sort algorithm has a time complexity of O(n log n) for the average and worst case scenarios
*/
void report_on_productID(product_line* line_array, int lines, int log_size) {
    
    //Merge and Sort the array
    merge_sort(line_array, 0, 4 * log_size - 1);
    

    //Print the logs for the first line
    printf("\n---Logs for Line 1---\n");
    for (int i = 0; i < log_size; i++) {
        //Create a temporary instance of the product_line struct for ease of printing
        product_line log = line_array[i];
        printf("Product ID: %d, Issue Code: %d, Date: %02d-%02d-%02d\n", log.productId, log.issue.code,
            log.batchDateTime.dayOfMonth, log.batchDateTime.hourOfDay, log.batchDateTime.minuteOfHour);
    }

    //Print the logs for the second line
    printf("\n---Logs for Line 2---\n");
    for (int i = log_size; i < 2 * log_size; i++) {
        //Create a temporary instance of the product_line struct for ease of printing
        product_line log = line_array[i];
        printf("Product ID: %d, Issue Code: %d, Date: %02d-%02d-%02d\n", log.productId, log.issue.code,
            log.batchDateTime.dayOfMonth, log.batchDateTime.hourOfDay, log.batchDateTime.minuteOfHour);
    }

    //Print the logs for the third line
    printf("\n---Logs for Line 3---\n");
    for (int i = 2 * log_size; i < 3 * log_size; i++) {
        //Create a temporary instance of the product_line struct for ease of printing
        product_line log = line_array[i];
        printf("Product ID: %d, Issue Code: %d, Date: %02d-%02d-%02d\n", log.productId, log.issue.code,
            log.batchDateTime.dayOfMonth, log.batchDateTime.hourOfDay, log.batchDateTime.minuteOfHour);
    }

    //Print the logs for the fourth line
    printf("\n---Logs for Line 4---\n");
    for (int i = 3 * log_size; i < 4 * log_size; i++) {
        //Create a temporary instance of the product_line struct for ease of printing
        product_line log = line_array[i];
        printf("Product ID: %d, Issue Code: %d, Date: %02d-%02d-%02d\n", log.productId, log.issue.code,
            log.batchDateTime.dayOfMonth, log.batchDateTime.hourOfDay, log.batchDateTime.minuteOfHour);
    }
}

//Function to merge two sub-arrays of line_array[]
void merge(product_line line_array[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    //Create temporary arrays
    struct product_line L[n1], R[n2];

    //Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        L[i] = line_array[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = line_array[middle + 1 + j];
    }

    //Merge the temporary arrays back into line_array[]
    i = 0;
    j = 0;
    k = left;
    //Sort using the compare_lines function
    while (i < n1 && j < n2) {
        if (compare_lines(&L[i], &R[j]) <= 0) {
            line_array[k] = L[i];
            i++;
        } else {
            line_array[k] = R[j];
            j++;
        }
        k++;
    }

    //Copy the remaining elements of L[], if there are any
    while (i < n1) {
        line_array[k] = L[i];
        i++;
        k++;
    }

    //Copy the remaining elements of R[], if there are any
    while (j < n2) {
        line_array[k] = R[j];
        j++;
        k++;
    }
}

//Function to merge sort the array of product_line structs
void merge_sort(product_line line_array[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        //Sort the first and second halves
        merge_sort(line_array, left, middle);
        merge_sort(line_array, middle + 1, right);

        //Merge the sorted halves
        merge(line_array, left, middle, right);
    }
}

/* 
Function to compare two product_line structs
By comparing the product ID, issue code, and date
*/
int compare_lines(product_line* line1, product_line* line2)
{
    //Compare by line code, if they're not equal, return the difference
    if (line1->lineCode.numeric != line2->lineCode.numeric) return line1->lineCode.numeric - line2->lineCode.numeric;

    //If line is equal, compare by product ID, and return the difference
	if (line1->productId.numeric != line2->productId.numeric) return line1->productId.numeric - line2->productId.numeric;

	//If product ID is equal, compare by issue code and return the difference
	if (line1->issue.code != line2->issue.code) return line1->issue.code - line2->issue.code;

	//If issue code and product id are also equal, compare by date and return the difference
	if (line1->batchDateTime.dayOfMonth != line2->batchDateTime.dayOfMonth) return line1->batchDateTime.dayOfMonth - line2->batchDateTime.dayOfMonth;

	//Both entries are completely equal, return 0
	return 0; 
}

// ---------- Task 1 End ----------


// ---------- Task 2 Start ----------

/*
Single list to report issue codes by product Id and line Id for all lines
Function to print all lines
Big O Notation: O(n)
We are iterating through the array once to print all the lines
*/
void print_all(product_line line_array[], int left, int right) {
    for (int i = left; i <= right; i++) {
        printf("Product ID: %d, Line Code: %d, Issue Code: %d\n", line_array[i].productId.numeric, line_array[i].lineCode.numeric, line_array[i].issue.code);
    }
}

// ---------- Task 2 End ----------


// ---------- Task 3 Start ----------

/*
Function to search for a specific issue code in the array
Big O Notation: O(n)
We are iterating through the array once to count the number of occurrences of the issue code
*/
void search_issue_code(product_line* line_array) {
    //Variable to store the number of occurrences of the issue code
    int issue_code, occurrences = 0;

    // Ask the user for the issue code
    printf("Enter the issue code: ");
    scanf("%d", &issue_code);

    //Iterate through the array and count the number of occurrences of the issue code
    for (int i = 0; i < 44; i++) {
        if (line_array[i].issue.code == issue_code) {
            occurrences++;
        }
    }

    //Print the number of occurrences of the issue code
    printf("\n---Issue Code %d Occurrences---\n", issue_code);
    printf("Number of Occurrences: %d\n", occurrences);
    if (occurrences == 0) {
        printf("No occurrences of issue code %d found.\n", issue_code);
    }
}

// ---------- Task 3 End ----------

// ---------- Task 4 Start ----------

/*
Function to list all the issue codes, the product ID related and their descriptions
Big O Notation: O(n)
We are iterating through the array once to print the issue codes, product IDs, and descriptions
*/
void list_issue_codes(product_line* line_array) {
    //Iterate through the array and print the issue codes, product IDs, and descriptions
    printf("\n---Issue Codes List---\n");
    for (int i = 0; i < 44; i++) {
        printf("Issue Code: %d, Product ID: %d, Description: %s\n", line_array[i].issue.code, line_array[i].productId.numeric, line_array[i].issue.description);
    }
}

/*
Function to count the number of issues for each product
Big O Notation: O(n)
We are iterating through the array once to count the number of issues for each product    
*/
void count_issues_for_all_products(product_line* line_array, int array_size) {
    int max_product_id = 0;
    
    //Find the maximum product ID in the array
    for(int i = 0; i < array_size; i++) {
        //If the current product ID is greater than the max product ID, update the max product ID
        if(line_array[i].productId.numeric > max_product_id) {
            //Update the max product ID
            max_product_id = line_array[i].productId.numeric;
        }
    }

    //Create an array to store the number of issues for each product
    int *issue_counts = (int*)calloc(max_product_id + 1, sizeof(int));

    //Iterate through the array and count the number of issues for each product
    for(int i = 0; i < array_size; i++) {
        //Increment the issue count for the product ID
        issue_counts[line_array[i].productId.numeric]++;
    }

    printf("\n---Issue Counts for All Products---\n");

    //Print the number of issues for each product
    for(int i = 0; i <= max_product_id; i++) {
        //If the issue count is greater than 0, print the product ID and the issue count
        if(issue_counts[i] > 0) {
            printf("Product ID: %d, Issue Count: %d\n", i, issue_counts[i]);
        }
    }

    //Free the memory allocated for the issue_counts array
    free(issue_counts);
}

// ---------- Task 4 End ----------

// ---------- Testing Data Start ----------

//This is not a part of the main code, but is used to test the functionality of the program
void insert_test_data(struct product_line line_array[]) 
{
	//Line 1 Test Data
	line_array[0] = (struct product_line){.lineCode = 1, .batchCode = 101, .batchDateTime = {15, 10, 30}, .productId = 105, .issue = {404, "Leakage detected"}, .resolution = {200, "Leak sealed"}, .reportingEmployee = 501};
    line_array[1] = (struct product_line){.lineCode = 1, .batchCode = 102, .batchDateTime = {16, 11, 45}, .productId = 107, .issue = {402, "Incorrect labeling"}, .resolution = {201, "Labels corrected"}, .reportingEmployee = 502};
    line_array[2] = (struct product_line){.lineCode = 1, .batchCode = 103, .batchDateTime = {17, 9, 15}, .productId = 104, .issue = {401, "Temperature deviation"}, .resolution = {202, "Temperature stabilized"}, .reportingEmployee = 503};//Done the Same for testing
    line_array[3] = (struct product_line){.lineCode = 1, .batchCode = 104, .batchDateTime = {18, 14, 0}, .productId = 103, .issue = {401, "Temperature deviation"}, .resolution = {202, "Temperature stabilized"}, .reportingEmployee = 504};//Done the Same for testing
    line_array[4] = (struct product_line){.lineCode = 1, .batchCode = 105, .batchDateTime = {19, 12, 30}, .productId = 105, .issue = {405, "Equipment failure"}, .resolution = {204, "Equipment repaired"}, .reportingEmployee = 505};
    line_array[5] = (struct product_line){.lineCode = 1, .batchCode = 106, .batchDateTime = {20, 13, 45}, .productId = 106, .issue = {406, "Software glitch"}, .resolution = {205, "Software updated"}, .reportingEmployee = 506};
    line_array[6] = (struct product_line){.lineCode = 1, .batchCode = 107, .batchDateTime = {21, 15, 0}, .productId = 107, .issue = {407, "Human error"}, .resolution = {206, "Error corrected"}, .reportingEmployee = 507};
    line_array[7] = (struct product_line){.lineCode = 1, .batchCode = 108, .batchDateTime = {22, 14, 30}, .productId = 108, .issue = {408, "Missing component"}, .resolution = {207, "Component added"}, .reportingEmployee = 508};
    line_array[8] = (struct product_line){.lineCode = 1, .batchCode = 109, .batchDateTime = {23, 15, 45}, .productId = 109, .issue = {409, "Cracked vial"}, .resolution = {208, "Vial replaced"}, .reportingEmployee = 509};
    line_array[9] = (struct product_line){.lineCode = 1, .batchCode = 110, .batchDateTime = {24, 16, 0}, .productId = 110, .issue = {410, "Improper seal"}, .resolution = {209, "Seal reapplied"}, .reportingEmployee = 510};
    line_array[10] = (struct product_line){.lineCode = 1, .batchCode = 111, .batchDateTime = {25, 14, 30}, .productId = 118, .issue = {411, "Incorrect dosage"}, .resolution = {210, "Dosage corrected"}, .reportingEmployee = 511};

    //Line 2 Test Data
    line_array[11] = (struct product_line){.lineCode = 2, .batchCode = 201, .batchDateTime = {12, 8, 30}, .productId = 201, .issue = {408, "Missing component"}, .resolution = {206, "Component added"}, .reportingEmployee = 507};
    line_array[12] = (struct product_line){.lineCode = 2, .batchCode = 202, .batchDateTime = {13, 12, 45}, .productId = 202, .issue = {410, "Improper seal"}, .resolution = {207, "Seal reapplied"}, .reportingEmployee = 508};
    //Even though it's prod ID is part of line 2, it is manufactured in line 1 hence it's grouped in line 1 for testing
    line_array[13] = (struct product_line){.lineCode = 1, .batchCode = 203, .batchDateTime = {14, 10, 15}, .productId = 203, .issue = {409, "Cracked vial"}, .resolution = {208, "Vial replaced"}, .reportingEmployee = 509};
    line_array[14] = (struct product_line){.lineCode = 2, .batchCode = 204, .batchDateTime = {15, 16, 0}, .productId = 207, .issue = {414, "Documentation error"}, .resolution = {209, "Documentation corrected"}, .reportingEmployee = 510};
    line_array[15] = (struct product_line){.lineCode = 2, .batchCode = 205, .batchDateTime = {16, 14, 30}, .productId = 205, .issue = {412, "Labeling missing"}, .resolution = {210, "Labeling completed"}, .reportingEmployee = 511};
    line_array[16] = (struct product_line){.lineCode = 2, .batchCode = 206, .batchDateTime = {17, 15, 45}, .productId = 206, .issue = {413, "Test failure"}, .resolution = {211, "Re-tested successfully"}, .reportingEmployee = 512};
    line_array[17] = (struct product_line){.lineCode = 2, .batchCode = 207, .batchDateTime = {18, 16, 0}, .productId = 207, .issue = {415, "Calibration off"}, .resolution = {212, "Calibration adjusted"}, .reportingEmployee = 513};
    line_array[18] = (struct product_line){.lineCode = 2, .batchCode = 208, .batchDateTime = {19, 14, 30}, .productId = 208, .issue = {416, "OverFill"}, .resolution = {213, "Fill level corrected"}, .reportingEmployee = 514};
    line_array[19] = (struct product_line){.lineCode = 2, .batchCode = 209, .batchDateTime = {20, 15, 45}, .productId = 203, .issue = {414, "UnderFill"}, .resolution = {214, "Fill level adjusted"}, .reportingEmployee = 515};
    line_array[20] = (struct product_line){.lineCode = 2, .batchCode = 210, .batchDateTime = {21, 16, 0}, .productId = 210, .issue = {417, "Label misprint"}, .resolution = {215, "Labels reprinted"}, .reportingEmployee = 516};
    line_array[21] = (struct product_line){.lineCode = 2, .batchCode = 211, .batchDateTime = {22, 14, 30}, .productId = 201, .issue = {419, "Incorrect ingredient"}, .resolution = {216, "Ingredient corrected"}, .reportingEmployee = 517};
    
    //Line 3 Test Data
    line_array[22] = (struct product_line){.lineCode = 3, .batchCode = 301, .batchDateTime = {20, 9, 30}, .productId = 301, .issue = {415, "Calibration off"}, .resolution = {212, "Calibration adjusted"}, .reportingEmployee = 513};
    line_array[23] = (struct product_line){.lineCode = 3, .batchCode = 302, .batchDateTime = {21, 13, 45}, .productId = 302, .issue = {416, "OverFill"}, .resolution = {213, "Fill level corrected"}, .reportingEmployee = 514};
    line_array[24] = (struct product_line){.lineCode = 3, .batchCode = 303, .batchDateTime = {22, 11, 15}, .productId = 303, .issue = {414, "UnderFill"}, .resolution = {214, "Fill level adjusted"}, .reportingEmployee = 515};
    line_array[25] = (struct product_line){.lineCode = 3, .batchCode = 304, .batchDateTime = {23, 15, 0}, .productId = 304, .issue = {417, "Label misprint"}, .resolution = {215, "Labels reprinted"}, .reportingEmployee = 516};
    line_array[26] = (struct product_line){.lineCode = 3, .batchCode = 305, .batchDateTime = {24, 10, 30}, .productId = 305, .issue = {419, "Incorrect ingredient"}, .resolution = {216, "Ingredient corrected"}, .reportingEmployee = 517};
    line_array[27] = (struct product_line){.lineCode = 3, .batchCode = 306, .batchDateTime = {25, 11, 45}, .productId = 306, .issue = {418, "Packing error"}, .resolution = {217, "Repacked"}, .reportingEmployee = 518};
    line_array[28] = (struct product_line){.lineCode = 3, .batchCode = 307, .batchDateTime = {26, 12, 0}, .productId = 307, .issue = {411, "Incorrect dosage"}, .resolution = {218, "Dosage corrected"}, .reportingEmployee = 519};
    line_array[29] = (struct product_line){.lineCode = 3, .batchCode = 308, .batchDateTime = {27, 13, 30}, .productId = 302, .issue = {419, "Incorrect ingredient"}, .resolution = {219, "Ingredient corrected"}, .reportingEmployee = 520};
    line_array[30] = (struct product_line){.lineCode = 3, .batchCode = 309, .batchDateTime = {28, 14, 45}, .productId = 309, .issue = {422, "Machine jam"}, .resolution = {220, "Jam cleared"}, .reportingEmployee = 521};
    line_array[31] = (struct product_line){.lineCode = 3, .batchCode = 310, .batchDateTime = {29, 15, 0}, .productId = 311, .issue = {423, "Package tear"}, .resolution = {221, "Package replaced"}, .reportingEmployee = 522};
    line_array[32] = (struct product_line){.lineCode = 3, .batchCode = 311, .batchDateTime = {30, 16, 30}, .productId = 311, .issue = {424, "Label error"}, .resolution = {222, "Label fixed"}, .reportingEmployee = 523};
    
    //Line 4 Test Data
    line_array[33] = (struct product_line){.lineCode = 4, .batchCode = 401, .batchDateTime = {25, 9, 30}, .productId = 401, .issue = {423, "Package tear"}, .resolution = {215, "Package replaced"}, .reportingEmployee = 513};
    line_array[34] = (struct product_line){.lineCode = 4, .batchCode = 402, .batchDateTime = {26, 14, 45}, .productId = 402, .issue = {422, "Machine jam"}, .resolution = {213, "Jam cleared"}, .reportingEmployee = 514};
    line_array[35] = (struct product_line){.lineCode = 4, .batchCode = 403, .batchDateTime = {27, 12, 15}, .productId = 403, .issue = {411, "Incorrect dosage"}, .resolution = {214, "Dosage corrected"}, .reportingEmployee = 515};
    //Even though it's prod ID is part of line 4, it is manufactured in line 2 hence it's grouped in line 2 for testing
    line_array[36] = (struct product_line){.lineCode = 2, .batchCode = 404, .batchDateTime = {28, 17, 0}, .productId = 408, .issue = {423, "Package tear"}, .resolution = {215, "Package replaced"}, .reportingEmployee = 516};
    line_array[37] = (struct product_line){.lineCode = 4, .batchCode = 405, .batchDateTime = {29, 11, 30}, .productId = 405, .issue = {424, "Label error"}, .resolution = {216, "Label fixed"}, .reportingEmployee = 517};
    line_array[38] = (struct product_line){.lineCode = 4, .batchCode = 406, .batchDateTime = {31, 10, 45}, .productId = 406, .issue = {423, "Package tear"}, .resolution = {215, "Package replaced"}, .reportingEmployee = 518};
    line_array[39] = (struct product_line){.lineCode = 4, .batchCode = 407, .batchDateTime = {1, 9, 0}, .productId = 410, .issue = {422, "Machine jam"}, .resolution = {213, "Jam cleared"}, .reportingEmployee = 519};
    line_array[40] = (struct product_line){.lineCode = 4, .batchCode = 408, .batchDateTime = {2, 8, 30}, .productId = 408, .issue = {411, "Incorrect dosage"}, .resolution = {214, "Dosage corrected"}, .reportingEmployee = 520};
    line_array[41] = (struct product_line){.lineCode = 4, .batchCode = 409, .batchDateTime = {3, 7, 45}, .productId = 409, .issue = {423, "Package tear"}, .resolution = {215, "Package replaced"}, .reportingEmployee = 521};
    line_array[42] = (struct product_line){.lineCode = 4, .batchCode = 410, .batchDateTime = {4, 6, 0}, .productId = 410, .issue = {424, "Label error"}, .resolution = {216, "Label fixed"}, .reportingEmployee = 522};
    line_array[43] = (struct product_line){.lineCode = 4, .batchCode = 411, .batchDateTime = {5, 5, 30}, .productId = 411, .issue = {423, "Package tear"}, .resolution = {215, "Package replaced"}, .reportingEmployee = 523};
}

// ---------- Testing Data End ----------
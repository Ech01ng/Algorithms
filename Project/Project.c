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
product_line* merge_sort(struct product_line line_array[], int left, int right);
void merge(struct product_line line_array[], int left, int middle, int right);
void report_on_productID(product_line* line_array, int lines, int log_size);

int main() {
    //Array of product_line structs
    struct product_line line_array[44];

    //Insert test data into the array
    insert_test_data(line_array);

    //Sort the array using merge sort
    printf("\n---TASK 1) Report based on product ID---\n");
    printf("\n---Line 1---\n");
    report_on_productID(line_array, 0, 10);
    printf("\n---Line 2---\n");
    merge_sort(line_array, 11, 21);
    printf("\n---Line 3---\n");
    merge_sort(line_array, 22, 32);
    printf("\n---Line 4---\n");
    merge_sort(line_array, 33, 43);

    /*Use this code to print the data in the array (FOR TESTING PURPOSES ONLY)
    //Print the data in the array
    for (int i = 0; i < 44; i++) {
        printf("--------------------\n");
        printf("Line %d\n", i+1);
        printf("Line Code: %d\n", line_array[i].lineCode.numeric);
        printf("Batch Code: %d\n", line_array[i].batchCode.numeric);
        printf("Batch Date and Time: %d/%d %d:%d\n", line_array[i].batchDateTime.dayOfMonth, line_array[i].batchDateTime.hourOfDay, line_array[i].batchDateTime.minuteOfHour);
        printf("Product ID: %d\n", line_array[i].productId.numeric);
        printf("Issue Code: %d\n", line_array[i].issue.code);
        printf("Issue Description: %s\n", line_array[i].issue.description);
        printf("Resolution Code: %d\n", line_array[i].resolution.code);
        printf("Resolution Description: %s\n", line_array[i].resolution.description);
        printf("Reporting Employee ID: %d\n", line_array[i].reportingEmployee.id);
        printf("--------------------\n");
        printf("\n");
    }
    */


    return 0;
}

//Function to print the merged array
void report_on_productID(product_line* line_array, int lines, int log_size) {
    for (int i = 0; i < lines; i++) 
	{
		//Sort the current line's logs by product ID using merge sort
		merge_sort(&line_array[i], 0, log_size - 1);

		//Print the sorted logs
		printf("\n---Sorted Logs for Line %d---\n", i + 1);
		
        //Create a temporary instance of the product_line struct for ease of printing
		product_line log = line_array[i];
			
		printf("Product ID: %d, Issue Code: %d, Date: %02d-%02d-%02d\n", log.productId, log.issue,
		log.batchDateTime, log.batchDateTime, log.batchDateTime);
		
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
    while (i < n1 && j < n2) {
        if (L[i].productId.numeric <= R[j].productId.numeric) {
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

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        line_array[k] = R[j];
        j++;
        k++;
    }
}

//Function to merge sort the array of product_line structs
product_line* merge_sort(product_line line_array[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        merge_sort(line_array, left, middle);
        merge_sort(line_array, middle + 1, right);

        merge(line_array, left, middle, right);
    }
    return line_array;
}

//This is not a part of the main code, but is used to test the functionality of the program
void insert_test_data(struct product_line line_array[]) 
{
	//Line 1 Test Data
	line_array[0] = (struct product_line){.lineCode = 1, .batchCode = 101, .batchDateTime = {15, 10, 30}, .productId = 101, .issue = {404, "Leakage detected"}, .resolution = {200, "Leak sealed"}, .reportingEmployee = 501};
    line_array[1] = (struct product_line){.lineCode = 1, .batchCode = 102, .batchDateTime = {16, 11, 45}, .productId = 102, .issue = {402, "Incorrect labeling"}, .resolution = {201, "Labels corrected"}, .reportingEmployee = 502};
    line_array[2] = (struct product_line){.lineCode = 1, .batchCode = 103, .batchDateTime = {17, 9, 15}, .productId = 103, .issue = {401, "Temperature deviation"}, .resolution = {202, "Temperature stabilized"}, .reportingEmployee = 503};
    line_array[3] = (struct product_line){.lineCode = 1, .batchCode = 104, .batchDateTime = {18, 14, 0}, .productId = 104, .issue = {403, "Power issue"}, .resolution = {203, "Power restored"}, .reportingEmployee = 504};
    line_array[4] = (struct product_line){.lineCode = 1, .batchCode = 105, .batchDateTime = {19, 12, 30}, .productId = 105, .issue = {405, "Equipment failure"}, .resolution = {204, "Equipment repaired"}, .reportingEmployee = 505};
    line_array[5] = (struct product_line){.lineCode = 1, .batchCode = 106, .batchDateTime = {20, 13, 45}, .productId = 106, .issue = {406, "Software glitch"}, .resolution = {205, "Software updated"}, .reportingEmployee = 506};
    line_array[6] = (struct product_line){.lineCode = 1, .batchCode = 107, .batchDateTime = {21, 15, 0}, .productId = 107, .issue = {407, "Human error"}, .resolution = {206, "Error corrected"}, .reportingEmployee = 507};
    line_array[7] = (struct product_line){.lineCode = 1, .batchCode = 108, .batchDateTime = {22, 14, 30}, .productId = 108, .issue = {408, "Missing component"}, .resolution = {207, "Component added"}, .reportingEmployee = 508};
    line_array[8] = (struct product_line){.lineCode = 1, .batchCode = 109, .batchDateTime = {23, 15, 45}, .productId = 109, .issue = {409, "Cracked vial"}, .resolution = {208, "Vial replaced"}, .reportingEmployee = 509};
    line_array[9] = (struct product_line){.lineCode = 1, .batchCode = 110, .batchDateTime = {24, 16, 0}, .productId = 110, .issue = {410, "Improper seal"}, .resolution = {209, "Seal reapplied"}, .reportingEmployee = 510};
    line_array[10] = (struct product_line){.lineCode = 1, .batchCode = 111, .batchDateTime = {25, 14, 30}, .productId = 111, .issue = {411, "Incorrect dosage"}, .resolution = {210, "Dosage corrected"}, .reportingEmployee = 511};

    //Line 2 Test Data
    line_array[11] = (struct product_line){.lineCode = 2, .batchCode = 201, .batchDateTime = {12, 8, 30}, .productId = 201, .issue = {408, "Missing component"}, .resolution = {206, "Component added"}, .reportingEmployee = 507};
    line_array[12] = (struct product_line){.lineCode = 2, .batchCode = 202, .batchDateTime = {13, 12, 45}, .productId = 202, .issue = {410, "Improper seal"}, .resolution = {207, "Seal reapplied"}, .reportingEmployee = 508};
    line_array[13] = (struct product_line){.lineCode = 2, .batchCode = 203, .batchDateTime = {14, 10, 15}, .productId = 203, .issue = {409, "Cracked vial"}, .resolution = {208, "Vial replaced"}, .reportingEmployee = 509};
    line_array[14] = (struct product_line){.lineCode = 2, .batchCode = 204, .batchDateTime = {15, 16, 0}, .productId = 204, .issue = {414, "Documentation error"}, .resolution = {209, "Documentation corrected"}, .reportingEmployee = 510};
    line_array[15] = (struct product_line){.lineCode = 2, .batchCode = 205, .batchDateTime = {16, 14, 30}, .productId = 205, .issue = {412, "Labeling missing"}, .resolution = {210, "Labeling completed"}, .reportingEmployee = 511};
    line_array[16] = (struct product_line){.lineCode = 2, .batchCode = 206, .batchDateTime = {17, 15, 45}, .productId = 206, .issue = {413, "Test failure"}, .resolution = {211, "Re-tested successfully"}, .reportingEmployee = 512};
    line_array[17] = (struct product_line){.lineCode = 2, .batchCode = 207, .batchDateTime = {18, 16, 0}, .productId = 207, .issue = {415, "Calibration off"}, .resolution = {212, "Calibration adjusted"}, .reportingEmployee = 513};
    line_array[18] = (struct product_line){.lineCode = 2, .batchCode = 208, .batchDateTime = {19, 14, 30}, .productId = 208, .issue = {416, "OverFill"}, .resolution = {213, "Fill level corrected"}, .reportingEmployee = 514};
    line_array[19] = (struct product_line){.lineCode = 2, .batchCode = 209, .batchDateTime = {20, 15, 45}, .productId = 209, .issue = {414, "UnderFill"}, .resolution = {214, "Fill level adjusted"}, .reportingEmployee = 515};
    line_array[20] = (struct product_line){.lineCode = 2, .batchCode = 210, .batchDateTime = {21, 16, 0}, .productId = 210, .issue = {417, "Label misprint"}, .resolution = {215, "Labels reprinted"}, .reportingEmployee = 516};
    line_array[21] = (struct product_line){.lineCode = 2, .batchCode = 211, .batchDateTime = {22, 14, 30}, .productId = 211, .issue = {419, "Incorrect ingredient"}, .resolution = {216, "Ingredient corrected"}, .reportingEmployee = 517};
    
    //Line 3 Test Data
    line_array[22] = (struct product_line){.lineCode = 3, .batchCode = 301, .batchDateTime = {20, 9, 30}, .productId = 301, .issue = {415, "Calibration off"}, .resolution = {212, "Calibration adjusted"}, .reportingEmployee = 513};
    line_array[23] = (struct product_line){.lineCode = 3, .batchCode = 302, .batchDateTime = {21, 13, 45}, .productId = 302, .issue = {416, "OverFill"}, .resolution = {213, "Fill level corrected"}, .reportingEmployee = 514};
    line_array[24] = (struct product_line){.lineCode = 3, .batchCode = 303, .batchDateTime = {22, 11, 15}, .productId = 303, .issue = {414, "UnderFill"}, .resolution = {214, "Fill level adjusted"}, .reportingEmployee = 515};
    line_array[25] = (struct product_line){.lineCode = 3, .batchCode = 304, .batchDateTime = {23, 15, 0}, .productId = 304, .issue = {417, "Label misprint"}, .resolution = {215, "Labels reprinted"}, .reportingEmployee = 516};
    line_array[26] = (struct product_line){.lineCode = 3, .batchCode = 305, .batchDateTime = {24, 10, 30}, .productId = 305, .issue = {419, "Incorrect ingredient"}, .resolution = {216, "Ingredient corrected"}, .reportingEmployee = 517};
    line_array[27] = (struct product_line){.lineCode = 3, .batchCode = 306, .batchDateTime = {25, 11, 45}, .productId = 306, .issue = {418, "Packing error"}, .resolution = {217, "Repacked"}, .reportingEmployee = 518};
    line_array[28] = (struct product_line){.lineCode = 3, .batchCode = 307, .batchDateTime = {26, 12, 0}, .productId = 307, .issue = {420, "Incorrect dosage"}, .resolution = {218, "Dosage corrected"}, .reportingEmployee = 519};
    line_array[29] = (struct product_line){.lineCode = 3, .batchCode = 308, .batchDateTime = {27, 13, 30}, .productId = 308, .issue = {421, "Incorrect ingredient"}, .resolution = {219, "Ingredient corrected"}, .reportingEmployee = 520};
    line_array[30] = (struct product_line){.lineCode = 3, .batchCode = 309, .batchDateTime = {28, 14, 45}, .productId = 309, .issue = {422, "Machine jam"}, .resolution = {220, "Jam cleared"}, .reportingEmployee = 521};
    line_array[31] = (struct product_line){.lineCode = 3, .batchCode = 310, .batchDateTime = {29, 15, 0}, .productId = 310, .issue = {423, "Package tear"}, .resolution = {221, "Package replaced"}, .reportingEmployee = 522};
    line_array[32] = (struct product_line){.lineCode = 3, .batchCode = 311, .batchDateTime = {30, 16, 30}, .productId = 311, .issue = {424, "Label error"}, .resolution = {222, "Label fixed"}, .reportingEmployee = 523};
    
    //Line 4 Test Data
    line_array[33] = (struct product_line){.lineCode = 4, .batchCode = 401, .batchDateTime = {25, 9, 30}, .productId = 401, .issue = {423, "Package tear"}, .resolution = {215, "Package replaced"}, .reportingEmployee = 513};
    line_array[34] = (struct product_line){.lineCode = 4, .batchCode = 402, .batchDateTime = {26, 14, 45}, .productId = 402, .issue = {422, "Machine jam"}, .resolution = {213, "Jam cleared"}, .reportingEmployee = 514};
    line_array[35] = (struct product_line){.lineCode = 4, .batchCode = 403, .batchDateTime = {27, 12, 15}, .productId = 403, .issue = {421, "Incorrect dosage"}, .resolution = {214, "Dosage corrected"}, .reportingEmployee = 515};
    line_array[36] = (struct product_line){.lineCode = 4, .batchCode = 404, .batchDateTime = {28, 17, 0}, .productId = 404, .issue = {423, "Package tear"}, .resolution = {215, "Package replaced"}, .reportingEmployee = 516};
    line_array[37] = (struct product_line){.lineCode = 4, .batchCode = 405, .batchDateTime = {29, 11, 30}, .productId = 405, .issue = {424, "Label error"}, .resolution = {216, "Label fixed"}, .reportingEmployee = 517};
    line_array[38] = (struct product_line){.lineCode = 4, .batchCode = 406, .batchDateTime = {31, 10, 45}, .productId = 406, .issue = {423, "Package tear"}, .resolution = {215, "Package replaced"}, .reportingEmployee = 518};
    line_array[39] = (struct product_line){.lineCode = 4, .batchCode = 407, .batchDateTime = {1, 9, 0}, .productId = 407, .issue = {422, "Machine jam"}, .resolution = {213, "Jam cleared"}, .reportingEmployee = 519};
    line_array[40] = (struct product_line){.lineCode = 4, .batchCode = 408, .batchDateTime = {2, 8, 30}, .productId = 408, .issue = {421, "Incorrect dosage"}, .resolution = {214, "Dosage corrected"}, .reportingEmployee = 520};
    line_array[41] = (struct product_line){.lineCode = 4, .batchCode = 409, .batchDateTime = {3, 7, 45}, .productId = 409, .issue = {423, "Package tear"}, .resolution = {215, "Package replaced"}, .reportingEmployee = 521};
    line_array[42] = (struct product_line){.lineCode = 4, .batchCode = 410, .batchDateTime = {4, 6, 0}, .productId = 410, .issue = {424, "Label error"}, .resolution = {216, "Label fixed"}, .reportingEmployee = 522};
    line_array[43] = (struct product_line){.lineCode = 4, .batchCode = 411, .batchDateTime = {5, 5, 30}, .productId = 411, .issue = {423, "Package tear"}, .resolution = {215, "Package replaced"}, .reportingEmployee = 523};
}
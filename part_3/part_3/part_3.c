#include <stdio.h>
#include <string.h>

int compare_numbers(char *a, char *b) {
  // Handle leading zeros
  int i = 0;
  while (a[i] == '0' && a[i + 1] != '\0') {
    i++;
  }
  a = a + i;

  i = 0;
  while (b[i] == '0' && b[i + 1] != '\0') {
    i++;
  }
  b = b + i;

  // Compare string lengths
  int len_a = strlen(a);
  int len_b = strlen(b);
  if (len_a < len_b) {
    return -1;
  } else if (len_a > len_b) {
    return 1;
  }

  // Compare digits one by one
  for (i = 0; i < len_a; i++) {
    int digit_diff = a[i] - b[i];
    if (digit_diff < 0) {
      return -1;
    } else if (digit_diff > 0) {
      return 1;
    }
  }

  // Numbers are equal
  return 0;
}

int read_number_from_file(char *filename, char *buffer, int max_size) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return -1; // Error opening file
  }

  int chars_read = fread(buffer, 1, max_size - 1, fp); // Read characters, leave space for null terminator
  if (chars_read < 0) {
    fclose(fp);
    return -2; // Error reading from file
  }

  buffer[chars_read] = '\0'; // Add null terminator
  fclose(fp);

  return chars_read; // Return the number of characters read (excluding null terminator)
}

int main() {
    char num1[2001]; // Adjust size based on digit count and null terminator
    char num2[2001]; // Adjust size based on digit count and null terminator
    char num3[2001]; // Adjust size based on digit count and null terminator
    
    // Read numbers from a text file (adjust filename as needed)
    int exit_code_num1 = read_number_from_file("number1.txt", num1, sizeof(num1));
    int exit_code_num2 = read_number_from_file("number2.txt", num2, sizeof(num2));
    int exit_code_num3 = read_number_from_file("number3.txt", num3, sizeof(num3));

    //printf("%s\n%s\n%s\n", num1, num2, num3);

    if (exit_code_num1 < 0) {
        printf("Error reading number 1 from file\n");
        return 1;
    }
    if (exit_code_num2 < 0) {
        printf("Error reading number 2 from file\n");
        return 1;
    }
    if (exit_code_num3 < 0) {
        printf("Error reading number 3 from file\n");
        return 1;
    }
    
    int result_compare_num1_num2 = compare_numbers(num1, num2);
    int result_compare_num2_num3 = compare_numbers(num2, num3);
    int result_compare_num3_num1 = compare_numbers(num3, num1);

    
    //printf("%d\n", result_compare_num1_num2);
    switch (result_compare_num1_num2) {
      case -1:
        // num1 < num2
        printf("%s", "The first number is less than the second number\n");
        break;
      case 1:
        // num1 > num2
        printf("%s", "The first number is greater than the second number\n");
        break;
      default:
        // num1 = num2
        printf("%s", "The first number is equal to the second number\n");
    }
    //printf("%d\n", result_compare_num2_num3);
    switch (result_compare_num2_num3) {
      case -1:
        // num2 < num3
        printf("%s", "The second number is less than the third number\n");
        break;
      case 1:
        // num2 > num3
        printf("%s", "The second number is greater than the third number\n");
        break;
      default:
        // num2 = num3
        printf("%s", "The second number is equal to the third number\n");
    }
    //printf("%d\n", result_compare_num3_num1);
    switch (result_compare_num3_num1) {
      case -1:
        // num3 < num1
        printf("%s", "The third number is less than the first number\n");
        break;
      case 1:
        // num3 > num1
        printf("%s", "The third number is greater than the first number\n");
        break;
      default:
        // num3 = num1
        printf("%s", "The third number is equal to the first number\n");
    }
    
    return 0;
    
}

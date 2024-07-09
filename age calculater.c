#include <stdio.h>
#include <time.h>

int main() {
    int birth_day, birth_month, birth_year;
    int current_day, current_month, current_year;
    
    // Input birth date
    printf("Enter your birth date (DD MM YYYY): ");
    scanf("%d %d %d", &birth_day, &birth_month, &birth_year);
    
    // Get current system date
    time_t now = time(NULL);
    struct tm *local_now = localtime(&now);
    current_day = local_now->tm_mday;
    current_month = local_now->tm_mon + 1; // tm_mon is 0-based
    current_year = local_now->tm_year + 1900; // tm_year is years since 1900
    
    // Calculate age
    int age_years = current_year - birth_year;
    int age_months = current_month - birth_month;
    int age_days = current_day - birth_day;
    
    // Adjust age if birthday hasn't occurred this year yet
    if (age_months < 0 || (age_months == 0 && age_days < 0)) {
        age_years--;
    }
    
    // Output age
    printf("Your age is: %d years\n", age_years);
    
    return 0;
}

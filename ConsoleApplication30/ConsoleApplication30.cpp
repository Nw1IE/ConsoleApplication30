#include <iostream>
#include <vector>

bool isLeapYear(int year) {
    
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int calculateDaysInMonth(int month, int year) {
   
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month - 1]; 
}

int calculateDayOfYear(int day, int month, int year) {
    int totalDays = 0;
    for (int m = 1; m < month; ++m) {
        totalDays += calculateDaysInMonth(m, year);
    }
    totalDays += day; 
    return totalDays;
}

int calculateDateDifference(int day1, int month1, int year1,
    int day2, int month2, int year2) {
    
    int totalDays1 = year1 * 365 + calculateDayOfYear(day1, month1, year1);
    int totalDays2 = year2 * 365 + calculateDayOfYear(day2, month2, year2);

   
    for (int year = std::min(year1, year2); year < std::max(year1, year2); ++year) {
        if (isLeapYear(year)) {
            totalDays1++;
            totalDays2++;
        }
    }

    return std::abs(totalDays2 - totalDays1);
}

int main() {
    setlocale(LC_ALL, "ru");
    int day1, month1, year1;
    int day2, month2, year2;

   
    std::cout << "Введите первую дату (день месяц год): ";
    std::cin >> day1 >> month1 >> year1;

    
    std::cout << "Введите вторую дату (день месяц год): ";
    std::cin >> day2 >> month2 >> year2;

    int difference = calculateDateDifference(day1, month1, year1, day2, month2, year2);
    std::cout << "Разница между датами: " << difference << " дней" << std::endl;

    return 0;
}











double calculateAverage(const int* arr, int size) {
    if (size == 0) {
        return 0.0; 
    }

    double sum = 0.0; 

    for (int i = 0; i < size; ++i) {
        sum += arr[i]; 
    }

    return sum / size; 
}

int main() {
    setlocale(LC_ALL, "ru");
    int size;

    
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Размер массива должен быть положительным." << std::endl;
        return 1; 
    }

    int* array = new int[size];

    
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }


    double average = calculateAverage(array, size);
    std::cout << "Среднее арифметическое: " << average << std::endl;

    delete[] array; 
    return 0; 






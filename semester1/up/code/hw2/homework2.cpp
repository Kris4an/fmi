//
// Домашно 2 по "Увод в програмирането"
//
// Име: Кристиан Христакиев
// ФН: 6MI0800608
// Специалност: КН2
// Курс: 1
// Административна група: 8
//

#include <iostream>

// Напишете решението си тук (можете да изтриете този коментар)

bool isLittleEndian()
{
    int a = 4;
    char *p = (char *)&a;
    return *p;
}

bool isBigEndian()
{
    return !(isLittleEndian);
}

int fastPow(int base, unsigned int power)
{
    if (power == 0)
        return 1;
    if (power == 1)
        return base;
    int result = 1;
    while (power > 1)   {
        if (power & 1)
        {
            result *= base;
        }
        base *= base;
        power = power >> 1;
    }

    return result * base;
}

void commonDigits(int a, int b)
{
    int contentVector[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    if (a < 0)
        a *= -1;
    if (b < 0)
        b *= -1;

    if (a == 0)
        contentVector[0] = 1;

    while (a > 0)
    {
        int digit = a % 10;
        if (contentVector[digit] == 0)
            contentVector[digit] = 1;
        a /= 10;
    }

    if (b == 0 && contentVector[0] == 1)
        contentVector[0] = 2;

    while (b > 0)
    {
        int digit = b % 10;
        if (contentVector[digit] == 1)
            contentVector[digit] = 2;
        b /= 10;
    }

    bool hasCommonDigits = false;
    for (int i = 0; i < 10; ++i)
    {
        if (contentVector[i] == 2)
        {
            hasCommonDigits = true;
            std::cout << i;
        }
    }

    if (!hasCommonDigits)
    {
        std::cout << "none";
    }
}

bool isSorted(int *arr, size_t size)
{
    if (size <= 1)
        return true;
    for (size_t i = 0; i < size - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

bool binarySearch(int element, int *arr, size_t size)
{
    size_t dif = size / 2;

    for (size_t i = dif; i < size && i >= 0;)
    {
        if (element == arr[i])
        {
            return true;
        }
        if (dif == 0)
        {
            return false;
        }
        if (element < arr[i])
        {
            dif /= 2;
            i /= 2;
        }
        else if (element > arr[i])
        {
            i += (dif / 2 == 0 ? 1 : dif / 2);
            dif /= 2;
        }
    }
    return false;
}

//---------------------------------------------------------------------
// Моля, не променяйте кода от тук до края на файла (под чертата)

void printCommonDigits(int a, int b)
{
    std::cout << "\n  The common digit(s) of " << a << " and " << b << " are: ";
    commonDigits(a, b);
}

int main(int argc, char *argv[])
{
    std::cout << "\n\n# Task 1";
    std::cout << "\n  isBigEndian() returns " << isBigEndian();
    std::cout << "\n  isLittleEndian() returns " << isLittleEndian();

    std::cout << "\n\n# Task 2";
    for (int i = 0; i < 15; ++i)
    {
        std::cout << "\n  3^" << i << " = " << fastPow(3, i);
    }

    std::cout << "\n\n# Task 3";
    printCommonDigits(1221253, 7542111);
    printCommonDigits(1221253, -7542111);
    printCommonDigits(12340, 90);
    printCommonDigits(101, 0);
    printCommonDigits(123, 456);
    printCommonDigits(123, 0);
    printCommonDigits(-5, -5);
    printCommonDigits(5, 5);
    printCommonDigits(0, 0);

    std::cout << "\n\n# Task 4";
    int arr1[] = {1, 2, 3, 4, 5};
    std::cout << "\n  isSorted(arr1) returns " << isSorted(arr1, 5);
    int arr2[] = {5, 4, 3, 2, 1};
    std::cout << "\n  isSorted(arr2) returns " << isSorted(arr2, 5);
    int arr3[] = {1, 1, 1, 1, 1};
    std::cout << "\n  isSorted(arr3) returns " << isSorted(arr3, 5);
    int arr4[] = {0, 1, 0, 1, 1};
    std::cout << "\n  isSorted(arr4) returns " << isSorted(arr4, 5);

    std::cout << "\n\n# Task 5";
    const size_t size = 9;
    int haystack[] = {-90, -3, 0, 1, 5, 10, 10, 1'000, 3'000};

    for (size_t i = 0; i < size; ++i)
    {
        std::cout
            << "\n  Binary search lookup for " << haystack[i] << " returns "
            << binarySearch(haystack[i], haystack, size);
    }

    std::cout << "\n  Binary search lookup for -91 returns " << binarySearch(-91, haystack, size);
    std::cout << "\n  Binary search lookup for 2 returns " << binarySearch(2, haystack, size);
    std::cout << "\n  Binary search lookup for 3000 returns " << binarySearch(3000, haystack, size);

    std::cout << "\nDone.\n\n";
}
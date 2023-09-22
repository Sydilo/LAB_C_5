#include <iostream>
#include <cmath>


bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int lowerLimit = 100;
    int upperLimit = 200;

    for (int evenNumber = lowerLimit; evenNumber <= upperLimit; evenNumber += 2) {
        bool found = false;

        for (int i = 2; i <= evenNumber / 2; i++) {
            if (isPrime(i) && isPrime(evenNumber - i)) {
                std::cout << evenNumber << " = " << i << " + " << evenNumber - i << std::endl;
                found = true;
                break; // Знайдено представлення, можна вийти з цього циклу
            }
        }

        if (!found) {
            std::cout << "Не вдалося знайти представлення для " << evenNumber << std::endl;
        }
    }

    return 0;
}

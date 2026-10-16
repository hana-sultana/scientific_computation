#include <iostream>
using namespace std;

bool isprime(int num) {
    if (num == 0 or num == 1) {
        return false;
    }
    int i = 2;
    while (i < num) {
        if (num % i == 0) {
            return false;
        }
        else {
            i++;
        }
    }

    return true;
}



class primegenerator {
public:
    int num;
    primegenerator() {
        num = 2;
    }
    int nextprime() {
        while (isprime(num) == false) {
            num++;
        }
        int prime = num;
        num++;
        return prime;
    }
};

int main() {
    int nprimes;
    cin >> nprimes;
    primegenerator sequence;
    int numberfound{0};

    while (numberfound < nprimes) {
        int number = sequence.nextprime();
        numberfound++;
	cout << "Number " << number << " is prime\n";

    }
}

/*
 * @lc app=leetcode id=1116 lang=cpp
 *
 * [1116] Print Zero Even Odd
 */
#include <functional>

using std::function;

// @lc code=start
#include <semaphore.h>

class ZeroEvenOdd {
private:
    int n;
    sem_t sem_zero, sem_odd, sem_even;

public:
    ZeroEvenOdd(int n) {
        this->n = n;

        // sem_init(sem_t *__sem, int __pshared, unsigned int __value) initializes the 
        // value of semaphore to __value. If __pshared is zero, then the semaphore 
        // cannot be shared between processes.
        sem_init(&sem_zero, 0, 1);
        sem_init(&sem_odd, 0, 0);
        sem_init(&sem_even, 0, 0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; ++i) {
            sem_wait(&sem_zero);
            printNumber(0);
            if (i & 1) {
                sem_post(&sem_odd);
            } else {
                sem_post(&sem_even);
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            sem_wait(&sem_even);
            printNumber(i);
            sem_post(&sem_zero);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            sem_wait(&sem_odd);
            printNumber(i);
            sem_post(&sem_zero);
        }
    }
};
// @lc code=end


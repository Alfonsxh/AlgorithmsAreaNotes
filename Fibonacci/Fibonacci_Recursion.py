"""
@author: Alfons
@contact: alfons_xh@163.com
@file: Fibonacci_Recursion.py
@time: 18-10-8 下午10:42
@version: v1.0 
"""
from timer import timer
import time


def FibsRecursion(n):
    if n == 0:
        return 0

    if n == 1:
        return 1
    return FibsRecursion(n - 1) + FibsRecursion(n - 2)


cache = {0: 0, 1: 1}


def FibsRecursionCache(n):
    if n in cache:
        return cache[n]

    ret = FibsRecursionCache(n - 1) + FibsRecursionCache(n - 2)
    cache[n] = ret
    return ret


if __name__ == "__main__":
    numZS = int(input('How many Fibonacci numbers do you want? '))
    startTime = time.time()
    # print(FibsRecursion(numZS))
    print(FibsRecursionCache(numZS))
    stopTime = time.time()
    print("{func} use time -> {time}'s".format(func=FibsRecursion.__name__,
                                               time=stopTime - startTime))

"""
@author: Alfons
@contact: alfons_xh@163.com
@file: Fibonacci_Matrix.py
@time: 18-10-9 下午8:51
@version: v1.0 
"""


# 使用矩阵的方式化简Fibonacci数列

def FibsMatrix(n):
    if n <= 0:
        return 0, 1

    f_m, f_m1 = FibsMatrix(int(n / 2))

    if n % 2 == 0:
        return 2 * f_m1 * f_m - f_m ** 2, f_m ** 2 + f_m1 ** 2

    return f_m ** 2 + f_m1 ** 2, f_m1 ** 2 + 2 * f_m1 * f_m


if __name__ == "__main__":
    numZS = int(input('How many Fibonacci numbers do you want? '))
    print(FibsMatrix(numZS)[0])

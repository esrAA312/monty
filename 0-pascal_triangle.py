#!/usr/bin/python3
''' Pascal's triangle.
'''


def pascal_triangle(n):
    '''Creates a list
    '''
    t_list = []
    if n <= 0:
        return t_list
    for x in range(n):
        line = []
        for j in range(x + 1):
            if j == 0 or j == x:
                line.append(1)
            elif x > 0 and j > 0:
                line.append(t_list[x - 1][j - 1] + t_list[x - 1][j])
        t_list.append(line)
    return t_list

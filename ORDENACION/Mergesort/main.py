from yogi import *

n = scan(int)
while n is not None:
    v = [read(float) for _ in range(n)]
    mergesort(v)
    for i in range(n):
        print('', f'{v[i]:.1f}', end='')
    print()
    n = scan(int)

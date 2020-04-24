import numpy as np

T = int(input())
for _ in range(T):

    n = int(input())
    a = list(map(int, input().split()))
    while(len(a)<16): a.append(0)
    
    n = int(input())
    b = list(map(int, input().split()))
    while(len(b)<16): b.append(0)
    
    c = np.fft.fft(a)*np.fft.fft(b)
    c = np.fft.ifft(c)

    for x in c: print(c, end=' ')
    print("\n")


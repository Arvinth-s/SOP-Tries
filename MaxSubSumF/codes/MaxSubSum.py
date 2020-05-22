#OM NAMO NARAYANA
import numpy as np
fname = '.././Tries/MaxSubSumF/input/input'
T = 20
Nmax = 30
for t in range(T):
    # print("testcase:",t+1)
    ifile = open(fname+str(t)+'.txt', 'w')
    numbers = []
    N = 100000
    ifile.write(str(N)+"\n")
    for n in range(N):
        number = ""
        for i in range(Nmax):
            number += str(np.random.randint(0, 10, 1)[0])
        numbers.append(number)
        ifile.write(number+"\n")
        if(n%10000==0):
            print((t)*5 + n/20000)
    ifile.close()
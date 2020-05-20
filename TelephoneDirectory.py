#OM NAMO NARAYANA
import numpy as np
T = 20
Nsize = 18
for t in range(T):
    file_name = '.././Tries/TelephoneDirectoryF/input/input'+str(t)+'.txt'
    ifile = open(file_name, 'w')
    Q = 100000
    ifile.write(str(Q)+'\n')
    nums = np.arange(2, Q+1, 1)
    np.random.shuffle(nums)
    nums = list(nums)
    n4 = 0.2
    n3 = 0.4
    n2 = 0.2
    n1 = 1 - (n2+n3+n4)
    assert(n1 < 1 and n1 > 0)
    pivot1 = int(n1*Q)
    pivot2 = int(pivot1 + n2*Q)
    pivot3 = int(pivot2 + n3*Q)
    pivot4 = int(pivot3 + n4*Q)
    id1 = [1]+nums[:pivot1]
    id2 = nums[pivot1:pivot2]
    id3 = nums[pivot2:pivot3]
    id4 = nums[pivot3:pivot4]
    id1.sort()
    id2.sort()
    id3.sort()
    id4.sort()
    count = 0
    query1 = []
    query2 = []
    query3 = []
    assert(len(id1)%10 == 0)
    for i in range(0, 10):
        dif = np.random.randint(2, 3)
        collection = np.arange(0, 10, 1)
        np.random.shuffle(collection)
        collection = list(collection)
        collection = collection[:dif]
        for j in range(int(len(id1)/10)):
            number = ""
            for k in range(Nsize):
                number = number + str(collection[np.random.randint(dif)])
            query1.append([id1[count], number])
            count+=1
    count = 0
    assert(len(id2)%10 == 0)
    for i in range(0, 10):
        dif = np.random.randint(2, 5)
        collection = np.arange(0, 10, 1)
        np.random.shuffle(collection)
        collection = list(collection)
        collection = collection[:dif]
        for j in range(int(len(id2)/10)):
            number = ""
            for k in range(Nsize):
                number = number + str(collection[np.random.randint(dif)])
            query2.append([id2[count], number])
            count+=1
    
    count = 0
    assert(len(id3)%10 == 0)
    for i in range(0, 10):
        dif = np.random.randint(2, 5)
        collection = np.arange(0, 10, 1)
        np.random.shuffle(collection)
        collection = list(collection)
        collection = collection[:dif]
        for j in range(int(len(id3)/10)):
            number = ""
            for k in range(Nsize):
                number = number + str(collection[np.random.randint(dif)])
            query3.append([id3[count], number])
            count+=1

    for i in range(int(n3*Q/2)):
        query1_idx = np.random.randint(len(query1))
        query3_idx = np.random.randint(min(len(query3), len(query1)))
        query3[query3_idx][1] = query1[query1_idx][1]
    inp = np.zeros(Q)
    for id in id1:
        inp[id-1]=1
    for id in id2:
        inp[id-1]=2
    for id in id3:
        inp[id-1]=3
    for id in id4:
        inp[id-1]=4
    q1 = 0
    q2 = 0
    q3 = 0
    for q in range(Q):
        if(inp[q]==4):
            ifile.write("4\n")
            continue
        if(inp[q]==1):
            assert(query1[q1][0]==q+1)
            query = query1[q1]
            ifile.write("1 "+str(query[1])+"\n")
            q1+=1
        elif(inp[q]==2):
            assert(query2[q2][0]==q+1)
            query = query2[q2]
            ifile.write("2 "+str(query[1])+"\n")
            q2+=1
        elif(inp[q]==3):
            assert(query3[q3][0]==q+1)
            query = query3[q3]
            ifile.write("3 "+str(query[1])+"\n")
            q3+=1
        else:
            print("error")
            exit()

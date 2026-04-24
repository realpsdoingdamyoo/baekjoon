def main():
    s = input().strip()
    n = len(s)
    
    v = []
    ans = []
    
    for i in range(n):
        if len(v) == 0 or int(s[i]) != v[-1][0]:
            v.append([int(s[i]), 1])
        else:
            v[-1][1] += 1
    
    while len(v) > 2:
        tmp = v[-1]
        n -= tmp[1]
        v.pop()
        idx = len(v) - 1
        mns = 0
        
        if v[idx-1][1] < v[idx][1]:
            mns = v[idx-1][1]
            ans.append([n - v[idx][1] - mns + 1, n - v[idx][1] + mns])
            v[idx-2][1] += v[idx][1] - mns
            v.pop()
            v.pop()
            v.append(tmp)
            n += -mns * 2 + tmp[1]
        
        elif v[idx-1][1] == v[idx][1]:
            mns = v[idx][1]
            ans.append([n - 2 * mns + 1, n])
            v.pop()
            v.pop()
            v.append(tmp)
            n += -mns * 2 + tmp[1]
        
        else:  # v[idx-1][1] > v[idx][1]
            mns = v[idx][1]
            ans.append([n - 2 * mns + 1, n])
            v.pop()
            v[idx-1][1] -= mns
            v[-1][1] += tmp[1]
            n += -mns * 2 + tmp[1]
    
    ans.append([1, n])
    
    print(len(ans))
    for interval in ans:
        print(interval[0], interval[1])

if __name__ == "__main__":
    main()

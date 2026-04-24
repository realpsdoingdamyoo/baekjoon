st = input()
st1=''
for i in st:
    if 65<=ord(i)<=96:
        st1+=chr(ord(i)+32)
    else:
        st1+=chr(ord(i)-32)
print(st1)

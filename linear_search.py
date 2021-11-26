array = []
n = int(input())
for i in range(0,n):
    x=int(input())
    array.append(x)

print(array)    #list of all elements
print("enter the number to be searched")
find = int(input())
for i in range(0,len(array)):
    if array[i] != find:
        i=i+1
    else:
        print("index of the element found:",i)    




#we perform binary search in order to reduce the time taken for execution
# assume,we have been given sorted array
def sam_binary_search(arr,target):
    n = len(arr)
    left,right = 0,n-1
    while(left<=right):
        mid = (left+right)//2
        if (arr[mid] == target):
            return mid
        elif (arr[mid] > target):
            right = mid-1
        else:
            left = mid+1
    return -1                
target = int(input())
arr = [1,2,3,4,5,6,7,8,9]
print("index of seached element is :",sam_binary_search(arr,target))

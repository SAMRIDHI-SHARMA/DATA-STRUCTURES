#sort elements using quicksort
def sam_quicksort(arr):
    length = len(arr)
    if length <= 1:
        return arr
    else:
        pivot = arr.pop()
        print(pivot)
    items_greater = []
    items_lower = []
    for item in arr:
        if item > pivot:
            items_greater.append(item)
        else:
            items_lower.append(item)
    return (sam_quicksort(items_lower)+ [pivot]+ sam_quicksort(items_greater))
#arr = [int(x) for x in input.split()]
arr = [1,9,7,5,6,3,4,9,2,3]
print(sam_quicksort(arr))                        
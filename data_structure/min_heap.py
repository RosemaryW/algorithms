from math import floor


def heapify (heap, root, size):
	if root >= size:
		return

	l = root * 2 + 1
	r = root * 2 + 2

	smallest = root

	if l < size and heap[l] < heap[smallest]:
		smallest = l
	if r < size and heap[r] < heap[smallest]:
		smallest = r

	if heap[smallest] != heap[root]:
		temp = heap[smallest]
		heap[smallest] = heap[root]
		heap[root] = temp
		heapify(heap, smallest, size)

def build_min_heap(arr, size):
	for i in reversed(range(0, floor(size / 2))): # floor(size / 2) - 1 downto 0
		heapify(arr, i, size)


if __name__ == "__main__":
	arr = [7, 2, 4, 8, 1, 2, 6, 9, 1]
	build_min_heap(arr, 9)
	print(arr)
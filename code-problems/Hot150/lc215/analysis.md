
# Quick Select

## Partition:

pick a `pivot` and rearrange the array such that all elements smaller than the pivot are on its left, and larger ones are on its right.

only recurses into the side containing the index

use a **random pivot** to avoid the worst-case

# Core Optimizations

**Three-Way Partitioning**

If the array contains many **duplicate elements** Three-way partition(<,=,>)

**The "Hole" Method**

Instead of using `std::swap` (which involves 3 assignments), we store the pivot in a temporary variable and "fill the holes" by shifting elements. This reduces the number of memory writes, improving the **constant factor** of the  complexity.

**Cache Locality & Small K**

If  is very small compared to , a **Min-Heap** of size  might actually be faster in practice because the heap can fit entirely into the **L1 Cache**, minimizing expensive DRAM access.

# Potential Questions 

 **Why is the average complexity O(n)?**
 
  It forms a geometric series: $n + n/2 + n/4 + \dots$, which converges to $2n$.

 **How to handle a massive data stream?** 

  Use a Min-Heap of size $k$. This maintains the top $k$ elements with $O(N \log k)$ time and $O(k)$ space

 **What if the array is read-only?** 
 
  Quick Select is in-place and modifies the array. If the array is read-only, we must use the Heap approach or copy the data, which increases space complexity to $O(n)$.

 **Can we go faster than ?** 

  Not for a general unsorted array, as we must inspect every element at least once. However, if the range of values is small, **Counting Sort** can achieve $O(n + \text{Range})$

# Keywords

**Pivot Selection:Random** 

**In-place:** 

**Time-Space Trade-off** 


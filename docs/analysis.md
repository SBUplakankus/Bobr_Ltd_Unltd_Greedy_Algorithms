# Analysis of Greedy Algorithms

This document provides a detailed analysis of our greedy algorithm examples, including their **time complexity**, advantages and limitations.

---

## 1. Alien Defence System
**Problem:** Select the maximum number of non-overlapping activities from a given set.  
**Greedy Strategy:** Always pick the next activity that finishes earliest.

| Aspect | Analysis |
|--------|---------|
| Time Complexity | O(n log n) (sorting aliens by ease to kill) |
| Advantages | Kills the most amount of aliens possible |
| Limitations | May not kill the closest or most dangerous aliens |

---

## 2. Knapsack Problem
**Problem:** Maximize total value in a knapsack with a weight limit, allowing fractions of items.  
**Greedy Strategy:** Pick items based on highest value-to-weight ratio first.

| Aspect | Analysis |
|--------|---------|
| Time Complexity | O(n log n) (sorting items by value/weight) |
| Advantages | Gives most value possible within the weight limit |
| Limitations | May want as many or as few items as possible instead |

---

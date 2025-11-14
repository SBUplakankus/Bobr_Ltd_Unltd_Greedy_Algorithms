# Greedy Algorithms Overview

## Introduction
In the Greedy Algorithm, the solution is built part by part.
The decision to choose the next part is done on the basis that it gives an immediate benefit
They are commonly used in games as optimisation is key which is why we chose to do it for our projects.

## Our Examples
| Problem | Description | Greedy Strategy |
|---------|-------------|----------------|
| **Alien Defence System** | Kill the maximum amount of aliens before running out of energy | Kills enemies in order of lowest energy usage |
| **Knapsack Problem** | Get the most value from a given list of items | Pick items with highest value-to-weight ratio first |
| **Fuhad Solution** | ... | ... |

## Advantages
- Simple and easy to implement.
- Often more **time-efficient** for problems with greedy choice property.
- Works well for **game optimisation** where you don't need to calculate all possibilities and increase performance.

## Limitations
- Greedy algorithms do not always give the optimal solution for every problem.
- They require **careful analysis** to ensure the greedy choice property is the most efficient.

## When to Use
- Problems with **optimal substructure** and **greedy choice property**.
- When a **fast and approximate solution** is acceptable, even if not guaranteed to be optimal.

---

This repository provides explanations, code implementations, and visual examples of greedy algorithms in C++


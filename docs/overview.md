# :rocket: Greedy Algorithms Overview

## :book: Introduction
In the Greedy Algorithm, the solution is built part by part.  
The decision to choose the next part is done on the basis that it gives an **immediate benefit**.  
They are commonly used in games as optimisation is key — which is why we chose to feature them in our project.

## :jigsaw: Our Examples
| :video_game: Problem | :page_facing_up: Description | :zap: Greedy Strategy |
|----------------------|------------------------------|------------------------|
| **Alien Defence System** | Kill the maximum amount of aliens before running out of energy | Kills enemies in order of lowest energy usage |
| **Knapsack Problem** | Get the most value from a given list of items | Pick items with highest value-to-weight ratio first |
| **Fuhad Solution** | ... | ... |

## :white_check_mark: Advantages
- Simple and easy to implement.
- Often more **time-efficient** for problems with greedy choice property.
- Works well for **game optimisation** where you don't need to evaluate all possibilities.

## :warning: Limitations
- Greedy algorithms do **not always** return the optimal solution.
- They require **careful analysis** to confirm the greedy choice is correct for the problem.

## :brain: When to Use
- Problems with **optimal substructure** and **greedy choice property**.
- When a **fast, approximate solution** is acceptable.

---

This repository provides explanations, code implementations, and visual examples of greedy algorithms in **C++**.

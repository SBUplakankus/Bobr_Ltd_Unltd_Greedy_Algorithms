# :rocket: Greedy Algorithms Overview

## :book: Introduction
In the Greedy Algorithm, the solution is built part by part.  
The decision to choose the next part is done on the basis that it gives an **immediate benefit**.  
They are commonly used in games as optimisation is key — which is why we chose to feature them in our project.
Greedy algorithms allow to effectively solve a certain range of optimization tasks. However, their application requires careful analysis of the task and structure of the processed data, as a greedy approach does not always guarantee an optimal solution. 



## :jigsaw: Our Examples
| :video_game: Problem | :page_facing_up: Description | :zap: Greedy Strategy |
|----------------------|------------------------------|------------------------|
| **Alien Defence System** | Kill the maximum amount of aliens before running out of energy | Kills enemies in order of lowest energy usage |
| **Knapsack Problem** | Get the most value from a given list of items | Pick items with highest value-to-weight ratio first |
| **Fuhad Solution** | ... | ... |

## :interrobang: How to detect Greedy Algorithm
-Local optimality - at every step the algorithm makes a choice that seems best, most cost-effective at the moment (and may be retroactively incorrect).
-Irreversibility - the choice made in each step is not changed. The algorithm does not return to change its previous decision.
-Incremental solution - the algorithm builds a solution step by step, adding new elements to an already built partial solution.

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



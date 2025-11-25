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
 - **Local optimality** - at every step the algorithm makes a choice that seems best, most cost-effective at the moment (and may be            retroactively incorrect).

 - **Irreversibility** - the choice made in each step is not changed. The algorithm does not return to change its previous decision.
 - **Incremental solution** - the algorithm builds a solution step by step, adding new elements to an already built partial solution.

## :white_check_mark: Advantages
- Simple and easy to implement. Generally simple to understand and program, because their logic is based on making the most profitable decisions at each stage.
- Often more **time-efficient** for problems with greedy choice property. Usually have low computational complexity, often linear or logarithmic, making them suitable for tasks requiring quick solutions.
- Works well for **game optimisation** where you don't need to evaluate all possibilities.
- **Small memory requirements.** because greedy algorithms make solutions based on the current state, they do not require storing a large amount of intermediate data this saves memory.

## :warning: Limitations
- Greedy algorithms do **not always** return the optimal solution.
- Problems for which it is necessary to evaluate the consequences of actions cannot be solved by a greedy algorithm effectively.
- They require **careful analysis** to confirm the greedy choice is correct for the problem.
- **Lack of flexibility.** Greedy algorithms follow a fixed strategy of choice, not allowing for changes or improvements in the solutions during execution. They do not adapt to changing conditions or new data.

## :brain: When to Use
- Problems with **optimal substructure** and **greedy choice property**.
- When a **fast, approximate solution** is acceptable.
## :video_game: In game examples
- **Europa Universals 4** In Europa Universalis 4 AI, if he finds out that he can demolish the enemy army, the bot will do that in most situations. According to this knowledge, we can assume that AI in EU4 has a greedy algorithm if a small stack army is detected next to his army. One more proof that it is a greedy algorithm is that even if a big enemy stack of army is in range to go into this battle, AI will start the attack anyway.
- **Grand Thief Auto San Andreas** In GTA San Andreas AI planes which are flying around have a system of vectors. One of the situations happened when all vectors warned about a collision. The plane makes a 180-degree turn and reaches 500 metres. According to this information, we can assume that planes, when detecting a collision, make changes immediately without thinking about the future. As well as planes checking for collision every 2 seconds and making a new point to reach, without thinking where the next point will be. As well, spawning planes is a greedy algorithm because the first route for flying depends on the way the player is looking, so technically planes are flying blindly for the first two seconds before the first check.

This repository provides explanations, code implementations, and visual examples of greedy algorithms in **C++**.














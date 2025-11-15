# Greedy Algorithm Designs

This document explains the design and reasoning behind the greedy strategies used in the project.  
Each example includes a brief explanation and accompanying diagrams and images.

---

## 1. Alien Defence System
**Explanation:**  
The goal of the alien defence system example is to showcase how the greedy algorithm could be used in a game related setting. 
Being inspired by the sentry scene in Aliens, the defence system has a given amount of energy it can use to kill as many aliens as possible.
This is a common design you would see in defence or resource oriented games where you can deploy sentry guns to help you fight off hordes of enemies.

**The Problem:** 
Aliens are swarming your defences. You must try take out as many of them as possible before running out of power.

**The Greedy Choice**
To maximise efficiency, the defence system is being told to kill aliens in order of the least amount of energy required to kill them.
This is calculated based off of the aliens distance to the sentry gun and health. 
If a sentry can't kill the final alien at full health, it will damage it as much as possible before powering down.

**Why This Choice Works**
Picking off enemies in order of how easy it is to kill them allows the turret to kill as many as possible before powering down.

**Defence System Diagram:**  
![Aliens Before Diagram](imgs/Aliens_Diagram_Before)

---

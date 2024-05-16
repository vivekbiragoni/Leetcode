# Submission Notes for Climbing Stairs Problem

## Overview
This document outlines the solution for the "Climbing Stairs" problem, focusing on the dynamic programming approach. The problem involves finding the number of distinct ways to climb a staircase with `n` steps, where each step can be climbed either one or two steps at a time.

## Problem Statement
Given a staircase with `n` steps, determine the number of distinct ways to climb to the top, where you can take either 1 or 2 steps at a time.

## Approach
The problem can be solved using dynamic programming, which optimizes the recursive solution by storing intermediate results to avoid redundant calculations.

### Recursive Solution
Initially, we considered a naive recursive approach, which directly implements the mathematical definition of the problem. However, this approach is inefficient due to repeated calculations of the same subproblems.

### Dynamic Programming Solution
To address the inefficiency of the recursive approach, we implemented a dynamic programming solution. The key idea is to use an auxiliary array (`dp`) to store the number of ways to climb each step up to `n`. Before computing the number of ways to climb `n` steps, we check if this value has already been calculated and stored in `dp`. If so, we return the stored value; otherwise, we compute it by summing the number of ways to climb `n-1` and `n-2` steps.



1-->The 8-Puzzle Problem is a sliding puzzle on a 3×3 grid with 8 tiles and one empty space. The goal is to reach the target configuration by sliding tiles.
This project solves it using two AI techniques:
- Best-First Search (Manhattan Distance): Selects the move with the smallest total distance of tiles from their goal positions.
- Hill Climbing (Misplaced Tile): Moves to the neighbor with fewer misplaced tiles until no better move exists.
Best-First Search guarantees a solution but takes more time (O(bᵈ)).
Hill Climbing is faster but can get stuck in local minima (O(bᵈ)).
2-->A Magic Square is an n × n grid where each row, column, and diagonal adds up to the same sum.
The program generates odd-order squares using the Siamese method and doubly even-order squares using a position flip technique.
Time Complexity: O(n²), since each cell is filled exactly once.
3-->Tic Tac Toe is a two-player strategy game played on a 3×3 grid.
One player uses X and the other uses O. Players take turns placing their marks in empty squares.
The computer makes random moves while checking winning conditions using rule-based logic.
Time Complexity: O(1), since the board has a fixed 3×3 size.
4-->The Water Jug Problem is a classic AI puzzle. You are given two jugs with different capacities (for example, 4 liters and 3 liters) and an unlimited supply of water.
The goal is to measure exactly X liters of water using only these jugs by filling, emptying, or pouring between them.
The program uses simulation logic with a GCD check to verify if the goal is achievable.
Time Complexity: O(x + y), where x and y are the jug capacities.

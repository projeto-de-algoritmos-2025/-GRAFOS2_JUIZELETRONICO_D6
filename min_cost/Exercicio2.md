
-----

# 1584. Min Cost to Connect All Points

**Dificuldade:** Média

-----

## Descrição do Problema

You are given an array `points` representing integer coordinates of some points on a 2D-plane, where `points[i] = [xi, yi]`.

The cost of connecting two points `[xi, yi]` and `[xj, yj]` is the manhattan distance between them: $|xi - xj| + |yi - yj|$, where $|val|$ denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

------

## Exemplos

### Exemplo 1:

**Input:** `points = [[0,0],[2,2],[3,10],[5,2],[7,0]]`  
**Output:** 20  
**Explanation:**

![Image of connected points for example 1](https://assets.leetcode.com/uploads/2020/08/26/d.png)  
We can connect the points as shown above to get the minimum cost of 20.  
Notice that there is a unique path between every pair of points.

### Exemplo 2:

**Input:** `points = [[3,12],[-2,5],[-4,1]]`  
**Output:** 18

------

## Restrições:

* `1 <= points.length <= 1000`
* $-10^6 \le x_i, y_i \le 10^6$
* All pairs $(x_i, y_i)$ are distinct.
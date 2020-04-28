## Dijkstra's Shortest Path Assignment 

For this project you are to write a C++ program that takes the input of a maze in a directed graph form and output the length and the shortest path of the maze. You can use the algorithm shown below from "Shortest Path Algorithms" powerpoint lecture to solve this problem. 

```c++
q.enqueue(v_start)

while (!q.isEmpty()) {

    v = q.dequeue();

    for each w adjacent to v {

        if (w is unknown){

            w.cost = v.cost + 1

            w.known = true

            w.parent = v

            q.enqueue(w);

        }

    }

}
```

The complexity of this algorithm is O(V+E), where V is the number of vertices and E is the number of edges. The output is a set of vertices from the beginning of the maze to the end and it must be the shortest path.

**Input:**

I'm providing a visual maze, so you can figure out what the output should be, but your program will take the text input file. The input file has the following format. Each line is a vertex. The first number is a vertex number, any number that following are vertices that this one connects too. It is possible that a vertex doesn't connect to any other vertex. The value  -1 marks the end of a vertex

**Example**

1 2 3 -1 // so v1 connects to v2 and v3
2 -1 // doesn't connect to any other vertex.


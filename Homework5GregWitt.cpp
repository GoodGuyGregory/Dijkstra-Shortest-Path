#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Vertex
{
public:
    bool known;
    int id;
    int parent;
    vector<int> neighbors;
    int pathCost;

    // Defaiult Const
    Vertex(int valueNum)
    {
        id = valueNum;
        known = false;
        vector<int> neighbors;
        parent = 0;
        pathCost = 1;
    }
};

void printPath(vector<Vertex> elements)
{
    for (int i = 0; i < elements.size(); i++)
    {
        cout << elements[i].id << " -> ";
    }
    cout << "END ";
}

void shortestPath()
{
    // dijkstra's Shortest Algorithm
    // q.enqueue(v_start)

    //     while (!q.isEmpty())
    // {

    //     v = q.dequeue();

    // for
    //     each w adjacent to v
    //     {

    //         if (w is unknown)
    //         {

    //             w.cost = v.cost + 1

    //                               w.known = true

    //                                         w.parent = v

    //                                                        q.enqueue(w);
    //         }
    //     }
    // }
}

int main()
{
    // Test Filestream inputs
    fstream mazefile;
    // Open the file

    mazefile.open("test-maze.txt", std::ios::in);

    if (!mazefile)
    {
        cout << "Unable to Open file." << endl;
        exit(1);
    }
    else if (mazefile.is_open())
    {
        cout << "Sucessfully Found Maze file:" << endl;
        cout << "=============================" << endl;
        string line;

        // Vector Holder
        vector<Vertex> PathElements;

        while (getline(mazefile, line))
        {
            // cout << line << endl;
            stringstream readLine(line);

            // pipe the value
            int NodeValue;
            readLine >> NodeValue;

            cout << "Creating Node Value... " << NodeValue << endl;

            Vertex Edge(NodeValue);

            while (getline(readLine, line))
            {
                int neighborValue;
                cout << "Checking For Neighbors... " << endl;

                neighborValue = stoi(line);

                cout << "Found Neighbor " << neighborValue << endl;

                (string) line;
                stringstream neighborHood(line);

                neighborHood >> line;
                // cout << line << endl;
                while (neighborHood >> line)
                {
                    cout << "Checking for additional neighbors" << endl;
                    // cout << line << endl;
                    int end = stoi(line);

                    if (end == -1)
                    {
                        cout << "Nothing was found.. DEAD END.... " << endl;
                        break;
                    }
                    Edge.neighbors.push_back(end);
                }
                cout << "Current Vertex:" << endl;
                // Path Collection for Elements in the Path
                PathElements.push_back(Edge);
            }
        }
        printPath(PathElements);
    }
}

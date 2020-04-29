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

    Vertex(int valueNum)
    {
        id = valueNum;
        known = false;
        vector<int> neighbors;
        parent = 0;
        pathCost = 1;
    }
};

//  This will Print the Maze as it is Currently not solved
void printPath(vector<Vertex> elements)
{
    cout << "===========================" << endl;
    for (int i = 0; i < elements.size(); i++)
    {
        // Starting at End of Path
        cout << (elements[i].parent + 1) << " -> ";
    }
    cout << "END " << endl;
    cout << "===========================" << endl;
}

void printPathSolved(vector<Vertex> elements)
{
    //  Runs the Path in reverse.
    for (int i = 99; i >= 0; i = elements.at(i).parent - 1)
    {
        // Starting at End of Path
        cout << (elements[i].id) << " -> ";
    }
    cout << "END ";
}

void printShortestPathValue(vector<Vertex> pathElements)
{
    cout << "===========================" << endl;
    cout << "Calculated Shortest Path: " << pathElements.back().pathCost << endl;
    cout << "===========================" << endl;
}

vector<Vertex> shortestPath(vector<Vertex> pathElements)
{
    // dijkstra's Shortest Algorithm
    // cout << firstElement.id << endl;
    queue<Vertex> holder;
    holder.push(pathElements[0]);

    while (!holder.empty())
    {
        Vertex v = holder.front();
        holder.pop();

        for (int i = 0; i < v.neighbors.size(); i++)
        {

            if (pathElements.at(v.neighbors[i]).known == false)
            {
                pathElements.at(v.neighbors[i]).pathCost = v.pathCost + 1;
                // cout << "Print Parent attributes :" << endl;
                // cout << w.parent << endl;
                // cout << v.id << endl;
                pathElements.at(v.neighbors[i]).parent = v.id;
                pathElements.at(v.neighbors[i]).known = true;
                holder.push(pathElements.at(v.neighbors[i]));
            }
        }
    }
    return pathElements;
}

int main()
{
    // Vector Holder
    vector<Vertex> PathElements;
    // Test Filestream inputs
    fstream mazefile;
    // Open the file

    mazefile.open("maze.txt", std::ios::in);

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

        while (getline(mazefile, line))
        {
            // cout << line << endl;
            stringstream readLine(line);

            // pipe the value
            int NodeValue;
            // Stores into
            readLine >> NodeValue;

            cout << "Creating Node Value... " << NodeValue << endl;

            Vertex Edge(NodeValue);

            while (readLine >> NodeValue)
            {

                cout << "Looking for Path Neighbors" << endl;
                if (NodeValue != -1)
                {
                    cout << "Adding Path Options" << endl;
                    Edge.neighbors.push_back(NodeValue - 1);
                }
                else
                {
                    cout << "Nothing was found.. DEAD END.... " << endl;
                    break;
                }
            }

            // cout << "Current Vertex:" << endl;
            // Path Collection for Elements in the Path

            PathElements.push_back(Edge);

            //  TEST
            // id Node Check:
            // for (int i = 0; i < PathElements.size(); i++)
            // {
            //     cout << PathElements.at(i).id << endl;
            // }
        }
    }

    PathElements = shortestPath(PathElements);
    cout << "Completed Path: " << endl;
    printPath(PathElements);

    printShortestPathValue(PathElements);
    // id Node Check:
    // for (int i = 0; i < PathElements.size(); i++)
    // {
    //     cout << PathElements.at(i).id << " " << PathElements.at(i).parent << endl;
    // }
    cout << "Shortest Path: " << endl;
    cout << "===========================" << endl;
    printPathSolved(PathElements);
}

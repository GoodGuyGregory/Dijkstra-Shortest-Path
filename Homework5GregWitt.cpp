#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Vertex
{
public:
    bool known;
    int vNum;
    int parent;
    vector<int> neighbors;
    int pathCost;

    // Defaiult Const
    Vertex(int vNum)
    {
        vNum = vNum;
        known = false;
        parent = 0;
    }
};

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

        while (getline(mazefile, line))
        {

            cout << line << endl;
            stringstream readLine(line);

            // pipe the value
            int NodeValue;
            readLine >> NodeValue;

            cout << "Creating Node Value... " << NodeValue << endl;

            Vertex Edges(NodeValue);
            while (getline(readLine, line))
            {

                int neighborValue;
                neighborValue = stoi(line);
                cout << "Checking For Neighbors... " << endl;
                if (neighborValue != -1)
                {
                    cout << "Found Neighbor " << neighborValue << endl;
                    (string) line;
                    stringstream neighborHood(line);
                    while (getline(neighborHood, line))
                    {
                        cout << "Reading Again: " << endl;
                        while (getline(readLine, line))
                        {
                            cout << "Checking for additional neighbors" << endl;
                            int endOfLine;
                            endOfLine = stoi(line);
                            if (endOfLine == -1)
                            {
                                cout << "Nothing was found.. DEAD END.... " << endl;
                            }
                        }
                    }
                }
                else
                {
                    cout << "None Found" << endl;
                    break;
                }
            }
        }
    }
}
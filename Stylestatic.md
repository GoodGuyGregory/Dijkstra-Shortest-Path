```c++
   int neighborValue;
                // cout << "Checking For Neighbors... " << endl;

                // neighborValue = stoi(line);

                (string) line;
                stringstream neighborHood(line);

                neighborHood >> neighborValue;

                // cout << line << endl;
                while (neighborHood >> neighborValue)
                {

                    cout << line << endl;
                    int end = stoi(line);

                    if (end != -1)
                    {

                        cout << "Added " << line << endl;
                        Edge.neighbors.push_back(end);
                    }
                    else
                    {
                        cout << "Nothing was found.. DEAD END.... " << endl;
                        break;
                    }
                }
```
/*Computing a vector values that represent distances between two distances. Find the smallest and greatest values. Further, find the mean
distance among the values.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <double> distances;
double dist = 0;                // Variable for keeping the distances and the total sum of distances.

int main()
{
    cout << "\nEnter a distance: ";
    
    while (cin >> dist)
    {
        distances.push_back(dist);
        cout << "Enter a distance: ";
    }
    
    sort(distances.begin(),distances.end());
    for (int i = 0; i <= distances.size(); ++i)
        dist += distances[i];

    cout << "\n\nThe smallest value is: " << distances[0];
    cout << "\nThe greatest value is: " << distances[distances.size() - 1];
    cout << "\nThe total distance is: " << dist;
    cout << "\nThe mean of distances is:" << dist / distances.size() << "\n\n";
}
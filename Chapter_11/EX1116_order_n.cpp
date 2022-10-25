/*Program that reads a file of white-separated numbers and output them in order
, one value per line. It writes the count of the number occurrences on its line.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#include "runtime_errors.h"

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    try
    {
        cout << "\n\n\tReads a file of white-separated numbers and output them in"
             << " order. It writes the count of the number occurrences.\n\t";

        // Opening the input and ouput files.
        ifstream ifs{"mydata_order_n_1116"};
        if(!ifs) error("\n\n\tCan't open the input file.\n\t");
        
        vector<int> nums;               // Collects the numbers.
        vector<int> occurrences;        // Counts the occurrences of each number.

        int n, index;
        while(ifs>>n)
        {
            index = find(nums.begin(),nums.end(),n) - nums.begin();
            if(index == nums.size())        // n was not found.
            {
                nums.push_back(n);
                occurrences.push_back(1);
            }
            else
                ++occurrences[index];
        }

        vector<int> aux = nums;
        vector<int> aux2 = occurrences;

        cout << "\n\tNumbers\tOccurrences\n\n\t";
        sort(nums.begin(),nums.end());
        for(int i=0; i < nums.size(); ++i)
        {
           index = find(aux.begin(),aux.end(),nums[i]) - aux.begin();
           occurrences[i] = aux2[index];
           cout << nums[i] << '\t' << occurrences[i] << "\n\t";
        }

        return 0;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        cerr << "\n\n\tSomething is wrong.\n\t";
        return 1;
    }
}

//------------------------------------------------------------------------------

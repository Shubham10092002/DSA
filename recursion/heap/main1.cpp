#include <iostream>
using namespace std;
class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        size = 0;
    }

    void insert(int value)
    {
        size = size + 1;
        int index = size;
        arr[index] = value;

        // insert the value at correct position
        while (index > 1)
        {
            int parentindex = index / 2;
            if (arr[index] > arr[parentindex])
            {
                swap(arr[index], arr[parentindex]);
                index = parentindex;
            }
            else
            {
                break;
            }
        }
    }
};


int main()
{

    return 0;
}
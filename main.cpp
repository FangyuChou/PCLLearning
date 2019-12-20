#include <iostream>
#include <vector>

using namespace std;


vector<int> deleteEvenNum(vector<int> ivVec)
{
    vector<int> ivOddVec;

    if(ivVec.empty())
    {
        cerr << "数组大小为０" << endl;
    }
    else
    {
        for (size_t i=0; i<ivVec.size(); i++)
        {
            if (ivVec[i] % 2 != 0)
            {
                ivOddVec.push_back(ivVec[i]);
            }
        }

    }

    return ivOddVec;
}

int main (int argc, char** argv)
{
    vector<int> ivTest;
    for (size_t i=0; i<10; i++)
    {
        ivTest[i] = i;
    }

    cout << "vector before deleting even number:" << endl;
    for (size_t i=0; i<ivTest.size(); i++)
    {
        cout << "vector: " << ivTest[i] << " " << endl;
    }

    vector<int> ivTest_after_delete = deleteEvenNum(ivTest);

    cout << "vector after deleting even number:" << endl;
    for (size_t i=0; i<ivTest_after_delete.size(); i++)
    {
        cout << "vector: " << ivTest_after_delete[i] << " " << endl;
    }

    return 0;
}
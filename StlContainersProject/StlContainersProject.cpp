#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

class User
{
    string name;
    int age;
public:
    User() : name{ "" }, age{ 0 } {}
    User(string name, int age) 
        : name{ name }, age{ age } {}
    string& Name() { return name; }
    int& Age() { return age; }

    friend ostream& operator<<(ostream& out, const User& user)
    {
        out << "Name: " << user.name << ", age: " << user.age;
        return out;
    }
};

template <class Iterator>
void ContainerIntInit(Iterator itBegin, Iterator itEnd)
{
    for (itBegin; itBegin != itEnd; itBegin++)
        *itBegin = rand() % 100;
}

template <class Iterator>
void ContainerPrint(Iterator itBegin, Iterator itEnd)
{
    for (itBegin; itBegin != itEnd; itBegin++)
        cout << *itBegin << " ";
    cout << "\n";
}

template <class Iterator>
void ContainerPrintEol(Iterator itBegin, Iterator itEnd)
{
    for (itBegin; itBegin != itEnd; itBegin++)
        cout << *itBegin << "\n";
    cout << "\n";
}

int main()
{
    srand(time(nullptr));

    /*
    // <array>
    array<User, 10> usersArr;
    array<int, 10> array;
    ContainerIntInit(array.begin(), array.end());
    ContainerPrint(array.begin(), array.end());
    //array.fill(0);
    //ContainerPrint(array.begin(), array.end());
    int arr[5]{ 1, 2, 3, 4, 5 };
    auto array2 = to_array(arr);
    //ContainerIntInit(array2.begin(), array2.end());
    ContainerPrint(array2.begin(), array2.end());
    */

    array<int, 10> array;
    ContainerIntInit(array.begin(), array.end());
    cout << "array init\n";
    ContainerPrint(array.begin(), array.end());

    vector<int> vectFromArr(array.begin(), array.end());
    cout << "\nvectFromArr init\n";
    ContainerPrint(vectFromArr.begin(), vectFromArr.end());


    vector<int> vtemp;

    vector<int> vector;
    for (int i = 0; i < 10; i++)
        vector.push_back(rand() % 100);
    cout << "\nvector init\n";
    ContainerPrint(vector.begin(), vector.end());
}

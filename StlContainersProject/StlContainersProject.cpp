#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <forward_list>
#include <set>

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

    friend bool operator<(const User& u1, const User& u2)
    {
        return u1.name < u2.name;
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

template <typename I>
void print_equal_range(I first, I lb, I ub, I last) {
    for (I i{ first }; i != lb; ++i)
        std::cout << *i << " ";
    std::cout << "[ ";
    for (I i{ lb }; i != ub; ++i)
        std::cout << *i << " ";
    std::cout << ") ";
    for (I i{ ub }; i != last; ++i)
        std::cout << *i << " ";
    std::cout << '\n';
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

    /*
    array<int, 10> array;
    ContainerIntInit(array.begin(), array.end());
    cout << "array init\n";
    ContainerPrint(array.begin(), array.end());

    vector<int> vectFromArr(array.begin() + 2, array.end() - 3);
    cout << "\nvectFromArr init\n";
    ContainerPrint(vectFromArr.begin(), vectFromArr.end());

    vector<int> vect;
    for (int i = 0; i < 10; i++)
        vect.push_back(rand() % 10);
    cout << "\nvector init\n";
    ContainerPrint(vect.begin(), vect.end());
    cout << "input value: ";
    int key;
    cin >> key;
    //erase(vect, key);
    erase_if(vect, [key](auto item) { return item < key; });
    cout << "\nvector\n";
    ContainerPrint(vect.begin(), vect.end());
    */
    /*
    vector<User> usersV;
    usersV.push_back(User("Tom", 24));
    usersV.push_back(User("Sam", 33));
    usersV.push_back(User("Bob", 19));
    usersV.push_back(User("Jim", 41));
    usersV.push_back(User("Tim", 28));
    cout << "\nvector Users:\n";
    ContainerPrintEol(usersV.begin(), usersV.end());

    usersV.insert(usersV.begin() + 2, User("Leo", 22));
    cout << "\n";
    ContainerPrintEol(usersV.begin(), usersV.end());
    usersV.emplace(usersV.begin() + 2, "Bill", 33);
    cout << "\n";
    ContainerPrintEol(usersV.begin(), usersV.end());
    */
    

    forward_list<int> flist1{ 3, 5, 5, 9, 2, 2, 2, 7, 1, 5, 3, 2 };
    forward_list<int> flist2{ 6, 9, 1, 2, 8, 3 };
    cout << "list 1:\n";
    ContainerPrint(flist1.begin(), flist1.end());
    cout << "list 2:\n";
    ContainerPrint(flist2.begin(), flist2.end());

    // sort and merge
    //flist1.sort();
    //flist2.sort();
    //merge(flist2);
    /*
    auto it_pos = flist1.begin();
    for (int i = 0; i < 2; i++, it_pos++);

    auto it_start = flist2.begin();
    for (int i = 0; i < 1; i++, ++it_start);

    auto it_finish = flist2.begin();
    for (int i = 0; i < 4; i++, ++it_finish);

    cout << *it_start << " " << *it_finish << "\n";

    //flist1.splice_after(it_pos, flist2);
    //flist1.splice_after(it_pos, flist2, it_finish);
    flist1.splice_after(it_pos, flist2, it_start, it_finish);
    */
    flist1.sort();
    flist1.unique();
    cout << "\nlist 1:\n";
    ContainerPrint(flist1.begin(), flist1.end());
    cout << "list 2:\n";
    ContainerPrint(flist2.begin(), flist2.end());

    /*
    forward_list<User> users1;
    forward_list<User> users2;

    users1.push_front(User("hhhh", 19));
    users1.push_front(User("bbbb", 21));
    users1.push_front(User("llll", 35));
    users1.push_front(User("aaaa", 33));
    cout << "users 1:\n";
    ContainerPrintEol(users1.begin(), users1.end());

    users1.sort([](User u1, User u2) { return u1.Age() < u2.Age(); });

    cout << "users 1:\n";
    ContainerPrintEol(users1.begin(), users1.end());
    */


    std::set<int> c{ 4, 3, 1, 3, 3 };
    std::cout << "c = ";
    print_equal_range(begin(c), begin(c), end(c), end(c));
    for (int key{}; key != 6; ++key) {
        std::cout << "key = " << key << "; equal range = ";
        const auto [lb, ub] = c.equal_range(key);
        print_equal_range(begin(c), lb, ub, end(c));
    }
}

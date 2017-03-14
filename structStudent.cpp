#include <iostream>
using namespace std;
struct Student
{
    char name [20];
    int age;
    int grade;
    void input ()
    {
        cin>>name>>age>>grade;
    }
    void output()
    {
        cout<<name<<" "<<age<<" "<<grade<<endl;
    }
};
void sorting (Student** arr, int n)
{
    Student* temp;
    bool flag = true;
    for (int i = 1; (i<n) && flag; i++)
    {
        flag = false;
        for (int j = 0; j < n-1; j++)
            if ((arr[j+1]->grade) > (arr[j]->grade))
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = true;
            }
    }
}
int main ()
{
    int n;
    cin>>n;
    Student* arr = new Student [n];
    for(int i =0;i<n;i++)
        arr[i].input();
    cout<<endl;
    for(int i =0;i<n;i++)
        arr[i].output();
    cout<<endl;
    Student** parr = new Student* [n];
    for(int i =0;i<n;i++)
        parr[i] = (arr+i);
    sorting(parr,n);
    for(int i =0;i<n;i++)
        parr[i]->output();
    /*
        Mario 20 5              Bozhin 20 6
        Bozhin 20 6             Stamen 21 6
        Filip 18 4              Mario 20 5
        Stamen 21 6      --->   Georgi 20 5
        Georgi 20 5             Filip 18 4
        Rangel 20 3             Rangel 20 3
    */
    delete[] parr;
    delete[] arr;

    return 0;
}

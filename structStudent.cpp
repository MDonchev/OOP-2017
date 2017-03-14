#include <iostream>
using namespace std;
/*asdasdasdasdasdas */
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
/*
    Функция, която сортира масив от
    студенти спрямо успеха им. Всъщност работим
    с масив от указатели към съответните адреси
    в масива от структурите. Ще разместваме указателите,
    защото е по-бързо от това да разместваме целите структури.
*/
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
    //масив от студенти n студенти
    Student* arr = new Student [n];
    for(int i =0;i<n;i++)
        arr[i].input();
    cout<<endl;
    //масивам в оригиналния вид
    for(int i =0;i<n;i++)
        arr[i].output();
    cout<<endl;
    /*
        помощен масив от указатели, които
        задаваме да сочат към съответните
        елементи от масива
    */
    Student** parr = new Student* [n];
    for(int i =0;i<n;i++)
        parr[i] = (arr+i);
    //сортираме, чрез масива от указатели
    sorting(parr,n);
    //масива, сортиран по полето grade
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
    //не забравяме да изчистим заделената динамична памет
    delete[] parr;
    delete[] arr;

    return 0;
}

#include <iostream>
#include <math.h>

using namespace std;

float sigmoid(float x)
{
    x = -x;
    return 1 / (1 + pow(2.71, x));
}

void operation_S(float arr[], int n)
{
    for (int i = 1; i <= n; i++)
        arr[i] = sigmoid(arr[i]);
}

void threshold(float arr[], int n, int &start, int &end)
{
    int i, k = 0, max_seq = 0;
    start = 0;
    end = 0;
    for (i = 1; i <= n; i++)
        if (arr[i] > 0.5)
            k++;
        else if (k > max_seq)
        {
            max_seq = k;
            end = i - 1;
            start = i - k;
            k = 0;
        }
    if (k > max_seq)
    {
        max_seq = k;
        end = i - 1;
        start = i - k;
    }
}

int main()
{
    float arr[100], nr;
    int start = 0, end = 0, comm;
    int n, i;
    cout << "Menu:\n";
    cout << "Press 1 to find out the sigmoid of a number\n";
    cout << "Press 2 to find out if a person is smiling or not\n";
    cout << "Press 3 to exit\n";
    cin >> comm;
    while (comm != 3)
    {

        if (comm == 1)
        {
            cout << "Introduce number: ";
            cin >> nr;
            cout << "The sigmoid value is: " << sigmoid(nr);
        }
        else if (comm == 2)
        {
            cout << "Introduce the number of values and the values:\n";
            cin >> n;
            for (i = 1; i <= n; i++)
                cin >> arr[i];

            operation_S(arr, n);
            threshold(arr, n, start, end);
            if (start == 0)
                cout << "The person is not smiling\n";
            else
                cout << "The starting index is: " << start << "\n The ending index is: " << end;
        }
        else
            cout << "Try again";
        cin >> comm;

    }
    



}

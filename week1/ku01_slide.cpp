#include <bits/stdc++.h>

using namespace std;

struct linear_line
{
    float slope;
    float y_intersect;
};

float median(float arr[], int n)
{
    if (n % 2 != 0)
    {
        return (float)arr[n / 2];
    }

    return (float)(arr[(n - 1) / 2] + arr[n / 2]) / 2.0;
}

bool positive_solution(linear_line e1, linear_line e2)
{
    float a1 = -e1.slope;
    float a2 = -e2.slope;
    float b1 = 1, b2 = 1;
    float c1 = e1.y_intersect, c2 = e2.y_intersect;

    float unique_solution = (a1 * b2) - (a2 * b1);
    if (unique_solution == 0)
    {
        return false;
    }
    else
    {
        float intersect_1 = ((c1 * b2) - (c2 * b1)) / unique_solution;
        float intersect_2 = ((a1 * c2) - (a2 * c1)) / unique_solution;
        if (intersect_1 > 0 && intersect_2 > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

// print float array
void print_array(float arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, k;
    cin >> n;
    float air[n] = {0};
    linear_line arr[n];
    float divi = 3.0 / (n * 10.0);
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        arr[i].slope = (divi * (i + 1)) * (i + 1 + 0.01 * (i + 1));
        arr[i].y_intersect = n - k + 1;
        air[i] = arr[i].slope;
    }

    sort(air, air + n);
    float med = median(air, n);

    for (int i = 0; i < n; i++)
    {
        arr[i].slope -= med;
        air[i] = arr[i].slope;
    }

    // print linear_line array
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i].slope << " " << arr[i].y_intersect << endl;
    // }

    // cout << "\n";

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (positive_solution(arr[i], arr[j]))
            {
                count++;
            }
        }
    }

    cout << count;

    return 0;
}
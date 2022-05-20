#include <bits/stdc++.h>  
 
using namespace std;

#define forn(i,e) for(ll i = 0; i < e; i++)
#define ln "\n"
#define gl(str) std::getline(std::cin >> std::ws, str) //read string with spaces
#define N 9

/*_________________________________________________________________________________________*/

int row[N], column[N], grid[N];
bool bitmask = false;


int foo(int i,int j)
{
    return i / 3 * 3 + j / 3;
}

void showExample()
{
    cout << " ";
    for(int i = 0; i < N; i++)
        cout << "_ ";
    cout << ln;
    
    for(int i = 0; i < N; i++)
    {
        cout << "|";
        for(int j = 1; j <= N; j++)
        {
            cout << "_|";
        }
        cout << ln;
    }
    cout << ln << "Example " << N << "x" << N << " grid." << ln <<
        "Give input row-wise, separated by a space." << ln <<
        "Press enter to move to the next column." << ln <<
        "Enter '0' for null." << ln;
}

void takeInput(int arr[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
}

bool isValid(int x, int y, int value)
{
    return !((row[x] >> value) & 1)
        && !((column[y] >> value) & 1)
        && !((grid[foo(x, y)] >> value) & 1);
}

void setSudoku(int arr[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int  j = 0; j < N; j++)
        {
            row[i] |= 1 << arr[i][j];
            column[j] |= 1 << arr[i][j];
            grid[foo(i, j)] |= 1 << arr[i][j];
        }
    }
}

bool solve(int arr[N][N], int i, int j)
{
    if(!bitmask)
    {
        bitmask = true;
        setSudoku(arr);
    }

    if(i == N - 1 && j == N)
        return true;

    if(j == N)
    {
        j = 0;
        ++i;
    }

    if(arr[i][j])
        return solve(arr, i, j + 1);
    
    for(int k = 1; k <= N; k++)
    {
        if(isValid(i, j, k))
        {
            arr[i][j] = k;
            row[i] |= 1 << k;
            column[j] |= 1 << k;
            grid[foo(i, j)] |= 1 << k;

            if(solve(arr, i, j + 1))
                return true;

            row[i] &= ~(1 << k);
            column[j] &= ~(1 << k);
            grid[foo(i, j)] &= ~(1 << k);
        }
        arr[i][j] = 0;
    }
    return false;
}

void displayMatrix(int arr[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << ln;
    }
}

int main()
{
    showExample();
    int arr[N][N];
    takeInput(arr);
    if(solve(arr, 0, 0))
        displayMatrix(arr);
    // displayMenu(arr);
    return 0;
}

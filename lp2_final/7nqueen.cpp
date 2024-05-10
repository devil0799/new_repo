#include <iostream>
using namespace std;

class Nqueen
{
private:
    int n;
    int board[10][10];
    int pass;

public:
    Nqueen(int val)
    {
        n = val;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board[i][j] = 0;
            }
        }
        pass = 1;
    }
    bool isSafe(int row, int col)
    {
        int i, j;
        // Check this row on left side
        for (i = 0; i < col; i++)
        {
            if (board[row][i])
                return false;
        }
        // Check upper diagonal on left side
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j])
                return false;
        }
        // Check lower diagonal on left side
        for (i = row, j = col; j >= 0 && i < n; i++, j--)
        {
            if (board[i][j])
                return false;
        }
        return true;
    }
    void printTable()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j])
                    cout << " Q";
                else
                    cout << " X";
            }
            cout << endl;
        }
        cout << "the no. of passes are:" << pass << endl;
    }
    bool solveNQtil(int col)
    {
        if (col >= n)
        {
            return true;
        }
        for (int i = 0; i < n; i++)
        {
            if (isSafe(i, col))
            {
                
                board[i][col] = 1;
                if (solveNQtil(col + 1))
                {
                    return true;
                }

                board[i][col] = 0;
            }
          
        }
        pass++; 
        printTable();
        return false;
    }
};

int main()
{
    int n;
    cout << "Enter The n: ";
    cin >> n;
    cout << endl;
    Nqueen queen(n);
    queen.solveNQtil(0);
    queen.printTable();
    return 0;
}

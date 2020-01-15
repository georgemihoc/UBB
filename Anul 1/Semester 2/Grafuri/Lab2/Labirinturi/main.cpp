#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

ifstream f ("date.txt");

int directie_linie[] = {0,1,0,-1};
int directie_coloana[] = {-1,0,1,0};
int matrice[1000][1000], Lines,Columns,startLine,startColumn,stopLine,stopColumn;


void read()
{
    string lineString;
    int i = 0,j,maxColumn = 0;
    while(getline(f,lineString))
    {
        i++;
        for(j = 0; lineString[j] != NULL; j++)
            if(lineString[j] == '1')
                matrice[i][j + 1] = -1;
            else if(lineString[j] == 'S')
                startLine = i,startColumn = j + 1, matrice[i][j + 1] = 0;
            else if(lineString[j] == 'F')
                stopLine = i,stopColumn = j + 1, matrice[i][j + 1] = 0;
            else
                matrice[i][j + 1] = 0;
        maxColumn = max(j,maxColumn);
    }
    Lines = i;
    Columns = maxColumn;
}

bool isGood(int i,int j)
{
    if(matrice[i][j] != 0)
        return false;
    if(i > Lines || i < 1 || j > Columns || j < 1)
        return false;
    return true;
}

void lee()
{
    int newLine,newColumn,Line,Column;
    queue < pair < int,int > > Q;
    Q.push(make_pair(startLine, startColumn));
    matrice[startLine][startColumn] = 1;

    while(not Q.empty())
    {
        Line = Q.front().first;
        Column = Q.front().second;
        Q.pop();

        if(Line == stopLine && Column == stopColumn)
            break;

        for(int i = 0; i <= 3; i++)
        {
            newLine = Line + directie_linie[i];
            newColumn = Column + directie_coloana[i];

            if(isGood(newLine,newColumn))
                Q.push(make_pair(newLine,newColumn)), matrice[newLine][newColumn] = matrice[Line][Column] + 1;
        }
    }
}

void printMatrix()
{
    for(int i = 1; i <= Lines; i++)
    {
        for(int j = 1; j <= Columns; j++)
            if(i == startLine && j == startColumn)
                cout << "S";
            else if(i == stopLine && j == stopColumn)
                cout << "F";
            else if(matrice[i][j] < -1)
                cout << "0";
            else if(matrice[i][j] == -1)
                cout << "1";
            else
                cout << " ";
        cout << "\n";
    }
}

void solve()
{
    int copyStopLine = stopLine,copyStopColumn = stopColumn,newLine,newColumn;
    while(copyStopLine != startLine || copyStopColumn != startColumn)
    {
        for(int i = 0; i <= 3; i++)
        {
            newLine = copyStopLine + directie_linie[i];
            newColumn = copyStopColumn + directie_coloana[i];

            if(matrice[copyStopLine][copyStopColumn] - 1 == matrice[newLine][newColumn])
            {
                matrice[copyStopLine][copyStopColumn] = -matrice[copyStopLine][copyStopColumn];
                copyStopLine = newLine;
                copyStopColumn = newColumn;
                break;
            }
        }
    }
    printMatrix();
}

int main()
{
    read();
    lee();
    solve();
    return 0;
}

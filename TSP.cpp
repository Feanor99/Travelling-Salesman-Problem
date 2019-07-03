#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <list> 
#include <iterator> 
#include <cstring>
// SEYYAR SATICI PROBLEMI - TRAVELLING SALESMAN PROBLEM

// YUNUS DILBER 3 JUL 19

// IF YOU CHANGE THE STATE NUMBER DONT FORGET TO CHANGE TOTALSMATRIX ARRAY LIMIT

using namespace std;

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

template <class Y,size_t B,size_t C> class noktalar{
    int matrix[B*C][2],count;
    
    public:
        noktalar(Y (&mat)[B][C]){
            for (int i = 0,count = 0; i < B; i++)
            {
                for (int j = 0; j < C; j++)
                {
                   switch (mat[i][j])
                    {
                    case 101:
                        matrix[count][0] = j;
                        matrix[count][1] = i;
                        count++;
                        break;
                    
                    default:
                        break;
                    } 
                }
            }
        }
        char* startpoint(char T){
            switch (T)
            {
            case 'A':
                return (char*)"ABCDEFG";
                break;
            case 'B':
                return (char*)"BACDEFG";
                break;
            case 'C':
                return (char*)"CABDEFG";
                break;
            case 'D':
                return (char*)"DABCEFG";
                break;
            case 'E':
                return (char*)"EABCDFG";
                break;
            case 'F':
                return (char*)"FABCDEG";
                break;
            case 'G':
                return (char*)"GABCDEF";
                break;
            default:
            return (char*)"";
                break;
            }
        }
        double distance(int x1,int y1, int x2, int y2)
        {
            return pow((pow(x1-x2,2)+pow(y1-y2,2)),0.5);
        }
        void Allcosts(int nodes)
        {
            double totalsmatrix[720];
            char strt;
            list <string> strlist;
            cout << "Enter The Start Letter Please:" << endl;
            cin >> strt;
            strt = toupper(strt);
            char* ways = new char();
            strcpy(ways,startpoint(strt));
            string way;
            double total = 0;
            for (int i = 0; i <= factorial(nodes-1); i++)
            {
                way = ways;
                string state1,state2;
                char s1,s2;
                int xy1,xy2;
                for (int j = 0; j < 7; j++)
                {
                    if (j != 6){
                    state1 = way.substr(j,1);
                    s1 = state1[0];
                    xy1 = s1 - 65;
                    
                    state2 = way.substr(j+1,1);
                    s2 = state2[0];
                    xy2 = s2 - 65;
                    }
                    else
                    {
                    state1 = way.substr(0,1);
                    s1 = state1[0];
                    xy1 = s1 - 65;
                    state2 = way.substr(j,1);
                    s2 = state2[0];
                    xy2 = s2 - 65;
                    }
                total += distance(matrix[xy1][0],matrix[xy1][1],matrix[xy2][0],matrix[xy2][1]);

                }
                totalsmatrix[i] = total;
                total = 0;
                strlist.push_back(way);
                next_permutation(ways,ways+7);
                
            }
                double best = totalsmatrix[0];
                int pos = 0;
                
                 for (int j = 1; j < 643; j++)
                {
                   if (best > totalsmatrix[j])
                    {
                        best = totalsmatrix[j];
                        pos = j;
                    }  
                }
                list <string> :: iterator it = strlist.begin();
                advance(it,pos);
                cout << "The Best Way: " ;
                cout << *it << strt << endl;
                cout << "Distance: " << best << endl;
        }
};


template<typename T, size_t N, size_t M>
void assignpoints(T (&matrix)[N][M],int nodes)
{
    srand(time(NULL));
    for (int i = 0; i < nodes; i++)
    {
        int a,b;
        do{
            a = rand() % M;
            b = rand() % M;
        }while (a == b || matrix[b][a] == 101);
        
        matrix[b][a] = 101;
    }
    
}
template<typename T, size_t M, size_t N>
void printmatrix(T (&matrix)[M][N]){
    for (int i = 0; i < N; i++)
    {
        cout << "\t" << i ;
    }
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "\t" << " " ;
    }
        cout << endl;
    for (int i = 0,j = 65; i < M; i++)
    {
        cout << i << "\t";
        for (int k = 0; k < N; k++)
        {
            switch (matrix[i][k])
            {
            case 101:
                cout << (char) j << '\t';
                j++;
                break;
            
            default:
                cout << '-' << '\t';
                break;
            } 
        }
        cout << endl << endl;
    }
    
}
int main()
{

    int a[10][10];
    assignpoints(a,7);
    printmatrix(a);
    noktalar<int,10,10> noktalar(a);
    noktalar.Allcosts(7);
    return 0;
}
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

//a(0,0)b(1,0)c(2,0)d(3,0)e(0,1)f(1,1)g(2,1)h(3,1)i(0,2)j(1,2)
using namespace std;


//revert example...

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
template<typename T,size_t L,size_t M>
void sortarray(T (&matrix)[L][M]){
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < L; j++)
        {
            if (matrix[i][1] < matrix[j][1])
            {
                int temp = matrix[i][0];
                int temp2 = matrix[i][1];
                matrix[i][0] = matrix[j][0];
                matrix[i][1] = matrix[j][1];
                matrix[j][0] = temp;
                matrix[j][1] = temp2;
            }else if (matrix[i][1] == matrix[j][1])
            {
                if (matrix[i][0] < matrix[j][0])
            {
                int temp = matrix[i][0];
                int temp2 = matrix[i][1];
                matrix[i][0] = matrix[j][0];
                matrix[i][1] = matrix[j][1];
                matrix[j][0] = temp;
                matrix[j][1] = temp2;
            }
            }
            
            
        }
        
    }

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
        noktalar(Y (&Xmat)[B],Y (&Ymat)[C],int nodes){
            for (int i = 0; i < B*C; i++)
            {
                        matrix[i][0] = 102;
                        matrix[i][1] = 102;
            }
            for (int i = 0; i < nodes; i++)
            {
                        matrix[i][0] = Xmat[i];
                        matrix[i][1] = Ymat[i];
            }
            sortarray(matrix);
        }
        char* startpoint(char T, int N){
            string formula;
            char* RET = new char();

            formula[0] = T;
            int j = 1;
            int k = 1;
            for (int i = 1; i < N; i++,j++,k++)
            {
                if ((k + 64) != (int) T)
                {
                    formula[j] = (char) (k + 64);
                }else
                {
        
                    k++;
                    formula[j] = (char) (k + 64);
                    
                }
                
            }
            formula[j] = '\0';
            RET = const_cast <char*>(formula.c_str());
            return RET;
            
        }
        double distance(int x1,int y1, int x2, int y2)
        {
            return pow((pow(x1-x2,2)+pow(y1-y2,2)),0.5);
        }
        void Allcosts(int nodes)
        {
            list <string> strlist;
            list <double> totalslist;
            char strt;
            cout << "Enter The Start Letter Please:" << endl;
            cin >> strt;
            strt = toupper(strt);
            char* ways = new char();
            strcpy(ways,startpoint(strt,nodes));
            string way;
            double total = 0;
            for (int i = 0; i <= factorial(nodes-1); i++)
            {
                way = ways;
                string state1,state2;
                char s1,s2;
                int xy1,xy2;
                //reading way ex: ABCD
                for (int j = 0; j < nodes; j++)
                {
                    if (j != nodes-1){
                    state1 = way.substr(j,1);
                    s1 = state1[0];
                    xy1 = s1 - 65;
                    
                    state2 = way.substr(j+1,1);
                    s2 = state2[0];
                    xy2 = s2 - 65;
                    }
                    else// returnin the start letter
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
                totalslist.push_back(total);
                total = 0;
                strlist.push_back(way);
                next_permutation(ways,ways+nodes);
                
            }
                list <double> :: iterator it2 = totalslist.begin();
                advance(it2,0);
                double best = *it2;
                int pos = 0;
                ++it2;

                for (int j = 1;it2 != totalslist.end(); ++it2,j++)
                {
                   if (best > *it2)
                    {
                        best = *it2;
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

template<typename T,size_t b>
int removeDuplicates(T (&arr)[b], int n)
{
    int j = 0;

    for (int i=0; i < n; i++){
        for(int j=0;j<i;j++){

            if(arr[i]==arr[j]){
                n--;
                for (int k=i; k<n; k++){
                    {
                        arr[k]=arr[k+1];
                    }
                }
                i--;  
            }
        }
    }

    return n;
}

template<typename T,size_t L>
void sortarray(T (&matrix)[L]){
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < L; j++)
        {
            if (matrix[i] < matrix[j])
            {
                int temp = matrix[i];
                matrix[i] = matrix[j];
                matrix[j] = temp;
            }
            
        }
        
    }
    removeDuplicates(matrix,L);

}

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
//"A(15,21)B(9,4)C(55,22)A(4,5)B(6,7)C(8,9)A(10,91)B(92,93)C(94,95)C(96,97)";
template<typename T,size_t K>
void assignpoints(string str, T (&Xmatrix)[K],T (&Ymatrix)[K],int L){
    string temp;
    char c;
    int i = 0,j = 0,k=0;
    while (k != L)
    {
       while (str[i] != '(')
       {
           i++;
       }
       i++;
       int end = str.find(',',i);
       temp = str.substr(i,end-i);
       if (temp.length() == 1)
       {
            c = temp[0];
            Xmatrix[j] = (int)((int) c - (int) '0');
       }else
       {
            Xmatrix[j] = stoi(temp);
       }
       
       i += end-i+1;
       end = str.find(')',i);
       temp = str.substr(i,end-i);
       if (temp.length() == 1)
       {
            c = temp[0];
            Ymatrix[j] = (int)((int) c - (int) '0');
       }else
       {
            Ymatrix[j] = stoi(temp);
       }
       j++;
       k++;
    }
    
}

template<typename T, size_t K>
void printmatrix(T (&Xmatrix)[K],T (&Ymatrix)[K],int L){
    int matrix[11][11] = {};
    for (int i = 0; i < 11; i++)
    {
       matrix[i][0]=Xmatrix[i];
       matrix[i][1]=Ymatrix[i];
    }
    sortarray(matrix);
    sortarray(Ymatrix);
    sortarray(Xmatrix);
    for (int i = 0; Xmatrix[i] != 102 && i < L; i++)
    {
        cout << "\t" << Xmatrix[i] ;
    }
    cout << endl;
    for (int i = 0; Ymatrix[i] != 102 && i < L; i++)
    {
        cout << "\t" << " " ;
    }
    cout << endl;
    for (int i = 0, j = 65,z = 0; Ymatrix[i] != 102 && i < L; i++)
    {
        cout << Ymatrix[i] << "\t";
        for (int k = 0; Xmatrix[k] != 102 && k < L; k++)
        {
            if (Xmatrix[k] == matrix[z][0] && Ymatrix[i] == matrix[z][1])
            {
                cout << (char) j << '\t';
                j++;
                z++;
            }else
            {
                cout << '-' << '\t';
            }
              
        }
        cout << endl << endl;
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
    string str = "A(15,21)B(9,4)C(55,7)";
    int nodes = 0,ctrl = 1 , ctr = 0;
    cout << "How Many Nodes Do You Want (MAX 10)" << endl;
    cin >> nodes;
    int Xmatrix[11],Ymatrix[11];
    fill_n(Xmatrix,11,102);
    fill_n(Ymatrix,11,102);
    int a[10][10];
    cout << "Enter 0 for random coordinates Enter 1 for special coordinates: " ;
    cin >> ctr;
    if (ctr == 1)
    {
        cout << "Enter The Coordinates: (ex: A(47,44)B(55,11)... (max xy [-100,100])" << endl;
        cin >> str;
        assignpoints(str,Xmatrix,Ymatrix,nodes);
        noktalar<int,11,11> noktalar(Xmatrix,Ymatrix,nodes);//detect nodes position
        printmatrix(Xmatrix,Ymatrix,nodes);
        cout << "Possible ways: " << (factorial(nodes-1) * nodes) << endl;
     while(ctrl != 0){
      
        noktalar.Allcosts(nodes);
        cout << endl << "Enter 0 for exit, enter 1 for start from other letter" << endl;
        cin >> ctrl;
        }
    }else
    {
        assignpoints(a,nodes);
        printmatrix(a);
        noktalar<int,10,10> noktalar(a);//detect nodes position
        cout << "Possible ways: " << (factorial(nodes-1) * nodes) << endl;
     while(ctrl != 0){
      
        noktalar.Allcosts(nodes);
        cout << endl << "Enter 0 for exit, enter 1 for start from other letter" << endl;
        cin >> ctrl;
        }
    }
    return 0;
}
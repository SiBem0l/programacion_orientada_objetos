#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename T>
void muestra(vector<T> elements)
{
    for(const T& element : elements)
    {
        cout << element << " ";
    } 
    cout << endl;
}

int main()
{
    int c1[] = {1,2,4,5,6,8,9,10,12,15};
    int c2[] = {1,3,4,5,7};

    int t1,t2;
    t1=sizeof(c1)/sizeof(int);
    t2=sizeof(c2)/sizeof(int);

    vector<int> v1(c1,c1+t1), v2(c2,c2+t2),v3(t1);
    vector<int>::iterator final;
    ostream_iterator<int> salida(cout," ");

    cout << "Valores de v1 "; muestra(v1);
    cout << "Valores de v2 "; muestra(v2);

    if (includes(v1.begin(), v1.end(), v2.begin(), v2.end()))
        cout << "v2 está incluido en v1\n";
    else 
        cout << "v2 no está incluido en v1\n";
    
    final = set_union(v1.begin(),v1.begin() + 6,
                      v2.begin(),v2.end(), v3.begin());

    cout << "Valores de v3. Unión de v1..v1+5 y v2\n";
    copy(v3.begin(),final,salida);
    final= set_intersection(v1.begin(),v1.begin()+6,
                            v2.begin(), v2.end(),v3.begin());
    cout << "\nValores de v3. Intersección de v1..v1+5 y v2\n";
    copy(v3.begin(),final,salida);
    final= set_difference(v1.begin(),v1.end(),
                          v2.begin(),v2.end(), v3.begin());
    cout << "\nValores de v3. Diferencia de v1 y v2\n";
    copy(v3.begin(),final,salida);
    return 0;
}
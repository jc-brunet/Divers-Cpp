#include <iostream>
#include <limits>
using namespace std;
int main()
{
long n(10);
cout << n << endl;
n = n * n;
cout << n << endl;
n = n * n;
cout << n << endl;
n = n * n;
cout << n << endl;
n = n * n;
cout << n << endl;
n = n * n;
cout << n << endl;

cout << "plus grand long : "
<< numeric_limits<long>::max() << endl;
cout << "plus grand int : "
<< numeric_limits<int>::max() << endl;
cout << "plus grand long long : "
<< numeric_limits<long long int>::max() << endl;

return 0;
}

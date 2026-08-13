//fibonacci sequence using recursion
#include <iostream>

int fib_rec(int n);
int fib_tail(int n, int p, int q);

int main()
{
	std::cout<<"Which term of the Fibonacci sequence do you want to be computed?[enter a number starting from 0]"<<std::endl;
	int n;
	std::cin >> n;

	std::cout<<"do you want to calculate the term recursively or tail recursively?[enter r or t]"<<std::endl;
	char type;
	std::cin>>type;
	
	if (type == 'r')
	std::cout << "fib(" << n << " )= "<<fib_rec(n)<<std::endl;
	if (type == 't')
	std::cout << "fib(" << n << " )= "<<fib_tail(n, 0, 1)<<std::endl;
	else
	std::cout<<"invalid input"<<std::endl;

return 0;  

}
	int fib_rec(int n){
		if ( n == 0 ){
		return 0;
		}
		if ( n == 1 ){
		return 1;
		}
		return fib_rec(n - 1) + fib_rec(n - 2);
	}
    int fib_tail(int n, int p, int q){
		int p = 0;
		int q = 1;
		if (n == 0)
        return 0;
		if (n == 1)
        return 1;
    return fib_tail(n - 1, p, p + q);
    }

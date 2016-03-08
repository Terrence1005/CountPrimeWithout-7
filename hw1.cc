//Author Xiaotian Zhang
//Stevens ID:10402569
#include <iostream>
#include <inttypes.h>
//#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;
static int count_fac=0;

bool NotContain_Seven(uint64_t testnum){
	uint64_t temp = testnum;
	while(temp>0){
		if(temp%10 == 7){
			return false;
		}
		temp = temp/10;
	}
	return true;

}
uint64_t* EraSieveOf_PrimeFac(uint64_t num)
{
    int i = sqrt(num);

    bool prime_t[i+1];
    /*
    for(int j = 0;j<i;j++){
    	prime_t[j] = true;
    }
    */
    memset(prime_t,true,sizeof(prime_t));
    for(int f = 2;f*f<=i;f++)
    {
        if(prime_t[f] == true)
        {
            for(int j=f*2;j<=i; j+=f)
                prime_t[j] = false;
        }
    }
    uint64_t* arr = new uint64_t[1000000];
    for(int p=2;p<=i;p++)
    {
        if(prime_t[p])
        {
            arr[count_fac] = p;
            count_fac++;
        }
    }

    return arr;
}

bool isPrime(uint64_t n,uint64_t arr [])
{
    if(n==1) {return false;}
    if(n==2||n==3){return true;}
    if((n%6 != 1)&&(n%6 != 5)) {return false;}

    for(int i = 0;i<count_fac;i++)
    {
        if(n != arr[i] && n % arr[i] == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
   int prime_count = 0;
   uint64_t start_num;
   cout<<"Input Start Number: "<<endl;
   cin>>start_num;
   uint64_t last_num;
   cout<<"Input End Number: "<<endl;
   cin>>last_num;
   uint64_t* primeArray;
   uint64_t* NotContainSevenArray = new uint64_t [last_num - start_num];
   //primeArray =  EraSieveOf_PrimeFac(last_num);
   uint64_t i = 0;
   for(uint64_t n = start_num; n<=last_num;n++){
	   if(NotContain_Seven(n)){
		   NotContainSevenArray[i]= n;
		   i++;
	   }

   }
   //cout<<i<<" "<<NotContainSevenArray[i-1]<<endl;

   primeArray =  EraSieveOf_PrimeFac(NotContainSevenArray[i-1]);
   for(uint64_t j = 0; j<i;j++)
	{
		if(isPrime(NotContainSevenArray[j],primeArray))
			prime_count++;
	}
    cout<<"Number of Primes not contain 7 between "<<start_num
    		<<" and " <<last_num<<" is: "<<prime_count<<endl;

   delete [] NotContainSevenArray;
}

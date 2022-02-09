/*
 * CS 11 Spring 2022
 * Lab 03
 *
 * Practice on recursion.
 * 
 * Modified by: Eddy Zhang
 * Date: Wed Feb 9 2022
 */

#include <iostream>
#include<math.h>

using namespace std;

//Multiply
//-------------------------------------------------------
int multiply(int x, int y)
{
    if (y > 0)
    {
        x += x;
        multiply(x , y-1);
    }
    return x;
}

//Power
//-------------------------------------------------------
int power_helper(int power, int x, int k)
{
    power *= x;
    if (k > 1)
    {
        return power_helper(power, x, k-1);
    }
    return power;
}

int power(int x, int k)
{
    int power = 1;
    return power_helper(power, x, k);
}

//Power JFFE: If k is a power of 2
//the "2" in the code can be replaced by the k's factor n 
int powerJFFE(int x, int k)
{
    x *= x;
    if (k != 2)
    {
        return powerJFFE(x, k/2);
    }
    return x;
}

//Sum from 
//-------------------------------------------------------
int sum_helper(int sum, int a, int b)
{
    sum += a;
    if (a < b)
    {
        return sum_helper(sum, a+1, b);
    }
    return sum;
}

int sum_from(int a, int b)
{
    int sum = 0;
    return sum_helper(sum, a, b);
}

//Double digits 
//-------------------------------------------------------
int double_help(int output, int n, int digits)
{
    output += n % 10 * 11 * (pow(10, digits));
    n /= 10;
    if (n > 0)
    {
        return double_help(output, n, digits + 2);
    }
    return output;
}

//maximum n is 19999 since the int is below 2147483648
int double_digits(int n)
{
    return double_help(0, n, 0);
}

//Is prime
//-------------------------------------------------------
bool is_prime_helper(int i, int n)
{
    if (i * i < n)
    {
        if (n % i == 0)
        return false;
        else
        return is_prime_helper(i+1, n);
    }
    return true;
}

bool is_prime(int n)
{
    return is_prime_helper(2, n);
}

//Reverse
//-------------------------------------------------------
string reverse_helper(string reverse, string s, int n)
{
    reverse[s.length()-1-n] = s[n];
    if(n < (int)s.length()-1)
    {
        return reverse_helper(reverse, s, n+1);
    }
    return reverse;
}

string reverse(string s)
{
    string reverse = s;
    return reverse_helper(reverse, s, 0);
}

//Remove non-numeric
//-------------------------------------------------------
string remove_non_numeric_helper(string s, int n)
{
    if (int(s[n]) <= 48 or int(s[n]) >= 57)
    {
        s.erase(s.begin() + n);
        if(n < int(s.length()))
        {
            return remove_non_numeric_helper(s, n);
        }
    }
    else
    {
        if(n+1 < int(s.length()))
        return remove_non_numeric_helper(s, n+1);
    }
    return s;
}

string remove_non_numeric(string s)
{
    return remove_non_numeric_helper(s, 0);
}

//main function
//-------------------------------------------------------
int main(){

    //cout << Put the function you want to test here! << endl;
    return 0;
    
}
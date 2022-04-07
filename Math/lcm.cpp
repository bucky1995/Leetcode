int gcd(int value1, int value2)
{
    while (value1 != 0 && value2 != 0)
    {
        if (value1 > value2)
            value1 %= value2;
        else
            value2 %= value1;
    }
    return Math.Max(value1, value2);
}

int lcm(int a, intb){
    return (a/gcd(a,b)*b);
}
// we can answer query in 0(1) complexity 
// query related to find all divisor of a number by storing 
// all the count of number of its divisor
for (ll i = 1; i < p; i++)
{
    for (ll j = i; j < p; j += i)
    {
        r[j]++;
    }
}

#include "rsa.h"

std::vector<sam_int> sam_input()
{
    std::string input;
    std::vector<sam_int> input_vector;

    std::cin >> input;

    for(char digit: input)
    {
        if(digit >= '0' && digit <= '9')
        {
            input_vector.push_back(digit - '0');
        }
    }
    
    std::reverse(input_vector.begin(), input_vector.end());

    return input_vector;
}

void sam_print(const std::vector<sam_int> &v)
{
    for(auto iter = v.rbegin(); iter != v.rend(); iter++)
    {
        std::cout << *iter << " ";
    }
    std::cout << "\n";
}

std::vector<sam_int> sam_mp(const std::vector<sam_int> &first, const std::vector<sam_int> &second)
{
    std::vector<sam_int> mp_vector;

    mp_vector.resize(first.size() + second.size() + 1);

    for(size_t i = 0; i != first.size(); i++)
    {
        int transfer = 0;

        for(size_t j = 0; j != second.size(); j++)
        {
            int mp = first[i] * second [j] + mp_vector[i + j] + transfer;
            mp_vector[i + j] = mp % 10;
            transfer = mp / 10;
        }
        
        mp_vector[i + second.size()] += transfer;
    }

    while(mp_vector.back() == 0)
    {
        mp_vector.pop_back();
    }
   
    return mp_vector;
}

bool sam_gcd(const std::vector<sam_int> &first, int e)
{
    int mod_gcd_int = sam_mod_int(first, e);
    
    int gcd_res = sam_evklid(mod_gcd_int, e);
    
    return gcd_res == 1;
}

int sam_mod_int(std::vector<sam_int> first, int e)
{
	int mod = 0;
	
	std::reverse(first.begin(), first.end());
	
	for(int digit: first)
	{
		mod = (mod * 10 + digit) % e; 
	}
	
	return mod;
}

int sam_evklid(int a, int b)
{
	while(b != 0)
	{
		int t = b;
		b = a % b;
		a = t;
	}
	
	return a;
}

std::vector<sam_int> sam_pow(const std::vector<sam_int> &first, int e, const std::vector<sam_int> &n) 
{
    std::vector<sam_int> pow_vector = {1}; 
    std::vector<sam_int> mod_vector = sam_mod(first, n); 

    while (e > 0) 
    {
        if (e % 2 == 1)
        {
            pow_vector = sam_mod(sam_mp(pow_vector, mod_vector), n); 
		}

        mod_vector = sam_mod(sam_mp(mod_vector, mod_vector), n); 
        e >>= 1;
    }

    return pow_vector;
}

std::vector<sam_int> sam_mod(std::vector<sam_int> first, std::vector<sam_int> second)
{
    auto[chast, ostatok] = sam_divide(first, second);
    return ostatok;
}

std::pair<std::vector<sam_int>, std::vector<sam_int>> sam_divide(const std::vector<sam_int> &first, const std::vector<sam_int> &second) 
{
    std::vector<sam_int> chast;
    std::vector<sam_int> ostatok;
    

    for (int i = first.size() - 1; i >= 0; i--) 
    {
        ostatok.insert(ostatok.begin(), first[i]);

        while (ostatok.size() > 1 && ostatok.back() == 0)
        {
            ostatok.pop_back();
        } 
        
        int ch = 0;

        while (sam_compare(second, ostatok)) 
        {
            sam_subtract(ostatok, second);
            ch++;
        }
        chast.push_back(ch);
    }

    std::reverse(chast.begin(), chast.end());

    while (chast.size() > 1 && chast.back() == 0)
    {
        chast.pop_back();
    } 

    return {chast, ostatok};
}

bool sam_compare(const std::vector<sam_int> &first, const std::vector<sam_int> &second)
{
    if (first.size() != second.size())
    {
        return first.size() < second.size();
    } 
    for (int i = first.size() - 1; i >= 0; i--) 
    {
        if (first[i] != second[i])
        {
            return first[i] < second[i];
        } 
    }
    return true;
}

void sam_subtract(std::vector<sam_int> &first, const std::vector<sam_int> &second)
{
    int t;
    t = 0;

    for(size_t i = 0; i < first.size(); i++)
    {
        int p;
        p = t;

        if(i < second.size())
        {
            p += second[i];
        }

        if(first[i] < p)
        {
            first[i] += 10;
            t = 1;
        }
        else
        {
            t = 0;
        }

        first[i] -= p;
    }

    while(first.back() == 0)
    {
        first.pop_back();
    }
}

//---------------------------------------------------------------------------------

std::vector<sam_int> sam_division_int(std::vector<sam_int> first, int e)
{
    std::vector<sam_int> divider_vector;

    std::reverse(first.begin(), first.end());

    int divider = 0;

    for (int digit : first)
    {
        divider = (divider * 10) + digit;

        int res = divider / e;

        divider_vector.push_back(res);

        divider %= e;
    }


    while (!divider_vector.empty() && divider_vector[0] == 0) 
    {
        divider_vector.erase(divider_vector.begin());
    }

    std::reverse(divider_vector.begin(), divider_vector.end());

    return divider_vector;
}

std::vector<sam_int> sam_pow_vector(const std::vector<sam_int> &first, std::vector<sam_int> d, const std::vector<sam_int> &n) 
{
    std::vector<sam_int> pow_vector = {1}; 
    std::vector<sam_int> mod_vector = sam_mod(first, n); 
    std::vector<sam_int> two = {2};
    std::vector<sam_int> nolik = {0};

    while (!sam_equal(nolik, d)) 
    {
        auto[chast, ostatok] = sam_divide(d, two);

        if (sam_equal({1}, ostatok))
        {
            pow_vector = sam_mod(sam_mp(pow_vector, mod_vector), n); 
		}

        mod_vector = sam_mod(sam_mp(mod_vector, mod_vector), n); 
        d = chast;
    }

    return pow_vector;
}

bool sam_equal(const std::vector<sam_int> &first, const std::vector<sam_int> &second)
{
    return first == second;
}

std::vector<char> sam_input_char()
{
    std::string input;
    std::vector<char> input_vector;

    std::cin >> input;

    for(char symbol: input)
    {
        input_vector.push_back(symbol);
    }

    return input_vector;
}

std::pair<std::vector<sam_int>, std::vector<sam_int>> sam_encryption_char(const std::vector<char> &message, int e, const std::vector<sam_int> &n)
{
    std::pair<std::vector<sam_int>, std::vector<sam_int>> result;
    
    std::vector<sam_int> res;
    std::vector<sam_int> count;
    
    for(char symbol: message)
    {
		int count_int = 0;
		int sym = symbol;
		std::cout << sym << "\n";

		while(sym > 0)
		{
			res.push_back(sym % 10);
			sym /= 10;
			count_int++;
		}

		count.push_back(count_int);
	}
	
	std::vector<sam_int> res_pow;
	
	res_pow = sam_pow(res, e, n);
	
	std::cout << "res_pow\t";
	sam_print(res_pow);
		
	result.first = res_pow;
	result.second = count;    

    return result;
}

std::vector<sam_int> sam_decryption_char(std::pair<std::vector<sam_int>, std::vector<sam_int>> &cmessage, std::vector<sam_int> &d, const std::vector<sam_int> &n)
{
    
    std::vector<sam_int> res;
    
    std::string output;

    res = sam_pow_vector(cmessage.first, d, n);
    
    std::vector<sam_int> t_int;
    t_int = res;
    
    std::reverse(cmessage.second.begin(), cmessage.second.end());
    
    for(size_t i = 0; i < cmessage.second.size(); i++)
    {
		int count;
		int count_erase;
		count = cmessage.second[i];
		count_erase = cmessage.second[i];
		
		int num = 0;
		for(auto iter = t_int.end() - 1; iter != t_int.begin() - 1; iter--)
		{
			num = (num * 10) + *iter;
			count--;
			if(count < 1)
			{
				break;
			}
		}
		
		t_int.erase(t_int.end() - count_erase, t_int.end());
		
		output += static_cast<char> (num);
	} 
	
	std::reverse(output.begin(), output.end());
	std::cout << "output\t" << output << "\n";

    return res;
}

//----------------------------------------------------------------------------------

std::vector<sam_int> sam_calculation_d(const std::vector<sam_int> &phi, int e)
{
    std::vector<sam_int> k {1};
    std::vector<sam_int> first;

    while(1)
    {
        first = sam_mp(phi, k);
        ++first; 

        int t; 
        t = sam_mod_int(first, e); 

        if(t == 0)
        {
            break;
        }

        ++k;
    }

    std::cout << "k\t";
    sam_print(k);

    std::vector<sam_int> d;

    d = sam_division_int(first, e);

    return d;
}

std::vector<sam_int> &operator ++(std::vector<sam_int> &first)
{
    sam_int t = 0;
    first[0] += 1;

    for(size_t i = 0; i != first.size(); i++)
    {
        first[i] += t; 
        t = 0;
        if(first[i] > 9)
        {
            t = 1;
            first[i] -= 10;
        }
    }

    if(t == 1)
    {
        first.push_back(1);
    }

    return first;
}
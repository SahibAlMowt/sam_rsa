#include "rsa.h"

int main()
{
    std::vector<sam_int> p;
    std::vector<sam_int> q;

    std::cout << "p\t";
    p = sam_input();
    std::cout << "q\t";
    q = sam_input();

    std::vector<sam_int> n;

    n = sam_mp(p, q);
   
    std::cout << "n\t";
    sam_print(n);

    p[0] -= 1;
    q[0] -= 1;

    std::cout << "p - 1\t";
    sam_print(p);

    std::cout << "q - 1\t";
    sam_print(q);

    std::vector<sam_int> phi;

    phi = sam_mp(p, q);

    std::cout << "phi\t";
    sam_print(phi);

    int e = 2;

    do
    {   
        e -= 1;
        e = e << 1;
        e += 1;
      
    } while (!sam_gcd(phi,e));
    
    std::cout << "e\t" << e << "\n";
      
    std::vector<sam_int> d;
    
    d = sam_calculation_d(phi, e);

    std::cout << "d\t";
    sam_print(d);  

    std::vector<char> real_message;

    std::cout << "message\t";
    real_message = sam_input_char();

    std::pair<std::vector<sam_int>, std::vector<sam_int>> cf;
    cf = sam_encryption_char(real_message, e, n);

    std::vector<sam_int> dc;

    dc = sam_decryption_char(cf, d, n);

    std::cout << "df\t";
    sam_print(dc);


    return 0;
    
    
}

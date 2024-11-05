#ifndef rsa_h
#define rsa_h

#include <vector>
#include <iostream>
#include <algorithm>

typedef short int sam_int;

std::vector<sam_int> sam_input();
void sam_print(const std::vector<sam_int> &v);
std::vector<sam_int> sam_mp(const std::vector<sam_int> &first, const std::vector<sam_int> &second);
bool sam_gcd(const std::vector<sam_int> &first, int e);
int sam_mod_int(std::vector<sam_int> first, int e);
int sam_evklid(int a, int b);
std::vector<sam_int> sam_pow(const std::vector<sam_int> &first, int exp, const std::vector<sam_int> &n);
std::vector<sam_int> sam_mod(std::vector<sam_int> first, std::vector<sam_int> second);
std::pair<std::vector<sam_int>, std::vector<sam_int>> sam_divide(const std::vector<sam_int> &first, const std::vector<sam_int> &second);
bool sam_compare(const std::vector<sam_int> &first, const std::vector<sam_int> &second);
void sam_subtract(std::vector<sam_int> &first, const std::vector<sam_int> &second);
//--------------------------------------------------------------------
std::vector<sam_int> sam_division_int(std::vector<sam_int> first, int e);
std::vector<sam_int> sam_pow_vector(const std::vector<sam_int> &first, std::vector<sam_int> d, const std::vector<sam_int> &n);
bool sam_equal(const std::vector<sam_int> &first, const std::vector<sam_int> &second);
std::vector<char> sam_input_char();
std::pair<std::vector<sam_int>, std::vector<sam_int>> sam_encryption_char(const std::vector<char> &message, int e, const std::vector<sam_int> &n);
std::vector<sam_int> sam_decryption_char(std::pair<std::vector<sam_int>, std::vector<sam_int>> &cmessage, std::vector<sam_int> &d, const std::vector<sam_int> &n);
//---------------------------------------------------------------------
std::vector<sam_int> sam_calculation_d(const std::vector<sam_int> &phi, int e);
std::vector<sam_int> &operator ++(std::vector<sam_int> &first);

#endif //rsa_h

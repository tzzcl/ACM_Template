�� Built-in Function: int __builtin_ffs (unsigned int x)

Returns one plus the index of the least significant 1-bit of x, or if x is zero, returns zero.
���������һ����1����λ�á�

�� Built-in Function: int __builtin_clz (unsigned int x)

Returns the number of leading 0-bits in x, starting at the most significant bit position. If x is 0, the result is undefined.
���������һ����1��֮ǰ0�ĸ�����

�� Built-in Function: int __builtin_ctz (unsigned int x)

Returns the number of trailing 0-bits in x, starting at the least significant bit position. If x is 0, the result is undefined.
���������һ����1��֮���0�ĸ�����

�� Built-in Function: int __builtin_popcount (unsigned int x)

Returns the number of 1-bits in x.
���ء�1���ĸ�����

�� Built-in Function: int __builtin_parity (unsigned int x)

Returns the parity of x, i.e. the number of 1-bits in x modulo 2.
���ء�1���ĸ�������ż�ԡ�

�� Built-in Function: int __builtin_ffsl (unsigned long)

Similar to __builtin_ffs, except the argument type is unsigned long. 

�� Built-in Function: int __builtin_clzl (unsigned long)

Similar to __builtin_clz, except the argument type is unsigned long. 

�� Built-in Function: int __builtin_ctzl (unsigned long)

Similar to __builtin_ctz, except the argument type is unsigned long. 

�� Built-in Function: int __builtin_popcountl (unsigned long)

Similar to __builtin_popcount, except the argument type is unsigned long. 

�� Built-in Function: int __builtin_parityl (unsigned long)

Similar to __builtin_parity, except the argument type is unsigned long. 

�� Built-in Function: int __builtin_ffsll (unsigned long long)

Similar to __builtin_ffs, except the argument type is unsigned long long. 

�� Built-in Function: int __builtin_clzll (unsigned long long)

Similar to __builtin_clz, except the argument type is unsigned long long. 

�� Built-in Function: int __builtin_ctzll (unsigned long long)

Similar to __builtin_ctz, except the argument type is unsigned long long. 

�� Built-in Function: int __builtin_popcountll (unsigned long long)

Similar to __builtin_popcount, except the argument type is unsigned long long. 

�� Built-in Function: int __builtin_parityll (unsigned long long)

Similar to __builtin_parity, except the argument type is unsigned long long.
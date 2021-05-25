# simple-cipher
A simple cipher I've thrown together. Similar to Vigenere.



**Example 1**

Encrypt or Decrypt? (1, 2) : 1

Enter a string to encrypt : The quick brown fox jumps over the lazy dog. 1234567890!@#$%^&*

Enter a key (integer) : 8572912837


Encrypted : 77 100 95 29 105 113 98 95 106 30 91 110 105 116 102 28 95 107 119 30 99 113 103 109 107 28 104 114 100 112 25 112 98 98 24 104 90 118 120 30 93 107 97 43 24 45 43 47 51 51 47 51 50 54 40 29 57 31 35 35 87 34 36

..........

Encrypt or Decrypt? (1, 2) : 2

Enter a string to decrypt : 77 100 95 29 105 113 98 95 106 30 91 110 105 116 102 28 95 107 119 30 99 113 103 109 107 28 104 114 100 112 25 112 98 98 24 104 90 118 120 30 93 107 97 43 24 45 43 47 51 51 47 51 50 54 40 29 57 31 35 35 87 34 36

Enter a key (integer) : 8572912837

Decrypted : The quick brown fox jumps over the lazy dog. 1234567890!@#$%^&*

-----------------------

**Example 2**

Encrypt or Decrypt? (1, 2) : 1

Enter a string to encrypt : ddddddddd

Enter a key (integer) : 321


Encrypted : 99 98 97 99 98 97 99 98 97 

..........

Encrypt or Decrypt? (1, 2) : 2

Enter a string to decrypt : 99 98 97 99 98 97 99 98 97 

Enter a key (integer) : 321


Decrypted : ddddddddd

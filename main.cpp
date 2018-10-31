#include <bits/stdc++.h>
void computeLPSArray(char* pat, int M, int* lps);

void KMPSearch(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    computeLPSArray(pat, M, lps);
    int i = 0;
    int j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            std::cout << "Found pattern at index " << i-j << std::endl;
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
void computeLPSArray(char* pat, int M, int* lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int main()
{
    std::cout << "Enter string:" << std::endl;
    std::string str;
    std::getline(std::cin, str);
    char * string = new char[str.size()];
    for(int i =0; i<str.size(); i++){
        string[i] = str.c_str()[i];
    }
    std::cout << "Enter pattern:" << std::endl;
    std::string patt;
    std::getline(std::cin, patt);
    char * pattern = new char[patt.size()];
    for(int i =0; i<patt.size(); i++){
        pattern[i] = patt.c_str()[i];
    }
        KMPSearch(pattern, string);
    return 0;
}

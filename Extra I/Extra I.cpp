#include <iostream>
#include <fstream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

ifstream file("distribution2.txt");

void read_distribution(float arr[]) //the distribution of the letters from a file and stores it into an array
{
    int i;
    for (i = 1; i <= 26; i++)
        file >> arr[i];
}

void normalized_frequency(char arr[], float frequency[]) //computes the normalized frequency of each character (a histogram) in a text.
{
    int i, p = 1;
    char c, c2;
    float x, freq, ch_nr = 0;

    ch_nr = strlen(arr);
    for (i = 0; i < strlen(arr); i++)
    {
        if (isalpha(arr[i]) == 0)
            ch_nr--;
    }
    for (c = 'a'; c <= 'z'; c++)
    {
        c2 = c - 32;
        freq = 0;
        for (i = 0; i < strlen(arr); i++)
        {
            if (arr[i] == c || arr[i] == c2)
                freq++;
        }
        x = (freq * 100) / ch_nr;
        frequency[p] = x;
        p++;
    }
}

int Chi_squared_dist(float arr1[], float arr2[]) //computes the Chi squared distance between two histograms
{
    float sum = 0;
    int i;

    for (i = 1; i <= 26; i++)
    {
        sum = sum + ((arr1[i] - arr2[i]) * (arr1[i] - arr2[i])) / arr2[i];
    }
    return sum;
}

void permute_text(char text[], int nr_perm) //permutes the letters from a text n given times
{
    int i, k;

    for (i = 0; i < strlen(text); i++)
    {
        k = 0;
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] += 32;
            k = 1;
        }
        if (isalpha(text[i]))
        {
            if (text[i] + nr_perm > 'z')
                text[i] = 'a' + (text[i] + nr_perm - 'z') - 1;
            else
                text[i] = text[i] + nr_perm;
        }
        if (k == 1)
        {
            text[i] -= 32;
        }
    }
}

void Caesar_cipher(float freq_arr[], char code_text[]) //breaks the Caesar’s cipher using frequency analysis
{
    int i, p;
    float freq_text[27], res, min_chi = 1000000;
    char text_copy[400];

    for (i = 0; i <= 26; i++)
    {
        strcpy_s(text_copy, code_text);
        permute_text(text_copy, i);
        normalized_frequency(text_copy, freq_text);
        res = Chi_squared_dist(freq_text, freq_arr);
        if (res < min_chi) 
        {
            min_chi = res;
            p = i;

        }
    }
    permute_text(code_text, p);
}

int main()
{
    float distribution_letters[27];
    char code_text[400];

    read_distribution(distribution_letters);

    cout << "Introduce text:\n";
    cin.getline(code_text, 400);

    Caesar_cipher(distribution_letters, code_text);

    cout << code_text;
}


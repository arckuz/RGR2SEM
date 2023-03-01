#pragma once

#include <vector>
#include <iostream>
#include <string.h>
#include <random>
#include <fstream>
#include <string>

using namespace std;

int findd(char str, vector<char>& alphabet);
void letter_encryption(int i, int& cnt, int n, string str, string& str1, string key, vector<char> alphabet);
void letter_decryption(int i, int& cnt, int n, string str1, string& str2, string key, vector<char> alphabet);
void vij_enc(string message, string key);
void vij_dec(string key);
void vij();


int step(int a, int x, int p);
int step_with_numb(int Y, int k, int M, int p);
int nod(int a, int b);
int vzaim_prost(int p);
void encryption(int p, int g, int Y, string message, vector<pair<int, int>>& encoded_message);
void decryption(int p, int x, vector<pair<int, int>> encoded_message, string& decoded_message);
void El_Gamal();


void skital_encode();
void skital_decode();
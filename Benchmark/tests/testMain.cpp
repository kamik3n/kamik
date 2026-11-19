#include "../src/Sorting.h"
#include "../src/Timer.h"
#include <algorithm>
#include <random>
#include <string>
#include <vector>
std::vector<int> ints(size_t n){std::mt19937 g(20261119);std::uniform_int_distribution<int>d(0,1000);std::vector<int>a(n);for(auto&x:a)x=d(g);return a;}
std::vector<double> doubles(size_t n){std::mt19937 g(1);std::uniform_real_distribution<double>d(0,1000);std::vector<double>a(n);for(auto&x:a)x=d(g);return a;}
std::vector<std::string> strings(size_t n){std::vector<std::string>a(n);for(size_t i=0;i<n;++i)a[i]=std::string((i%8)+1,'a')+std::to_string(i);return a;}
template<class T> int check(const std::string& label,std::vector<T> a){auto b=a;{NBenchmark::CTimer t(label+" BubbleSortClassic");NBenchmark::BubbleSortClassic(a);} {NBenchmark::CTimer t(label+" std::sort");NBenchmark::StdSort(b);}return std::is_sorted(a.begin(),a.end())&&std::is_sorted(b.begin(),b.end())?0:1;}
int main(){for(size_t n:{0u,1u,2u,1000u,5000u}){if(check("int",ints(n)))return 1;if(check("double",doubles(n)))return 1;if(check("string",strings(n)))return 1;}return 0;}

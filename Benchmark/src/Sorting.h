#pragma once
#include <algorithm>
#include <utility>
#include <vector>
namespace NBenchmark {
template<class T> void BubbleSortClassic(std::vector<T>& a){if(a.size()<2)return;for(size_t i=0;i<a.size()-1;++i)for(size_t j=0;j<a.size()-1;++j)if(a[j]>a[j+1])std::swap(a[j],a[j+1]);}
template<class T> void StdSort(std::vector<T>& a){std::sort(a.begin(),a.end());}
}

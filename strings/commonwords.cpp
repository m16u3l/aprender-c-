#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

int main()
{
 std::vector<std::string> most { "lion","tiger","kangaroo",
                                 "donkey","lion","tiger",
                                 "lion","donkey","tiger"
                                 };
std::map<std::string, int> src;
for(auto x:most)
    ++src[x];

std::multimap<int,std::string,std::greater<int> > dst;

std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), 
                   [] (const std::pair<std::string,int> &p) {
                   return std::pair<int,std::string>(p.second, p.first);
                   }
                 );

std::multimap<int,std::string>::iterator it = dst.begin();

 for(int count = 0;count<3 && it !=dst.end();++it,++count)
   std::cout<<it->second<<":"<<it->first<<std::endl;

}
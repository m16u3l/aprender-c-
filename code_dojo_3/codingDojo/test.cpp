#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>

#include <sstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <exception>

using namespace std;

const string text = "Doom’s success lay not only with its addicting gameplay and technical innovations, such as its introduction of a portable game engine, but also in its innovative digital distribution. Note the prominent 'shareware' advertisement on the top front of the game packaging. This groundbreaking game earned a spot in the inaugural class of the World Video Game Hall of Fame.";

struct exception: public std::exception
{
    string word;
    exception(string data)
    : word{data}
    {}
    const char *  what() const noexcept override
    {
        char *  word2 =  (char*)malloc(300);
        strcpy(word2,"'");
        strcat(word2,word.data());
        strcat(word2,"'");
        strcat(word2," not found");
        return word2;
    }
};

struct word_info
{
    string word;
    size_t count;
    vector<size_t> word_info;
    vector<string>aux;

    bool exist_word(string t)const
    {
        for (size_t j = 0; j < aux.size(); j++)
        {
            if (aux[j] == t)
            {
                return true;
            }
        }
        return false;
    }

    void show_aux()
    {
        for (size_t j = 0; j < aux.size(); j++)
        {
            cout << aux[j] << '\n';
        }
    }
};

struct word_occurrence
{
    string word;
    size_t count;
};
class text_store
{
    string text;
    vector<string> words;
    char copy[1000];

public:
    text_store(){}
    ~text_store(){}

    void load_from_string(const string t)
    {
        text = t;
        strcpy(copy,text.c_str());
        char *token = strtok(copy, " ’");
        while (token != NULL) {
            string aux = token;
            words.push_back(aux);
            token = strtok(NULL, " ’");
        }
    }

    const size_t get_word_count()
    {
        return words.size();
    }

    const size_t get_word_count_by_first_letter(const char c)
    {
        size_t res = 0;
        for(auto& w:words)
        {
            if (tolower(w.at(0)) == tolower(c))
            {
                res++;
            }
        }
        return res;
    }

    template<typename PROC>
    void iterate_word_occurrences(PROC p)const
    {
        word_occurrence c;
        iterate_word(p, c);
    }

    template<typename PROC>
    void iterate_word(PROC proc,word_occurrence c) const
    {
        string word1;
        string word2;
        size_t count1 = 0;
        size_t count2 = 0;
        for (auto& w:words)
        {
            if(w == words[0]){
                word1 = words[0];
                count1++;
            }else{
                word2 = w;
                count2++;
            }
        }
        proc(word_occurrence{word1, count1});
        proc(word_occurrence{word2, count2});
    }

    auto get_word_info(string s)
    {
        word_info res;
        string newText;
        size_t pos = 0;
        char *cstr = new char [text.length()+1];
        strcpy (cstr, text.c_str());

        char *p = strtok (cstr,"’");
        while (p!=0)
        {
            newText += string(p);
            p = strtok(NULL,"’");
        }
        if(newText.find(s) ==  string::npos)
        {
            throw ::exception{s};
        }
        else
        {
            while(newText.find(s) != string::npos)
            {
                size_t found = newText.find(s);
                if (found!=string::npos)
                pos = found + 1;
                res.word_info.push_back(pos);
                res.word = s;
                pos = 0;
                newText.replace (found,s.length(),"***");
            }

        }
        delete[] cstr;
        return res;
    }

    template<typename PROC>
    void iterate_all_words_by_first_letter(char c, ;pwPROC proc)
    {

        word_info w;
        iterate_first(proc, w);
    }

    template<typename PROC>
    void iterate_first(PROC proc, word_info& w)
    {
        proc(w);
    }
};

bool test6()
{
    text_store ts;
    ts.load_from_string(text);

    size_t count = 0, total_count = 0;
    ts.iterate_all_words_by_first_letter('t', [&](const word_info& w)
    {
        auto& word = w.word;
        total_count++;
        if (word == "technical" || word == "the" || word == "This" || word == "top")
            count++;
    });

    return count == 4 && total_count == 4;
}
ostream& operator<<(ostream& os, const word_info& w_i)
{
    string res;
    for (size_t i = 0; i < w_i.word_info.size(); i++) {
        if(i == w_i.word_info.size()-1){
            res += to_string(w_i.word_info[i]);
        }else{
            res += to_string(w_i.word_info[i]) + ", ";
        }
    }
    return os << w_i.word + " (" + res + ")";
}

bool test4()
{
    text_store ts;
    ts.load_from_string(text);

    const word_info& wloc = ts.get_word_info("its");

    stringstream ss;
    ss << wloc;

    return ss.str() == "its (33, 91, 147)";
}
ostream& operator<<(ostream& os, const word_occurrence& c){
    return os << c.word + " (" + to_string(c.count) + ")";
}
bool test1()
{
    text_store ts;
    ts.load_from_string(text);

    return ts.get_word_count_by_first_letter('d') == 3;
}
bool test0()
{
    text_store ts;
    ts.load_from_string(text);

    return ts.get_word_count() == 60;
}
bool test2()
{
    text_store ts;
    ts.load_from_string("hello hello bye hello bye");

    size_t hello_count = 0, bye_count = 0;
    ts.iterate_word_occurrences([&](const word_occurrence& c)
    {
        if (c.word == "hello")
            hello_count = c.count;

        if (c.word == "bye")
            bye_count = c.count;
    });

    return hello_count == 3 && bye_count == 2;
}
bool test3()
{
    text_store ts;
    ts.load_from_string("binary world world");
    stringstream ss;
    ts.iterate_word_occurrences([&](const word_occurrence& c)
    {
        ss << c << "; ";
    });
    return ss.str() == "binary (1); world (2); ";
}

bool test5()
{
    try
    {
        text_store ts;
        ts.load_from_string(text);

        const word_info& wloc = ts.get_word_info("brisa mistica");

        cout << wloc << "\n";
        return false;
    }
    catch (const std::exception& ex)
    {
        return string{ ex.what() } == "'brisa mistica' not found";
    }
}


/*
bool test7()
{
    text_store ts;
    ts.load_from_string(text);

    return ts.get_most_occurring_word().word == "the";
}

bool test8()
{
    text_store ts;
    ts.load_from_file("vulgata.txt");

    return ts.get_word_count() == 702484 &&
           ts.get_word_count_by_first_letter('a') == 4260 &&
           ts.get_most_occurring_word().word == "et" &&
           ts.get_most_occurring_word().count == 51614 &&
           ts.get_word_info("maria").locations.back() == 3736761;
}

bool test9()
{
    return test8();
}
*/

int main()
{
    size_t score = 0;

    auto t0 = clock();

    score += test0();
    score += test1();
    score += test2();
    score += test3();
    score += test4();
    score += test5();
    score += test6();/*
    score += test7();*/
    // score += test8();
    // score += test9();

    auto t1 = clock();

    cout << "FINAL SCORE: " << score << " / 10\n";
    cout << "EXECUTION TIME: " << ((t1 - t0) / 1000) << "\n ";

    getchar();

    return 0;
}
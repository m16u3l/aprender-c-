#include <iostream>
#include <cstring>

using namespace std;

class text_processor
{
    char* a;
    char* b;
    char* c;

    struct parraf
    {
        size_t len;
        char* words;
    };

    struct word
    {
        size_t len_word;
        char* word;
    };
public:

    text_processor(const char* a, const char*b, const char* c)
    {
        size_t len_a = strlen(a);
        size_t len_b = strlen(b);
        size_t len_c = strlen(c);

        this->a = new char[len_a+1];
        this->b = new char[len_b+1];
        this->c = new char[len_c+1];
            
        memcpy(this->a, a, len_a+1);
        memcpy(this->b, b, len_b+1);
        memcpy(this->c, c, len_c+1);        
    }

    ~text_processor()
    {
        delete[] a;
        delete[] b;
        delete[] c;
    }
/*
    text_processor get_most_frequent_words()
    {

    }

    text_processor get_least_frequent_words()
    {
    
    }
*/
    void print()
    {
        cout<< "hi" <<endl;
    }

    size_t get_char_count()
    {
        return 0;
    }

    int CountWords(const char* str)
    {
        if (str == NULL)
            return 0;  // let the requirements define this...

        bool inSpaces = true;
        int numWords = 0;

        while (*str) //!= nullptrf NULL
        {
            if (std::isspace(*str))
            {
                inSpaces = true;
            }
            else if (inSpaces)
            {
                numWords++;
                inSpaces = false;
            }
            ++str;
        }
        return numWords;
    }

    int CountWordsAndLetters(char* str, int& words, int& letters)
    {
        words = 0;
        unsigned int i = 0;
        letters = 0;

        while (str[i] == ' ')
                i++;

        for (; str[i]; i++)
        {
                if (((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= 'A') && (str[i] <= 'Z')))
                        letters++;
                if (str[i] == ' ')
                {
                        words++;
                        while (1)
                                if (str[i] == ' ')
                                        i++;
                                else
                                {
                                        i--;
                                        break;
                                }

                }

        }
        words = words + 1;
        return (words);
    }


    size_t get_letter_count()
    {
        return 0;
    }
    
    size_t get_digit_count()
    {
        return 0;
    }
    size_t get_word_count()
    {
        return 0;
    }

    size_t get_frequency_by_word(const char* c)
    {
        return 0;
    }

    /*
    text_processor add_word(const char* c)
    {

    }*/
};

int main()
{
    text_processor ts { "hp and asus have announced the first windows 10 pcs running on arm - snapdragon 835 - and they're boasting about instant-on, 22 hour battery life, and gigabit lte. these machines run full windows 10 - so not some crippled windows rt nonsense - and support 32bit x86 applications. microsoft hasn't unveiled a whole lot just yet about their x86-on-arm emulation, but ars did compile some information. ",
	"the emulator runs in a just-in-time basis, converting blocks of x86 code to equivalent blocks of arm code. this conversion is cached both in memory (so each given part of a program only has to be translated once per run) and on disk (so subsequent uses of the program should be faster, as they can skip the translation). moreover, system libraries - the various dlls that applications load to make use of operating system feature - are all native arm code, including the libraries loaded by x86 programs. calling them compiled hybrid portable executables (or 'chippie' for short), these libraries are arm native code, compiled in such a way as to let them respond to x86 function calls.",
	"while processor-intensive applications are liable to suffer a significant performance hit from this emulation - photoshop will work in the emulator, but it won't be very fast - applications that spend a substantial amount of time waiting around for the user - such as word - should perform with adequate performance. as one might expect, this emulation isn't available in the kernel, so x86 device drivers won't work on these systems. it's also exclusively 32-bit; software that's available only in a 64-bit x86 version won't be compatible. "};
    
    //ts.get_most_frequent_words().print();
    //ts.get_least_frequent_words().print();
    cout << ts.get_char_count() << "\n";
    cout << ts.get_letter_count() << "\n";
    cout << ts.get_digit_count() << "\n";
    cout << ts.get_word_count() << "\n";
    cout << ts.get_frequency_by_word("emulator") << "\n";
    cout << ts.get_frequency_by_word("atari") << "\n";
    //
    //ts.print_all_frequencies();
    //ts.add_word("asus").add_word("asus").add_word("asus").add_word("asus").add_word("asus").add_word("asus");
    //cout << "*****************\n";
    //ts.print_all_frequencies();
    // should print something like:
    //      hp: 2 occurrence(s)
    //    asus: 6 occurrence(s)
    //   while: 1 occurrence(s)
    return 0;
}

/*
Do not use string class
Do not use vectors
No memory handling will remove you 10 points
Uncompiling code will render your score to 0.
Crashing code will decrease your score in 50%
*/

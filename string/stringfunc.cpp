//erase
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
 
int main()
{
    std::string s = "This Is An Example";
    std::cout << "1) " << s << '\n';
 
    s.erase(7, 3); // erases " An" using overload (1)
    std::cout << "2) " << s << '\n';
 
    s.erase(std::find(s.begin(), s.end(), ' ')); // erases first ' '; overload (2)
    std::cout << "3) " << s << '\n';
 
    s.erase(s.find(' ')); // trims from ' ' to the end of the string; overload (1)
    std::cout << "4) " << s << '\n';
 
    auto it = std::next(s.begin(), s.find('s')); // obtains iterator to the first 's'
    s.erase(it, std::next(it, 2)); // erases "sI"; overload (3)
    std::cout << "5) " << s << '\n';

}
s.erase(find(s.begin(),s.end(), ' '));




//back
#include <iostream>
#include <string>
 
int main()
{
    std::string s("Exemplary");
    char& back1 = s.back();
    back1 = 's';
    std::cout << s << '\n'; // "Exemplars"
 
    std::string const c("Exemplary");
    char const& back2 = c.back();
    std::cout << back2 << '\n'; // 'y'
}

//front
#include <iostream>
#include <string>
 
int main()
{
    std::string s("Exemplary");
    char& f1 = s.front();
    f1 = 'e';
    std::cout << s << '\n'; // "exemplary"
 
    std::string const c("Exemplary");
    char const& f2 = c.front();
    std::cout << &f2 << '\n'; // "Exemplary"
}

#include <iostream>
#include <string>
 
int main()
{
    std::basic_string<char> str = "string";
    const char* cptr = "C-string";
    const char carr[] = "Two and one";
 
    std::string output;
 
    // 1) Append a char 3 times. 
    // Notice, this is the only overload accepting chars.
    output.append(3, '*');
    std::cout << "1) " << output << '\n';
 
    // 2) Append a whole string
    output.append(str);
    std::cout << "2) " << output << '\n';
 
    // 3) Append part of a string (last 3 letters, in this case)
    output.append(str, 3, 3);
    std::cout << "3) " << output << '\n';
 
    // 4) Append part of a C-string
    // Notice, because `append` returns *this, we can chain calls together
    output.append(1, ' ').append(carr, 4);
    std::cout << "4) " << output << '\n';
 
    // 5) Append a whole C-string
    output.append(cptr);
    std::cout << "5) " << output << '\n';
 
    // 6) Append range
    output.append(&carr[3], std::end(carr));
    std::cout << "6) " << output << '\n';
 
    // 7) Append initializer list
    output.append({' ', 'l', 'i', 's', 't'});
    std::cout << "7) " << output << '\n';
}

//output

1) ***
2) ***string
3) ***stringing
4) ***stringing Two 
5) ***stringing Two C-string
6) ***stringing Two C-string and one
7) ***stringing Two C-string and one list

//swap
#include <iostream>
#include <string>
 
int main() 
{
    std::string a = "AAA";
    std::string b = "BBBB";
 
    std::cout << "Before swap:\n"
                 "a = " << a << "\n"
                 "b = " << b << "\n\n";
 
    a.swap(b);
 
    std::cout << "After swap:\n"
                 "a = " << a << "\n"
                 "b = " << b << '\n';
}

//output
Before swap:
a = AAA
b = BBBB
 
After swap:
a = BBBB
b = AAA

//find


#include <iomanip>
#include <iostream>
#include <string>
 
void print(int id, std::string::size_type n, std::string const& s)
{
    std::cout << id << ") ";
    if (std::string::npos == n)
        std::cout << "not found! n == npos\n";
    else
        std::cout << "found @ n = " << n << ", substr(" << n << ") = "
                  << std::quoted(s.substr(n)) << '\n';
}
 
int main()
{
    std::string::size_type n;
    std::string const s = "This is a string"; /*
                             ^  ^  ^
                             1  2  3          */
 
    // search from beginning of string
    n = s.find("is");
    print(1, n, s);

    // search from position 5
    n = s.find("is", 5);
    print(2, n, s);
 
    // find a single character
    n = s.find('a');
    print(3, n, s);
 
    // find a single character
    n = s.find('q');
    print(4, n, s);
}

//output


1) found @ n = 2, substr(2) = "is is a string"
2) found @ n = 5, substr(5) = "is a string"
3) found @ n = 8, substr(8) = "a string"
4) not found! n == npos

//to string from integer

#include <cstdio>
#include <format>
#include <initializer_list>
#include <iostream>
#include <string>
 
#if __cpp_lib_to_string >= 202306L
constexpr auto revision() { return " (post C++26)"; }
#else
constexpr auto revision() { return " (pre C++26)"; }
#endif
 
int main()
{
    for (const double f : {1.23456789555555, 23.43, 1e-9, 1e40, 1e-40, 123456789.0})
    {
        std::cout << "to_string:\t" << std::to_string(f) << revision() << '\n';
 
        // Before C++26, the output of std::to_string matches std::printf.
        std::printf("printf:\t\t%f\n", f);
 
        // As of C++26, the output of std::to_string matches std::format.
        std::cout << std::format("format:\t\t{}\n", f);
 
        std::cout << "std::cout:\t" << f << "\n\n";
    }
}
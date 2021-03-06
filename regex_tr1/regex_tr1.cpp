// regex_tr1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <regex>
#include <cassert>
using namespace std::tr1;


int main()
{
    // The features that are available in the various regular expression grammars provided by TR1.

    std::wstring wstr;
    wsmatch      mres;
    wregex       regx;

    // alternation using '|'
    wstr = _T("abd");
    regx = wregex(_T("a(b|c)d"));
    assert(regex_search(wstr, mres, regx));
    //wstr = mres.str();

    wstr = _T("acd");
    regx = wregex(_T("a(b|c)d"));
    assert(regex_search(wstr, mres, regx));
    //wstr = mres.str();

    // anchor
    wstr = _T("abc");
    regx = wregex(_T("^abc$"));
    assert(regex_search(wstr, mres, regx));

    wstr = _T("abcd");
    regx = wregex(_T("^abc$"));
    assert(!regex_search(wstr, mres, regx));
    regx = wregex(_T("^bcd$"));
    assert(!regex_search(wstr, mres, regx));

    // capture group using "()" and back reference
    wstr = _T("<name>maoxd</name>");
    regx = wregex(_T("<(name)>maoxd</\\1>"));
    assert(regex_search(wstr, mres, regx));
    //wstr = mres.str();

    // bracket expression
    wstr = _T("123");
    regx = wregex(_T("[123][123][123]"));
    assert(regex_search(wstr, mres, regx));
    //wstr = mres.str();

    //// control escape sequence
    //assert(regex_search(wstr, mres, reg));
    //regx = wregex(_T("\c"));

    // dsw character escape
    wstr = _T("My birthday is 1990/02/16.");
    regx = wregex(_T("\\d+/\\d+/\\d+"));
    assert(regex_search(wstr, mres, regx));
    //wstr = mres.str();

    regx = wregex(_T("\\s+"));
    assert(regex_search(wstr, mres, regx));
    //wstr = mres.str();

    regx = wregex(_T("\\w+"));
    assert(regex_search(wstr, mres, regx));
    //wstr = mres.str();

    regx = wregex(_T("\\D+"));
    assert(regex_search(wstr, mres, regx));
    //wstr = mres.str();

    regx = wregex(_T("\\S+"));
    assert(regex_search(wstr, mres, regx));

    //wstr = mres.str();
    regx = wregex(_T("\\W+"));
    assert(regex_search(wstr, mres, regx));

    //// file format escape
    //assert(regex_search(wstr, wregex(_T(""))));

    // hexadecimal escape
    wstr = _T("abc");
    regx = wregex(_T("\\x61\\x62\\x63"));
    assert(regex_search(wstr, mres, regx));

    // identity escape
    wstr = _T(".*?+|(){}[]\\");
    regx = wregex(_T("\\.\\*\\?\\+\\|\\(\\)\\{\\}\\[\\]\\\\"));
    assert(regex_search(wstr, mres, regx));
    //wstr = mres.str();

    // positive assert
    wstr = _T("abc");
    regx = wregex(_T("ab(?=c)"));
    assert(regex_search(wstr, mres, regx));

    regx = wregex(_T("ab(?=d)"));
    assert(!regex_search(wstr, mres, regx));

    // negative assert
    wstr = _T("abc");
    regx = wregex(_T("ab(?!d)"));
    assert(regex_search(wstr, mres, regx));

    regx = wregex(_T("ab(?!c)"));
    assert(!regex_search(wstr, mres, regx));

    // word boundary assert
    wstr = _T("I am maoxd.");
    regx = wregex(_T("\\bam\\b"));
    assert(regex_search(wstr, mres, regx));

    // negative word boundary assert
    regx = wregex(_T("\\Baox\\B"));
    assert(regex_search(wstr, mres, regx));

    // non-capture group
    wstr = _T("<name>maoxd</name>");
    regx = wregex(_T("<(name)>maoxd</\\1>"));

    //regx = wregex(_T("<(?:name)>maoxd</\\1>"));
    //assert(regex_search(wstr, mres, regx));

    // non-greedy repetition
    wstr = _T("abbb");
    regx = wregex(_T("ab+"));
    assert(regex_search(wstr, mres, regx));
    //wstr = mres.str();

    regx = wregex(_T("ab+?"));
    assert(regex_search(wstr, mres, regx));
    //wstr = mres.str();

    // repetition using "{}"
    wstr = _T("abbb");
    regx = wregex(_T("ab{0}"));
    assert(regex_search(wstr, mres, regx));
    regx = wregex(_T("ab{1,}"));
    assert(regex_search(wstr, mres, regx));
    regx = wregex(_T("ab{2}"));
    assert(regex_search(wstr, mres, regx));
    regx = wregex(_T("ab{1,3}"));
    assert(regex_search(wstr, mres, regx));

    // repetition using '*'
    wstr = _T("ac");
    regx = wregex(_T("ab*c"));
    assert(regex_search(wstr, mres, regx));

    wstr = _T("abc");
    regx = wregex(_T("ab*c"));
    assert(regex_search(wstr, mres, regx));

    // repetition using '?' and '+'
    wstr = _T("ac");
    regx = wregex(_T("ab?c"));
    assert(regex_search(wstr, mres, regx));

    wstr = _T("abc");
    regx = wregex(_T("ab?c"));
    assert(regex_search(wstr, mres, regx));

    regx = wregex(_T("ab+c"));
    assert(regex_search(wstr, mres, regx));

    wstr = _T("abbc");
    regx = wregex(_T("ab+c"));
    assert(regex_search(wstr, mres, regx));

    // unicode escape sequence
    wstr = _T("abcd");
    regx = wregex(_T("\\u0061\\u0062\\u0063\\u0064"));
    assert(regex_search(wstr, mres, regx));

    return 0;
}


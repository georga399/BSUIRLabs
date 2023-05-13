#include "parser.h"
#include <QDebug>
#include "custlist.h"
#include "bracket.h"
QString GetAllVars(QString input)
{
    std::string inp = input.toStdString();
    std::regex pattern (R"((int|char|long|auto)[\\* ]+.+;)");
    auto beg = std::sregex_iterator(inp.begin(), inp.end(), pattern);
    auto end = std::sregex_iterator();
    QString res;
    for (std::sregex_iterator i = beg; i != end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
            res+=QString::fromStdString(match_str) + "\n";
    }
    return res;
}

QString GetAllClassesStructs(QString input)
{
    std::string inp = input.toStdString();
    std::regex pattern;
    try
    {
        pattern = std::regex(R"(\b(class|struct) +\w+.*\n* *)");
    }
    catch(...)
    {
        qDebug() << QString("regex error");
    }

    auto beg = std::sregex_iterator(inp.begin(), inp.end(), pattern);
    auto end = std::sregex_iterator();
    QString res = "Count of structs or classes: ";
    res += QString::number(std::distance(beg, end));
    return res;
}

QString GetAllArrays(QString input)
{
    std::string inp = input.toStdString();
    std::regex pattern;
    try
    {
        pattern = std::regex(R"((int|char|long|auto)[\\* ]\w*\[\w*\])");
    }
    catch(...)
    {
        qDebug() << QString("regex error");
    }

    auto beg = std::sregex_iterator(inp.begin(), inp.end(), pattern);
    auto end = std::sregex_iterator();
    QString res = "Count of arrs: ";
    res += QString::number(std::distance(beg, end));
    return res;
}

QString GetAllFunProto(QString input)
{
    std::string inp = input.toStdString();
    std::regex pattern (R"((int|char|long|auto|void)[\* ]*\\w*[:]*\\w*\(.*\))");
    auto beg = std::sregex_iterator(inp.begin(), inp.end(), pattern);
    auto end = std::sregex_iterator();
    QString res;
    for (std::sregex_iterator i = beg; i != end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
            res+=QString::fromStdString(match_str) + " pos:" + QString::number(match.position()) + "\n";
    }
    return res;
}

QString GetAllChanges(QString input)
{
    std::string inp = input.toStdString();
    std::regex pattern (R"(\\w[ ]*(=|\*=|\+=|-=|\/=|\^=|\+\+|--)[^;]*;)");
    auto beg = std::sregex_iterator(inp.begin(), inp.end(), pattern);
    auto end = std::sregex_iterator();
    QString res;
    for (std::sregex_iterator i = beg; i != end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
            res+=QString::fromStdString(match_str) + " pos:" + QString::number(match.position()) + "\n";
    }
    return res;
}

QString GetAllLocalVars(QString input)
{
    std::string inp = input.toStdString();
    std::regex pattern (R"((int|char|long|auto)[\\* ]+.+;)");
    auto beg = std::sregex_iterator(inp.begin(), inp.end(), pattern);
    auto end = std::sregex_iterator();
    QString res;
    for (std::sregex_iterator i = beg; i != end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
            res+=QString::fromStdString(match_str) + QString::number(match.position()) + "\n";
    }
    return res;
}

QString GetOverrideFuncs(QString input)
{
    std::string inp = input.toStdString();
    std::regex pattern (R"((int|char|long|auto|void)[ \*]*(\w+) *\([ \w\*]*\))");
    auto beg = std::sregex_iterator(inp.begin(), inp.end(), pattern);
    auto end = std::sregex_iterator();
    QString res = " ";
    for (std::sregex_iterator i = beg; i != end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        qDebug() << QString::fromStdString(match_str);
        std::regex pattern1(R"( +\w+)");
        auto beg1 = std::sregex_iterator(match_str.begin(), match_str.end(), pattern1);
        qDebug() << ((*beg1).str().c_str());
        std::string funName = (*beg1).str();
        std::string regExpression = "(int|char|long|auto|void)[ \\*]*";
        regExpression += funName;
        regExpression +=  "*\\([ \\w\\*]*\\)";
        std::regex patternForOverride(regExpression);
        auto beg2 = std::sregex_iterator(inp.begin(), inp.end(), patternForOverride);
        auto end2 = std::sregex_iterator();
        qDebug() << QString("Count of overrided funcs ") + QString::fromStdString(match_str) + QString(": ") + QString::number(std::distance(beg2, end2));
        res+= QString("Count of overrided funcs ") + QString::fromStdString(match_str) + QString(": ") + QString::number(std::distance(beg2, end2)) + QString('\n');
    }
    return res;
}

QString GetDeepBranches(QString input)
{
    QString res ="";
    std::string inp = input.toStdString();
    std::regex pattern (R"(if *\([\w \=\-\+\<\>]+\)[ \n]*\{)");
    auto beg = std::sregex_iterator(inp.begin(), inp.end(), pattern);
    auto end = std::sregex_iterator();
    for (std::sregex_iterator i = beg; i != end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        qDebug() << QString::fromStdString(match_str);
        int nesting = GetNestingsIn(match.position(), input.size(), input);
        res += QString::fromStdString(match_str) + QString("position: ") + QString::number(match.position()) + QString("nesting: ") + QString::number(nesting) + "\n";

    }
    return res;
}

QString GetLogicalWarns(QString input)
{
    QString res ="";
    std::string inp = input.toStdString();
    std::regex pattern (R"((while\(false\))|(if\(false\))|(if\(true\)))");
    auto beg = std::sregex_iterator(inp.begin(), inp.end(), pattern);
    auto end = std::sregex_iterator();
    for (std::sregex_iterator i = beg; i != end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        qDebug() << QString::fromStdString(match_str);
        res += QString::fromStdString(match_str) + QString("position: ") + QString::number(match.position()) + "\n";
    }
    return res;
}

int GetNestingsIn(int pos, int sizeStr, QString allText)
{
    int i = pos;
    for(; i<sizeStr; i++)
    {
        if(i == '{')
        {
            pos = i;
            break;
        }
    }
    if(i == pos) return 0;
    CustList<char> stck;
    stck.push_front('{');
    int maxNest = 0;
    for(int i = 0; i<allText.size(); i++)
    {
        if(allText[i] == '{')
        {
            stck.push_front('{');
            maxNest = std::max (maxNest, (int)stck.size());
        }
        else if(allText[i] == '}') stck.pop_back();
        if(stck.empty()) break;

    }
    return maxNest;
}
